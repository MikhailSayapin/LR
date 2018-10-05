#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	string Name;
	string GroupId;
	map<string, int> ratings;
};

void Print(const vector<Student> &s);

int main()
{
	setlocale(LC_ALL, "ru");
	vector<Student> students =
	{
		{ "Иван", "РЛ1-11",{ { "Math", 3 },{ "ИНЖГРАФ", 5 },{ "ТОЭ", 4 }, {"Политология", 2} } },
		{ "Евгений", "РЛ1-12",{ { "Math", 5 },{ "ИНЖГРАФ", 2 },{ "ТОЭ", 5 }, { "Политология", 5 } } },
		{ "Слава", "РЛ1-13",{ { "Math", 4 },{ "ИНЖГРАФ", 3 },{ "ТОЭ", 5 }, { "Политология", 4 } } },
		{ "Михаил", "ИУ8-31",{ { "Math", 3 },{ "ИНЖГРАФ", 5 },{ "ТОЭ", 4 }, { "Политология", 4 } } },
		{ "Сергей", "ИУ8-31",{ { "Math", 5 },{ "ИНЖГРАФ", 2 },{ "ТОЭ", 5 }, { "Политология", 3 } } },
		{ "Виталий", "Э9-51",{ { "Math", 3 },{ "ИНЖГРАФ", 3 },{ "ТОЭ", 4 }, { "Политология", 5 } } },
		{ "Пётр", "Э9-55",{ { "Math", 5 },{ "ИНЖГРАФ", 5 },{ "ТОЭ", 5 }, { "Политология", 2 } } },
		{ "Вася", "СМ5-113",{ { "Math", 5 },{ "ИНЖГРАФ", 5 },{ "ТОЭ", 5 }, { "Политология", 3 } } },
	};

	sort(students.begin(), students.end(), [](const Student &s1, const Student &s2)
	{
		return s1.Name < s2.Name;
	});

	cout << "Задание 1" << endl;
	Print(students);

	cout << "=======================================================" << endl;
	cout << "Задание 3" << endl;

	int rezult = count_if(students.begin(), students.end(), [](const vector<Student> &v)
	{
		for (auto ev : v)
		{
			for (auto es : ev.ratings)
			{
				if (es.second == 2)
				{
					return true;
				}
			}
		}
	});
	cout << rezult << endl;


}
void Print(const vector<Student> &s)
{
	for (auto el : s)
	{
		cout << el.Name << " | " << el.GroupId << " | " << "Math: " << el.ratings["Math"] << " ИНЖГРАФ: " << el.ratings["ИНЖГРАФ"]
			<< " ТОЭ: " << el.ratings["ТОЭ"] << " Политология: " << el.ratings["Политология"] << endl;
	}
}
