#include <iostream>
#include "queue.h"
#include "son.h"
#include <stdlib.h>
#include <stdio.h>

template <class tmp>

void workWithClass(tmp* queue) 
{
	int choise;
	int number = 0;         // Номер обрабатываемой очереди
	int count = 1;          // Количество очередей с которыми работает пользователь
	int value;              //введенное значение
	int action, flag = 1;   // меню

	do
	{
		//меню
		std::cout << "Номер используемой очереди: " << number << "\n\n"; 
		std::cout << "Выберете пункт меню:\n"; 
		std::cout << "1-Добавление нового элемента\n"; 
		std::cout << "2-Удаление первого элемента\n"; 
		std::cout << "3-Вывод очереди на экран\n"; 
		std::cout << "4-Нахождение максимального элемента\n"; 
		std::cout << "5-Создании копии\n"; 
		std::cout << "6-Слияние очередей\n"; 
		std::cout << "7-Выбор другой очереди\n"; 
		std::cout << "8-Выход из программы\n\n"; 
		std::cin >> action;

		switch (action)
		{
		case 1:
			std::cout << "Введите новый элемент: "; //добавление элемента
			std::cin >> value;
			queue[number].push(value);
			break;

		case 2:
			if (!queue[number].empty()) break; //проверка пуста ли очередь
			value = queue[number].pop(); //удаление элемента
			std::cout << "Удалённый элемент: " << value << '\n'; //удален этот элемент
			break;

		case 3:
			if (!queue[number].empty()) break; //проверка пуста ли очередь
			std::cout << "Очередь:"; 
			queue[number].show();  //вывод на экран выбранной очереди
			break;

		case 4:
			if (!queue[number].empty()) break; //проверка пуста ли очередь
			std::cout << "Максимальный элемент:" << '\n'; //максимальный элемент
			std::cout << queue[number].max_value() << '\n';
			break;

		case 5:
			if (!queue[number].empty()) break; //проверка пуста ли очередь
			queue[count].copy(queue[number]);   //копирование выбранной очереди
			std::cout << "Копия очереди создана. Номер очереди: " << count++ << '\n'; //копия создана
			break;

		case 6:
			if (count == 1) 
			{
				std::cout << "Существует только одна очередь" << '\n';
				break;
			}

			std::cout << "Выберете очередь, с которой хотите сделать слияние (0 - " << count - 1 << ") :  ";
			std::cin >> choise;

			if ((choise < 0) || (choise == number) || (choise >= count))
			{
				std::cout << "Некорректное значение. Слияние не произведено" << '\n';
				break;
			}

			queue[count].concat(queue[number], queue[choise]);
			std::cout << "Слияниее произведено. Номер очереди результата: " << count << '\n';
			count++;
			break;
		
		case 7:
			if (count == 1)
			{
				std::cout << "Существует только одна очередь" << '\n';
				break;
			}

			std::cout << "Выберете, на какую очередь переключиться: (0 - " << count - 1 << ") :  ";
			std::cin >> choise;
			if ((choise < 0) || (choise == number) || (choise >= count))
			{
				std::cout << "Некорректное значение. Переключение не выполнено" << '\n';
			}
			else
			{
				number = choise;
			}
			break;

		case 8:
			flag = 0;
		}
	} while (flag == 1);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int Number_queue = 0;
	int Type_son;

	std::cout << "Введите количество очередей" << '\n';
	std::cin >> Number_queue;
	child1* Object1 = NULL;
	child2* Object2 = NULL;
	child3* Object3 = NULL;

	std::cout << "Выбирете тип наследования" << '\n';
	std::cout << "'1' - Public" << '\n';
	std::cout << "'2' - Protected" << '\n';
	std::cout << "'3' - Private" << '\n';
	std::cin >> Type_son;

	switch (Type_son)
	{
	case 1:
		Object1 = new child1[Number_queue];
		workWithClass(Object1);
		delete[] Object1;
		break;

	case 2:
		Object2 = new child2[Number_queue];
		workWithClass(Object2);
		delete[] Object2;
		break;
	case 3:
		Object3 = new child3[Number_queue];
		workWithClass(Object3);
		delete[] Object3;
		break;
	default:
		std::cout << "некорректный ввод";
		break;
	}

	return 0;
}
