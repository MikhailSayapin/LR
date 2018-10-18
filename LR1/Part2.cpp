#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Entity
{
	string Query;
	double Frequency;
};

multimap<std::string, Entity> load(const string& filename);
vector<Entity> suggest(const dict&, const string& currentWord);

int main()
{
	setlocale(LC_ALL, "ru");
	multimap <string, Entity> dict;
	dict.insert(pair<string, Entity>("добрый", { "сок", 0.07 }));
	dict.insert(pair<string, Entity>("добрый", { "вечер", 0.1 }));
	dict.insert(pair<string, Entity>("добрый", { "утро", 0.01 }));
	dict.insert(pair<string, Entity>("добрый", { "человек", 0.02 }));
	dict.insert(pair<string, Entity>("добрый", { "сок", 0.21 }));
	dict.insert(pair<string, Entity>("добрый", { "сна", 0.11 }));
}

multimap<std::string, Entity> load(const string& filename)
{
	cout << "Введите путь к файлу" << endl;
}
