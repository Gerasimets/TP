#include <iostream>
#include <iomanip>
#include "myStack.h"
#include <ctime>

using namespace std;

template <class T1>
void inversion(T1* mas, int size)
{
	cout << size <<endl; // выводим размер массива
	T1 *mass_tmp = new T1[size]; //выделяем память под временный массив
	for (int i = 0; i < size; i++)
	{
		mass_tmp[i] = mas[i]; //перезаписываем оригинальный во временный
		cout.setf(ios::fixed);
		cout << setprecision(4) << mass_tmp[i] << " ";
	}
	cout << endl;

	for (int i = 0, j = size - 1; i < size; i++, j--) //зеркалим массив и выводим
	{
		mas[i] = mass_tmp[j];
		cout << mas[i] << " ";
	}
	cout << resetiosflags(ios_base::floatfield) << endl;
	delete[] mass_tmp;
	system("pause");
}

template <class T2, typename T3>
void work_with_stack(T2* stack_ptr, T3 s)
{
	int S;
	cin >> S;
	T2 first_stack(S);
	stack_ptr = new T2[1];
	stack_ptr[0] = first_stack;
	int menu2 = 1; // выбор пользователя в меню второго задания
	int total = 1; // общее количество очередей или индекс последней созданной
	int current_number = 0; // номер текущей очереди
	T2* stack_tmp;
	T3 val;
	int choise; // номер выбранной пользователем очереди

	while (menu2)
	{
		system("cls");
		cout << "Используется очередь № " << current_number + 1 << endl;
		cout << "| 0| - Выход" << endl;
		cout << "| 1| - Добавление элемента к текущему стеку" << endl;
		cout << "| 2| - Извлечение элемента из текущего стека" << endl;
		cout << "| 3| - Вывод текущего стека на экран" << endl;
		cout << "| 4| - Добавление элемента к новому стеку и переключение на него" << endl;
		cout << "| 5| - Вывод всех стеков" << endl;
		cout << "| 6| - Выбор другого стека" << endl;
		cout << "| 7| - Сложить два стека" << endl;
		cout << "| 8| - Вычесть из одного стека другой" << endl;
		cout << "| 9| - Присвоить один стек к другому" << endl;
		cout << "|10| - Сравнение двух стеков" << endl;
		cin >> menu2;
		system("cls");

		switch (menu2)
		{
		case 0:
			delete[] stack_ptr;
			break;

		case 1:
			cin >> val;
			stack_ptr[current_number].push(val);
			stack_ptr[current_number].show();
			system("pause");
			break;

		case 2:
			try
			{
				if (stack_ptr[current_number].empty() == 0)
				{
					throw "Невозможно извлечь элемент из пустой очереди";
				}
				stack_ptr[current_number].pop();
				stack_ptr[current_number].show();
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			
			system("pause");
			break;

		case 3:
			stack_ptr[current_number].show();
			system("pause");
			break;

		case 4:
			try
			{
				for (int i = 0; i < total; i++)
				{
					if (stack_ptr[i].empty() == 0)
					{
						throw i;
					}
				}
				
				current_number = total; // переключаемся на очередь, которую сейчас создадим
				cout << "Переключение на новую очередь выполнено" << endl;

				stack_tmp = new T2[total]; // создаем временный массив, который на 1 больше общего количества очередей

				for (int i = 0; i < total; i++) // копируем все очереди кроме последней в новый массив
				{
					stack_tmp[i] = stack_ptr[i];
				}

				delete[] stack_ptr;

				stack_ptr = new T2[++total]; // выделяем память в старом массиве под новое количество очередей

				for (int i = 0; i < total - 1; i++) // копируем все очереди из временного массива в старый
				{
					stack_ptr[i] = stack_tmp[i];
				}

				delete[] stack_tmp; // временный больше не нужен
				//////////////////////////////////////////////////////////////////////////////////////////
				cin >> S;

				for (int i = 0; i < S; i++)
				{
					stack_ptr[current_number].push((130.0 + rand() % 56) / (2.0 + rand() % 2));
				}

				cout << "Текущая стек № " << current_number + 1 << ":" << endl;
				stack_ptr[current_number].show();
			}
			catch (const int i)
			{
				cout << "Стек под номером "<< i+1 <<" пуст, продолжите работу в нем" <<endl;
				current_number = i;

				for (int i = 0; i < total; i++) // выводим все очереди на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}
			}
			system("pause");
			break;

		case 5:
			for (int i = 0; i < total; i++) // выводим все очереди на экран
			{
				cout << "Стек № " << i + 1 << " состоит из:" << endl;
				stack_ptr[i].show();
			}
			system("pause");
			break;

		case 6:
			try 
			{
				if (total == 1)
				{
					throw "Существует только один стек";
				}
				cout << "Введите номер очереди от 1 до " << total << " на которую следует переключиться:\n(кроме " << current_number + 1 << ", так как она сейчас используется)" << endl;

				for (int i = 0; i < total; i++) // выводим все очереди на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cin >> choise;
				system("cls");
				choise--;

				if ((choise < 0) || (choise == current_number) || (choise >= total))
				{
					cout << "Некорректное значение. Переключение не выполнено" << endl;
				}
				else
				{
					current_number = choise;
					cout << "Переключение выполнено" << endl;
					cout << "Стек № " << current_number + 1 << " состоит из:" << endl;

					stack_ptr[current_number].show();
				}
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			
			system("pause");
			break;

		case 7:
			try
			{
				if(total == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Введите номер очереди c которой следует сложить от 1 до " << total << ":\n(кроме " << current_number + 1 << ", так как она сейчас используется)" << endl;

				for (int i = 0; i < total; i++) // выводим все очереди на экран
				{
					cout << "Очередь № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cin >> choise;
				choise--;

				if ((choise < 0) || (choise == current_number) || (choise >= total))
				{
					cout << "Некорректное значение. Сложение не произведено" << endl;
					system("pause");
					break;
				}
				stack_ptr[current_number] + stack_ptr[choise];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			system("pause");
			break;

		case 8:
			try
			{
				if (total == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Введите номер очереди которую следует вычесть от 1 до " << total << ":\n(кроме " << current_number + 1 << ", так как она сейчас используется)" << endl;

				for (int i = 0; i < total; i++) // выводим все очереди на экран
				{
					cout << "Очередь № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cin >> choise;
				choise--;

				if ((choise < 0) || (choise == current_number) || (choise >= total))
				{
					cout << "Некорректное значение. Вычитание не произведено" << endl;
					system("pause");
					break;
				}
				stack_ptr[current_number] - stack_ptr[choise];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			system("pause");
			break;

		case 9:
			try
			{
				if (total == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Введите номер очереди которую следует присвоить от 1 до " << total << ":\n(кроме " << current_number + 1 << ", так как она сейчас используется)" << endl;

				for (int i = 0; i < total; i++) // выводим все очереди на экран
				{
					cout << "Очередь № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cin >> choise;
				choise--;

				if ((choise < 0) || (choise == current_number) || (choise >= total))
				{
					cout << "Некорректное значение. Вычитание не произведено" << endl;
					system("pause");
					break;
				}

				stack_ptr[current_number] = stack_ptr[choise];

				stack_ptr[current_number].show();
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			system("pause");
			break;

		case 10:
			try
			{
				if (total == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Введите номер очереди которую следует сравнить с текущей от 1 до " << total << ":\n(кроме " << current_number + 1 << ", так как она сейчас используется)" << endl;

				for (int i = 0; i < total; i++) // выводим все очереди на экран
				{
					cout << "Очередь № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cin >> choise;
				choise--;

				if ((choise < 0) || (choise == current_number) || (choise >= total))
				{
					cout << "Некорректное значение. Сравнение не произведено" << endl;
					system("pause");
					break;
				}

				stack_ptr[current_number] == stack_ptr[choise];
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}
			system("pause");
			break;

		default:
			cout << "некорректный ввод" << endl;
			system("pause");
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	system("chcp 1251");

	srand(time(0)); // автоматическая рандомизация

	int menu_1 = 1; // выбор типа данных

	int* mas1 = 0; // целочисленный массив
	float* mas2 = 0;
	double* mas3 = 0;
	char* mas4 = 0;

	int size; //размер массива

	while (menu_1)
	{
		system("cls");
		cout << "С каким типом будет работать класс?" << endl;
		cout << "|0| - Выход" << endl;
		cout << "|1| - int" << endl;
		cout << "|2| - float" << endl;
		cout << "|3| - double" << endl;
		cout << "|4| - char" << endl;
		
		cin >> menu_1;

		switch (menu_1)
		{
		case 0:
			break;

		case 1:
			try
			{
				size = -60 + rand() % 119; //размер массива
				if (size <= 0)
				{
					throw "Размер созданного рандомно массива оказадся меньше или равен нулю, выберите тип данных еще раз";
				}
				mas1 = new int[size]; //выделяем память под массив размером с задданный рандомом
				for (int i = 0; i < size; i++) //заполняем массив
				{
					mas1[i] = -30 + rand() % 59;
				}

				inversion(mas1, size); //вызываем шаблонную функцию
				delete[] mas1;
			}
			catch (const char* ex)
			{
				cout << ex;
				system("pause");
			}
			break;

		case 2:
			try
			{
				size = -60 + rand() % 119; //размер массива
				if (size <= 0)
				{
					throw "Размер созданного рандомно массива оказадся меньше или равен нулю, выберите тип данных еще раз";
				}
				mas2 = new float[size]; //выделяем память под массив размером с задданный рандомом
				for (int i = 0; i < size; i++) //заполняем массив
				{
					mas2[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2);
				}

				inversion(mas2, size);
				delete[] mas2;
			}
			catch (const char* ex)
			{
				cout << ex;
				system("pause");
			}
			break;

		case 3:
			try
			{
				size = -60 + rand() % 119; //размер массива
				if (size <= 0)
				{
					throw "Размер созданного рандомно массива оказадся меньше или равен нулю, выберите тип данных еще раз";
				}
				mas3 = new double[size]; //выделяем память под массив размером с задданный рандомом
				for (int i = 0; i < size; i++) //заполняем массив
				{
					mas3[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2);
				}

				inversion(mas3, size);
				delete[] mas3;
			}
			catch (const char* ex)
			{
				cout << ex;
				system("pause");
			}
			break;

		case 4:
			try
			{
				size = -60 + rand() % 119; //размер массива
				if (size <= 0)
				{
					throw "Размер созданного рандомно массива оказадся меньше или равен нулю, выберите тип данных еще раз";
				}
				mas4 = new char[size]; //выделяем память под массив размером с задданный рандомом
				for (int i = 0; i < size; i++) //заполняем массив
				{
					mas4[i] = 65 + rand() % 56;
					//mas4[i] = 0 + rand() % 30;
				}

				inversion(mas4, size);
				delete[] mas4;
			}
			catch (const char* ex)
			{
				cout << ex;
				system("pause");
			}
			break;

		default:
			cout << "некорректный ввод" << endl;
			system("pause");
			break;
		}
	}

	myStack<int>* stack1 = 0;
	int x1 = 0;
	myStack<float>* stack2 = 0;
	float x2 = 0;
	myStack<double>* stack3 = 0;
	double x3 = 0;
	myStack<char>* stack4 = 0;
	char x4 = 0;

	int menu_2 = 1;

	while (menu_2)
	{
		system("cls");
		cout << "С каким типом будет работать класс?" << endl;
		cout << "|0| - Выход" << endl;
		cout << "|1| - int" << endl;
		cout << "|2| - float" << endl;
		cout << "|3| - double" << endl;
		cout << "|4| - char" << endl;

		cin >> menu_2;

		switch (menu_2)
		{
		case 0:
			break;

		case 1:
			work_with_stack(stack1, x1);
			break;

		case 2:
			work_with_stack(stack2, x2);
			break;

		case 3:
			work_with_stack(stack3, x3);
			break;

		case 4:
			work_with_stack(stack4, x4);
			break;

		default:
			cout << "некорректный ввод" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
