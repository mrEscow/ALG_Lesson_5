#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#include "Header.h"


// 1.Описать очередь с приоритетным исключением
#define T_DATA char
#define SIZE 1000


T_DATA Queue[SIZE];
int first = 0;
int end = -1;

int items = 0;

//bool enQueue(T_DATA data) {
//	if (end < SIZE) {
//		Queue[++end] = data;
//		return true;
//	}
//	else {
//		cout << "Queue is full" << endl;
//		return false;
//	}
//}
bool enQueue(T_DATA data) {
	if (items == SIZE) {
		cout << "Queue is full" << endl;
		return false;
	}
	if(end == SIZE - 1)
		end = -1;
	Queue[++end] = data;
	items++;
	return true;
}

//T_DATA deQueue() {
//	if (first <= end) {
//		return Queue[first++];
//	}
//	else {
//		cout << "Queue is empty" << endl;
//		return -1;
//	}
//}

T_DATA deQueue() {
	if (items == 0) {
		cout << "Queue is empty" << endl;
		return -1;
	}
	else{
		char tmp = Queue[first++];
		first %= SIZE;  // if (first == SIZE) first = 0;
		items--;
		return tmp;
	}
}

//#define T_DATA char
//#define SIZE 1000
//
//int cursor = -1;
//T_DATA Stack[SIZE];
//
//bool push(T_DATA data) {
//	if (cursor < SIZE) {
//		Stack[++cursor] = data;
//		return true;
//	}
//	else {
//		cout << "Stack overflow" << endl;
//		return false;
//	}
//}
//
//T_DATA pop() {
//	if (cursor != -1) {
//		return Stack[cursor--];
//	}
//	else {
//		cout << "Stack is empty" << endl;
//		return -1;
//	}
//}

// 2.Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

int main() {

	enQueue('a');
	enQueue('b');
	enQueue('c');
	enQueue('d');
	enQueue('e');
	enQueue('f');

	while (items > 0){
		cout << deQueue();
	}

	return 0;
}