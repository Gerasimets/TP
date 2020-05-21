#pragma once
#include <string>
using namespace std;

class Figure
{
private:

protected:
	string way;
	
public:
	virtual float space() = 0; //площадь поверхности
	virtual ~Figure(); //деструктор
	Figure& read(Figure** &massU, int &kp, int &np); // чтение из файла в массив
	void write(); //ввод в файл и в массив
	void show(); // вывод из массива указателей на экран

	float result = 0;

	float radius = -1; // радиус шара

	float rib = -1; // ребро тетраэдра

	float height = -1; // высота
	float length = -1; // длина
	float width = -1; // ширина
};
