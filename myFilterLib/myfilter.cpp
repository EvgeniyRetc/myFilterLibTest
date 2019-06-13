#include "myfilter.h"
#include "math.h"
Filter::Filter(std::vector<double> &frequencies_, uint32_t freqSampling_, int order_, TypeOfFilter typeOfFilter_) {

    frequencies = frequencies_;
    typeOfFilter = typeOfFilter_;
    order = order_;
    freqSampling = freqSampling_;
    uint32_t N = static_cast<uint32_t>(frequencies.size());
    std::vector <double> freqNorm(N);
    for (uint32_t i = 0; i < frequencies.size(); i++ ){
        freqNorm[i] = frequencies[i]/freqSampling;
    }
    impulseResponse.assign(static_cast<uint64_t>(order), 0.0);
    CreateImpulseResponse(freqNorm);
}
Filter::Filter() {

    std::vector<double> freqTmp;
    frequencies = freqTmp;
    typeOfFilter = lowpass;
    order = 0;
    freqSampling = 0;
    impulseResponse.assign(static_cast<uint64_t>(order), 0.0);
}
void Filter::SetParams(std::vector <double> &frequencies_, uint32_t freqSampling_, int order_, TypeOfFilter typeOfFilter_) {

    frequencies = frequencies_;
    typeOfFilter = typeOfFilter_;
    order = order_;
    freqSampling = freqSampling_;
    uint32_t N = static_cast<uint32_t>(frequencies.size());
    std::vector <double> freqNorm(N);
    for (uint32_t i = 0; i < frequencies.size(); i++) {
        freqNorm[i] = frequencies[i] / freqSampling;
    }
    impulseResponse.assign(static_cast<uint64_t>(order), 0.0);
    CreateImpulseResponse(freqNorm);
}


void Filter::CreateImpulseResponse(std::vector<double> &frequencies_){

    int cntr = order/2 + order%2; // находим индекс центрального 3центральный элемент
    std::vector <double> W(static_cast<uint64_t>(order)); // весовая функция Блэкмана
    switch (typeOfFilter){
        //************  LOWPASS ************
        case lowpass:
            CreateLowpass(frequencies_, W, cntr);
            break;

        // ************ HIGHPASS ************
        case highpass:
            CreateHighpass(frequencies_, W, cntr);
            break;
        // ************ PASSBAND ************
        case passband:
            CreatePassband(frequencies_, W, cntr);
            break;
        // ************ STOPBAND ************
        case stopband:
            CreateStopband(frequencies_, W, cntr);
            break;
    }
    ScaleFilter();
}

void Filter::CreateLowpass(std::vector <double> &frequencies_, std::vector <double> &W, int cntr){

    if (frequencies_.size() != 1){
        throw std::invalid_argument("wrong number of frequencies");
    }
    double fCut = frequencies_[0];
    for(int i = 0; i < order; i++){
        if (i != cntr){
            impulseResponse[static_cast<uint64_t>(i)] = sin(2*PI*fCut*(i - cntr))/(PI*(i - cntr));
        }
        else{
            impulseResponse[static_cast<uint64_t>(i)] = 2*fCut;
        }
        W[static_cast<uint64_t>(i)] = 0.42 - 0.5*cos(2*PI*(i - cntr)/(order - 1)) + 0.8*cos(4*PI*(i - cntr)/(order - 1));// весовая функция Блэкмана
        impulseResponse[static_cast<uint64_t>(i)] = impulseResponse[static_cast<uint64_t>(i)]*W[static_cast<uint64_t>(i)];
    }
}
void Filter::CreateHighpass(std::vector <double> &frequencies_, std::vector <double> &W, int cntr){

    if (frequencies_.size() != 1){
        throw std::invalid_argument("wrong number of frequencies");
    }
    double fCut = frequencies_[0];
    for(int i = 0; i < order; i++){
        if (i != cntr){
            impulseResponse[static_cast<uint64_t>(i)] = -sin(2*PI*fCut*(i - cntr))/(PI*(i - cntr));
        }
        else{
            impulseResponse[static_cast<uint64_t>(i)] = 1 - 2*fCut;
        }
        W[static_cast<uint64_t>(i)] = 0.42 - 0.5*cos(2*PI*(i - cntr)/(order - 1)) + 0.8*cos(4*PI*(i - cntr)/(order - 1));
        impulseResponse[static_cast<uint64_t>(i)] = impulseResponse[static_cast<uint64_t>(i)]*W[static_cast<uint64_t>(i)];
    }
}
void Filter::CreatePassband(std::vector <double> &frequencies_, std::vector <double> &W, int cntr){

    double fLow, fHigh;
    if (frequencies_.size() != 2){
        throw std::invalid_argument("wrong number of frequencies");
    }
    if (frequencies_[0] < frequencies_[1]){
        fLow  = frequencies_[0];
        fHigh = frequencies_[1];
    }else{
        fLow  = frequencies_[1];
        fHigh = frequencies_[0];
    }
    for(int i = 0; i < order; i++){
        if (i != cntr){
            impulseResponse[static_cast<uint64_t>(i)] = sin(2*PI*fHigh*(i - cntr))/(PI*(i - cntr))  - sin(2*PI*fLow*(i - cntr))/(PI*(i - cntr));
        }
        else{
            impulseResponse[static_cast<uint64_t>(i)] = 2*(fHigh - fLow);
        }
        W[static_cast<uint64_t>(i)] = 0.42 - 0.5*cos(2*PI*(i - cntr)/(order - 1)) + 0.8*cos(4*PI*(i - cntr)/(order - 1));
        impulseResponse[static_cast<uint64_t>(i)] = impulseResponse[static_cast<uint64_t>(i)]*W[static_cast<uint64_t>(i)];

    }
};
void Filter::CreateStopband(std::vector <double> &frequencies_, std::vector <double> &W, int cntr){

    double fLow, fHigh;
    if (frequencies_.size() != 2){
        throw std::invalid_argument("wrong number of frequencies");
    }
    if (frequencies_[0] < frequencies_[1]){
        fLow  = frequencies_[0];
        fHigh = frequencies_[1];
    }else{
        fLow  = frequencies_[1];
        fHigh = frequencies_[0];
    }
    for(int i = 0; i < order; i++){
        if (i != cntr){
            impulseResponse[static_cast<uint64_t>(i)] = sin(2*PI*fLow*(i - cntr))/(PI*(i - cntr))  - sin(2*PI*fHigh*(i - cntr))/(PI*(i - cntr));
        }
        else{
            impulseResponse[static_cast<uint64_t>(i)] = 1 - 2*(fHigh - fLow);
        }
        W[static_cast<uint64_t>(i)] = 0.42 - 0.5*cos(2*PI*(i- cntr)/(order - 1)) + 0.8*cos(4*PI*(i - cntr)/(order - 1));
        impulseResponse[static_cast<uint64_t>(i)] = impulseResponse[static_cast<uint64_t>(i)]*W[static_cast<uint64_t>(i)];
    }
}

std::vector<double> Filter::GetImpulseResponse() {
    return impulseResponse;
}

int Filter::GetOrder() {
    return order;
}

void Filter::ScaleFilter() {

    double tmpSin = 0;
    double tmpCos = 0;
    double coef = 1;
    double f0;
    switch (typeOfFilter){
        case lowpass:
            coef = 0;
            for (int i = 0; i < order; i++) {
                coef += impulseResponse[static_cast<uint64_t>(i)];
            }
            break;
        case highpass:
            f0 = 1;
            for (int i = 0; i < order; i++) {
                tmpCos += cos(2 * PI*i*f0/2)*impulseResponse[static_cast<uint64_t>(i)];
                tmpSin -= sin(2 * PI*i*f0/2)*impulseResponse[static_cast<uint64_t>(i)];
            }
            coef = sqrt(tmpCos*tmpCos + tmpSin * tmpSin);
            break;
        case passband:
            if (frequencies[0] < frequencies[1]) {
                f0 = (frequencies[1] + frequencies[0])/freqSampling/2;
            }
            else {
                f0 = (frequencies[0] + frequencies[1])/freqSampling/2;
            }

            for (int i = 0; i < order; i++) {
                tmpCos += cos(2 * PI*i*f0)*impulseResponse[static_cast<uint64_t>(i)];
                tmpSin -= sin(2 * PI*i*f0)*impulseResponse[static_cast<uint64_t>(i)];
            }
            coef = sqrt(tmpCos*tmpCos + tmpSin * tmpSin);
            break;
        case stopband:
            coef = 0;
            for (int i = 0; i < order; i++) {
                coef += impulseResponse[static_cast<uint64_t>(i)];
            }
            break;
    }
    for (int i = 0; i < order; i++) {
        impulseResponse[static_cast<uint64_t>(i)] = impulseResponse[static_cast<uint64_t>(i)]/coef;
    }

}

