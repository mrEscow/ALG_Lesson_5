#pragma once
//-----------------------------------------------------------------------
void printArray(int array[], int numRows,int numCols );
void printArray(int array[], int size);
void TPK();
void swapInt(int& first, int& second);
void fillIntRandom(int* array, int size, int border);
void qsL(int* arr, int first, int last);
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
		std::cout << array[i] << "  ";
	}
	std::cout << '\n';
}
//-----------------------------------------------------------------------
//������� ��������� ���� - ����� ��������� ������ - ����� - �����
//1 - ��������� � ������������ 11 ����� � �������� �� � ������������������ � 
//2 - ������������� ������������������ � 
//3 - ��� ������� �������� ������������������ � ���������� ���������� �� ������� sqrt(fabs(�)) + 5 * pow(�, 3) 
//� ���� ��������� ���������� ��������� 400 - ���������������� ������������.
//-----------------------------------------------------------------------
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
		if (temp > 400) std::cout << "sqrt(fabs(" << array[i] << ")) + 5 * pow(" << array[i] << ", 3) =" << temp << "\n";
	}
}
//-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------
void swapInt(int &first, int &second) {
	int tmp = first;
	first = second;
	second = tmp;
}
//-----------------------------------------------------------------------
void fillIntRandom(int* array, int size, int border) {
	for (int i = 0; i < size; ++i)
		*(array + i) = rand() % border;
}
//-----------------------------------------------------------------------
void qsL(int* arr, int first, int last) {
	if (first < last) {
		int x = arr[last];
		int i = first;
		int j;
		for (j = first; j <= last - 1; j++) {
			if (arr[j] <= x) {
				swapInt(arr[i], arr[j]);
				i++;
			}
		}
		swapInt(arr[i], arr[last]);
		qsL(arr, first, i - 1);
		qsL(arr, i + 1, last);
	}
}