#pragma once

using namespace std;

class Figure
{
private:
protected:
	float result;
public:
	virtual ~Figure(); //деструктор
	virtual void enter(); //ввод данных
	virtual float space(); //площадь поверхности
	virtual void read(); // чтение из файла в массив
	virtual void write(); //ввод в файл и в массив
	void show(); // из массива на экран
};
