#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Student
{
	string Name;
	string GroupId;
	map<string, int> ratings;
};

int main()
{
	setlocale(LC_ALL, "ru");
	vector<Student> students =
	{
		{"Иван", "РЛ1-11", {{"MA", 3 }, {"ИНЖГРАФ", 5}, {"РадМат", 4}}}, 
		{"Евгений", "РЛ1-12", {{"MA", 5 }, {"ИНЖГРАФ", 2}, {"РадМат", 5}}},
	  {"Слава", "РЛ1-13", {{"MA", 4 }, {"ИНЖГРАФ", 3}, {"РадМат", 5}}},
	  {"Иван", "ИУ8-31", {{"АЯ", 3 }, {"ДискрМат", 5}, {"ТОЭ", 4}}},
		{"Сергей", "ИУ8-31", {{"АЯ", 5 }, {"ДискрМат", 2}, {"ТОЭ", 5}}},
		{"Виталий", "Э9-51", {{"Экология", 3 }, {"БЖД", 3}, {"Физика", 4}}},
		{"Сергей", "Э9-55", {{"Экология", 5 }, {"БЖД", 5}, {"Физика", 5}}},
		{"Вася", "СМ5-113", {{"Экология", 5 }, {"БЖД", 5}, {"Физика", 5}}},
	};
}
