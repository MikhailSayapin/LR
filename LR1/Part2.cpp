#include <iostream> 
#include <map> 
#include <string> 
#include <vector> 
#include <fstream> 
#include <cstdio> 
#include <algorithm> 
#include <iterator> 

using namespace std;

struct Entity 
{
	string Query;
	float Frequency;
};

using Dict = multimap<string, Entity>;

multimap<string, Entity> load(const string &filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
		cerr << "This file does not exist" << endl;
	else 
	{
		fin.close();
		fin.open(filename);
		Dict objForTrans;
		string str1, str2;
		float fl;
		Entity en;

		while (fin >> str1 >> str2 >> fl) 
		{
			en.Query = str2;
			en.Frequency = fl;
			objForTrans.emplace(str1, en);
			cout << str1 << " " << en.Query << " " << en.Frequency << endl;
		}
		fin.close();
		return objForTrans;
	}
}

vector<Entity> suggest(const Dict &dict, const string &current_word) 
{
	vector<Entity> entity;

	auto result = dict.equal_range(current_word);

	for (auto it = result.first; it != result.second; ++it)
		entity.push_back(it->second);

	sort(entity.begin(), entity.end(), [](const Entity &s1, const Entity &s2) 
	{
		return s1.Frequency > s2.Frequency;
	});

	return entity;
}

int main() 
{
	auto dict = load("dictionary.txt");

	auto result = suggest(dict, "добрый");

	cout << "result == ";

	for (auto el : result)
		cout << "{" << el.Query << ", " << el.Frequency << "} ";
}
