// 19.09.2018.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

int buf_size = 0, cur_size = 0;

struct date
{
	int day, month, year;
	void enter_date()
	{
		char c;
		cin >> day >> c >> month >> c >> year;
	}
	bool cmp_date(date d)
	{
		return (d.day == day && d.month == month && d.year == year);
	}

	bool operator>(date d)
	{
		if (year > d.year) return true;
		else if (year == d.year)
		{
			if (month > d.month) return true;
			else if (month == d.month)
			{
				if (day > d.day) return true;
				else if (day == d.day) return false;
			}
		}

		return false;
	}
	bool operator==(date d)
	{
		return (d.day == day && d.month == month && d.year == year);
	}

	void print()
	{
		cout << day << '.' << month << '.' << year;
	}

};
struct student
{
	string fname;
	int group;
	date entering_date;
	void enter_student()
	{
		cin >> fname >> group;
		entering_date.enter_date();
	}

	void print()
	{
		cout << fname << " " << group << " ";
		entering_date.print();
		cout << endl;
	}
};

struct abonent
{
	string name;
	string number;

	void enter()
	{
		cin >> name >> number;
	}
	void print()
	{
		cout << name << " " << number << endl;
	}
};

void add(abonent* &book, abonent a)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		book = new abonent[buf_size];
		book[cur_size++] = a;
	}
	else
	{
		if (buf_size > cur_size)
		{
			book[cur_size++] = a;
		}
		else
		{
			abonent* tmp;
			tmp = new abonent[buf_size * 2];
			for (int i = 0; i < buf_size; i++)
			{
				tmp[i] = book[i];
			}
			delete[] book;
			book = tmp;
			buf_size *= 2;
			book[cur_size++] = a;
		}
	}

}

void sort_book(abonent* book)
{
	int n = cur_size;
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n-1; i++)
		{
			if (book[i].name > book[i + 1].name)
				swap(book[i], book[i + 1]);
		}
	}
}

void erase(abonent* book)
{
	int choice;
	int index;
	string poisk;
	cout << "Enter 1 to delete by name, 2 - to delete by number" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: 
	{
		cin >> poisk;
		for (int i = 0; i < cur_size; i++)
			if (strstr(book[i].name.c_str(), poisk.c_str()))
			{
				index = i;
				break;
			}
	}
		break;
	case 2:
	{
		cin >> poisk;
		for (int i = 0; i < cur_size; i++)
			if (strstr(book[i].name.c_str(), poisk.c_str()))
			{
				index = i;
				break;
			}
	}
	break;
	
	}
	
	for (int i = 0; i < cur_size-1; i++)
	{
		book[i] = book[i + 1];
	}
	cur_size--;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	abonent* book;
	abonent a;
	int choice;
	a.name="Zhanar";
	a.number = "123456";
	add(book, a);
	
	
	
	/*while (true)
	{
		int n;
		cout << "1 - для добавления номера" << endl;
		cout << "2 - для сортировки" << endl;
		cout << "3 - для удаления" << endl;
		cout << "0 - для выхода" << endl;
		cin >> n;
		switch (n)
		{
		case 1: 
			cout << "Введите данные:" << endl;
			a.enter();
			add(book, a);
			
			for (int i = 0; i < cur_size; i++)
			{
				book[i].print();
			}

			break;
		case 2:
			sort_book(book);
			for (int i = 0; i < cur_size; i++)
			{
				book[i].print();
			}
			break;
		case 3:
			erase(book);
			cout << "Phone number after erase" << endl;
			for (int i = 0; i < cur_size; i++)
			{
				book[i].print();
			}
			break;
		case 4: break;
			break;
		default:
			break;
		}
	}*/
	while (true)
	{
		
		cout << "Enter 0 to break input else enter any number" << endl;
		cin >> choice;
		if (choice == 0) break;		
			a.enter();
			add(book, a);		
	}

	sort_book(book);
	for (int i = 0; i < cur_size; i++)
	{
		book[i].print();
	}
	
	erase(book);
	cout << "Phone number after erase" << endl;
	for (int i = 0; i < cur_size; i++)
	{
		book[i].print();
	}
	////заполнение
	//for (int i = 0; i < n; i++)
	//{
	//	p[i].enter();
	//}


	////распечатка
	//for (int i = 0; i < n; i++)
	//{
	//	p[i].print();
	//}
	//delete[] p;


	/*int n;
	date d;
	student* s;
	cin >> n;
	s = new student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i + 1 << " the student " << endl;
		s[i].enter_student();
	}
	cout << "Enter date to compare with: " << endl;
	d.enter_date();
	for (int i = 0; i < n; i++)
	{
		if (s[i].entering_date > d)
			s[i].print();
	}
	delete[] s;*/

	/*date d1, d2;
	d1.enter_date();
	d2.enter_date();*/

	//if (d1.operator==(d2)) cout << "Equal" << endl;
	/*if (d1 > d2) cout << "True" << endl;
	else cout << "False" << endl;
*/
	system("pause");
	return 0;
}

