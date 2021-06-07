#include <string>
#include <cstring>  // for wcscpy_s, wcscat_s
#include <cstdlib>  // for _countof
#include <iostream> // for cout, includes <cstdlib>, <cstring>
#include <errno.h>  // for return values

using std::cout;
using std::endl;
using std::cin;

#include "Header.h"
#include "Source.h"



// 1.Реализовать обход в глубину с использованием стека

//-------------------------------------------------------------
#define T_DATA int
#define SIZE 1000

int cursor = -1;
T_DATA Stack[SIZE];

bool pushStack(T_DATA data) {
	if (cursor < SIZE) {
		Stack[++cursor] = data;
		return true;
	}
	else {
		cout << "Stack overflow" << endl;
		return false;
	}
}

T_DATA popStack() {
	if (cursor != -1) {
		return Stack[cursor--];
	}
	else {
		cout << "Stack is empty" << endl;
		return -1;
	}
}

//-------------------------------------------------------------

//const int n = 6;
//int matrix[n][n] = {
//
//        {0, 1, 1, 0, 0, 0},
//        {0, 0, 0, 1, 1, 1},
//        {0, 0, 0, 0, 0, 1},
//        {1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0},
//
//};

const int n = 3;
int matrix[n][n] = {

		{0, 1, 1},
		{0, 0, 0},
		{1, 0, 0},

};

int visitedDepth[n] = { 0 };
int visitedDepth2[n][n] = { 0 };

void depthTravers(int st) {
    int r;
    printf("%d ", st);

    visitedDepth[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visitedDepth[r]) {
            depthTravers(r);
        }
    }
}

void resetArr() {
    for (int i = 0; i < n; ++i) {
        visitedDepth[i] = 0;
    }
}
void resetArr2() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visitedDepth2[i][j] = 0;
		}
	}
}
void depthTraversStack(int st) {
	pushStack(st); 
	visitedDepth2[0][st] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++){
			if (matrix[j][i] == 1 && !visitedDepth2[j][i]) {
					visitedDepth2[i][j] = 1;
					pushStack(j);
			}
		}
	}

	int count = cursor;
	for (int i = 0; i <= count; ++i) {

		cout << popStack()<< " ";
		
	}
}
//-------------------------------------------------------------
bool decToBin(int a, std::string& result) {
	if (a <= 0) return false;
	while (a >= 1) {
		pushStack(a % 2);
		a /= 2;
	}
	int count = cursor;
	for (int i = 0; i <= count; ++i) {

		result += (popStack()) ? "1" : "0";

	}
	return true;
}
//-------------------------------------------------------------


// не проверяйте до 8-ого работа и тд


// 2.Моделируем робота поисковой системы.Дан готовый простой граф с циклическими связями.
// Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа(полустепень захода).
// 2.1 обход графа рекурсивной функцией(с подсчётом только смежных со стартовой вершин)
// 2.2 обход графа по матрице смежности(с подсчётом всех вершин графа) 
// В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.

// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.




int main() {
	std::string result;
	resetArr();
	resetArr2();

	depthTraversStack(0);
    resetArr2();
    printf("\n");
	depthTraversStack(1);
    resetArr2();
    printf("\n");
	depthTraversStack(2);
    resetArr2();
    printf("\n");

	printf("\n");
	depthTravers(0);
	resetArr();
	printf("\n");
	depthTravers(1);
	resetArr();
	printf("\n");
	depthTravers(2);
	resetArr();



	return 0;
}