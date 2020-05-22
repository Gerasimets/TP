#include "Tetrahedron.h"
#include <iostream>
#include "cmath"
#include "Figure.h"
#include <string>

using namespace std;

Tetrahedron::Tetrahedron()
{
	way = "Tetrahedron.txt";
}

Tetrahedron::Tetrahedron(string path) //с параметром
{
	way = path;
}

Tetrahedron::Tetrahedron(const Tetrahedron& Tetrahedron_tmp) //копирования
{
	rib = Tetrahedron_tmp.rib;
	result = Tetrahedron_tmp.result;
	way =Tetrahedron_tmp.way;
}

Tetrahedron::~Tetrahedron()
{

}

float Tetrahedron::space()
{
	result = rib * rib * sqrt(3.0);
	return result;
}

void Tetrahedron::enter()
{
	cout << "Введите данные" << endl;
	cout << "Ребро:";
	cin >> this->rib;
}

void Tetrahedron::extention(Figure*& T, int& t, int v)
{
	Figure* obj_tmp = new Tetrahedron[t]; // выделяем память во временном массиве объектов

	for (int j = 0; j < t; j++) // перезаписываем ориганальный массив во временный
	{
		obj_tmp[j] = T[j];
	}

	T = new Tetrahedron[++t]; // увеличиваем память в оригинальном массиве

	for (int j = 0; j < t - 1; j++) // перезаписываем временный в оригинальный
	{
		T[j] = obj_tmp[j];
	}
	delete[] obj_tmp; // очищаем временный
}
