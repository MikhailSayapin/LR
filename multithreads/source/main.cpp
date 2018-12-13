#include <iostream>
#include <thread>
#include <string>
#include "picosha256.h" 
#include <vector>
#include <stdlib.h>
//picosha2::hash256_hex_string(src)
using namespace std;

std::string random_string(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

void run()
{
	string curr_str;
	string hash;
	while (true)
	{
		curr_str = random_string(6);
		hash = picosha2::hash256_hex_string(curr_str);
		if (hash[60] == '0' && hash[61] == '0' && hash[62] == '0' && hash[63] == '0')
		{
			cout << "Пара найдена!" << endl;
			cout << curr_str << "\t" << hash << endl;
			cout << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N;
	cout << "Введите кол-во потоков N: ";
	cin >> N;
	thread beg(run);
	vector<thread> v;
	for (int i = 0; i < N; i++)
	{
		v[i] = beg;
	}
}
