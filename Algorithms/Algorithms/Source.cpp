#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#include "Header.h"


// 1.Описать очередь с приоритетным исключением

#define SZ 10

typedef struct{

	int pr;
	int dat;

}Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init() {
	for (int i = 0; i < SZ; i++){
		arr[i] = NULL;
	}
	head = 0;
	tail = 0;
	items = 0;

}

void ins(int pr, int dat) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;
	int flag;

	if (items == 0) {
		arr[tail++] = node;
		items++;
	}
	else if (items == SZ) {
		cout << "Queue is full" << endl;
		return;
	}
	else {
		int i = 0;
		int idx = 0;
		Node* tmp;
		for ( i = head; i < tail; ++i){
			idx = i % SZ;
			if (arr[idx]->pr > pr)
				break;
			else
				idx++;
		}
		flag = idx % SZ;
		i++;
		while (i <= tail) {
			idx = i % SZ;
			tmp = arr[idx];
			arr[idx] = arr[flag];
			arr[flag] = tmp;
			i++;
		}
		arr[flag] = node;
		items++;
		tail++;
	}
}

Node* rem() {
	if (items == 0) {
		return NULL;
	}
	else {
		int idx = head++ % SZ;
		Node* tmp = arr[idx];
		arr[idx] = NULL;
		items--;
		return tmp;
	}
}

void printQueue() {
	cout << "[ ";
	for (int i = 0; i < SZ; i++){
		if (arr[i] == NULL)
			cout << "[*, *]";
		else
			cout << "[" << arr[i]->pr << ", " << arr[i]->dat << "]";
	}
	cout << " ]";
}
// 2.Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

int main() {

	init();
	ins(1, 45);
	ins(4, 5);
	ins(7, 4);
	ins(3, 466);
	ins(1, 37);
	ins(6, 29);
	ins(9, 130);
	ins(2, 30);
	ins(1, 15);
	ins(5, 15);
	printQueue();

	return 0;
}