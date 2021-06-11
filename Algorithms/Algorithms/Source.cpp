#include <string>
#include <stdio.h>
#include <cstring>  // for wcscpy_s, wcscat_s
#include <cstdlib>  // for _countof
#include <iostream> // for cout, includes <cstdlib>, <cstring>
#include <errno.h>  // for return values

using std::cout;
using std::endl;
using std::cin;

#include "Header.h"
#include "Source.h"

// 1.Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов.
int  hash(char* S){

    int i, r = 0;
    while (*S)
    {
        r += (int)(*S);
        S++;
    }
    return r;
}
//1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.


int hashFunction(std::string String)  {

    int s = 0;

    for (int i = 0; i < String.size(); i++) {
        s += (int)String[i];
    }

    return s;
}


//2. Имеются монеты номиналом 50, 10, 5, 2, 1 коп. 
//   Напишите функцию которая минимальным количеством монет наберет сумму 98 коп. 
//   Для решения задачи используйте “жадный” алгоритм.

//int countCoins(int n) {
//
//    int count = 0;
//    int i = 0;
//
//    count += n / 50;
//    n -= (count-i) * 50;
//    i = count;
//
//    count += n / 10;
//    n -= (count - i) * 10;
//    i = count;
//
//    count += n / 5;
//    n -= (count - i) * 5;
//    i = count;
//
//    count += n / 2;
//    n -= (count - i) * 2;
//    i = count;
//
//    count += n / 1;
//    //n -= (count - i) * 1;
//    //i = count;
//
//    return count;
//}


#define COINS 5
#define MAX 20


// Все деноминации валюты

int coins[COINS] = { 1, 2, 5, 10, 50};



void findMin(int cost)

{

    int coinList[MAX] = { 0 };

    int i, k = 0;



    for (i = COINS - 1; i >= 0; i--) {

        while (cost >= coins[i]) {

            cost -= coins[i];

            coinList[k++] = coins[i]; // добавить монету в список

        }

    }



    for (i = 0; i < k; i++) {

        printf("%d ", coinList[i]); // Распечатать

    }

    return;

}





int main() {

    //std::string String = "ABC";
    //cout << hashFunction(String) << endl;

    //int arr[5] = { 50,10,5,2,1 };
    //int n = 98;
    ////cout << n / 50 << endl;
    //cout << countCoins(n);


    int n = 98; // входное значение
    printf("Following is minimal number of change for %d: ", n);
    findMin(n);

 
	return 0;
}