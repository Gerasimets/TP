#include "queue.h"
#include <iostream>

// this - указатель на объект, который вызвал данную фунцию

queue_element* queue::get_end() //
{
	return end;
}

// функция проверяет, пуста ли очередь
bool queue::empty() const
{
	if (size == 0)
	{
		std::cout << "Очередь пуста" << '\n';
		return 0;
	}
	return 1;
}

queue::queue() //конструктор
{
	end = nullptr;
	size = 0;
}

queue::~queue() //деструктор
{
	while (size > 0) //если очередь не пуста
	{
		queue_element* temp = end; //временная переменная, которой присвоили указатель на последний элемент
		end = temp->prev; //предпоследний элемент становится последним
		delete temp; //удаляем изначальный последний
		size--;
	}
}

// добавление элемента в конец списка
void queue::push(int new_value)
{
	queue_element* new_element = new queue_element; // выделить память под переменную типа queue_element и присвоить адрес
													// начала выделенной памяти в переменную-указатель new_element
	new_element->prev = end; //указатель на предыдущий элемент указывает на прошлый последний элемент
	end = new_element;	// новый элемент теперь является концом списка
	end->value = new_value; //писваеваем значение// пойти по указателю end, получить переменную типа queue_element, которая там находится
                                                //и в ней изменить поле value
	size++;		// размер списка увеличился на единицу
}

//удаление первого элемента
int queue::pop()
{
	int deleted_element = 0;
	queue_element* element_to_delete = end; //новой переменной присваиваем указатель на последний элемент
	if (element_to_delete->prev == nullptr) // если указатель на предыдущий равен 0, то есть у нас всего один элемент
	{
		deleted_element = element_to_delete->value; //переменной присваиваем значение 
		delete end; //удаляем элемент
		end = nullptr; //указатель на последний(здесь:единственный) элемент теперь указывает на ноль
		size--; //уменьшаем количество элементов в очереди
	}
	else
	{
		while (element_to_delete->prev->prev != nullptr) //пока пред-пред не ноль
		{
			element_to_delete = element_to_delete->prev; //двигаемся по элементам в обратном направлении
		}
		deleted_element = element_to_delete->prev->value; //присваиваем значение 1го элемента
		delete element_to_delete->prev; //удаляем 1ый элемент
		element_to_delete->prev = nullptr; //у второго элемента прев теперь ноль, потому что удалили первый
		size--; //уменьшаем количество элементов в очереди
	}
	return deleted_element;
}

void queue::show() //вывод очереди на экран
{
	queue_element* temp = end; //временной переменной присваиваем указатель на последний элемент

	while (temp->prev != nullptr) //пока не первый элемент
	{
		std::cout << temp->value << "  ->  "; //выводим значение
		temp = temp->prev; //двигаемся по элементам
	};
	std::cout << temp->value << '\n'; //первый элемент выводим
}

void queue::copy(queue& src) //конструктор копирования (очередь, которую копируем)
{
	int* temp1 = new int[src.size]; //создаем указатель на массив, выделяем память под массив, размера копируемой очереди
	queue_element* temp = src.end; //создаём указатель типа queue_element, ставим его на конец очереди, src текущая очередь

	for (int i = src.size - 1; i >= 0; i--) 
	{
		temp1[i] = temp->value; //присваиваем значение элемента очереди ячейке массива
		temp = temp->prev; //двигаемся дальше по элементам
	}

	for (int i = 0; i < src.size; i++)
	{
		this->push(temp1[i]); // добавляем копируемые элементы в очередь
	}

	delete[] temp1; //очищаем память
	this->show(); //выводим скопированную очередь
}

void queue::concat(queue& Q1, queue& Q2) //слияние очередей 
{
	int* temp1 = new int[Q1.size];
	queue_element* temp = Q1.end; //ставим на конец списка

	for (int i = Q1.size - 1; i >= 0; i--)
	{
		temp1[i] = temp->value; //присваиваем значение элемента очереди ячейке массива
		temp = temp->prev; //двигаемся дальше по элементам
	}

	for (int i = 0; i < Q1.size; i++)
	{
		this->push(temp1[i]); // добавляем копируемые элементы в очередь
	}

	delete[] temp1; //очищаем память

	int* temp2 = new int[Q2.size];
	queue_element* temp_1 = Q2.end; //ставим на конец списка

	for (int i = Q2.size - 1; i >= 0; i--)
	{
		temp2[i] = temp_1->value; //присваиваем значение элемента очереди ячейке массива
		temp_1 = temp_1->prev; //двигаемся дальше по элементам
	}

	for (int i = 0; i < Q2.size; i++)
	{
		this->push(temp2[i]); // добавляем копируемые элементы в очередь
	}

	delete[] temp2; //очищаем память
	this->show(); //вывод очереди 
}


