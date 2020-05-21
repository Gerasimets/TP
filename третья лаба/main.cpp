#include <iostream>
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include "Figure.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus"); // для вывода русского языка

	Figure** mass = nullptr; // массив указателей на фигуры
	Figure** mass_tmp = nullptr; // временный массив указателей на фигуры
	int k = 0; // количество всех фигур

	Figure* B = 0; // массив шаров
	Figure* B_tmp = 0; // временный массив шаров
	int b = 0; // количество шаров
	Ball obb;

	Figure* P = 0; // массив параллелепипедов
	Figure* P_tmp = 0; // временный массив параллелепипедов
	int p = 0; // количество параллелепипедов
	Parallelepiped obp;

	Figure* T = 0; // массив тетраэдров
	Figure* T_tmp = 0; // временный массив тетраэдров
	int t = 0; // количество тетраэдров
	Tetrahedron obt;

	int action = 1; // флаг для меню

	while (action)
	{
		cout << "Меню" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - Вычислить площадь поверхности шара" << endl;
		cout << "2 - Вычислить площадь поверхности параллелепипеда" << endl;
		cout << "3 - Вычислить площадь поверхности тетраэда" << endl;
		cout << "4 - Вывод всех фигур" << endl;
		cout << "5 - Добавление всех фигур из файла в программу" << endl;

		cin >> action;

		switch (action)
		{
		case 0:
			break;

		case 1:
			mass_tmp = new Figure* [k]; // выделяем память во временном массиве указателей

			for (int j = 0; j < k; j++) // перезаписываем данные из оригинального массива
			{
				mass_tmp[j] = mass[j];
			}

			mass = new Figure * [++k]; // увеличиваем размер оригинального массива

			for (int j = 0; j < k - 1; j++) // перезаписываем временный в ориинальный
			{
				mass[j] = mass_tmp[j];
			}

			delete[] mass_tmp; // временный очищаем

			B_tmp = new Ball[b]; // выделяем память во временном массиве объектов

			for (int j = 0; j < b; j++) // перезаписываем ориганальный массив во временный
			{
				B_tmp[j] = B[j];
			}

			B = new Ball[++b]; // увеличиваем память в оригинальном массиве

			for (int j = 0; j < b - 1; j++) // перезаписываем временный в оригинальный
			{
				B[j] = B_tmp[j];
			}
			delete[] B_tmp; // очищаем временный

			cout << "Введите данные" << endl;
			cout << "Радиус:";
			cin >> B[b - 1].radius; // считываем радиус нового объекта
			cout << B[b - 1].space() << endl; // выводим площадь последнего
			mass[k - 1] = &B[b - 1]; // кладем адрес объекта в массив указателей
			B[b - 1].write(); // записываем в файл последний объект
			break;

		case 2:
			mass_tmp = new Figure *[k]; // выделяем память во временном массиве указателей

			for (int j = 0; j < k; j++) // перезаписываем данные из оригинального массива
			{
				mass_tmp[j] = mass[j];
			}

			mass = new Figure* [++k]; // увеличиваем размер оригинального массива

			for (int j = 0; j < k - 1; j++) // перезаписываем временный в ориинальный
			{
				mass[j] = mass_tmp[j];
			}
			delete[] mass_tmp; // временный очищаем

			P_tmp = new Parallelepiped[p]; // выделяем память во временном массиве объектов

			for (int j = 0; j < p; j++) // перезаписываем ориганальный массив во временный
			{
				P_tmp[j] = P[j];
			}

			P = new Parallelepiped[++p]; // увеличиваем память в оригинальном массиве

			for (int j = 0; j < p - 1; j++) // перезаписываем временный в оригинальный
			{
				P[j] = P_tmp[j];
			}
			delete[] P_tmp; // очищаем временный

			cout << "Введите данные" << endl;
			cout << "Высота:";
			cin >> P[p - 1].height;
			cout << "Длина:";
			cin >> P[p - 1].length;
			cout << "Ширина:";
			cin >> P[p - 1].width;
			cout << P[p - 1].space() << endl; // выщитываем и выводим площадь последнего
			mass[k - 1] = &P[p - 1]; // кладем адрес оюъекта в массив указателей
			P[p - 1].write(); // записываем в файл последний объект
			break;

		case 3:
			mass_tmp = new Figure * [k]; // выделяем память во временном массиве указателей

			for (int j = 0; j < k; j++) // перезаписываем данные из оригинального массива
			{
				mass_tmp[j] = mass[j];
			}

			mass = new Figure * [++k]; // увеличиваем размер оригинального массива

			for (int j = 0; j < k - 1; j++) // перезаписываем временный в ориинальный
			{
				mass[j] = mass_tmp[j];
			}

			delete[] mass_tmp; // временный очищаем

			T_tmp = new Tetrahedron[t]; // выделяем память во временном массиве объектов

			for (int j = 0; j < t; j++) // перезаписываем ориганальный массив во временный
			{
				T_tmp[j] = T[j];
			}

			T = new Tetrahedron[++t]; // увеличиваем память в оригинальном массиве

			for (int j = 0; j < t - 1; j++) // перезаписываем временный в оригинальный
			{
				T[j] = T_tmp[j];
			}
			delete[] T_tmp; // очищаем временный

			cout << "Введите данные" << endl;
			cout << "Ребро:";
			cin >> T[t - 1].rib;
			cout << T[t - 1].space() << endl; // выводим площадь последнего
			mass[k - 1] = &T[t - 1]; // кладем адрес объекта в массив указателей
			T[t - 1].write(); // записываем в файл последний объект
			break;

		case 4:
			for (int i = 0; i < k; i++)
			{
				(*mass[i]).show();
			}
			break;

		case 5:
			k = 0;
			b = 0;
			t = 0;
			p = 0;
			delete[] mass; // 
			delete[] B;
			delete[] T;
			delete[] P;

			B = &(obb).read(mass, k, b); // берем адрес первого объекта из массива
			T = &(obt).read(mass, k, t);
			P = &(obp).read(mass, k, p);
			break;

		default:
			cout << "некорректный ввод\n";
			break;
		}
	}
	return 0;
}
