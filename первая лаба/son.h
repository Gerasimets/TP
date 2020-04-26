#pragma once

#include "queue.h"

class child1 : public queue
{
public:
	int max_value();
};

class child2 : protected queue
{
public:
	int max_value(); //нахождение максимального элемента
	bool empty() const;  // функция  проверяет, пуст ли список
	void push(int new_value);  // добавление элемента в конец списка
	int pop(); // удаление первого элемента
	void show(); //вывод очереди на экран
	void copy(child2& src);//копирование
	void concat(child2& Q1, child2& Q2);//слияние
};

class child3 : private queue
{
public:
	int max_value(); //нахождение максимального элемента
	bool empty() const;  // функция  проверяет, пуст ли список
	void push(int new_value);  // добавление элемента в конец списка
	int pop(); // удаление первого элемента
	void show(); //вывод очереди на экран
	void copy(child3& src);//копирование
	void concat(child3& Q1, child3& Q2);//слияние
};
