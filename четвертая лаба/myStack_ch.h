#pragma once
#include "Stack_element.h"

using namespace std;

class myStack_ch
{
private:
	Stack_element<char*>* last_ch = 0;
	int size; // размер стека
protected:

public:
	myStack_ch() : size(0) // конструктор стека
	{

	};

	myStack_ch(int quantity) : size(0)// конструктор стека с параметром
	{
		for (int i = 0; i < quantity; i++)
		{
			int j;
			int str_size = 2 + rand() % 8;
			char* strok = new char[str_size];
			for (j = 0; j < str_size; j++)
			{
				strok[j] = 65 + rand() % 56;
			}
			strok[--j] = '\0';
			this->push_ch(strok);
		}
	};

	~myStack_ch() // деструктор стека
	{
		while (this->size > 0) // пока размер стэка больше нуля
		{
			this->pop();
		}
		system("cls");
	};

	void push_ch(char* new_ch) // добавление элементов в конец стека
	{
		Stack_element<char*>* new_element = new(Stack_element<char*>); // выделяем память под новый элемент
		new_element->set_prev(0, last_ch)/*prev = last*/; // новый элемент будет ссылаться на последний
		new_element->set_value(0, new_ch)/*value = new_value*/; // изменяем значение нового элемента
		last_ch = new_element; // последний элемент изменился
		size++; // добавили один элемент
	};

	void pop() // извлекаем последний(головной) элемент из стека
	{
		char* deleted_element = 0; // извлеченный элемент
		deleted_element = last_ch->get_value_ch(); //присваиваем значение последнего элемента 
		if (size == 1) // если в стеке 1 элемент
		{
			delete last_ch; // удаляем указатель на него
			last_ch = nullptr; // и обнуляем
		}
		else // если больше одного элемента
		{
			Stack_element<char*>* element_to_delete = last_ch; // создаем переменную, которая будет идти от конца
			last_ch = last_ch->get_prev_ch(); //в указатель на последний присваиваем предыдущий
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

			Stack_element<char*>* current = last_ch; // создаем переменную, идем от конца к началу
			while (current->get_prev_ch() != 0) // пока не дойдем до первого элемента
			{
				cout << setprecision(4) << current->get_value_ch() << " <- "; // выводим значение текущего
				current = current->get_prev_ch(); // идем к началу
			}
			cout << setprecision(4) << current->get_value_ch() << endl; // последний выводим отдельно
			cout << resetiosflags(ios_base::floatfield);
		}
		catch (const char* ex)
		{
			cout << ex << endl;
		}
	}

	myStack_ch& operator = (const myStack_ch& tmp_stack) // перегрузка оператора присваивания
	{
		while (this->size > 0) // удаляем старые элементы
		{
			this->pop();
		}
		system("cls");

		char** tmp_mass_stack = new char*[tmp_stack.size]; // создаем массив размером с длину стека
		Stack_element<char*>* tmp_last = tmp_stack.last_ch; // временный становится последним

		for (int i = tmp_stack.size - 1; i >= 0; i--)
		{
			tmp_mass_stack[i] = tmp_last->get_value_ch(); // записываем в масив с конца
			tmp_last = tmp_last->get_prev_ch(); // временный идет от конца к началу
		}

		for (int i = 0; i < tmp_stack.size; i++)
		{
			this->push_ch(tmp_mass_stack[i]); // вставляем с перевого и до последнего элемента в ячейку массива стеков
		}
		delete[] tmp_mass_stack; // временный массив больше не нужен
		
		return *this; // возвращаем указатель на стек
	}

	void operator + (myStack_ch& Stack_tmp) // сложение двух стеков
	{
		
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Сложение стеков невозможно" << endl;
		}
		else
		{
			int flag = 0;
			Stack_element<char*>* current_last_tmp = last_ch; // указываем на конец текущего стека
			Stack_element<char*>* current_last_tmp2 = Stack_tmp.last_ch; // и на конец второго
			int razm = 0;

			while (razm < size)
			{
				if (strlen(current_last_tmp->get_value_ch()) != strlen(current_last_tmp2->get_value_ch()))
				{
					flag = 1;
				}
				current_last_tmp = current_last_tmp->get_prev_ch(); // двигаем к началу текущую
				current_last_tmp2 = current_last_tmp2->get_prev_ch(); // двигаем к началу вторую
				razm++;
			}
			
			if (flag == 0)
			{
				Stack_element<char*>* current_last_tmp = last_ch; // указываем на конец текущего стека
				Stack_element<char*>* current_last_tmp2 = Stack_tmp.last_ch; // и на конец второго
				int i = 0;
				
				while (current_last_tmp->get_prev_ch() != 0) // пока не дойдем до первого элемента
				{
					int size_s = strlen(current_last_tmp->get_value_ch());
					char* mas_str = new char[size_s+1];
					for (i = 0; i < size_s; i++ )
					{
						mas_str[i] = current_last_tmp->get_value_ch()[i];
						mas_str[i] += current_last_tmp2->get_value_ch()[i];
					}
					mas_str[i] = '\0';
					current_last_tmp->set_value (0, mas_str);
					
					current_last_tmp = current_last_tmp->get_prev_ch(); // двигаем к началу текущую
					current_last_tmp2 = current_last_tmp2->get_prev_ch(); // двигаем к началу вторую
				}
				
				int size_s = strlen(current_last_tmp->get_value_ch());
				char* mas_str = new char[size_s+1];
				for (i = 0; i < size_s; i++)
				{
					mas_str[i] = current_last_tmp->get_value_ch()[i];
					mas_str[i] += current_last_tmp2->get_value_ch()[i];
				}
				mas_str[i] = '\0';
				current_last_tmp->set_value(0, mas_str);
				cout << "Новый стек:" << endl; // выводим на экран
				this->show();
			}
			else
			{
				cout << "все строки должны быть одной длины" << endl; // выводим на экран
			}
		}
	}

	void operator - (myStack_ch& Stack_tmp) // сложение двух стеков
	{
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Сложение стеков невозможно" << endl;
		}
		else
		{
			int flag = 0;
			Stack_element<char*>* current_last_tmp = last_ch; // указываем на конец текущего стека
			Stack_element<char*>* current_last_tmp2 = Stack_tmp.last_ch; // и на конец второго
			int razm = 0;

			while (razm < size)
			{
				if (strlen(current_last_tmp->get_value_ch()) != strlen(current_last_tmp2->get_value_ch()))
				{
					flag = 1;
				}
				current_last_tmp = current_last_tmp->get_prev_ch(); // двигаем к началу текущую
				current_last_tmp2 = current_last_tmp2->get_prev_ch(); // двигаем к началу вторую
				razm++;
			}

			if (flag == 0)
			{
				Stack_element<char*>* current_last_tmp = last_ch; // указываем на конец текущего стека
				Stack_element<char*>* current_last_tmp2 = Stack_tmp.last_ch; // и на конец второго
				int i = 0;

				while (current_last_tmp->get_prev_ch()/*prev*/ != 0) // пока не дойдем до первого элемента
				{
					int size_s = strlen(current_last_tmp->get_value_ch());
					char* mas_str = new char[size_s + 1];
					for (i = 0; i < size_s; i++)
					{
						mas_str[i] = current_last_tmp->get_value_ch()[i];
						mas_str[i] -= current_last_tmp2->get_value_ch()[i];
					}
					mas_str[i] = '\0';
					current_last_tmp->set_value(0, mas_str);

					current_last_tmp = current_last_tmp->get_prev_ch()/*prev*/; // двигаем к началу текущую
					current_last_tmp2 = current_last_tmp2->get_prev_ch()/*prev*/; // двигаем к началу вторую
				}

				int size_s = strlen(current_last_tmp->get_value_ch());
				char* mas_str = new char[size_s + 1];
				for (i = 0; i < size_s; i++)
				{
					mas_str[i] = current_last_tmp->get_value_ch()[i];
					mas_str[i] -= current_last_tmp2->get_value_ch()[i];
				}
				mas_str[i] = '\0';
				current_last_tmp->set_value(0, mas_str);
				cout << "Новый стек:" << endl; // выводим на экран
				this->show();
			}
			else
			{
				cout << "все строки должны быть одной длины" << endl; // выводим на экран
			}
		}
	}

	void operator == (const myStack_ch& tmp_stack)
	{
		int x = 1;
		if (this->size != tmp_stack.size) //если не равен размер, то..
		{
			cout << "Размер стеков разный" << endl; //стеки не равны
			x = 0;
		}
		else // если размер равен, сравниваем поэлементно
		{
			Stack_element<char*>* tmp_comprasion_1 = this->last_ch; //создаем переменную-указаетель и присваиваем ей указатель на послений в текущем стеке, который вызвал этот перегруженный оператор
			Stack_element<char*>* tmp_comprasion_2 = tmp_stack.last_ch; // временный становится последним
			int i = size;
			do
			{
				int k = strlen(tmp_comprasion_1->get_value_ch());
				for (int j = 0; j < k; j++)
				{
					if (tmp_comprasion_1->get_value_ch()[i] == tmp_comprasion_2->get_value_ch()[i])
					{
						
					}
					else
					{
						x = 0;
						break;
					}
				}
				i--;
				tmp_comprasion_1 = tmp_comprasion_1->get_prev_ch()/*prev*/; //двигаемся по элементам
				tmp_comprasion_2 = tmp_comprasion_2->get_prev_ch()/*prev*/;
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
