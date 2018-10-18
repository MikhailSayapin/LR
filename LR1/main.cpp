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
	vector<Student> students;

	map<string, int> tempRatingsIvan = { { "Math", 3 },{ "ИНЖГРАФ", 5 },{ "ТОЭ", 4 }, {"Политология", 2} };
	map<string, int> tempRatingsEvgeny = { { "Math", 5 },{ "ИНЖГРАФ", 2 },{ "ТОЭ", 5 }, { "Политология", 5 } };
	map<string, int> tempRatingsSlava = { { "Math", 4 },{ "ИНЖГРАФ", 3 },{ "ТОЭ", 5 }, { "Политология", 4 } };
	map<string, int> tempRatingsMikhail = { { "Math", 3 },{ "ИНЖГРАФ", 5 },{ "ТОЭ", 4 }, { "Политология", 4 } };
	map<string, int> tempRatingsSergey = { { "Math", 5 },{ "ИНЖГРАФ", 2 },{ "ТОЭ", 5 }, { "Политология", 3 } };
	map<string, int> tempRatingsVitaly = { { "Math", 5 },{ "ИНЖГРАФ", 2 },{ "ТОЭ", 5 }, { "Политология", 3 } };
	map<string, int> tempRatingsPetr = { { "Math", 2 },{ "ИНЖГРАФ", 2 },{ "ТОЭ", 5 }, { "Политология", 2 } };
	map<string, int> tempRatingsVasya = { { "Math", 5 },{ "ИНЖГРАФ", 5 },{ "ТОЭ", 5 }, { "Политология", 5 } };
	students.push_back({ "Иван", "РЛ1-11", tempRatingsIvan });
	students.push_back({ "Евгений", "РЛ1-12", tempRatingsEvgeny });
	students.push_back({ "Слава", "РЛ1-13", tempRatingsSlava });
	students.push_back({ "Михаил", "ИУ8-31", tempRatingsMikhail });
	students.push_back({ "Сергей", "ИУ8-31", tempRatingsSergey });
	students.push_back({ "Виталий", "Э9-51", tempRatingsVitaly });
	students.push_back({"Пётр", "Э9-55", tempRatingsPetr});
	students.push_back({ "Вася", "СМ5-113", tempRatingsVasya });

	cout << "Задание 1" << endl;

	sort(students.begin(), students.end(), [](Student &s1, Student &s2)
	{
		return s1.Name < s2.Name;
	});

	Print(students);
	cout << endl;

	cout << "Задание 2" << endl;
	sort(students.begin(), students.end(), [](Student &s1, Student &s2)
	{
		return (s1.ratings["Math"] + s1.ratings["ИНЖГРАФ"] + s1.ratings["ТОЭ"] + s1.ratings["Политология"]) / 4 >
			(s2.ratings["Math"] + s2.ratings["ИНЖГРАФ"] + s2.ratings["ТОЭ"] + s2.ratings["Политология"]) / 4;
	});

	Print(students);
	cout << endl;

	cout << "Задание 3" << endl;
	cout << count_if(students.begin(), students.end(), [](Student &s)
	{
		return s.ratings["Math"] == 2 || s.ratings["ИНЖГРАФ"] == 2 || 
			s.ratings["ТОЭ"] == 2 || s.ratings["Политология"] == 2;
	});
	cout << " студентов имеют неудовлетворительную оценку хотя бы по одному предмету" << endl;
	cout << endl;

	cout << "Задание 4" << endl;
	cout << count_if(students.begin(), students.end(), [](Student &s)
	{
		return s.ratings["Math"] == 5 && s.ratings["ИНЖГРАФ"] == 5 &&
			s.ratings["ТОЭ"] == 5 && s.ratings["Политология"] == 5;
	});
	cout << " студентов сдали все экзамены на 5" << endl;
}
void Print(const vector<Student> &s)
{
	for (auto el : s)
	{
		cout << el.Name << " | " << el.GroupId << " | " << "Math: " << el.ratings["Math"] << " ИНЖГРАФ: " << el.ratings["ИНЖГРАФ"]
			<< " ТОЭ: " << el.ratings["ТОЭ"] << " Политология: " << el.ratings["Политология"] << endl;
	}
}
