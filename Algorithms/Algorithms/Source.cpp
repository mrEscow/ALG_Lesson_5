#include <iostream>

#include "Header.h"

void WBubleSort(int array[], int numRows, int numCols) {
	int temp;
	for (int i = 0; i < numRows * numCols - 1; i++) {
		for (int j = 0; j < numRows * numCols - i - 1; j++) {
			if (array[j] > array[j + 1]) {

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

//������� ��������� ���� - ����� ��������� ������ - ����� - �����
//1 - ��������� � ������������ 11 ����� � �������� �� � ������������������ � 
//2 - ������������� ������������������ � 
//3 - ��� ������� �������� ������������������ � ���������� ���������� �� ������� sqrt(fabs(�)) + 5 * pow(�, 3) 
//� ���� ��������� ���������� ��������� 400 - ���������������� ������������.

void TPK() {
	int temp;
	const int size = 11;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "Input  " << i + 1 << "  number :  ";
		std::cin >> array[i];
	}
	for (int i = 0; i < size / 2; i++)
	{
		temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
	}
	for (int i = 0; i < size; i++)
	{
		temp = sqrt(fabs(array[i])) + 5 * pow(array[i], 3);
		if (temp > 400) std::cout << "sqrt(fabs("<< array[i] <<")) + 5 * pow("<< array[i] <<", 3) ="<< temp << "\n";
	}
}
int main() {

	const int numRows = 3;
	const int numCols = 3;

	int array[numRows][numCols] =
	{
		{1,9,2}, 
		{5,7,6}, 
		{4,3,8} 
	};


	WBubleSort(*array, numRows, numCols);
	printArray(*array, numRows, numCols);

	TPK();

	return 0;
}