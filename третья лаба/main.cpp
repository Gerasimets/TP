#include <iostream>
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include "Figure.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Figure** mass = 0; // массив указателей
	Figure** mass_tmp = 0; //временный массив

	Ball* B = 0;
	Ball* B_tmp = 0;


	Parallelepiped* P = 0;
	Parallelepiped* P_tmp = 0;

	Tetrahedron* T = 0;
	Tetrahedron* T_tmp = 0;

	int action = 1;

	//int i = 0;

	int k = 0;

	int b = 0; //
	int p = 0; //
	int t = 0; //

	while (action)
	{
		cout << "Меню" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "1 - Вычислить площадь поверхности шара" << endl;
		cout << "2 - Вычислить площадь поверхности параллелепипеда" << endl;
		cout << "3 - Вычислить площадь поверхности тетраэда" << endl;
		cout << "4 - Вывод результатов для шара" << endl;
		cout << "5 - Вывод результатов для параллелепипеда" << endl;
		cout << "6 - Вывод результатов для тетраэда" << endl;
		cout << "7 - Ввод и чтение из файла" << endl;

		cin >> action;

		switch (action)
		{
		case 0:
			break;
		case 1:
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
			mass[k - 1] = &B[b - 1]; // кладем адрес оюъекта в массив указателей
			B[b - 1].write(); // записываем в файл последний объект
			//увеличение массива
			//mass[i++]= b.space;
			break;
			case 2:
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
				cout << P[p - 1].space() << endl; // выводим площадь последнего
				mass[k - 1] = &P[p - 1]; // кладем адрес оюъекта в массив указателей
				P[p - 1].write(); // записываем в файл последний объект
				//p.write(p.space);
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
				mass[k - 1] = &T[t - 1]; // кладем адрес оюъекта в массив указателей
				T[t - 1].write(); // записываем в файл последний объект
				//t.write(t.space);
				break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			cout << "некорректный ввод\n";
			break;
		}
	}
}
