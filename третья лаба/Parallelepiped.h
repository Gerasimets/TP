#pragma once 
#include "Figure.h"

using namespace std;

class Parallelepiped : public Figure
{
private:
	float height; // высота
	float length; // длина
	float width; // ширина
protected:
public:
	//деструктор
	void enter(); //ввод данных
	float space(); //площадь поверхности
	void read(); // чтение из файла в массив
	void write(); //ввод в файл и в массив
};
