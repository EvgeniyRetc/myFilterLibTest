#include "stdint.h"
#include <iostream>
#include <fstream>
#include "myfilter.h"
#include <locale>
#include "gtest/gtest.h"

const int ORDER = 1024;
const int FREQ_SAMP = 44000;

TEST(testLowpass, testFilterLib){

	std::string fileName = "..\..\files\sinus10k.txt";
	std::vector <double> fromFile, filteredSignal;
	std::vector<double> freqCut = { 5000 };
	std::ifstream inputFile(fileName);
	std::istream_iterator<double> input(inputFile);
	std::copy(input, std::istream_iterator<double>(), std::back_inserter(fromFile));
	Filter lowpass(freqCut, FREQ_SAMP, ORDER, lowpass);
	filteredSignal = Filtering(fromFile, lowpass, 1);
	std::ofstream fileOut("sinForLowpass.txt");
	std::copy(filteredSignal.begin(), filteredSignal.end(), std::ostream_iterator<double>(fileOut, " "));
	for (int i = 0; i < filteredSignal.size(); i++) {
		ASSERT_NEAR(filteredSignal[i], 0, 1e-5) << "Не были удовлетворены условия подавления ФНЧ фильтра";
	}
}	

//TEST(testLowpass, testFilterLib) {
//	const uint32_t NUMBER_OF_ELEMENTS = 10;
//	int vector[NUMBER_OF_ELEMENTS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, vectorRef[NUMBER_OF_ELEMENTS];
//	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
//	//копируем значение из основного вектора в опороный
//	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
//		vectorRef[i] = vector[i];
//	}
//	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // используем для сравнения стандартную сортировку
//	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
//	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
//		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании сортированного вектора было найдено несоответствие";
//	}
//}
//
//TEST(testLowpass, testFilterLib) {
//	const uint32_t NUMBER_OF_ELEMENTS = 10;
//	int vector[NUMBER_OF_ELEMENTS] = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1 }, vectorRef[NUMBER_OF_ELEMENTS];
//	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
//	//копируем значение из основного вектора в опороный
//	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
//		vectorRef[i] = vector[i];
//	}
//	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // используем для сравнения стандартную сортировку
//	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
//	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
//		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании  вектора состоящего из -1, 1 было найдено несоответствие";
//	}
//}
//
//
//TEST(testLowpass, testFilterLib) {
//	const uint32_t NUMBER_OF_ELEMENTS = 10;
//	int vector[NUMBER_OF_ELEMENTS] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, vectorRef[NUMBER_OF_ELEMENTS];
//	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
//	//копируем значение из основного вектора в опороный
//	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
//		vectorRef[i] = vector[i];
//	}
//	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // используем для сравнения стандартную сортировку
//	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
//	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
//		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании обратно отсортированного вектора  было найдено несоответствие";
//	}
//}





int main(int argc, char **argv){
	setlocale(LC_ALL, "Russian");
	std::string fileName = "../../files/sinForLowpass.txt";
	std::cout << "______________________\n";
	std::cout << "THE END\n";

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
//