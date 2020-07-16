#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

void all_elements(int* mass_number, int P, int N, int M)
{
    /*int quantity_0 = (P * N * M) / 100; // количество 0 в каждой матрице

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
    }*/

    __asm
    {
        mov eax, P // вставляем P
        mul N // домножаем P на N
        mul M // P * N * M
        mov ebx, 100 // вставляем 100
        div ebx // P * N * M / 100
        mov ebx, eax // теперь в ebx находится quantity_0

        mov eax, N // вставляем N
        mul M // домножаем на M
        mov edx, eax // теперь в edx находится N * M (количество элементов)

        xor ecx, ecx // обнуляем ecx
        mov esi, mass_number // в esi теперь адресс массива mass_number

        start: // заполнение текущего элемента массива
        cmp ecx, edx // сравниваем счетчик с количеством элементов
        je End // если они равны, значит мы прошли все элементы
        cmp ebx, 0 // если не равны, сравниваем счетчик нулей с нулем
        je one // если счетчик нулей равен нулю переходим на one

        xor eax, eax // обнуляем eax
        mov [esi], eax // кладем 0 в текущий элемент массива
        dec ebx // уменьшаем счетчик нулей
        jmp finish // переходим на finish

        one: // заполнение текущего эдемента массива единицей
        mov eax, 1 // вставляем 1
        mov [esi], eax // текущий элемент массива равен 1

        finish: // в конце любого заполнения...
        add esi, 4 // увеличиваем адресс текущего элемента на 4, так как у нас int
        inc ecx // увеличиваем счетчик, так как заполнили новый элемент
        jmp start // возвращаемся чтобы заполнить следующий элемент

        End: // все элементы заполнены
    }
}

void creator(int*** array, int K, int N, int M)
{
    for (int i = 0; i < K; i++) // i - индекс текущей матрицы
    {
        array[i] = new int* [N]; // выделение памяти под N строк в каждой матрице
        for (int j = 0; j < N; j++)
        {
            array[i][j] = new int[M]; // выделение памяти под M столбцов в каждой матрице
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
    ofstream fout1("gera_test1.txt", ios_base::app);

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

void filling(int ***array, int* mass_number, int K, int N, int M, int P)
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

            int left = 0; // левая граница массива элементов
            int right = N * M - 1; // правая граница массива элементов

            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    int error; // признак того, что случайный индекс уже был использован
                    int index; // индекс массива всех возможных элементов матриц
                    do
                    {
                        error = 0; // сбрасываем признак ошибки
                        
                        index = left + rand() % (right - left + 1); // генерим случайное значение учитывая границы (+1, так как right это индекс)

                        for (int i = 0; i < N * M && mass_index[i] != -1; i++) // пробигаем по всему массиву индексов
                        {
                            if (mass_index[i] == index) // если окажется, что случайный индекс уже встречался...
                            {
                                error = 1; // поднимаем флаг
                                break; // и сразу выходим
                            }
                        }
                    } while (error == 1); // будем повторять пока не найдем уникальный индекс
                    
                    int flag; // признак того, что граница была найдена
                    if (index == left && left != right) // если рандомное число совпадает с левой границей...
                    {
                        left++; // левая граница меняется
                        do
                        {
                            flag = 0; // сбрасываем флаг
                            for (int i = 0; i < N * M && mass_index[i] != -1; i++) // смотрим во всем массиве...
                            {
                                if (mass_index[i] == left) // есть ли там новая левая граница
                                {
                                    left++; // если есть, то левая граница меняется
                                    flag = 1; // флаг поднимается
                                    break; // нет смысла продолжать цикл
                                }
                            }
                        } while (flag != 0); // если граница поменялась, то надо проверить опять
                    }

                    if (index == right && left != right) // если рандомное число совпало с правой границей
                    {
                        right--; // двигаем правую границу
                        do
                        {
                            flag = 0; // сбрасываем флаг
                            for (int i = 0; i < N * M && mass_index[i] != -1; i++) // пробигаем по всему массиву индексов
                            {
                                if (mass_index[i] == right) // если нашли правую границу
                                {
                                    right--; // двигаем ее
                                    flag = 1; // флаг поднимаем
                                    break; // граница изменилась, надо пройти цикл заного
                                }
                            }
                        } while (flag != 0); // пока не окажется что граница не менялась
                    }

                    mass_index[ind++] = index; // так как этот индекс ни разу не встречался - запоминаем его

                    array[i][j][k] = mass_number[index]; // то число которое было под этим индексом вставляем в матрицу
                    fout << array[i][j][k] << " "; // вывод в файл
                }
                fout << endl; // кончилась строка выводим enter в файл
            }
            delete[] mass_index; // удаляем массив индексов, так как для работы с текущей матрицей он больше не нужен
            fout << endl;
        }
        fout.close();
    }
}

void input(int*** array, int*** array_copy, int K, int N, int M, int P) // ввод в файл с результатом
{
    ofstream fout2;
    fout2.open("gera_test1.txt", ios_base::app);
    if (!fout2.is_open())
    {
        cout << "Файл не может быть открыт!" << endl;
    }
    else
    {
        ifstream fin("gera_test.txt"); // открыли файл для чтения
        if (!fin.is_open())
        {
            cout << "Файл не может быть открыт!" << endl;
        }
        else
        {
            string line; // Строчка текста

            fout2 << "K = " << K << endl << "N = " << N << endl << "M = " << M << endl << "P = " << P << endl << endl;

            int in = 4; // первые 4 строчки пропускаем
            while (in >= 0)
            {
                if (in > 0)
                {
                    in--;
                    int a;
                    char space;
                    fin >> space >> space >> a;
                }
                else
                {
                    in--;
                    for (int i = 0; i < K; i++) // идем по каждой матрице
                    {
                        for (int j = 0; j < N; j++)
                        {
                            for (int k = 0; k < M; k++)
                            {
                                fin >> array[i][j][k];
                                cout << array[i][j][k] << " "; // вывод на экран
                                fout2 << array[i][j][k] << " "; // вывод в файл
                                array_copy[i][j][k] = array[i][j][k]; // и в копию
                            }
                            cout << endl; // кончилась строка выводим enter на экран
                            fout2 << endl; // вывод в файл
                            getline(fin, line);
                        }
                        result(array_copy, i, N, M); // после подсчета искомых нулей выведет результат под матрицей
                        getline(fin, line);
                    }
                }
            }
            fout2.close();
        }
        fin.close();
    }
}

void deliter(int*** array, int K, int N) // удаление массива
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
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
    fout.open("gera_test.txt", ios_base::trunc); // удаляем старое содержимое файла
    if (!fout.is_open())
    {
        cout << "Файл не может быть открыт!" << endl;
    }
    else
    {
        fout.close();
        ofstream fout3;
        fout3.open("gera_test1.txt", ios_base::trunc); // удаляем старое содержимое файла
        if (!fout3.is_open())
        {
            cout << "Файл не может быть открыт!" << endl;
        }
        else
        {
            fout3.close();
            
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
            creator(array, K, N, M); // выделяем память под все матрицы

            filling(array, mass_number, K, N, M, P); // заполнение матриц рандомными значениями

            delete[] mass_number; // удаляем массив элементов, так как все матрицы уже заполнены

            deliter(array, K, N); // удаление массива

            /*обнуляем переменные чтобы взять их из файла*/
            N = 0; // количество строк
            M = 0; // количество столбцов
            K = 0; // количество исходных матриц
            P = 0; // процент нулей

            ifstream fin("gera_test.txt"); // открыли файл для чтения
            if (!fin.is_open())
            {
                cout << "Файл не может быть открыт!" << endl;
            }
            else
            {
                char space; // пустой символ для корректного считывания
                /*считываем переменные*/
                fin >> space >> space >> K;
                fin >> space >> space >> N;
                fin >> space >> space >> M;
                fin >> space >> space >> P;

                int*** array = new int** [K]; // массив всех матриц
                int*** array_copy = new int** [K]; // копия массива всех матриц
                creator(array, K, N, M); // выделяем память под все матрицы и под их копии
                creator(array_copy, K, N, M); // выделяем память под все матрицы и под их копии

                input(array, array_copy, K, N, M, P); // ввод в исходный файл вместе с результатом

                deliter(array_copy, K, N); // удаление массива и его копии
                deliter(array, K, N); // удаление массива и его копии

                fin.close();
            }
        }
    }
    return 0;
}
