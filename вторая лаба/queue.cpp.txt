#include "Queue.h"
#include <iostream>

using namespace std;

queue::queue() //конструктор
{
	//end = nullptr;
	size = 0;
}

queue::queue(int size_par) // конструктор c параметрами
{
	this->size = size_par;
}

// функция проверяет, пуста ли очередь
bool queue::empty() 
{
	if (size == 0)
	{
		std::cout << "Очередь пуста" << '\n';
		return 0;
	}
	return 1;
}

queue::~queue() //деструктор
{
	while (/*this->*/size > 0) //если очередь не пуста
	{
		queue_element* temp = end; //временная переменная, которой присвоили указатель на последний элемент
		end = temp->prev; //предпоследний элемент становится последним
		delete temp; //удаляем изначальный последний
		size--;
	}
}

 queue::queue (const queue& tmp_queue) //конструктор копирования (очередь, которую копируем)
{
	int* temp1 = new int[tmp_queue.size]; //создаем указатель на массив, выделяем память под массив, размера копируемой очереди
	queue_element* temp = tmp_queue.end; //создаём указатель типа queue_element, ставим его на конец очереди, src текущая очередь

	for (int i = tmp_queue.size - 1; i >= 0; i--) // копируем с очередь с конца в массив
	{
		temp1[i] = temp->value; //присваиваем значение элемента очереди ячейке массива
		temp = temp->prev; //двигаемся дальше по элементам
	}

	for (int i = 0; i < tmp_queue.size; i++) // вставляем все элементы в новую очередь по порядку
	{
		this + temp1[i]; // добавляем копируемые элементы в очередь
	}

	delete[] temp1; //очищаем память
	//this->show(); //выводим скопированную очередь
}

 // добавление элемента в конец очереди
 void queue::operator + (int new_value) // + добавляет элемент в очередь
 {
	 queue_element* new_element = new queue_element; // выделить память под переменную типа queue_element и присвоить адрес
													 // начала выделенной памяти в переменную-указатель new_element
	 new_element->prev = end; //указатель на предыдущий элемент указывает на прошлый последний элемент
	 end = new_element;	// новый элемент теперь является концом очереди
	 end->value = new_value; //писваеваем значение// пойти по указателю end, получить переменную типа queue_element, которая там находится
												 //и в ней изменить поле value
	 size++;		// размер списка увеличился на единицу
 }



 int queue::operator - () // - извлекает элемент из очереди
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

 queue& queue::operator = (const queue& tmp_queue2) // перегрузка оператора присваивания
 {
	 while (this->size > 0) // удаляем старые элементы
	 {
		 queue_element* tmp_delete = end; // временный становится последним
		 end = tmp_delete->prev; // последний становится предыдущим
		 delete tmp_delete; // временный больше не нужен
		 size--;
	 }

	 int* mass_Queue = new int[tmp_queue2.size]; // создаем массив размером с длину очереди
	 queue_element* tmp_unit1 = tmp_queue2.end; // временный становится последним
	 for (int i = tmp_queue2.size - 1; i >= 0; i--)
	 {
		 mass_Queue[i] = tmp_unit1->value; // записываем в масив с конца
		 tmp_unit1 = tmp_unit1->prev; // временный идет от конца к началу
	 }
	 for (int i = 0; i < tmp_queue2.size; i++)
	 {
		 this + mass_Queue[i]; // вставляем с перевого и до последнего элемента в очередь
	 }
	 delete[] mass_Queue; // временный массив больше не нужен
	 return *this; // возвращаем указатель на очередь
 }

 void operator * (queue& tmp_queue, int number) // * умножает каждый элемент очереди на пользовательское число
 {
	 queue_element* tmp_unit1 = tmp_queue.end; // временный становится последним
	 while (tmp_unit1->prev != nullptr) // пока мы не дойдем до первого элемента..
	 {
		 tmp_unit1->value = tmp_unit1->value * number; // изменяем значение на значение*число
		 tmp_unit1 = tmp_unit1->prev; // временный идет от конца к началу
	 }
	 tmp_unit1->value = tmp_unit1->value * number; //для первого элемента
 }

 void queue::operator== (const queue tmp_queue)
 {
	 if (this->size != tmp_queue.size) //если не равен размер, то..
	 {
		 cout << "Очередь №1 не равна Очереди №2" << endl; //очереди не равны
	 }
	 else //если размер равен, сравниваем поэлементно
	 {
		 queue_element* tmp_comprasion = tmp_queue.end; // временный становится последним

		 while (this->end->value == tmp_comprasion->value) //пока значения равны
		 {
			 this->end = this->end->prev; //двигаемся по элементам
			 tmp_comprasion = tmp_comprasion->prev;
		 }

	 }

 }
