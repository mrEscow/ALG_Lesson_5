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



// 1 Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:
// 1.1.создаст[50] деревьев по[10000] узлов и заполнит узлы случайными целочисленными значениями;
// 1.2.рассчитает, какой процент из созданных деревьев является сбалансированными.

// 2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.

// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.




int main() {
	std::string result;
	decToBin(8, result);

	cout << result << endl;

	return 0;
}