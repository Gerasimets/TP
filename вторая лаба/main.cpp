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

	cout << "Введите: " << endl;

	// параметры
	int x = 0;
	int y = 0;
	int z = 0;

	cout << "День: ";
	cin >> x;
	cout << "Месяц: ";
	cin >> y;
	cout << "Год: ";
	cin >> z;

	Data date_1(x, y, z); // создаем новый объект используя конструктор с параметрами
	Data date_2(date_1); // создаем новый объект используя конструктор копирования
	//Data data_ex = 5; //невозможно, так как мы запретили неявное преобразование типа этого аргумента в тип класса

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
			show(date_1, date_2);
			//system("pause");
			break;

		case 2:
			date_1 = --date_2;
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
		}
	}

	system("cls");

	action = 1;

	queue queue_1;
	queue queue_2/*(0)*/;

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
		cout << "|11| - Вывод очереди №1 на экран" << endl;
		cout << "|12| - Вывод очереди №2 на экран" << endl;
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
			cout << "Элемент " << number << " добавлен" << endl;
			cout << "Очередь №1 состоит из: " << endl;
			queue_1.out();
			break;
		case 2:
			cout << "Введите элемент: ";
			cin >> number;
			queue_2 + number;
			cout << "Элемент " << number << " добавлен" << endl;
			cout << "Очередь №2 состоит из: " << endl;
			queue_2.out();
			break;
		case 3:
			if (!queue_1.empty()) break;
			value_del =- queue_1;
			cout << "Удалённый элемент из очереди №1: " << value_del << endl;
			cout << "Очередь №1 состоит из: " << endl;
			queue_1.out();
			break;
		case 4:
			if (!queue_2.empty()) break;
			value_del =- queue_2;
			cout << "Удалённый элемент из очереди №2: " << value_del << endl;
			cout << "Очередь №2 состоит из: " << endl;
			queue_2.out(); //вывод очереди получившейся
			break;
		case 5:
			if (!queue_1.empty()) break;
			cout << "Введите элемент: ";
			cin >> number;
			queue_1 * number;
			cout << "Очередь №1 состоит из: " << endl;
			queue_1.out(); //вывод очереди получившейся
			break;
		case 6:
			if (!queue_2.empty()) break;
			cout << "Введите элемент: ";
			cin >> number;
			queue_2 * number;
			cout << "Очередь №2 состоит из: " << endl;
			queue_2.out(); //вывод очереди получившейся
			break;
		case 7:
			if (!queue_2.empty()) break;
			queue_1 = queue_2;
			cout << "Очередь №1 состоит из: " << endl;
			queue_1.out(); //вывод очереди получившейся
			break;
		case 8:
			if (!queue_1.empty()) break;
			queue_2 = queue_1;
			cout << "Очередь №2 состоит из: " << endl;
			queue_2.out(); //вывод очереди получившейся
			break;
		case 9:
			if (!queue_1.empty()) break;
			if (!queue_2.empty()) break;
 			queue_1 == queue_2;
			break;
		case 10:
			if (!queue_1.empty()) break;
			if (!queue_2.empty()) break;
 			queue_1 != queue_2;
			break;
		case 11:
			if (!queue_1.empty()) break;
			cout << "Очередь №1: ";
			queue_1.out();
			break;
		case 12:
			if (!queue_2.empty()) break;
			cout << "Очередь №2: ";
			queue_2.out();
			break;
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
	dat_1.out();

	cout << "Дата 2:" << endl;
	dat_2.out();
}
