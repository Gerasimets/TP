#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T2>
struct Unit
{
	T2 value = 0; // значение элемента очереди
	Unit<T2>* prev = 0; // ссылка на предыдущий элемент очереди
};

template <typename T2>
class myStack
{
private:
	Unit<T2>* last = 0; // конец очереди
	int size; // размер очереди

protected:

public:
	myStack(): size(0) // конструктор стека
	{

	};

	myStack(int value): size(0)// конструктор стека с параметром
	{
		for (int i = 0; i < value; i++)
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

	void push(T2 value) // добавление элементов в конец очереди
	{
		Unit<T2>* new_unit = new(Unit<T2>); // выделяем память под новый элемент
		new_unit->prev = last; // новый элемент будет ссылаться на последний
		new_unit->value = value; // изменяем значение нового элемента
		last = new_unit; // последний элемент изменился
		size++; // добавили один элемент
	};

	void pop() // извлекаем первый элемент из очереди
	{
		T2 now_ex = 0; // извлеченный элемент
		now_ex = last->value;
		if (size == 1) // если в стеке 1 элемент
		{
			delete last; // удаляем указатель на него
			last = nullptr; // и обнуляем
		}
		else // если больше одного элемента
		{
			Unit<T2>* current = last; // создаем переменную, которая будет идти от конца
			last = last->prev;
			delete current;
			current = nullptr;
		}
		size--; // извлекли один элемент
		cout.setf(ios::fixed);
		cout << "Извлеченыый элемент: " << setprecision(4) << now_ex << endl;
		cout << resetiosflags(ios_base::floatfield);
	}

	void show()
	{
		try
		{
			if (this->empty() == 0)
			{
				throw "Стек пуст";
			}

			cout.setf(ios::fixed);

			Unit<T2>* current = last; // создаем переменную, идем от конца к началу
			while (current->prev != 0) // пока не дойдем до первого элемента
			{
				cout << setprecision(4) << current->value << " <- "; // выводим значение текущего
				current = current->prev; // идем к началу
			}
			cout << setprecision(4) << current->value << endl; // последний выводим отдельно
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

		T2* masValueStack = new T2[tmp_stack.size]; // создаем массив размером с длину стека
		Unit<T2>* tmp_unit1 = tmp_stack.last; // временный становится последним

		for (int i = tmp_stack.size - 1; i >= 0; i--)
		{
			masValueStack[i] = tmp_unit1->value; // записываем в масив с конца
			tmp_unit1 = tmp_unit1->prev; // временный идет от конца к началу
		}

		for (int i = 0; i < tmp_stack.size; i++)
		{
			this->push(masValueStack[i]); // вставляем с перевого и до последнего элемента в очередь
		}

		delete[] masValueStack; // временный массив больше не нужен
		return *this; // возвращаем указатель на очередь
	}

	void operator + (myStack<T2>& Stack_tmp) // сложение двух очередей
	{
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Сложение стеков невозможно" << endl;
		}
		else
		{
			Unit<T2>* current_item1 = last; // указываем на конец текущей очереди
			Unit<T2>* current_item2 = Stack_tmp.last; // и на конец второй
			while (current_item1->prev != 0) // пока не дойдем до первого элемента
			{
				current_item1->value += current_item2->value; // прибавляем к значению текущей значение второй
				current_item1 = current_item1->prev; // двигаем к началу текущую
				current_item2 = current_item2->prev; // двигаем к началу вторую
			}
			current_item1->value += current_item2->value; // к первому тоже прибавляем
			cout << "Новый стек " << endl ; // выводим на экран
			this->show();
		}
	}

	void operator - (myStack<T2>& Stack_tmp) // сложение двух очередей
	{
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Вычитание из стека невозможно" << endl;
		}
		else
		{
			Unit<T2>* current_item1 = last; // указываем на конец текущей очереди
			Unit<T2>* current_item2 = Stack_tmp.last; // и на конец второй
			while (current_item1->prev != 0) // пока не дойдем до первого элемента
			{
				current_item1->value -= current_item2->value;
				current_item1 = current_item1->prev; // двигаем к началу текущую
				current_item2 = current_item2->prev; // двигаем к началу вторую
			}
			current_item1->value -= current_item2->value;
			cout << "Новый стек " << endl; // выводим на экран
			this->show();
		}
	}

	void operator == (const myStack& tmp_stack)
	{
		int x = 1;
		if (this->size != tmp_stack.size) //если не равен размер, то..
		{
			cout << "Размер стеков разный" << endl; //очереди не равны
			x = 0;
		}
		else //если размер равен, сравниваем поэлементно
		{
			Unit<T2>* tmp_comprasion_1 = this->last;
			Unit<T2>* tmp_comprasion_2 = tmp_stack.last; // временный становится последним
			int i = size;
			do
			{
				if (tmp_comprasion_1->value == tmp_comprasion_2->value)
				{
					i--;
				}
				else
				{
					x = 0;
					break;
				}
				tmp_comprasion_1 = tmp_comprasion_1->prev; //двигаемся по элементам
				tmp_comprasion_2 = tmp_comprasion_2->prev;
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
