#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void all_elements(int* mass_number, int P, int N, int M)
{
    /*__asm
    {

    }*/

    int quantity_0 = (P * N * M) / 100; // количество 0 в каждой матрице

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
}

void creator(int*** array, int*** array_copy, int K, int N, int M)
{
    for (int i = 0; i < K; i++) // i - индекс текущей матрицы
    {
        array[i] = new int* [N]; // выделение памяти под N строк в каждой матрице
        array_copy[i] = new int* [N]; // выделение памяти под N строк в каждой матрице
        for (int j = 0; j < N; j++)
        {
            array[i][j] = new int[M]; // выделение памяти под M столбцов в каждой матрице
            array_copy[i][j] = new int[M]; // выделение памяти под M столбцов в каждой матрице
        }
    }
}

void zeros_finder(int*** array_copy, int& tek, int& i, int& j, int& k, int M, int N)
{
    if (j != 0) // смотрим сверху
    {
        if (array_copy[i][j - 1][k] == 0)
        {
            array_copy[i][j - 1][k] = 1;

            tek++;
            
            int new_j = j - 1;
            zeros_finder(array_copy, tek, i, new_j, k, M, N);
        }
    }

    if (k != M - 1) // смотрим справа
    {
        if (array_copy[i][j][k + 1] == 0)
        {
            array_copy[i][j][k + 1] = 1;

            tek++;
            
            int new_k = k + 1;
            zeros_finder(array_copy, tek, i, j, new_k, M, N);
        }
    }

    if (j != N - 1) // смотрим снизу
    {
        if (array_copy[i][j + 1][k] == 0)
        {
            array_copy[i][j + 1][k] = 1;

            tek++;
            
            int new_j = j + 1;
            zeros_finder(array_copy, tek, i, new_j, k, M, N);
        }
    }

    if (k != 0) // смотрим слева
    {
        if (array_copy[i][j][k - 1] == 0)
        {
            array_copy[i][j][k - 1] = 1;

            tek++;
        
            int new_k = k - 1;
            zeros_finder(array_copy, tek, i, j, new_k, M, N);
        }
    }
}

void result(int ***array_copy, int i, int N, int M) // после подсчета искомых нулей выведет результат под матрицей
{
    ofstream fout1("gera_test.txt", ios_base::app);

    int max_cnt = 0; // максимальное количество прилегающих нулей

    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < M; k++)
        {
            if (array_copy[i][j][k] == 0) // нашли новую кучку
            {
                int tek = 1; // количество нулей в текущей кучке

                array_copy[i][j][k] = 1; // чтобы больше не считать этот ноль заменяем его на 1

                zeros_finder(array_copy, tek, i, j, k, M, N); // вызываем рекурсивную функцию, которая проверит есть ли вокруг этого нуля другие
                if (tek > max_cnt) // если в текущей кучке нулей больше чем в максимальной кучке до этого...
                {
                    max_cnt = tek; // текущая кучка становится максимальной
                }
            }
        }
    }

    if (max_cnt == 1)
    {
        cout << "нет примыкающих друг к другу нулей" << endl << endl; // кончилась матрица выводим второй enter на экран
        fout1 << "нет примыкающих друг к другу нулей" << endl << endl; // кончилась матрица выводим второй enter в файл
    }
    else if (max_cnt == 0)
    {
        cout << "матрица состоит только из единиц" << endl << endl; // кончилась матрица выводим второй enter на экран
        fout1 << "матрица состоит только из единиц" << endl << endl; // кончилась матрица выводим второй enter в файл
    }
    else
    {
        cout << "максимальное количество нулей примыкающих друг к другу = " << max_cnt << endl << endl; // кончилась матрица выводим второй enter на экран
        fout1 << "максимальное количество нулей примыкающих друг к другу = " << max_cnt << endl << endl; // кончилась матрица выводим второй enter в файл
    }
}

void filling(int ***array, int ***array_copy, int* mass_number, int K, int N, int M, int P)
{
    ofstream fout;
    fout.open("gera_test.txt", ios_base::app);
    if (!fout.is_open())
    {
        cout << "Файл не может быть открыт!" << endl;
    }
    else
    {
        fout << "K = " << K << endl << "N = " << N << endl << "M = " << M << endl << "P = " << P << endl << endl;
        for (int i = 0; i < K; i++) // идем по каждой матрице
        {
            int* mass_index = new int[N * M]; // массив используемых индексов...

            for (int i = 0; i < N * M; i++) // заполняем...
            {
                mass_index[i] = -1; // отрицательным значением чтобы не перепутать с индексом
            }
            int ind = 0; // индекс массива индексов

            int left = 0;
            int right = N * M - 1;
            int right_value = 0;

            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    
                    int error; // признак того, что случайный индекс уже был использован
                    int index; // индекс массива всех возможных элементов матриц
                    do
                    {
                        error = 0; // сбрасываем признак ошибки
                        index = left + rand() % ((N * M) - left - right_value); // генерим случайное значение

                        for (int i = 0; i < N * M && mass_index[i] != -1; i++) // пробигаем по всему массиву индексов
                        {
                            if (mass_index[i] == index) // если окажется, что случайный индекс уже встречался...
                            {
                                error = 1; // поднимаем флаг
                                break; // и сразу выходим
                            }
                        }
                    } while (error == 1); // будем повторять пока не найдем уникальный индекс
                    
                    int flag;
                    if (index == left && left != right)
                    {
                        left++;
                        
                        do
                        {
                            flag = 0;
                            for (int i = 0; i < N * M && mass_index[i] != -1; i++) // пробигаем по всему массиву индексов
                            {
                                if (mass_index[i] == left) // 
                                {
                                    left++;
                                    flag = 1;
                                    break;
                                }
                            }
                        } while (flag != 0);
                    }

                    if (index == right && left != right)
                    {
                        right--;
                        right_value++;
                        do
                        {
                            flag = 0;
                            for (int i = 0; i < N * M && mass_index[i] != -1; i++) // пробигаем по всему массиву индексов
                            {
                                if (mass_index[i] == right) // 
                                {
                                    right--;
                                    right_value++;
                                    flag = 1;
                                    break;
                                }
                            }
                        } while (flag != 0);
                    }

                    mass_index[ind++] = index; // так как этот индекс ни разу не встречался - запоминаем его

                    array[i][j][k] = mass_number[index]; // то число которое было под этим индексом вставляем в матрицу
                    array_copy[i][j][k] = array[i][j][k]; // копируем это число в копию матрицы

                    cout << array[i][j][k] << " "; // вывод на экран
                    fout << array[i][j][k] << " "; // вывод в файл
                }
                cout << endl; // кончилась строка выводим enter на экран
                fout << endl; // кончилась строка выводим enter в файл
            }

            delete[] mass_index; // удаляем массив индексов, так как для работы с текущей матрицей он больше не нужен

            result(array_copy, i, N, M); // после подсчета искомых нулей выведет результат под матрицей
        }
        fout.close();
    }
}

void deliter(int*** array, int*** array_copy , int K, int N) // удаление массива и его копии
{
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
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int N; // количество строк
    int M; // количество столбцов
    int K; // количество исходных матриц
    int P; // процент нулей

    ofstream fout;
    fout.open("gera_test.txt", ios_base::trunc);
    if (!fout.is_open())
    {
        cout << "Файл не может быть открыт!" << endl;
    }
    else
    {
        fout.close();
    }

    cout << "Введите K (количество исходных матриц) ";
    cin >> K;

    cout << "Введите N (количество строк) ";
    cin >> N;

    cout << "Введите M (количество столбцов) ";
    cin >> M;

    cout << "Введите процент нулей ";
    cin >> P;
    cout << endl;

    int* mass_number = new int[N * M]; // массив в котором храняться все возможные элементы матриц
    all_elements(mass_number, P, N, M); // заполняем этот массив

    int*** array = new int** [K]; // массив всех матриц
    int*** array_copy = new int** [K]; // копия массива всех матриц
    creator(array, array_copy, K, N, M); // выделяем память под все матрицы и под их копии

    filling(array, array_copy, mass_number, K, N, M, P); // заполнение матриц рандомными значениями, а также вывод на экран и в файл вместе с значением нулей

    delete[] mass_number; // удаляем массив элементов, так как все матрицы уже заполнены

    deliter(array, array_copy, K, N); // удаление массива и его копии



     // чтение из файла
        // ввод матрицы в результирующий файл
        // подсчет количества нулей
        // вывод количества нулей

    return 0;
}
