#include "MyString.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyString s1;
	MyString s2{10};
	MyString s3{ "hello world!!!"};
	MyString s4{ "r " };

	cout << "Введіть рядок: ";
	s1.setString();
	s1.printString();
	
	cout << endl;
	cout << "Розмір рядка = " << s1.getSize() << endl;
	cout << endl;

	char* cP = s3.getString();
	cout << "object 3: ";
	for (size_t i = 0; cP[i]; i++)
	{
		cout << *(cP + i);
	}
	cout << endl;

	cout << "Кількість екземплярив классу MyString = " << MyString::numberOfClassInstances() << endl;
	cout << endl;

	return 0;
}

