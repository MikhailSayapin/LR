//ТЕСТ
#include "stack.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	Stack <int> *st = new Stack<int>;
	st->push2(4);
	cout << st->head() << endl;
	int a = 3;
	st->push1(a);
	cout << st->head() << endl;
	st->pop();
	cout << st->head() << endl;
	system("pause");
	return 0;
}
