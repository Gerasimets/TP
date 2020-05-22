#include "Parallelepiped.h"
#include <iostream>
#include <string>
#include "Figure.h"

using namespace std;

Parallelepiped::Parallelepiped()
{
	way = "Parallelepiped.txt";
}

Parallelepiped::Parallelepiped(string path)
{
	way = path;
}

Parallelepiped::Parallelepiped(const Parallelepiped& Paralllepiped_tmp)
{
	height = Paralllepiped_tmp.height; // высота
	length = Paralllepiped_tmp.length; // длина
	width = Paralllepiped_tmp.width; // ширина
	result = Paralllepiped_tmp.result; // площадь
	way = Paralllepiped_tmp.way;
}

Parallelepiped::~Parallelepiped()
{

}

float Parallelepiped::space()
{
	result = 2 * (length * width + width * height + length * height);
	return result;
}

void Parallelepiped::enter()
{
	cout << "Введите данные" << endl;
	cout << "Высота:";
	cin >> this->height;
	cout << "Длина:";
	cin >> this->length;
	cout << "Ширина:";
	cin >> this->width;
}

void Parallelepiped::extention(Figure*& P, int& p, int v)
{
	Figure* obj_tmp = new Parallelepiped[p]; // выделяем память во временном массиве объектов

	for (int j = 0; j < p; j++) // перезаписываем ориганальный массив во временный
	{
		obj_tmp[j] = P[j];
	}

	P = new Parallelepiped[++p]; // увеличиваем память в оригинальном массиве

	for (int j = 0; j < p - 1; j++) // перезаписываем временный в оригинальный
	{
		P[j] = obj_tmp[j];
	}
	delete[] obj_tmp; // очищаем временный
}
