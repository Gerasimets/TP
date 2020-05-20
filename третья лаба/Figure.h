#pragma once
#include <string>
using namespace std;

class Figure
{
private:

protected:
	string way;
	float result;
	virtual float space() = 0; //площадь поверхности

public:
	virtual ~Figure(); //деструктор
	virtual void enter() = 0; //ввод данных
	virtual void read() = 0; // чтение из файла в массив
	void write(); //ввод в файл и в массив
	void show(); // из массива на экран
};
