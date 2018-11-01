#include "shared_ptr.h"
#include<iostream>

using namespace std;

int main() //Тест
{
	SharedPtr<int> ptr;
	*ptr = 2;
	cout << ptr.use_count();
	SharedPtr<int> ptr2(ptr);
	cout << ptr.use_count();
	*ptr2 = 34;
	ptr.swap(ptr2);
}
