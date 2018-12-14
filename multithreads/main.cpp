#include <iostream>
#include <thread>
#include <string>
#include "picosha256.h" 
#include <vector>
#include <stdlib.h>
#include <fstream>
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

ofstream fout;

void run()
{
	string curr_str;
	string hash;
	fout.open("log.txt");
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	while (true)
	{
		curr_str = random_string(6);
		hash = picosha2::hash256_hex_string(curr_str);
		if (hash[60] == '0' && hash[61] == '0' && hash[62] == '0' && hash[63] == '0')
		{
			cout << "Пара найдена!" << endl;
			cout << curr_str << "\t" << hash << endl;
			cout << endl;

			fout << "Пара найдена!\n";
			fout << curr_str << "\t" << hash << "\n";
			fout << "\n";
		}
	}
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Количество потоков: " << std::thread::hardware_concurrency() << endl;
	thread t1(run);
	thread t2(run);
	thread t3(run);
	thread t4(run);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
