#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>

template <typename T2>
class Stack_element
{
private:
	T2 value = 0; // значение элемента очереди
	Stack_element<T2>* prev = 0; // ссылка на предыдущий элемент

public:
	Stack_element() : value(0) // конструктор 
	{

	};

	Stack_element(T2 val) : value(0) // конструктор 
	{
		value = val;
	};

	~Stack_element() // деструктор
	{

	}

	T2 get_value()
	{
		return value;
	}

	Stack_element<T2>*& get_prev()
	{
		return prev;
	}

	void set_prev(Stack_element<T2>* new_prev)
	{
		prev = new_prev;
	}

	void set_value(T2 new_val)
	{
		value = new_val;
	}
};
