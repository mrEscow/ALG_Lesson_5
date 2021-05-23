#pragma once
//-----------------------------------------------------------------------
void printArray(int array[], int numRows,int numCols );
void printArray(int array[], int size);


//-----------------------------------------------------------------------
void printArray(int array[], int numRows, int numCols ) {

	int count = 0;
	for (int row = 0; row < numRows; ++row)
	{
		for (int col = 0; col < numCols; ++col)
			std::cout << array[count + col] << "\t";

		std::cout << '\n';
		count += numRows;
	}
}
//-----------------------------------------------------------------------
void printArray(int array[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << "\t";
	}
	std::cout << '\n';
}