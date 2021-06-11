#include <string>
#include <windows.h>
#include <cstring>  // for wcscpy_s, wcscat_s
#include <cstdlib>  // for _countof
#include <iostream> // for cout, includes <cstdlib>, <cstring>
#include <errno.h>  // for return values

using std::cout;
using std::endl;
using std::cin;
using std::string;

#include "Header.h"
#include "Source.h"

// 1. ����������� ���������� � ����������� ������ � ������������ � ������� ���������� � ������
void password_caesar(std::string& str, int key) {
	std::string temp = str;

	for (int i = 0; i < str.size(); i++)
	{
		if(key > 0)
			if(i + key < str.size())
				temp[i] = str[i + key];
			else
				temp[i] = str[i + key - str.size()];
		else
			if (i + key < 0)
				temp[i] = str[i + str.size() + key];
			else
				temp[i] = str[i + key];
	}

	str = temp;
}

// 2. ����������� ���������� � ����������� �������������� � ������������ � ������� ���������� � ����������� ��������
string coder(string s, int w)
{
	int h;

	if (s.length() % w != 0) 
		h = s.length() / w + 1;
	else
		h = s.length() / w;

	//char a[h][w] ;

	/*�������� ���������� ����� � �������*/
	char** a = new char* [h];

	/*�������� ���������� �������� � �������*/
	for (int i = 0; i < w; i++) {
		a[i] = new char[w];
	}


		int k = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (k < s.length())
			{
				a[i][j] = s[k];
				k++;
			}
			else a[i][j] = ' ';
		}
	}

	string code;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			code += a[j][i];
		}
	}

	for (int i = 0; i < w; i++) {

		delete[] a[i];
	}

	//delete[] a;


	return code;
}
string decoder(string s, int w)
{
	int h = s.length() / w;;

	//char a[w][h];
	/*�������� ���������� ����� � �������*/
	char** a = new char* [h];
	/*�������� ���������� �������� � �������*/
	for (int i = 0; i < w; i++) {
		a[i] = new char[w];
	}

	int k = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			a[i][j] = s[k];
			k++;
		}
	}

	string decode;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			decode += a[j][i];
		}
	}

	for (int i = 0; i < w; i++) {
		delete[] a[i];
	}
	//delete[] a;

	return decode;
}

int main() {
	setlocale(LC_ALL, "Russian");

	//std::string str = "Hello World";
	//int key; 

	//key = 4;
	//password_caesar(str, key);
	//cout << "STRING: " << str << "  KEY: " << key << endl;

	//key = -4;
	//password_caesar(str, key);
	//cout << "STRING: " << str << "  KEY: " << key << endl;

	string s;
	cout << "���������� �����:" << endl;
	getline(cin, s);
	int w;
	cout << "���� (������ �������):" << endl;
	cin >> w;
	cout << "�������������� ����� : " << coder(s, w) << endl << "�������������� ����� : " << decoder(coder(s, w), w);

	return 0;
}