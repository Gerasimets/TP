#pragma once 
#include "Figure.h"

using namespace std;

class Tetrahedron : public Figure
{
private:
protected:
public:
	float rib; // ребро

	Tetrahedron();
	~Tetrahedron() override;//деструктор

	void enter() override; //ввод данных
	float space() override; //площадь поверхности
	void read() override; // чтение из файла в массив
};



/*

A *ptr = new B;

delete ptr;





A ptr[] = new B;

delete ptr[];




*/
