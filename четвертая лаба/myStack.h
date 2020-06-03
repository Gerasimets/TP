#pragma once
#include "Stack_element.h"

using namespace std;

//template <typename T2>
//struct Stack_element
//{
//	T2 value = 0; // значение элемента стека
//	Stack_element<T2>* prev = 0; // ссылка на предыдущий элемент стека
//};

template <typename T2>
class myStack
{
private:
	Stack_element<T2>* last = 0; // указатель на последний элемент стека
	int size; // размер стека
protected:

public:
	myStack() : size(0) // конструктор стека
	{

	};

	myStack(int quantity) : size(0)// конструктор стека с параметром
	{
		for (int i = 0; i < quantity; i++)
		{
			this->push((130.0 + rand() % 56) / (2.0 + rand() % 2));
		}
	};

	~myStack() // деструктор стека
	{
		while (this->size > 0) // пока размер стэка больше нуля
		{
			this->pop();
		}
		system("cls");
	};

	void push(T2 new_value) // добавление элементов в конец стека
	{
		Stack_element<T2>* new_element = new(Stack_element<T2>); // выделяем память под новый элемент ///////////////////////////////////////////////////
		new_element->set_prev(last)/*prev = last*/; // новый элемент будет ссылаться на последний
		new_element->set_value(new_value)/*value = new_value*/; // изменяем значение нового элемента
		last = new_element; // последний элемент изменился
		size++; // добавили один элемент
	};

	void pop() // извлекаем последний(головной) элемент из стека
	{
		T2 deleted_element = 0; // извлеченный элемент
		deleted_element = last->get_value()/*value*/; //присваиваем значение последнего элемента 
		if (size == 1) // если в стеке 1 элемент
		{
			delete last; // удаляем указатель на него
			last = nullptr; // и обнуляем
		}
		else // если больше одного элемента
		{
			Stack_element<T2>* element_to_delete = last; // создаем переменную, которая будет идти от конца
			last = last->get_prev()/*prev*/; //в указатель на последний присваиваем предыдущий
			delete element_to_delete; //удаляем элемент
			element_to_delete = nullptr;
		}
		size--; // извлекли один элемент, уменьшили размер стека
		cout.setf(ios::fixed);
		cout << "Извлеченыый элемент: " << setprecision(4) << deleted_element << endl;
		cout << resetiosflags(ios_base::floatfield);
	}

	void show() //вывод стека на экран
	{
		try
		{
			if (this->empty() == 0)
			{
				throw "Стек пуст";
			}

			cout.setf(ios::fixed);

			Stack_element<T2>* current = last; // создаем переменную, идем от конца к началу
			while (current->get_prev()/*prev*/ != 0) // пока не дойдем до первого элемента
			{
				cout << setprecision(4) << current->get_value()/*value*/ << " <- "; // выводим значение текущего
				current = current->get_prev()/*prev*/; // идем к началу
			}
			cout << setprecision(4) << current->get_value()/*value*/ << endl; // последний выводим отдельно
			cout << resetiosflags(ios_base::floatfield);
		}
		catch (const char* ex)
		{
			cout << ex << endl;
		}
	}

	myStack& operator = (const myStack& tmp_stack) // перегрузка оператора присваивания
	{
		while (this->size > 0) // удаляем старые элементы
		{
			this->pop();
		}
		system("cls");

		T2* tmp_mass_stack = new T2[tmp_stack.size]; // создаем массив размером с длину стека
		Stack_element<T2>* tmp_last = tmp_stack.last; // временный становится последним

		for (int i = tmp_stack.size - 1; i >= 0; i--)
		{
			tmp_mass_stack[i] = tmp_last->get_value()/*value*/; // записываем в масив с конца
			tmp_last = tmp_last->get_prev()/*prev*/; // временный идет от конца к началу
		}

		for (int i = 0; i < tmp_stack.size; i++)
		{
			this->push(tmp_mass_stack[i]); // вставляем с перевого и до последнего элемента в ячейку массива стеков
		}

		delete[] tmp_mass_stack; // временный массив больше не нужен
		return *this; // возвращаем указатель на стек///////////////////////////////////////////////////////////
	}

	void operator + (myStack<T2>& Stack_tmp) // сложение двух стеков
	{
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Сложение стеков невозможно" << endl;
		}
		else
		{
			Stack_element<T2>* current_last_tmp = last; // указываем на конец текущего стека
			Stack_element<T2>* current_last_tmp2 = Stack_tmp.last; // и на конец второго
			while (current_last_tmp->get_prev()/*prev*/ != 0) // пока не дойдем до первого элемента
			{
				//current_last_tmp->value += current_last_tmp2->value; // прибавляем к значению текущей значение второй
				current_last_tmp->set_value/*value*//* = */(current_last_tmp->get_value()/*value*/ + current_last_tmp2->get_value())/*value*/; // прибавляем к значению текущей значение второй
				current_last_tmp = current_last_tmp->get_prev()/*prev*/; // двигаем к началу текущую
				current_last_tmp2 = current_last_tmp2->get_prev()/*prev*/; // двигаем к началу вторую
			}
			//current_last_tmp->value += current_last_tmp2->value; // к первому тоже прибавляем
			current_last_tmp->set_value/*value*/ /*=*/ (current_last_tmp->get_value()/*value*/ + current_last_tmp2->get_value())/*value*/; // к первому тоже прибавляем
			cout << "Новый стек:" << endl; // выводим на экран
			this->show();
		}
	}

	void operator - (myStack<T2>& Stack_tmp) // сложение двух стеков
	{
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Вычитание из стека невозможно" << endl;
		}
		else
		{
			Stack_element<T2>* current_last_tmp = last; // указываем на конец текущего стека
			Stack_element<T2>* current_last_tmp2 = Stack_tmp.last; // и на конец второй
			while (current_last_tmp->get_prev()/*prev*/ != 0) // пока не дойдем до первого элемента
			{
				//current_last_tmp->value -= current_last_tmp2->value;
				current_last_tmp->set_value/*value*/ /*=*/ (current_last_tmp->get_value()/*value*/ - current_last_tmp2->get_value())/*value*/;
				current_last_tmp = current_last_tmp->get_prev()/*prev*/; // двигаем к началу текущую
				current_last_tmp2 = current_last_tmp2->get_prev()/*prev*/; // двигаем к началу вторую
			}
			//current_last_tmp->value -= current_last_tmp2->value;
			current_last_tmp->set_value/*value*/ /*=*/ (current_last_tmp->get_value()/*value*/ - current_last_tmp2->get_value())/*value*/;
			cout << "Новый стек:" << endl; // выводим на экран
			this->show();
		}
	}

	void operator == (const myStack& tmp_stack)
	{
		int x = 1;
		if (this->size != tmp_stack.size) //если не равен размер, то..
		{
			cout << "Размер стеков разный" << endl; //стеки не равны
			x = 0;
		}
		else //если размер равен, сравниваем поэлементно
		{
			Stack_element<T2>* tmp_comprasion_1 = this->last; //создаем переменную-указаетель и присваиваем ей указатель на послений в текущем стеке, который вызвал этот перегруженный оператор
			Stack_element<T2>* tmp_comprasion_2 = tmp_stack.last; // временный становится последним
			int i = size;
			do
			{
				if (tmp_comprasion_1->get_value()/*value*/ == tmp_comprasion_2->get_value()/*value*/)
				{
					i--;
				}
				else
				{
					x = 0;
					break;
				}
				tmp_comprasion_1 = tmp_comprasion_1->get_prev()/*prev*/; //двигаемся по элементам
				tmp_comprasion_2 = tmp_comprasion_2->get_prev()/*prev*/;
			} while (i != 0);
		}

		if (x == 1)
		{
			cout << "стеки равны" << endl;
		}
		else
		{
			cout << "стеки не равны" << endl;
		}
	}

	bool empty()
	{
		if (size == 0)
		{
			return 0;
		}
		return 1;
	}
};
