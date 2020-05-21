#pragma once 
#include "Figure.h"

using namespace std;

class Parallelepiped : public Figure
{
private:
protected:
public:
	//float height; // высота
	//float length; // длина
	//float width; // ширина

	Parallelepiped();
	~Parallelepiped() override;//деструктор
	float space() override; //площадь поверхности
};
