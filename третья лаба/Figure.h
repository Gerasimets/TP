#pragma once
#include <string>
using namespace std;

class Figure
{
private:

protected:
	string way;
	float radius = -1; // радиус шара
	float rib = -1; // ребро тетраэдра
	float height = -1; // высота
	float length = -1; // длина
	float width = -1; // ширина
	float result = 0; // площадь
	
public:
	virtual float space() = 0; //площадь поверхности
	virtual ~Figure(); //деструктор
	Figure& read(Figure** &massU, int &kp, int &np); // чтение из файла в массив
	void write(); //ввод в файл и в массив
	void show(); // вывод из массива указателей на экран
	virtual void enter() = 0;
	void extent_uk(Figure** &mass, int &k, int v = 1); // увеличивает массив указателей на v
	virtual void extention(Figure* &mass_obj, int &n, int v = 1) = 0; //-~-
};
