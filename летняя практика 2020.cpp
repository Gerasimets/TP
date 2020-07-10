#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void recurs(int &counter, int*** array_copy, int &tek, int& i, int &j , int & k, int &M, int &N)
{
    if (j != 0) // смотрим сверху
    {
        if (array_copy[i][j - 1][k] == 0)
        {
            array_copy[i][j - 1][k] = 1;

            tek++;
            if (tek > counter)
            {
                counter = tek;
            }
            int js = j - 1;
            recurs(counter, array_copy, tek, i, js, k, M, N);
        }
    }

    if (k != M - 1) // смотрим справа
    {
        if (array_copy[i][j][k + 1] == 0)
        {
            array_copy[i][j][k + 1] = 1;

            tek++;
            if (tek > counter)
            {
                counter = tek;
            }
            int ks = k + 1;
            recurs(counter, array_copy, tek, i, j, ks, M, N);
        }
    }

    if (j != N - 1) // смотрим снизу
    {
        if (array_copy[i][j + 1][k] == 0)
        {
            array_copy[i][j + 1][k] = 1;

            tek++;
            if (tek > counter)
            {
                counter = tek;
            }
            int js = j + 1;
            recurs(counter, array_copy, tek, i, js, k, M, N);
        }
    }

    if (k != 0) // смотрим слева
    {
        if (array_copy[i][j][k - 1] == 0)
        {
            array_copy[i][j][k - 1] = 1;

            tek++;
            if (tek > counter)
            {
                counter = tek;
            }
            int ks = k - 1;
            recurs(counter, array_copy, tek, i, j, ks, M, N);
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int N; // количество строк
    int M; // количество столбцов
    int K; // количество исходных матриц
    int P; // процент нулей

    cout << "Введите K (количество исходных матриц) ";
    cin >> K;

    cout << "Введите N (количество строк) ";
    cin >> N;

    cout << "Введите M (количество столбцов) ";
    cin >> M;

    cout << "Введите процент нулей ";
    cin >> P;
    cout << endl;

    int quantity_0 = (P * N * M) / 100; // количество 0 в каждой матрице

    int* mass_number = new int[N * M]; // массив в котором храняться все возможные элементы матриц

    for (int i = 0; i < N * M; i++) // заполняем массив элементов
    {
        if (quantity_0 != 0) // сначала используем все нули
        {
            mass_number[i] = 0;
            quantity_0--;
        }
        else
        {
            mass_number[i] = 1; // остальное заполняем единицами
        }
    }

    int*** array = new int** [K]; // создание массива и выделение памяти для K двумерных матриц
    int*** array_copy = new int** [K];
    for (int i = 0; i < K; i++) 
    {
        array[i] = new int* [N]; // выделение памяти под N строк
        array_copy[i] = new int* [N]; // выделение памяти под N строк
        for (int j = 0; j < N; j++) 
        {
            array[i][j] = new int[M]; // выделение памяти под M столбцов
            array_copy[i][j] = new int[M]; // выделение памяти под M столбцов
        }
    }

    /*заполнение рандомными значениями*/
    ofstream fout("gera_test.txt", ios_base::app);
    if (!fout.is_open())
    {
        cout << "Файл не может быть открыт!" << endl;
    }
    else
    {
        fout << "K = " << K << endl << "N = " << N << endl << "M = "<< M << endl << "P = " << P << endl << endl;
        for (int i = 0; i < K; i++) // идем по каждой матрице
        {
            int* mass_index = new int[N * M]; // массив используемых индексов...

            int ind; // индекс массива индексов
            for (ind = 0; ind < N * M; ind++) // заполняем...
            {
                mass_index[ind] = -1; // отрицательным значением чтобы не перепутать с индексом
            }
            ind = 0;

            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    int error; // признак того, что случайный индекс уже был использован
                    int index; // индекс массива всех возможных элементов матриц
                    do
                    {
                        error = 0; // сбрасываем признак ошибки
                        index = 0 + rand() % (N * M); // генерим случайное значение

                        for (int i = 0; i < N * M; i++) // пробигаем по всему массиву индексов
                        {
                            if (mass_index[i] == index) // если окажется, что случайный индекс уже встречался...
                            {
                                error = 1; // поднимаем флаг
                                break; // и сразу выходим
                            }
                        }
                    } while (error == 1); // будем повторять пока не найдем уникальный индекс

                    mass_index[ind++] = index; // так как этот индекс ни разу не встречался - запоминаем его

                    array[i][j][k] = mass_number[index]; // то число которое было под этим индексом вставляем в матрицу
                    array_copy[i][j][k] = mass_number[index]; // то число которое было под этим индексом вставляем в матрицу

                    cout << array[i][j][k] << " "; // вывод на экран
                    fout << array[i][j][k] << " "; // вывод в файл
                }
                cout << endl; // кончилась строка выводим enter на экран
                fout << endl; // кончилась строка выводим enter в файл
            }

            // надо удалить mass_index//////////////////////////////////////////////////////////////

            int counter = 0; // максимальное количество прилегающих нулей
            int tek = 0;
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    if (array_copy[i][j][k] == 0)
                    {
                        array_copy[i][j][k] = 1;

                        tek++;
                        if (tek > counter)
                        {
                            counter = tek;
                        }

                        recurs(counter, array_copy, tek, i, j, k, M, N);

                        tek = 0;
                    }
                }
            }

            if (counter == 1)
            {
                cout << "нет примыкающих друг к другу нулей" << endl << endl; // кончилась матрица выводим второй enter на экран
                fout << "нет примыкающих друг к другу нулей" << endl << endl; // кончилась матрица выводим второй enter в файл
            }
            else if (counter == 0)
            {
                cout << "при заданном проценте нулей нет" << endl << endl; // кончилась матрица выводим второй enter на экран
                fout << "при заданном проценте нулей нет" << endl << endl; // кончилась матрица выводим второй enter в файл
            }
            else
            {
                cout << "максимальное количество нулей примыкающих друг к другу = " << counter << endl << endl; // кончилась матрица выводим второй enter на экран
                fout << "максимальное количество нулей примыкающих друг к другу = " << counter << endl << endl; // кончилась матрица выводим второй enter в файл
            }
        }
        fout.close();
    }

    // удалить mass_number///////////////////////////////////////////////////////////////////////

    /*уничтожение*/
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            delete[] array[i][j];
            delete[] array_copy[i][j];
        }
        delete[] array[i];
        delete[] array_copy[i];
    }
    delete[] array;
    delete[] array_copy;

    return 0;
}
