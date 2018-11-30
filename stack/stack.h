#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T x;
	Node <T> *head, *next;
};

template <typename T>
class Stack
{
	Node <T> *h;
public:
	void push1(T &val)
	{
		Node<T> *temp = new Node<T>;
		temp->x = val;
		temp->next = h;
		h = temp;
	}

	void pop()
	{
		Node <T> *pv = h;
		h = h->next;
		delete pv;
	}

	T& head()
	{
		return h->x;
	}

	void push2(T &&value)
	{
		Node<T> *temp = new Node<T>;
		temp->next = h;
		temp->x = value;
		h = move(temp);
	}
};
