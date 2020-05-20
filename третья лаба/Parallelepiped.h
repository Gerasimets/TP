#pragma once 
#include "Figure.h"

using namespace std;

class Parallelepiped : public Figure
{
private:
protected:
public:
	float height; // высота
	float length; // длина
	float width; // ширина

	Parallelepiped(); 
	~Parallelepiped() override;//деструктор
	void enter() override; //ввод данных
	float space() override; //площадь поверхности
	void read() override; // чтение из файла в массив
};
