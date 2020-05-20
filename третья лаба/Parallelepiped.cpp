#include "Parallelepiped.h"
#include <iostream>

using namespace std;

Parallelepiped::Parallelepiped()
{

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
