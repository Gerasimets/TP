#pragma once 
#include "Figure.h"

using namespace std;

class Parallelepiped : public Figure
{
private:
protected:
public:
	Parallelepiped(); //конструктор
	Parallelepiped(string path); // конструктор с параметрами
	Parallelepiped(const Parallelepiped& Parallelepiped_tmp); // конструктор копирования
	~Parallelepiped() override;//деструктор
	float space() override; //площадь поверхности
	void enter() override;
	void extention(Figure*& P, int& p, int v = 1) override;
};
