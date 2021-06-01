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



// 1.Описать очередь с приоритетным исключением

#define SZ 10

typedef struct{

	int pr;
	int dat;

}Node;

Node* arr[SZ];
int tail;
int items;

void init() {

	tail = 0;
	items = 0;

	for (int i = 0; i < SZ; i++) {
		arr[i] = NULL;
	}
}

void ins(int pr, int dat) {

	Node* node = (Node*)malloc(sizeof(Node));

	node->pr = pr;
	node->dat = dat;

	if (items < SZ) {
		arr[tail++] = node;
		items++;
	}
	else {
		cout << "Queue is full" << endl;
		//return;
	}

}

void printQueue() {
	cout << "[ ";
	for (int i = 0; i < SZ; i++) {
		if (arr[i] == NULL)
			cout << "[*, *]";
		else
			cout << "[" << arr[i]->pr << ", " << arr[i]->dat << "]";
	}
	cout << " ]";
}
// 2.Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
#define T char
#define SIZE 1000

int cursor = -1;
T Stack2[SIZE];

bool pushStack(T data) {
	if (cursor < SIZE) {
		Stack2[++cursor] = data;
		return true;
	}
	else {
		printf("%s \n", "Stack overflow");
		return false;
	}
}

T popStack() {
	if (cursor != -1) {
		return Stack2[cursor--];
	}
	else {
		printf("%s \n", "Stack is empty");
		return -1;
	}
}

int rem() {
	if (items == 0) {
		cout << "Queue is empty" << endl;
		return NULL;
	}
	int max = arr[0]->pr;
	int idx = 0;

	for (int i = 0; i < items; i++){
		if (arr[i]->pr > max) {
			max = arr[i]->pr;
			idx = i;
		}
	}
	Node* tmp = arr[idx];
	int result = tmp->dat;
	arr[idx] = arr[tail];
	items--;
	tail--;
	delete tmp;
	return result;
}

bool decToBin(int a, std::string& result) {
	if (a <= 0) return false;
	while (a >= 1) {
		pushStack(a % 2);
		a /= 2;
	}
	int count = cursor;
	for (int i = 0; i <= count; ++i) {
		//strcpy_s(result, (rsize_t)1000, 'a');
		result += (popStack()) ? "1" : "0";
		//wcscpy_s(result, _countof(result) (popStack()) ? L"1" : L"0");
	}
	return true;
}




int main() {
	std::string result;
	decToBin(8, result);

	cout << result << endl;

	return 0;
}