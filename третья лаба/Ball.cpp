#include "Ball.h"
#include <iostream>
#include "Figure.h"
#include <string>
using namespace std;

Ball::Ball()
{
	way = "ball.txt";
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
