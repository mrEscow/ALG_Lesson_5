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

// Сортировать в массиве целых положительных чисел только чётные числа,
// нечётные оставив на своих местах при помощи алгоритма блочной сортировки, 
// то есть массив вида[0 2 8 3 4 6 5 9 8 2 7 3] превратить в[0 2 2 3 4 6 5 9 8 8 7 3]

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

    for (int digit = 1; digit <= 10; digit*=10) {
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
int main() {

	const int size = 12;
    int array[size] = { 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 };

	printArray(array, size);
    bucketSort(array, size);
    printArray(array, size);


	return 0;
}