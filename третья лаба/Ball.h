#pragma once
#include "Figure.h"

using namespace std;

class Ball : public Figure
{
private:
	
protected:
	
public:
	float radius; //радиус шара
	Ball(); //конструктор
	~Ball() override; //деструктор
	void enter() override; //ввод данных
	float space() override; //площадь поверхности
	void read() override; // чтение из файла в массив
};
