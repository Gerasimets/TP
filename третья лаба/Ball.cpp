#include "Ball.h"
#include <iostream>
#include "Figure.h"
#include <string>
using namespace std;

Ball::Ball()
{
	way = "ball.txt";
}

Ball::Ball(string path)
{
	way = path;
}

Ball::Ball(const Ball& Ball_tmp)
{
	radius = Ball_tmp.radius;
	result = Ball_tmp.result;
	way = Ball_tmp.way;
}

Ball::~Ball()
{

}

float Ball::space()
{
	const double PI = acos(-1.0); // обратная тригонометрическая ф-ия, число пи
	result = 4 * radius * radius * PI;
	return result;
}

void Ball::enter()
{
	cout << "Введите данные" << endl;
	cout << "Радиус:";
	cin >> this->radius;
}

void Ball::extention(Figure* &B, int& b, int v)
{
	Figure* obj_tmp = new Ball[b]; // выделяем память во временном массиве объектов

	for (int j = 0; j < b; j++) // перезаписываем ориганальный массив во временный
	{
		obj_tmp[j] = B[j];
	}

	B = new Ball[++b]; // увеличиваем память в оригинальном массиве

	for (int j = 0; j < b - 1; j++) // перезаписываем временный в оригинальный
	{
		B[j] = obj_tmp[j];
	}
	delete[] obj_tmp; // очищаем временный
}
