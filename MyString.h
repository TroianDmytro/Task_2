#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <istream>

using namespace std;

////////////////////////////////////// не виходить винести функції і конструктори в окремий файл .срр 
/////////////////////////////////////  відразу з`является якась не зрозуміла помилка
class MyString
{
private:

	char* str;
	static int classInstance;

	void copyStr(const char* other)
	{
		size_t length = strlen(other);
		str = new char[length + 1];
		strcpy_s(str, length + 1, other);
	}

public:
	
	MyString()
	{
		str = new char[80];
		classInstance++;
		cout << "constructor" << this << endl;
	}

	MyString(const char* str)
	{
		if (str != nullptr)
		{
			copyStr(str);
			classInstance++;
		}
		cout << "constructor" << this << endl;
	}

	MyString(int size) {
		str = new char[size];
		classInstance++;
		cout << "constructor" << this << endl;
	}

	~MyString()
	{
		delete[] str;
		str = nullptr;
		classInstance--;
		cout << "destructor" << this << endl;
	}

	// функція для вводу рядка з клавіатури
	void setString()
	{
		cin >> str;
	}

	// повертае рядок
	char* getString()
	{
		return str;
	}

	// Виводить рядок на екран
	void printString()
	{
		cout << str << endl;
	}

	// функція повертае розмір рядка
	size_t getSize()
	{
		return str != nullptr ? strlen(str) : 0;
	}
	
	// стасична функція яка повертае кількість екземплярів класу MyString
	static int numberOfClassInstances()
	{
		return classInstance;
	}

	//перевантаження оператора >> для вводу рядка з клавіатури 
	friend istream& operator>>(istream input, MyString& s)
	{
		input.getline(s.str, s.getSize(), '\n');
		return input;
	}
};

int MyString::classInstance = 0;

