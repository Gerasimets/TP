#include "son.h"
#include <iostream>

int child1::max_value()
{
	queue_element* end = get_end(); 
	int max = get_end()->value;
	if (size == 0)
	{
		std::cout << "queue is empty!\n";;
	}
	else
	{
		do
		{
			if (end->value > max) max = end->value;
			end = end->prev;
		} while (end != nullptr);
	}
	return max;
}

int child2::max_value()
{
	queue_element* end = get_end();
	int max = get_end()->value;
	if (size == 0)
	{
		std::cout << "queue is empty!\n";;
	}
	else
	{
		do
		{
			if (end->value > max) max = end->value;
			end = end->prev;
		} while (end != nullptr);
	}
	return max;
}

bool child2::empty() const
{
	return queue::empty();
}

void child2::push(int new_value)
{
	return queue::push(new_value);
}

int child2::pop() // удаление первого элемента
{
	return queue::pop();
}

void child2::show()
{
	return queue::show();
}

void child2::copy(child2& src) //копирование
{
	return queue::copy(src);
}

void child2::concat(child2& Q1, child2& Q2)//слияние
{
	return queue::concat(Q1, Q2);
}

int child3::max_value()
{
	queue_element* end = get_end();
	int max = get_end()->value;
	if (size == 0)
	{
		std::cout << "queue is empty!\n";;
	}
	else
	{
		do
		{
			if (end->value > max) max = end->value;
			end = end->prev;
		} while (end != nullptr);
	}
	return max;
}

bool child3::empty() const
{
	return queue::empty();
}

void child3::push(int new_value)
{
	return queue::push(new_value);
}

int child3::pop() // удаление первого элемента
{
	return queue::pop();
}

void child3::show()
{
	return queue::show();
}

void child3::copy(child3& src) //копирование
{
	return queue::copy(src);
}

void child3::concat(child3& Q1, child3& Q2)//слияние
{
	return queue::concat(Q1, Q2);
}
