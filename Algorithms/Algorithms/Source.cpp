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

// 1. Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
void password_caesar(std::string& str, int key) {
	std::string temp = str;

	for (int i = 0; i < str.size(); i++)
	{
		if(i + key < str.size())
			temp[i] = str[i + key];
		else
			temp[i] = str[i + key - str.size()];
	}

	str = temp;
}

int main() {
	std::string str = "Hello World";
	int key = 4;
	password_caesar(str, key);

	cout << "STRING: " << str << "  KEY: " << key << endl;

	return 0;
}