#include "stack.h"
#include <iostream>
#include<cmath>
#include <ctime>
#include <clocale>
#include <iomanip>
#include <conio.h>
using namespace std;
template<typename T>
T WorkMass(T *mass,int n) {
	
	for (inti = 0, j = n - 1; i< n / 2; i++, j--) {
		swap(mass[i], mass[j]);

	}
	cout<<endl<< "Инверсия массива" <<endl;
	return *mass;
};
template<typename T >
voidWorkStack(T *stack) {
	T s1; s1.push();
	cout<<endl;
	T s2; s2.push();
	T s3;
	intnum;
	do {
		system("pause");
		system("cls");
		cout<< "Рабочиестеки->\n" << "s1 ";
		s1.show();
		cout<<endl<< "s2 ";
		s2.show();
		cout<< "Выберитедействие->\n|1|-Присваиваниестеков\n|2|-Сравнениестеков\n|3|-Сложение\n|4|-Вычитание\n|5|-Выход\n";
		cin>>num;

		switch (num) {
		case 1:
			cout<< "|1|-s1=s2\n|2|-s2=s1\n->";
			cin>>num;
			switch (num)
			{
			case 1:
				s1 = s2;
				break;
			case 2:
				s2 = s1;
				break;
			}
			break;
		case 2:
			if (s1 == s2) cout<< "Стекиравны" <<endl;
			elsecout<< "Стеки не равны" <<endl;
			break;
		case 3:
			s1 = s1 + s2;
			break;
		case 4:
			s1 = s1 - s2;
			break;
		case 5:
			break;
		}
	} while (num != 5);
}
void task1() {
	int *mass1 = 0, num;
	float *mass2 = 0;
	double *mass3 = 0;
	char *mass4 = 0;
	int n;
	do {
		system("cls");
		cout<< "нажмите на любую клавишу\n";
		while (!_kbhit()) {
			n = rand() % 30;
		}
		system("cls");
		cout<< "Заданразмермассива->" <<n<<endl;
		cout<< "Выберетeтипмасиива\n|1|-int\n|2|-float\n|3|-double\n|4|-char\n|5|-exit\n->";
		cin>>num;

		switch (num)
		{
		case 1:
			mass1 = new int[n];
			for (inti = 0; i< n; i++) {
				mass1[i] = rand() % 20;
				cout<< mass1[i] << " ";
			}
			WorkMass(mass1, n);
			for (inti = 0; i< n; i++) {
				cout<< mass1[i] << " ";
			}
			cout<<endl;
			system("pause");
			break;
		case 2:
			mass2 = new float[n];

			for (inti = 0; i< n; i++) {
				mass2[i] = rand() / float(RAND_MAX) * 20;
				cout<<setprecision(2) << fixed << mass2[i] << " ";
			}
			WorkMass(mass2, n);
			for (inti = 0; i< n; i++) {
				cout<<setprecision(2) << fixed << mass2[i] << " ";
			}
			cout<<endl;
			system("pause");
			break;
		case 3:
			mass3 = new double[n];
			for (inti = 0; i< n; i++) {
				mass3[i] = rand() / double(RAND_MAX) * 20;
				cout<<setprecision(3) << fixed << mass3[i] << " ";
			}
			WorkMass(mass3, n);
			for (inti = 0; i< n; i++) {
				cout<<setprecision(3) << fixed << mass3[i] << " ";
			}
			cout<<endl;
			system("pause");
			break;
		case 4:
			mass4 = new char[n];
			for (inti = 0; i< n; i++) {
				mass4[i] = rand() / char(RAND_MAX) * 20;
				cout<< mass4[i] << " ";
			}
			WorkMass(mass4, n);
			for (inti = 0; i< n; i++) {
				cout<< mass4[i] << " ";
			}
			cout<<endl;
			system("pause");
			break;
		}
	} while (num != 5);
}

void task2() {
	stack<int> *s_int=0;
	stack<float> *s_float=0;
	stack<double> *s_double=0;
	stack<char> *s_cahr = 0;
	intnum;
	cout<< "Выберитетипстека->\n|1|-int\n|2|-float\n|3|-double\n|4|-char\n->";
	cin>>num;
	switch (num) {
	case 1:
		s_int = new stack<int>;
		WorkStack(s_int);
		delete[] s_int;
		break;
	case 2:
		s_float = new stack<float>;
		WorkStack(s_float);
		delete[] s_float;
		break;
	case 3:
		s_double = new stack<double>;
		WorkStack(s_double);
		delete[] s_double;
		break;
	case 4:
		s_cahr = new stack<char>;
		WorkStack(s_cahr);
		delete[]s_cahr;
		break;

	}



}

int main() {
	setlocale(LC_ALL, "rus");
	intnum;
	cout<< "Выберите задание\n|1|-Инверсия массива\n|2|-параметризированный стек\n->";
	cin>>num;
	switch (num)
	{
	case 1:
		task1();
	case 2:
		task2();
		break;
	default:
		break;
	}	
}
