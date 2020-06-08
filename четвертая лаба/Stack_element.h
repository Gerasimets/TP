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
	Stack_element<char*>* prev_ch = 0;
	char* value_ch = 0;

public:
	Stack_element() : value(0) // конструктор 
	{

	};

	Stack_element(T2 val) : value(0) // конструктор  с параметром
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

	char* get_value_ch()
	{
		return value_ch;
	}

	Stack_element<T2>*& get_prev()
	{
		return prev;
	}

	Stack_element<char*>*& get_prev_ch()
	{
		return prev_ch;
	}

	void set_value(T2 new_val, char* new_val_ch = 0)
	{
		if (strcmp(typeid(T2).name(), "char *") != 0)
		{
			value = new_val;
		}
		else
		{
			value_ch = new_val_ch;
		}
	}

	void set_prev(Stack_element<T2>* new_prev, Stack_element<char*>* new_prev_ch = 0)
	{
		if (strcmp(typeid(T2).name(), "char *") != 0)
		{
			prev = new_prev;
		}
		else
		{
			prev_ch = new_prev_ch;
		}
	}
};
