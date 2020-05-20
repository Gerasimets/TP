#include "Parallelepiped.h"
#include <iostream>
#include <string>
#include "Figure.h"

using namespace std;

Parallelepiped::Parallelepiped()
{
	way = "Parallelepiped.txt";
}

Parallelepiped::~Parallelepiped()
{

}

void Parallelepiped::enter()
{
	cout << "Введите данные" << endl;
	cout << "Высота:";
	cin >> height;
	cout << "Длина:";
	cin >> length;
	cout << "Ширина:";
	cin >> width;
}

float Parallelepiped::space()
{
	result = 2 * (length * width + width * height + length * height);
	return result;
}

void Parallelepiped::read()
{

}
