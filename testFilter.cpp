#include "stdint.h"
#include <iostream>
#include <fstream>
#include "myfilter.h"
#include <locale>
#include <iterator>
#include "gtest/gtest.h"

const int ORDER = 1024;
const int START_COMPARE = 530;
const int FREQ_SAMP = 44000;
const double ACCURACY = 0.0178; //подавление в -35 dB

TEST(testLowpass, testFilterLib){

	std::string fileName = "..//files//sinus10k.txt";
	std::vector <double> fromFile, filteredSignal;
	std::vector<double> freqCut = { 3000 };
	std::ifstream inputFile(fileName);
	std::istream_iterator<double> input(inputFile);
	std::copy(input, std::istream_iterator<double>(), std::back_inserter(fromFile));
	Filter lowpass(freqCut, FREQ_SAMP, ORDER, lowpass);
	filteredSignal = Filtering(fromFile, lowpass, 1);
	for (int i = START_COMPARE; i < filteredSignal.size(); i++) {
		ASSERT_NEAR(filteredSignal[i], 0, ACCURACY) << "Не были удовлетворены требования по подавлению ФНЧ фильтра";
	}
}	

TEST(testHighpass, testFilterLib) {

	std::string fileName = "..//files//sinus3k.txt";
	std::vector <double> fromFile, filteredSignal;
	std::vector<double> freqCut = { 10000 };
	std::ifstream inputFile(fileName);
	std::istream_iterator<double> input(inputFile);
	std::copy(input, std::istream_iterator<double>(), std::back_inserter(fromFile));
	Filter highpass(freqCut, FREQ_SAMP, ORDER, highpass);
	filteredSignal = Filtering(fromFile, highpass, 1);
	for (int i = START_COMPARE; i < filteredSignal.size(); i++) {
		ASSERT_NEAR(filteredSignal[i], 0, ACCURACY) << "Не были удовлетворены требования по подавлению ФВЧ фильтра";
	}
}


TEST(testPassband, testFilterLib) {

	std::string fileName = "..//files//sinus3k10k.txt";
	std::vector <double> fromFile, filteredSignal;
	std::vector<double> freqs = { 7000, 8000 };
	std::ifstream inputFile(fileName);
	std::istream_iterator<double> input(inputFile);
	std::copy(input, std::istream_iterator<double>(), std::back_inserter(fromFile));
	Filter passband(freqs, FREQ_SAMP, ORDER, passband);
	filteredSignal = Filtering(fromFile, passband, 1);
	for (int i = 2*START_COMPARE; i < filteredSignal.size(); i++) {
		ASSERT_NEAR(filteredSignal[i], 0, ACCURACY) << "Не были удовлетворены требования по подавлению полосового фильтра";
	}
}

TEST(testStopband, testFilterLib) {

	std::string fileName = "..//files//sinus7_5k.txt";
	std::vector <double> fromFile, filteredSignal;
	std::vector<double> freqs = { 7000, 8000 };
	std::ifstream inputFile(fileName);
	std::istream_iterator<double> input(inputFile);
	std::copy(input, std::istream_iterator<double>(), std::back_inserter(fromFile));
	Filter stopband(freqs, FREQ_SAMP, ORDER, stopband);
	filteredSignal = Filtering(fromFile, stopband, 1);
	for (int i = 2*START_COMPARE; i < filteredSignal.size(); i++) {
		ASSERT_NEAR(filteredSignal[i], 0, ACCURACY) << i << "Не были удовлетворены требования по подавлению режекторного фильтра ";
	}
}





int main(int argc, char **argv){
	setlocale(LC_ALL, "Russian");
	std::string fileName = "../../files/sinForLowpass.txt";
	std::cout << "______________________\n";
	std::cout << "THE END\n";

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
//