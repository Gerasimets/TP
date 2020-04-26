#pragma once

// элемент очереди
struct queue_element
{
	int value;	// значение данного элемента списка
	queue_element* prev;	// указатель на предыдущий элемент списка
};

// класс очередь
class queue
{
private:
	// данные
	queue_element* end; // указатель на последний элемент списка

protected:
	int size;	// количество элементов в списке
	queue_element* get_end(); //указатель на последний
public:
	queue(); // конструктор
	~queue(); //деструктор

	// функции
	bool empty() const;  // функция  проверяет, пуст ли список
	void push(int new_value);  // добавление элемента в конец списка
	int pop(); // удаление первого элемента
	void show(); //вывод очереди на экран
	void copy(queue& src);//копирование
	void concat(queue& Q1, queue& Q2);//слияние
};
