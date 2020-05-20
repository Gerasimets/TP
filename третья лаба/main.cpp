#include <iostream>
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include "Figure.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	//Ball b;
	//Parallelepiped p;
	//Tetrahedron t;

	Ball *B = 0;
	Parallelepiped *P;
	Tetrahedron *T;

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
		cin >> action;

		switch (action)
		{
		case 0:
			break;
		case 1:
			



			mass = new Figure*[++k];
			B = new Ball[++b];
			cout << "Введите данные" << endl;
			cout << "Радиус:";
			cin >> B[b-1].radius;
			cout << B[b].space() << endl;
			B[b].write(mass[k-1]);

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
