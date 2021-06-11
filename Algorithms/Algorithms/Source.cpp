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





int main() {

    std::string String = "ABC";
    cout << hashFunction(String) << endl;
	return 0;
}