#include "shared_ptr.h"
#include <iostream>

using namespace std;

int main() //Тест
{
	//int *p = new int(2);
	int p = 2;
	SharedPtr<int> ptr1;
	ptr1.reset(&p);
	//SharedPtr<int> ptr2(ptr1);
	//cout << *ptr2;
	
}
