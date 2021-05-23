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

//Описать подробную блок - схему алгоритма Трабба - Прадо - Кнута
//1 - запросить у пользователя 11 чисел и записать их в последовательность П 
//2 - инвертировать последовательность П 
//3 - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) 
//и если результат вычислений превышает 400 - проинформировать пользователя.

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