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

int countCoins(int n) {

    int count = 0;
    int i = 0;

    count += n / 50;
    n -= (count-i) * 50;
    i = count;

    count += n / 10;
    n -= (count - i) * 10;
    i = count;

    count += n / 5;
    n -= (count - i) * 5;
    i = count;

    count += n / 2;
    n -= (count - i) * 2;
    i = count;

    count += n / 1;
    n -= (count - i) * 1;
    i = count;

    return count;
}

int main() {

    //std::string String = "ABC";
    //cout << hashFunction(String) << endl;

    int arr[5] = { 50,10,5,2,1 };
    int n = 100;
    //cout << n / 50 << endl;
    cout << countCoins(n);

	return 0;
}