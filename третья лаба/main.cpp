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
	int b = 0; // количество шаров
	Ball obb;

	Figure* P = 0; // массив параллелепипедов
	int p = 0; // количество параллелепипедов
	Parallelepiped obp;

	Figure* T = 0; // массив тетраэдров
	int t = 0; // количество тетраэдров
	Tetrahedron obt;

	int action = 1; // флаг для меню

	while (action)
	{
		system("cls");
		cout << "Меню" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - Вычислить площадь поверхности шара" << endl;
		cout << "2 - Вычислить площадь поверхности параллелепипеда" << endl;
		cout << "3 - Вычислить площадь поверхности тетраэда" << endl;
		cout << "4 - Вывод всех фигур из программы" << endl;
		cout << "5 - Добавление всех фигур из файла в программу и вывод на экран" << endl;

		cin >> action;

		switch (action)
		{
		case 0:
			break;

		case 1:
			(obb).extent_uk(mass, k); // увеличиваем массив указателей
			k++;
			(obb).extention(B, b); // увеличиваем массив объектов
			B[b - 1].enter(); // вводим новые данные
			cout << B[b - 1].space() << endl; // выводим площадь последнего
			mass[k - 1] = &B[b - 1]; // кладем адрес объекта в массив указателей
			B[b - 1].write(); // записываем в файл последний объект
			system("pause");
			break;

		case 2:
			(obp).extent_uk(mass, k);
			k++;
			(obp).extention(P, p);
			P[p - 1].enter();
			cout << P[p - 1].space() << endl; // выщитываем и выводим площадь последнего
			mass[k - 1] = &P[p - 1]; // кладем адрес оюъекта в массив указателей
			P[p - 1].write(); // записываем в файл последний объект
			system("pause");
			break;

		case 3:
			(obt).extent_uk(mass, k);
			k++;
			(obt).extention(T, t);
			T[t - 1].enter();
			cout << T[t - 1].space() << endl; // выводим площадь последнего
			mass[k - 1] = &T[t - 1]; // кладем адрес объекта в массив указателей
			T[t - 1].write(); // записываем в файл последний объект
			system("pause");
			break;

		case 4:
			if (k == 0)
			{
				cout << "в программе нет ни одной фигуры" << endl;
			}

			for (int i = 0; i < k; i++)
			{
				(*mass[i]).show();
			}
			system("pause");
			break;

		case 5:
			k = 0;
			b = 0;
			t = 0;
			p = 0;
			delete[] mass;
			delete[] B;
			delete[] T;
			delete[] P;

			B = &(obb).read(mass, k, b); // берем адрес первого объекта из массива
			T = &(obt).read(mass, k, t);
			P = &(obp).read(mass, k, p);
			system("pause");
			break;

		default:
			cout << "некорректный ввод" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
