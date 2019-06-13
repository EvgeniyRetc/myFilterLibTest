#include "stdint.h"
#include <iostream>
#include <fstream>
#include "myfilter.h"
#include <windows.h> 
#include <locale>
#include "gtest/gtest.h"

/* TEST(testRandomVector, testQuickSort){
	const uint32_t NUMBER_OF_ELEMENTS = 10;
	int vector[NUMBER_OF_ELEMENTS], vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//копируем значение из основного вектора в опороный
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS); // используем для сравнения стандартную сортировку
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании рандомного вектора было найдено несоответствие";
	}
}	

TEST(testSortedVector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 10;
	int vector[NUMBER_OF_ELEMENTS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//копируем значение из основного вектора в опороный
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // используем для сравнения стандартную сортировку
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании сортированного вектора было найдено несоответствие";
	}
}

TEST(test1not1Vector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 10;
	int vector[NUMBER_OF_ELEMENTS] = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1 }, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//копируем значение из основного вектора в опороный
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // используем для сравнения стандартную сортировку
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании  вектора состоящего из -1, 1 было найдено несоответствие";
	}
}


TEST(testReverseVector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 10;
	int vector[NUMBER_OF_ELEMENTS] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//копируем значение из основного вектора в опороный
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // используем для сравнения стандартную сортировку
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании обратно отсортированного вектора  было найдено несоответствие";
	}
}


TEST(testEmptyVector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 1;
	int vector[NUMBER_OF_ELEMENTS] = {}, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//копируем значение из основного вектора в опороный
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // используем для сравнения стандартную сортировку
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "При тестировании пустого вектора  было найдено несоответствие";
	}
} */




int main(int argc, char **argv){
	setlocale(LC_ALL, "Russian");
	std::cout << std::endl;
	std::cout << "______________________\n";
	std::cout << "THE END\n";

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
//