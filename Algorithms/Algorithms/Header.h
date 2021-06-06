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
//Описать подробную блок - схему алгоритма Трабба - Прадо - Кнута
//1 - запросить у пользователя 11 чисел и записать их в последовательность П 
//2 - инвертировать последовательность П 
//3 - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) 
//и если результат вычислений превышает 400 - проинформировать пользователя.
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
//-----------------------------------------------------------------------
void qs(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

void sortShells(int* arr, int len) {
    int i;
    int j;
    int step;
    int temp;

    for (step = len / 2; step > 0; step /= 2) {
        for (i = step; i < len; ++i) {
            temp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (temp < arr[j - step]) {
                    arr[j] = arr[j - step];
                }
                else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}
//-----------------------------------------------------------------------
int med(int a, int b, int c)
{
    if (a > b) { // ba ?c
        if (c > a) // bac
            return a;
        return (b > c) ? b : c;
    }
    // ab ? c
    if (c > b) // abc
        return b;
    return (a > c) ? a : c;
}
//-----------------------------------------------------------------------
void bestQSort(int* arr, int first, int last) {
    if (last + 1 < 10)
        sortShells(arr, last + 1);
    else
    {
        int  left, mid, right, mediana;

        left = arr[0];
        mid = arr[last / 2];
        right = arr[last];

        mediana = med(left, mid, right);

        if (mediana == left)
            swapInt(arr[0], arr[last / 2]);
        if (mediana == right)
            swapInt(arr[last], arr[last / 2]);

        qs(arr, 0, last);
    }
}
//-----------------------------------------------------------------------
// Сортировать в массиве целых положительных чисел только чётные числа,
// нечётные оставив на своих местах при помощи алгоритма блочной сортировки, 
// то есть массив вида[0 2 8 3 4 6 5 9 8 2 7 3] превратить в[0 2 2 3 4 6 5 9 8 8 7 3]
//-----------------------------------------------------------------------
void bucketSort(int* arr, int len) {



    const int max = 12; len; // C++
    const int b = 10;

    int  buckets[b][max + 1];

    int temp_array[max];
    for (int i = 0; i < max; i++)
    {
        temp_array[i] = arr[i];
    }

    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit <= 10; digit *= 10) {
        for (int i = 0; i < max; ++i) {
            int d = (arr[i] / digit) % b;

            //int counter = buckets[d][max];          
            //buckets[d][counter] = arr[i];
            //counter++;
            //buckets[d][max] = counter;

            //std::cout << buckets[d][counter] << std::endl;
            buckets[d][buckets[d][max]++] = arr[i];
        }
        //printArray(*buckets, 12);
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {

                //if((arr[idx] & 1) == 0)
                arr[idx++] = buckets[i][j];
                //else
                {
                    //arr[idx++] = arr[idx--];
                    //idx++;  
                    //++j; 
                }
            }
            buckets[i][max] = 0;
        }
    }
    printArray(arr, max);
    for (int i = 0; i < max; i++)
    {
        if (temp_array[i] % 2 != 0)
            arr[i] = temp_array[i];
    }
}
//-----------------------------------------------------------------------



//////// 
//////#define T_DATA char
//////#define SIZE 1000
//////
//////
//////T_DATA Queue[SIZE];
//////int first = 0;
//////int end = -1;
//////
//////int items = 0;
//////
////////bool enQueue(T_DATA data) {
////////	if (end < SIZE) {
////////		Queue[++end] = data;
////////		return true;
////////	}
////////	else {
////////		cout << "Queue is full" << endl;
////////		return false;
////////	}
////////}
//////bool enQueue(T_DATA data) {
//////    if (items == SIZE) {
//////        cout << "Queue is full" << endl;
//////        return false;
//////    }
//////    if (end == SIZE - 1)
//////        end = -1;
//////    Queue[++end] = data;
//////    items++;
//////    return true;
//////}
//////
////////T_DATA deQueue() {
////////	if (first <= end) {
////////		return Queue[first++];
////////	}
////////	else {
////////		cout << "Queue is empty" << endl;
////////		return -1;
////////	}
////////}
//////
//////T_DATA deQueue() {
//////    if (items == 0) {
//////        cout << "Queue is empty" << endl;
//////        return -1;
//////    }
//////    else {
//////        char tmp = Queue[first++];
//////        first %= SIZE;  // if (first == SIZE) first = 0;
//////        items--;
//////        return tmp;
//////    }
//////}


////////#define T_DATA char
////////#define SIZE 1000
////////
////////int cursor = -1;
////////T_DATA Stack[SIZE];
////////
////////bool push(T_DATA data) {
////////	if (cursor < SIZE) {
////////		Stack[++cursor] = data;
////////		return true;
////////	}
////////	else {
////////		cout << "Stack overflow" << endl;
////////		return false;
////////	}
////////}
////////
////////T_DATA pop() {
////////	if (cursor != -1) {
////////		return Stack[cursor--];
////////	}
////////	else {
////////		cout << "Stack is empty" << endl;
////////		return -1;
////////	}
////////}


//////#define SZ 10
//////
//////typedef struct {
//////
//////	int pr;
//////	int dat;
//////
//////}Node;
//////
//////Node* arr[SZ];
//////int head;
//////int tail;
//////int items;
//////
//////void init() {
//////	for (int i = 0; i < SZ; i++) {
//////		arr[i] = NULL;
//////	}
//////	head = 0;
//////	tail = 0;
//////	items = 0;
//////
//////}
//////
//////void ins(int pr, int dat) {
//////	Node* node = (Node*)malloc(sizeof(Node));
//////	node->dat = dat;
//////	node->pr = pr;
//////	int flag;
//////
//////	if (items == 0) {
//////		arr[tail++] = node;
//////		items++;
//////	}
//////	else if (items == SZ) {
//////		cout << "Queue is full" << endl;
//////		return;
//////	}
//////	else {
//////		int i = 0;
//////		int idx = 0;
//////		Node* tmp;
//////		for (i = head; i < tail; ++i) {
//////			idx = i % SZ;
//////			if (arr[idx]->pr > pr)
//////				break;
//////			else
//////				idx++;
//////		}
//////		flag = idx % SZ;
//////		i++;
//////		while (i <= tail) {
//////			idx = i % SZ;
//////			tmp = arr[idx];
//////			arr[idx] = arr[flag];
//////			arr[flag] = tmp;
//////			i++;
//////		}
//////		arr[flag] = node;
//////		items++;
//////		tail++;
//////	}
//////}