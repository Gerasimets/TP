//#include <iostream>
//#include <iomanip>
#include "myStack.h"
//#include <ctime>

using namespace std;

template <class T1>
void inversion(T1* mas, int size)
{
	cout << "Размер массива: ";
	cout << size << endl; // выводим размер массива
	T1* mass_tmp = new T1[size]; //выделяем память под временный массив
	cout << "Элементы массива до инверсии:" << endl;
	for (int i = 0; i < size; i++)
	{
		mass_tmp[i] = mas[i]; //перезаписываем оригинальный во временный
		cout.setf(ios::fixed);
		cout << setprecision(4) << mass_tmp[i] << " ";
	}
	cout << endl;

	cout << "Элементы массива после инверсии:" << endl;
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
	cout << "Введите размер стека: ";
	cin >> S;
	T2 first_stack(S); //создаем новый объект, используя конструктор с параметром
	stack_ptr = new T2[1]; //выделяем память под стек [1] - размер стека
	stack_ptr[0] = first_stack; // в нулевую ячейку кледем наш первый стек
	int menu2 = 1; // выбор пользователя в меню второго задания
	int all_stack = 1; // общее количество стеков или индекс последней созданной
	int number_this_stack = 0; // номер текущего стека
	T2* stack_tmp; //временный массив стеков
	T3 val; //значение
	int choise; // номер выбранного пользователем стека

	while (menu2)
	{
		system("cls");
		cout << "Используется стек № " << number_this_stack + 1 << endl;
		cout << "| 0| - Выбрать другой тип данных" << endl;
		cout << "| 1| - Добавление элемента к текущему стеку" << endl;
		cout << "| 2| - Извлечение элемента из текущего стека" << endl;
		cout << "| 3| - Вывод текущего стека на экран" << endl;
		cout << "| 4| - Создание нового стека и переключение на него" << endl;
		cout << "| 5| - Вывод всех стеков" << endl;
		cout << "| 6| - Выбор другого стека" << endl;
		cout << "| 7| - Сложить два стека" << endl;
		cout << "| 8| - Вычесть из одного стека другой" << endl;
		cout << "| 9| - Присвоить один стек к другому" << endl;
		cout << "|10| - Сравнение двух стеков" << endl;
		cin >> menu2;
		//system("cls");

		switch (menu2)
		{
		case 0:
			delete[] stack_ptr;
			break;

		case 1:
			cout << "Введите новый элемент стека: ";
			cin >> val;
			stack_ptr[number_this_stack].push(val); // добавляем новый элемент
			cout << "Элементы стека: ";
			stack_ptr[number_this_stack].show();
			system("pause");
			break;

		case 2:
			try
			{
				if (stack_ptr[number_this_stack].empty() == 0)
				{
					throw "Невозможно извлечь элемент из пустого стека";
				}
				stack_ptr[number_this_stack].pop();
				cout << "Элементы стека: ";
				stack_ptr[number_this_stack].show();
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			system("pause");
			break;

		case 3:
			cout << "Используется стек № " << number_this_stack + 1 << endl;
			cout << "Элементы стека: ";
			stack_ptr[number_this_stack].show();
			system("pause");
			break;

		case 4:
			try
			{
				for (int i = 0; i < all_stack; i++)
				{
					if (stack_ptr[i].empty() == 0)
					{
						throw i;
					}
				}

				number_this_stack = all_stack; // текущий стек будет равен номеру всех стеков (допустим кол-во стеков 1, номер текущего был 0, теперь станет 1)
				cout << "Переключение на новый стек выполнено" << endl;

				stack_tmp = new T2[all_stack]; // создаем временный массив стеков размером с количество имеющихся стеков

				for (int i = 0; i < all_stack; i++) // копируем все стеки во временный массив
				{
					stack_tmp[i] = stack_ptr[i];
				}

				delete[] stack_ptr;

				stack_ptr = new T2[++all_stack]; // выделяем память в старом массиве стеков под новое количество стеков

				for (int i = 0; i < all_stack - 1; i++) // копируем все стеки из временного массива стеков в старый массив стеков
				{
					stack_ptr[i] = stack_tmp[i];
				}

				delete[] stack_tmp; // временный больше не нужен

				cout << "Введите размер нового стека: ";
				cin >> S;

				for (int i = 0; i < S; i++)
				{
					stack_ptr[number_this_stack].push((130.0 + rand() % 56) / (2.0 + rand() % 2));
				}

				cout << "Номер текущего стека: " << number_this_stack + 1 << endl;
				cout << "Элементы стека: ";
				stack_ptr[number_this_stack].show();
			}
			catch (const int i)
			{
				cout << "Стек под номером " << i + 1 << " пуст, продолжите работу в нем" << endl;
				number_this_stack = i;

				for (int i = 0; i < all_stack; i++) // выводим все стеки на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}
			}
			system("pause");
			break;

		case 5:
			for (int i = 0; i < all_stack; i++) // выводим все стеки на экран
			{
				cout << "Стек № " << i + 1 << " состоит из:" << endl;
				stack_ptr[i].show();
			}
			system("pause");
			break;

		case 6:
			try
			{
				if (all_stack == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Выберете стек, с которым хотите работать (от 1 до " << all_stack << ")" << endl;
				cout << "(кроме " << number_this_stack + 1 << ", так как вы сейчас с ним работаете)" << endl;

				for (int i = 0; i < all_stack; i++) // выводим все стеки на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cout << "Какой стек выбираете?" << endl;
				cin >> choise;
				system("cls");
				choise--; //( допустим для пользователя это 2 стек, а для программы 1, поэтому -- для корректной работы)

				if ((choise < 0) || (choise == number_this_stack) || (choise >= all_stack)) //выбранный стек не должен быть меньше 0, равняься текущему(с которым работает пользователь,
																							//не должен быть больше или равен количеству всех стеков(кол-во стеков 2, то есть это 0 и 1)
				{
					cout << "Некорректное значение. Переключение не выполнено" << endl;
				}
				else
				{
					number_this_stack = choise;
					cout << "Переключение выполнено" << endl;
					cout << "Стек № " << number_this_stack + 1 << " состоит из:" << endl;

					stack_ptr[number_this_stack].show();
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
				if (all_stack == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Выберете стек, с которым хотите произвести сложение (от 1 до " << all_stack << ")" << endl;
				cout << "(кроме " << number_this_stack + 1 << ", так как вы сейчас с ним работаете)" << endl;
				for (int i = 0; i < all_stack; i++) // выводим все стеки на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cout << "Какой стек выбираете?" << endl;
				cin >> choise;
				choise--; //( допустим для пользователя это 2 стек, а для программы 1, поэтому -- для корректной работы)

				if ((choise < 0) || (choise == number_this_stack) || (choise >= all_stack)) //выбранный стек не должен быть меньше 0, равняься текущему(с которым работает пользователь,
																							//не должен быть больше или равен количеству всех стеков(кол-во стеков 2, то есть это 0 и 1)
				{
					cout << "Некорректное значение. Сложение не произведено" << endl;
					system("pause");
					break;
				}
				stack_ptr[number_this_stack] + stack_ptr[choise]; //складываем стеки, вызываем перегруженный +
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
				if (all_stack == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Выберете стек, который хотите вычесть (от 1 до " << all_stack << ")" << endl;
				cout << "(кроме " << number_this_stack + 1 << ", так как вы сейчас с ним работаете)" << endl;

				for (int i = 0; i < all_stack; i++) // выводим все стеки на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cout << "Какой стек выбираете?" << endl;;
				cin >> choise;
				choise--; //( допустим для пользователя это 2 стек, а для программы 1, поэтому -- для корректной работы)

				if ((choise < 0) || (choise == number_this_stack) || (choise >= all_stack)) //выбранный стек не должен быть меньше 0, равняься текущему(с которым работает пользователь,
																							//не должен быть больше или равен количеству всех стеков(кол-во стеков 2, то есть это 0 и 1)
				{
					cout << "Некорректное значение. Вычитание не произведено" << endl;
					system("pause");
					break;
				}
				stack_ptr[number_this_stack] - stack_ptr[choise]; // вычитаем стеки, перегруженный -
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
				if (all_stack == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Выберете стек, который хотите присвоить (от 1 до " << all_stack << ")" << endl;
				cout << "(кроме " << number_this_stack + 1 << ", так как вы сейчас с ним работаете)" << endl;

				for (int i = 0; i < all_stack; i++) // выводим все стеки на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cout << "Какой стек выбираете?" << endl;;
				cin >> choise;
				cout << "Стеку №" << number_this_stack + 1 << " будет присвоен стек №" << choise << endl;
				choise--; //( допустим для пользователя это 2 стек, а для программы 1, поэтому -- для корректной работы)

				if ((choise < 0) || (choise == number_this_stack) || (choise >= all_stack)) //выбранный стек не должен быть меньше 0, равняься текущему(с которым работает пользователь,
																							//не должен быть больше или равен количеству всех стеков(кол-во стеков 2, то есть это 0 и 1)
				{
					cout << "Некорректное значение. Вычитание не произведено" << endl;
					system("pause");
					break;
				}

				stack_ptr[number_this_stack] = stack_ptr[choise]; //в текущий стек кладем(присваиваем) выбранный, перегруженное =

				/*cout << "Выбранный стек состоит из: ";
				stack_ptr[choise].show();*/

				cout << "Текущий стек после изменений: ";
				stack_ptr[number_this_stack].show();
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
				if (all_stack == 1)
				{
					throw "Существует только один стек";
				}

				cout << "Выберете стек, с которым хотите сравнить (от 1 до " << all_stack << ")" << endl;
				cout << "(кроме " << number_this_stack + 1 << ", так как вы сейчас с ним работаете)" << endl;

				for (int i = 0; i < all_stack; i++) // выводим все стеки на экран
				{
					cout << "Стек № " << i + 1 << " состоит из:" << endl;
					stack_ptr[i].show();
				}

				cout << "Какой стек выбираете?" << endl;;
				cin >> choise;
				choise--; //( допустим для пользователя это 2 стек, а для программы 1, поэтому -- для корректной работы)

				if ((choise < 0) || (choise == number_this_stack) || (choise >= all_stack)) //выбранный стек не должен быть меньше 0, равняься текущему(с которым работает пользователь,
																							//не должен быть больше или равен количеству всех стеков(кол-во стеков 2, то есть это 0 и 1)
				{
					cout << "Некорректное значение. Сравнение не произведено" << endl;
					system("pause");
					break;
				}

				stack_ptr[number_this_stack] == stack_ptr[choise]; //сравниваем, вызывается перегруженный ==
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
	char**mas5 = 0;

	int size; //размер массива

	while (menu_1)
	{
		system("cls");
		cout << "Задание №1 - инверсия массива" << endl;
		cout << "Выберете тип данных" << endl;
		cout << "|0| - Переход ко второму заданию" << endl;
		cout << "|1| - int" << endl;
		cout << "|2| - float" << endl;
		cout << "|3| - double" << endl;
		cout << "|4| - char" << endl;
		cout << "|5| - char*" << endl;

		cin >> menu_1;

		switch (menu_1)
		{
		case 0:
			break;

		case 1:
			try
			{
				size = -10 + rand() % 40; // размер массива
				if (size <= 0)
				{
					throw "Размер созданного рандомно массива оказался меньше или равен нулю, выберите тип данных еще раз";
				}
				mas1 = new int[size]; //выделяем память под массив размером с задданный рандомом

				for (int i = 0; i < size; i++) //заполняем массив
				{
					mas1[i] = -30 + rand() % 60;
				}

				inversion(mas1, size); //вызываем шаблонную функцию
				delete[] mas1;
			}
			catch (const char* ex)
			{
				cout << ex << endl;
				system("pause");
			}
			break;

		case 2:
			try
			{
				size = -10 + rand() % 40; //размер массива
				if (size <= 0)
				{
					throw "Размер созданного рандомно массива оказался меньше или равен нулю, выберите тип данных еще раз";
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
				cout << ex << endl;
				system("pause");
			}
			break;

		case 3:
			try
			{
				size = -10 + rand() % 40; //размер массива
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
				cout << ex << endl;
				system("pause");
			}
			break;

		case 4:
			try
			{
				size = -10 + rand() % 40; //размер массива
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
				cout << ex << endl;
				system("pause");
			}
			break;

		case 5:
			try
			{
				size = -10 + rand() % 40; //размер массива
				if (size <= 0)
				{
					throw "Размер созданного рандомно массива оказадся меньше или равен нулю, выберите тип данных еще раз";
				}
				mas5 = new char*[size]; //выделяем память под массив размером с задданный рандомом

				for (int i = 0; i < size; i++) // заполняем массив
				{
					int j;
					int size_str = 2 + rand() % 30;
					mas5[i] = new char[size_str];
					for (j = 0; j < size_str; j++)
					{
						mas5[i][j] = 65 + rand() % 56;
						//mas5[i] = 0 + rand() % 30;
					}
					mas5[i][--j] = '\0'; //
				}
				
				inversion(mas5, size);

				for (int i = 0; i < size; i++)
				{
					delete[] mas5[i];
				}
				delete[] mas5;
			}
			catch (const char* ex)
			{
				cout << ex << endl;
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
		cout << "Задание №2 - стек" << endl;
		cout << "С каким типом будет работать стек?" << endl;
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
