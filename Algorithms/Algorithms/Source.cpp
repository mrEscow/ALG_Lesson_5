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



// 1 �������� ������� ����������� �������� �� ���������� � �� �������� ������ ���������������� � �������� ���������, �������:
// 1.1.�������[50] �������� ��[10000] ����� � �������� ���� ���������� �������������� ����������;
// 1.2.����������, ����� ������� �� ��������� �������� �������� �����������������.

// 2. �������� ����������� ������� ��������� ������ � ������ ���������� � �����, � �� � �������.

// ����������� ������ ������ ����� ���� ���� � ����� �� ����� �, ���������� ������� main � ��� ����������� �������.




int main() {
	std::string result;
	decToBin(8, result);

	cout << result << endl;

	return 0;
}