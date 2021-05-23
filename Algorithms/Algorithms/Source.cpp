#include <iostream>

#include "Header.h"

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
void bestQSort(int* arr, int first, int last) {
    if (last + 1 < 10)
        sortShells(arr, last + 1);
    else
    {
        int  left, mid, right, mediana;

        left = arr[0];
        mid =  arr[last/2];
        right = arr[last];

        mediana = med(left, mid, right);

        if(mediana == left)
            swapInt(arr[0], arr[last / 2]);
        if (mediana == right)
            swapInt(arr[last], arr[last / 2]);

        qs(arr, 0, last);
    }
}


int main() {

	const int size = 20;
    int array[size];


    fillIntRandom(array,size,100);
	printArray(array, size);
    bestQSort(array, 0, size - 1);
    printArray(array, size);


	return 0;
}