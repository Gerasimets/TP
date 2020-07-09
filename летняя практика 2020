#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int N; // количество строк
    int M; // количество столбцов
    int K; // количество исходных матриц
    int P; // процент нулей
    int cnt = 0; // счетчик нулей

    cout << "Введите K (количество исходных матриц) ";
    cin >> K;

    cout << "Введите N (количество строк) ";
    cin >> N;

    cout << "Введите M (количество столбцов) ";
    cin >> M;

    cout << "Введите процент нулей ";
    cin >> P;

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

    int*** array = new int** [K]; // создание массива для K двумерных матриц
    for (int i = 0; i < K; i++) 
    {
        array[i] = new int* [N]; // выделение памяти под N строк
        for (int j = 0; j < N; j++) 
        {
            array[i][j] = new int[M]; // выделение памяти под N столбцов
        }
    }

    // заполнение рандомными значениями
    for (int i = 0; i < K; i++)
    {
        int* mass_index = new int[N * M]; // массив используемых индексов
        for (int i = 0; i < N * M; i++) // заполняем
        {
            mass_index[i] = -1; // отрицательным значением чтобы не перепутать с индексом
        }
        int cnt = 0;

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++) 
            {
                int error;
                int index;
                do
                {
                    error = 0;
                    index = 0 + rand() % (N * M);

                    for (int i = 0; i < N * M; i++)
                    {
                        if (mass_index[i] == index)
                        {
                            error = 1;
                            break;
                        }
                    }

                    if (error == 0)
                    {
                        mass_index[cnt++] = index;
                    }

                } while (error == 1);

                array[i][j][k] = mass_number[index];

                ofstream fout("gera_test.txt", ios_base::app);/////////////////////////////////////////////////////////////////////
                if (!fout.is_open())
                {
                    cout << "Файл не может быть открыт!" << endl;
                }
                else
                {
                    if (k == M - 1)
                    {
                        fout << array[i][j][k] << endl;
                    }
                    else 
                    {
                        fout << array[i][j][k] << " ";
                    }

                    if (k == M - 1 and j == N - 1)
                    {
                        fout << endl;
                    }
                    
                    fout.close();
                }

                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // уничтожение
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
