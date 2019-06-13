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
	//�������� �������� �� ��������� ������� � ��������
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS); // ���������� ��� ��������� ����������� ����������
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "��� ������������ ���������� ������� ���� ������� ��������������";
	}
}	

TEST(testSortedVector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 10;
	int vector[NUMBER_OF_ELEMENTS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//�������� �������� �� ��������� ������� � ��������
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // ���������� ��� ��������� ����������� ����������
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "��� ������������ �������������� ������� ���� ������� ��������������";
	}
}

TEST(test1not1Vector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 10;
	int vector[NUMBER_OF_ELEMENTS] = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1 }, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//�������� �������� �� ��������� ������� � ��������
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // ���������� ��� ��������� ����������� ����������
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "��� ������������  ������� ���������� �� -1, 1 ���� ������� ��������������";
	}
}


TEST(testReverseVector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 10;
	int vector[NUMBER_OF_ELEMENTS] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//�������� �������� �� ��������� ������� � ��������
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // ���������� ��� ��������� ����������� ����������
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "��� ������������ ������� ���������������� �������  ���� ������� ��������������";
	}
}


TEST(testEmptyVector, testQuickSort) {
	const uint32_t NUMBER_OF_ELEMENTS = 1;
	int vector[NUMBER_OF_ELEMENTS] = {}, vectorRef[NUMBER_OF_ELEMENTS];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	//�������� �������� �� ��������� ������� � ��������
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		vectorRef[i] = vector[i];
	}
	std::sort(vectorRef, vectorRef + NUMBER_OF_ELEMENTS);  // ���������� ��� ��������� ����������� ����������
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ASSERT_EQ(vector[i], vectorRef[i]) << "��� ������������ ������� �������  ���� ������� ��������������";
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