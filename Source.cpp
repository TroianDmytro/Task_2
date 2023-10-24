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

	cout << "������ �����: ";
	s1.setString();
	s1.printString();
	
	cout << endl;
	cout << "����� ����� = " << s1.getSize() << endl;
	cout << endl;

	char* cP = s3.getString();
	cout << "object 3: ";
	for (size_t i = 0; cP[i]; i++)
	{
		cout << *(cP + i);
	}
	cout << endl;

	cout << "ʳ������ ����������� ������ MyString = " << MyString::numberOfClassInstances() << endl;
	cout << endl;

	return 0;
}

