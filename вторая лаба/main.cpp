#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Date.h"
#include "Queue.h"

using namespace std;

void show (Data& dat_1, Data& dat_2);

int main()
{
	setlocale(LC_ALL, "Rus");

	// параметры
	int x = 0;
	int y = 0;
	int z = 0;



	Data date_1(x, y, z); // создаем новый объект используя конструктор с параметрами
	Data date_2(date_1); // создаем новый объект используя конструктор копирования

	int action = 1;

	while (action)
	{

		cout << "Задание 1 - унарные операции" << endl;
		cout << "|0| - Переход к бинарным операциям" << endl;
		cout << "|1| - Увеличение на выбор пользователя либо дату, либо месяц, либо год на 1" << endl;
		cout << "|2| - Уменьшение на выбор пользователя либо дату, либо месяц, либо год на 1" << endl;
		cout << "|3| - Увеличение на выбор пользователя либо дату, либо месяц, либо год на пользовательское число" << endl;
		cout << "|4| - Уменьшение на выбор пользователя либо дату, либо месяц, либо год на пользовательское число" << endl;
		cin >> action;

		switch (action)
		{
		case 0:
			break;

		case 1:
			date_1 = ++date_2;
			//cout << "Данные после увеличения на 1: " << endl;
			show(date_1, date_2);
			//system("pause");
			break;

		case 2:
			date_1 = --date_2;
			//cout << "Данные после уменьшения на 1: " << endl;
			show(date_1, date_2);
			break;

		case 3:
			date_1 = date_2++;
			//cout << "Данные после увеличения на пользовательское число: " << endl;
			show(date_1, date_2);
			break;

		case 4:
			date_1 = date_2--;
			//cout << "Данные после уменьшения на пользовательское число: " << endl;
			show(date_1, date_2);
			break;

		default:
			cout << "некорректный ввод\n";
			break;
			///////////////////////////
		}
	}

	system("cls");

	action = 1;

	queue queue_1;
	queue queue_2;

	int number = 0;
	int value_del;

	while (action)
	{
		cout << "Задание 2 - бинарные операции" << endl;
		cout << "|0|  - Выход" << endl;
		cout << "|1| - Добавление элемента в очередь №1" << endl;
		cout << "|2| - Добавление элемента в очередь №2" << endl;
		cout << "|3| - Извлечение элемента из очереди №1" << endl;
		cout << "|4| - Извлечение элемента из очереди №2" << endl;
		cout << "|5| - Умножить элементы очереди №1 на число" << endl;
		cout << "|6| - Умножить элементы очереди №2 на число" << endl;
		cout << "|7| - Очередь №1 = очередь №2" << endl;
		cout << "|8| - Очередь №2 = очередь №1" << endl;
		cout << "|9| - ==" << endl;
		cout << "|10| - !=" << endl;
		//вводить и выводить в поток
		cin >> action;

		switch (action)
		{
		case 0:
			break;
		case 1: 
			cout << "Введите элемент: ";
			cin >> number;
			queue_1 + number;
			break;
		case 2:
			cout << "Введите элемент: ";
			cin >> number;
			queue_2 + number;
			break;
		case 3:
			if (!queue_1.empty()) break;
			value_del =- queue_1;
			cout << "Удалённый элемент из очереди №1: " << value_del << endl;
			break;
		case 4:
			if (!queue_2.empty()) break;
			value_del =- queue_2;
			cout << "Удалённый элемент из очереди №1: " << value_del << endl;
			break;
		case 5:
			if (!queue_1.empty()) break;
			cout << "Введите элемент: ";
			cin >> number;
			queue_1 * number;
			//вывод очереди получившейся
			break;
		case 6:
			if (!queue_2.empty()) break;
			cout << "Введите элемент: ";
			cin >> number;
			queue_2 * number;
			//вывод очереди получившейся
			break;
		case 7:
			if (!queue_2.empty()) break;
			queue_1 = queue_2;
			//вывод 
			break;
		case 8:
			if (!queue_1.empty()) break;
			queue_2 = queue_1;
			//вывод 
			break;
		/*case 9:
			if (!queue_1.empty()) break;
			queue_1 == queue_2;
			break;*/
		/*case 10:
			!=
			break;*/
		default:
			cout << "некорректный ввод\n";
			break;
		}
	}
	return 0;
}



void show(Data& dat_1, Data& dat_2)
{
	cout << "Дата 1:" << endl;
	//cout << "Очередь 1" << endl;
	dat_1.out();

	cout << "Дата 2:" << endl;
	//cout << "Очередь 2" << endl;
	dat_2.out();
}
