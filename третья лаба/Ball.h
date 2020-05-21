#pragma once
#include "Figure.h"

using namespace std;

class Ball : public Figure
{
private:

protected:

public:
	//float radius; //радиус шара
	Ball(); //конструктор
	~Ball() override; //деструктор
	float space() override; //площадь поверхности
};
