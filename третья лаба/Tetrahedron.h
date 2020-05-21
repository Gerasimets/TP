#pragma once 
#include "Figure.h"

using namespace std;

class Tetrahedron : public Figure
{
private:

protected:

public:
	Tetrahedron();
	~Tetrahedron() override;//деструктор

	float space() override; //площадь поверхности
};
