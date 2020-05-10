#include <iostream>
#include "Date.h"

using namespace std;

Data::Data() // конструктор
{

}

Data::Data(int D, int M, int Y) // конструктор с параметром
{
	this->day = D;
	this->month = M;
	this->year = Y;
}

Data::~Data()//деструктор
{
	
}

void Data::out() // вывод на экран
{
	cout << "День: " << day << endl;
	cout << "Месяц: " << month << endl;
	cout << "Год: " << year << endl;
}

Data::Data(const Data& tmp_data_2) //конструктор копирования, const для того, чтобы случайно никто никак не изменил копируемое
{
	this->day = tmp_data_2.day; //
	this->month = tmp_data_2.month;
	this->year = tmp_data_2.year;
}

Data& Data::operator = (const Data& tmp_data) //
{
	this->day = tmp_data.day;
	this->month = tmp_data.month;
	this->year = tmp_data.year;
	return *this;
}


Data operator ++ (Data& tmp_data_2, int) // ++(постфиксная форма, дружественная функция) увеличивает на выбор пользователя либо дату, либо месяц, либо год на пользовательское число.
{
	Data copy_data_2(tmp_data_2); // создаем копию data_2

	int action = 0; //для меню
	int value; //значение, на которе изменяем

	cout << "Введите число, на которое хотите увеличить: ";
	cin >> value;

	cout << "Выберете, что будет увеличено:" << endl;
	cout << "|0| - День" << endl;
	cout << "|1| - Месяц" << endl;
	cout << "|2| - Год" << endl;
	cin >> action;

	switch (action)
	{
	case 0:
		tmp_data_2.day =+ value; //увеличиваем на пользовательское число data_2
		break;

	case 1:
		tmp_data_2.month =+ value;
		break;

	case 2:
		tmp_data_2.year =+ value;
		break;

	default:
		cout << "некорректный ввод\n";
		break;
	}
	return copy_data_2;
}

Data operator -- (Data& tmp_data, int) // --(постфиксная форма, дружественная функция) уменьшает на выбор пользователя либо дату, либо месяц, либо год на пользовательское число.
{
	Data tmp_Dat(tmp_data);
	int option = 0;
	int value;

	cout << "Введите число, на которое хотите уменьшить: ";
	cin >> value;

	cout << "Выберете, что будет уменьшено:" << endl;
	cout << "|0| - День" << endl;
	cout << "|1| - Месяц" << endl;
	cout << "|2| - Год" << endl;
	cin >> option;

	switch (option)
	{
	case 0:
		tmp_data.day =- value;
		break;

	case 1:
		tmp_data.month =- value;
		break;

	case 3:
		tmp_data.year =- value;
		break;

	default:
		cout << "некорректный ввод\n";
		break;
	}
	return tmp_Dat;
}

Data Data::operator ++ () // ++(префиксная форма, метод) увеличивает на выбор пользователя либо дату, либо месяц, либо год на 1
{
	int option = 0;
	cout << "Выберете, что будет увеличено на 1:" << endl;
	cout << "|0| - День" << endl;
	cout << "|1| - Месяц" << endl;
	cout << "|2| - Год" << endl;
	cin >> option;

	switch (option)
	{
	case 0:
		this->day += 1;
		break;

	case 1:
		this->month += 1;
		break;

	case 3:
		this->year += 1;
		break;

	default:
		cout << "некорректный ввод\n";
		break;
	}
	return *this; //возвращаем сам объект
}

Data Data::operator -- () // --(префиксная форма, метод) уменьшает на выбор пользователя либо дату, либо месяц, либо год на 1
{
	int option = 0;
	cout << "Выберете, что будет уменьшено на 1:" << endl;
	cout << "|0| - День" << endl;
	cout << "|1| - Месяц" << endl;
	cout << "|2| - Год" << endl;
	cin >> option;

	switch (option)
	{
	case 0:
		this->day -= 1;
		break;

	case 1:
		this->month -= 1;
		break;

	case 3:
		this->year -= 1;
		break;

	default:
		cout << "некорректный ввод\n";
		break;
	}
	return *this;
}
