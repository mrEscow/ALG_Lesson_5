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



// 1.����������� ����� � ������� � �������������� �����

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

const int n = 6;
int matrix[n][n] = {

        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},

};
int visitedDepth[n] = { 0 };

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
void depthTraversStack(int st) {
	pushStack(st); 
	visitedDepth[st] = 1;
	for (int i = 0; i < n; ++i) {
		if (matrix[st][i] == 1 && !visitedDepth[i]) {
		
		}
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

// 2.���������� ����� ��������� �������.��� ������� ������� ���� � ������������ �������.
// ����� ������ ���� ���� ����� ��������� � ���������� ���������� ������ �� ������ �� ����� �����(����������� ������).
// 2.1 ����� ����� ����������� ��������(� ��������� ������ ������� �� ��������� ������)
// 2.2 ����� ����� �� ������� ���������(� ��������� ���� ������ �����) 
// � ����� ������ ������� ��� ������������ ������ ���� ����� � ������� ���������� ���������� ������ �� ���.

// ����������� ������ ������ ����� ���� ���� � ����� �� ����� �, ���������� ������� main � ��� ����������� �������.




int main() {

	resetArr();

	//depthTraversStack(0);
 //   resetArr();
 //   printf("\n");
	//depthTraversStack(2);
 //   resetArr();
 //   printf("\n");
	//depthTraversStack(1);
 //   resetArr();
 //   printf("\n");

	printf("\n");
	depthTravers(0);
	resetArr();

	printf("\n");
	depthTravers(1);
	resetArr();

	printf("\n");
	depthTravers(2);
	resetArr();

	printf("\n");
	depthTravers(3);
	resetArr();

	printf("\n");
	depthTravers(4);
	resetArr();

	printf("\n");
	depthTravers(5);
	resetArr();

	printf("\n");


	return 0;
}