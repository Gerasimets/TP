#pragma once 
#include "Figure.h"

using namespace std;

class Tetrahedron : public Figure
{
private:

protected:

public:
	Tetrahedron();
	Tetrahedron(string path); //с параметром
	Tetrahedron(const Tetrahedron& Tetrahedron_tmp); //копирования
	~Tetrahedron() override;//деструктор
	float space() override; //площадь поверхности
	void enter() override;
	void extention(Figure*& T, int& t, int v = 1) override;
};
