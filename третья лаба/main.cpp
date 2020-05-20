#include <iostream>
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include "Figure.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Figure **mass_tmp = 0;

	Ball* B = 0;
	Ball* Bt = 0;



	Parallelepiped* P;
	Tetrahedron* T;

	Figure **mass = 0; // массив указателей

	int action = 1;

	//int i = 0;

	int k = 0;
	int b = 0;

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
			mass_tmp = new Figure* [k]; // выделяем память во временном массиве указателей

			for (int j = 0; j < k; j++) // перезаписываем данные из оригинального массива
			{
				mass_tmp[j] = mass[j];
			}

			mass = new Figure *[++k]; // увеличиваем размер оригинального массива

			for (int j = 0; j < k-1; j++) // перезаписываем временный в ориинальный
			{
				mass[j] = mass_tmp[j];
			}

			delete[] mass_tmp; // временный очищаем


			Bt = new Ball[b]; // выделяем память во временном массиве объектов
			
			for (int j = 0; j < b; j++) // перезаписываем ориганальный массив во временный
			{
				Bt[j] = B[j];
			}

			B = new Ball[++b]; // увеличиваем память в оригинальном массиве

			for (int j = 0; j < b-1; j++) // перезаписываем временный в оригинальный
			{
				B[j] = Bt[j];
			}
			delete[] Bt; // очищаем временный

			cout << "Введите данные" << endl;
			cout << "Радиус:";
			cin >> B[b - 1].radius; // считываем радиус нового объекта
			cout << B[b-1].space() << endl; // выводим площадь последнего
			mass[k - 1] = &B[b - 1]; // кладем адрес оюъекта в массив указателей
			B[b-1].write(); // записываем в файл последний объект

			//увеличение массива

			//mass[i++]= b.space;
			break;
			//case 2:
			//	cout << "Введите данные" << endl;
			//	cout << "Высота:";
			//	cin >> p.height;
			//	cout << "Длина:";
			//	cin >> p.length;
			//	cout << "Ширина:";
			//	cin >> p.width;
			//	//p.write(p.space);
			//	break;
			//case 3:
			//	cout << "Введите данные" << endl;
			//	cout << "Ребро:";
			//	cin >> t.rib;
			//	//t.write(t.space);
			//	break;
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
