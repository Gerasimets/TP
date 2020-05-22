#pragma once
#include "Figure.h"

using namespace std;

class Ball : public Figure
{
private:

protected:

public:
	Ball(); // конструктор
	Ball(string path); // конструктор с параметрами
	Ball(const Ball &Ball_tmp); // конструктор копирования
	~Ball() override; // деструктор
	float space() override; //площадь поверхности
	void enter() override;
	void extention(Figure* &B, int& b, int v = 1) override;
};
