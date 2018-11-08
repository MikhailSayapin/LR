#include "shared_ptr.h"
#include <iostream>
#include <string>

using namespace std;

int main() //Тест
{
	setlocale(LC_ALL, "ru");
	SharedPtr <int> intptr(5);
	cout << *intptr << endl;
	intptr.reset(new int(20));
	cout << *intptr << endl;
	SharedPtr<int>intptr2(intptr);
	cout << "кол-во ссылок: " << intptr.use_count() << endl;
	cout << "кол-во ссылок: " << intptr2.use_count() << endl;
	cout << endl;

	SharedPtr <string> strptr1("Hello World");
	SharedPtr <string> strptr2("Goodbye World");
	strptr1.swap(strptr2);
	cout << *strptr1 << endl;
	cout << *strptr2 << endl;
	cout << strptr1.use_count() << endl;
	strptr1.reset();
	cout << strptr1.use_count() << endl;
}
