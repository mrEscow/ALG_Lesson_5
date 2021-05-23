#include <iostream>

#include "Header.h"
// Реализовать пузырьковую сортировку двумерного массива например, 
// массив 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9
int main() {

	const int numRows = 3;
	const int numCols = 3;

	int array[numRows][numCols] =
	{
		{1,9,2}, 
		{5,7,6}, 
		{4,3,8} 
	};
	printArray(*array, numRows, numCols);
	//for (int row = 0; row < numRows; ++row)
	//{
	//	for (int col = 0; col < numCols; ++col)
	//		std::cout << array[row][col] << "\t";

	//	std::cout << '\n';
	//}


	return 0;
}