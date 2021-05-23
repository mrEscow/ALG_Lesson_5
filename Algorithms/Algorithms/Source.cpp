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



	return 0;
}