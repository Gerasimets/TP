#include "Figure.h"
#include <iostream>
#include <fstream>
#include "Ball.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"

using namespace std;

Figure::~Figure()
{

}

void Figure::write()
{
	ofstream fout(way, ios_base::app); // почитать
	if (!fout.is_open())
	{
		cout << "Файл не может быть открыт!" << endl;
	}
	else
	{
		fout << this->result; // выводим в файл результат
		if (this->radius >= 0) // если это шар
		{
			fout << " " << this->radius << endl;
		}
		else if (this->rib >= 0) // если это тетраэдр
		{
			fout << " " << this->rib << endl;
		}
		else if (this->width >= 0) // если это паралеллепипед
		{
			fout << " " << this->width;
			fout << " " << this->length;
			fout << " " << this->height << endl;
		}
		fout.close();
	}
}

void Figure::show()
{
	if (this->radius >= 0)
	{
		cout <<"Площадь шара: " <<this->result;
		cout << ", радиус шара: " <<this->radius << endl;
	}
	else if (this->rib >= 0)
	{
		cout << "Площадь тетраэдра: " << this->result;
		cout << ", ребро тетраэдра: " << this->rib << endl;
	}
	else if (this->width >= 0)
	{
		cout << "Площадь параллелепипеда: " << this->result;
		cout << ", ширина параллелепипеда: " << this->width;
		cout << ", длина параллелепипед: " << this->length;
		cout << ", высота параллелепипеда: " << this->height << endl;
	}
}

Figure& Figure::read(Figure** &massU, int &kp, int &np)
{
	Figure* mass_fig = 0; // временный массив фигур
	ifstream fin(way); // открыли файл для чтения
	if (!fin.is_open())
	{
		cout << "Файл не может быть открыт!" << endl;
	}
	else
	{
		string file; // переменная хранящая последнее слово файла
		int cnt = 0;

		while (!fin.eof()) // считаем количество слов в файле
		{
			fin >> file;
			cnt++;
		}
		fin.close(); // закрываем файл
		ifstream fin(way); // открыли файл для чтения

		if (way == "ball.txt") // если это шар
		{
			int size;
			if (--cnt % 2 != 0) // в каждой строке площадь и радиус
			{
				cout << "ошибка" << endl;
			}
			else
			{
				size = cnt / 2; // строк в файле в 2 раза меньше чем слов
				mass_fig = new Ball[size]; // выделяем память под шары

				Figure** mass_tmp = new Figure* [kp]; // выделяем память во временном массиве указателей

				for (int j = 0; j < (kp); j++) // перезаписываем данные из оригинального массива
				{
					mass_tmp[j] = massU[j];
				}

				massU = new Figure* [kp+size]; // увеличиваем размер оригинального массива

				for (int j = 0; j < kp; j++) // перезаписываем временный в ориинальный
				{
					massU[j] = mass_tmp[j];
				}

				delete[] mass_tmp; // временный очищаем

				for (np = 0; np != size; np++, kp++) // выводим все данные из файла в программу и на экран
				{
					fin >> mass_fig[np].result;
					fin >> mass_fig[np].radius;

					cout << "Площадь шара: " << mass_fig[np].result;
					cout << ", радиус шара: " << mass_fig[np].radius << endl;

					massU[kp] = &mass_fig[np]; // в массив указателей кладем аддрес текущего объекта
				}
			}
		}
		else if (way == "Tetrahedron.txt")
		{
			int size;
			if (--cnt % 2 != 0)
			{
				cout << "ошибка" << endl;
			}
			else
			{
				size = cnt / 2;
				mass_fig = new Tetrahedron[size];

				Figure** mass_tmp = new Figure * [kp]; // выделяем память во временном массиве указателей

				for (int j = 0; j < (kp); j++) // перезаписываем данные из оригинального массива
				{
					mass_tmp[j] = massU[j];
				}

				massU = new Figure * [kp + size]; // увеличиваем размер оригинального массива

				for (int j = 0; j < (kp); j++) // перезаписываем временный в ориинальный
				{
					massU[j] = mass_tmp[j];
				}

				delete[] mass_tmp; // временный очищаем

				for (np = 0; (np) != size; (np)++, (kp)++)
				{
					fin >> mass_fig[np].result;
					fin >> mass_fig[np].rib;

					cout << "Площадь тетраэдра: " << mass_fig[np].result;
					cout << ", ребро тетраэдра: " << mass_fig[np].rib << endl;

					massU[(kp)] = &mass_fig[(np)];
				}
			}
		}
		else if (way == "Parallelepiped.txt")
		{
			int size;
			if (--cnt % 4 != 0)
			{
				cout << "ошибка" << endl;
			}
			else
			{
				size = cnt / 4;
				mass_fig = new Parallelepiped[size];

				Figure** mass_tmp = new Figure * [kp]; // выделяем память во временном массиве указателей

				for (int j = 0; j < (kp); j++) // перезаписываем данные из оригинального массива
				{
					mass_tmp[j] = massU[j];
				}

				massU = new Figure * [kp + size]; // увеличиваем размер оригинального массива

				for (int j = 0; j < (kp); j++) // перезаписываем временный в ориинальный
				{
					massU[j] = mass_tmp[j];
				}

				delete[] mass_tmp; // временный очищаем

				for (np = 0; (np) != size; np++, kp++)
				{
					fin >> mass_fig[np].result;
					fin >> mass_fig[np].width;
					fin >> mass_fig[np].length;
					fin >> mass_fig[np].height;


					cout << "Площадь параллелепипеда: " << mass_fig[np].result;
					cout << ", ширина параллелепипеда: " << mass_fig[np].width;
					cout << ", длина параллелепипед: " << mass_fig[np].length;
					cout << ", высота параллелепипеда: " << mass_fig[np].height << endl;

					massU[(kp)] = &mass_fig[(np)];
				}
			}
		}

		fin.close(); // закрываем файл
	}
	return *mass_fig; // возвращаем первый объект массива объектов
}
