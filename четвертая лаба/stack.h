#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include <ctype.h>
template<typename T >
struct node
{
	node<T> *next;
	T value;

};

template<typename T >
class stack
{
	node<T> *tail;
	int size;
public:
	stack()
	{
		tail = nullptr;
		size = 0;
	}

	~stack() {
		{
			node<T>* tmp1; 
			node<T>* tmp2;
			tmp1 = tail;
			while (tmp1 != nullptr)
			{
				tmp2 = tmp1; 
				tmp1 = tmp1->next;
				delete tmp2; 
			}
			tail = nullptr; 

		}
	}

	stack(const stack &s)// конструкторкопии
	{
		node<T> *tmp1, *tmp2, *tmp3;
		tail = nullptr;
		tmp3 = nullptr;
		tmp1 = s.tail;
		while (tmp1 != nullptr)
		{
			try {
				tmp2 = new node<T>;
			}
			catch (bad_alloc e)
			{
				cout<<e.what() <<endl;
				return;
			}
			tmp2->value = tmp1->value;
			tmp2->next = nullptr;
			if (tail == nullptr)
			{
				tail = tmp2;
				tmp3 = tmp2;
			}
			else
			{
				tmp3->next = tmp2;
				tmp3 = tmp3->next;
			}
			tmp1 = tmp1->next;	
		}
		size = s.size;
	
	}

	bool operator==(stack &r);

	stack operator+(stack s) {
		if (size != s.size) {
			cout<< "Сложение невозможно, стеки разной длины\n";
				return *this;
		 }
		node<T> *tmpl, *tmpr;
		tmpl = tail;
		tmpr = s.tail;
		while (tmpl != nullptr) {
			tmpl->value += tmpr->value;
			tmpl = tmpl->next;
			tmpr = tmpr->next;
		 }
		return *this;
	 }

	stack operator-(stack s) {
		if (size != s.size) {
			cout<< "Вычитание невозможно, стеки разной длины\n";
			return *this;
		 }
		node<T> *tmpl, *tmpr;
		tmpl = tail;
		tmpr = s.tail;
		while (tmpl != nullptr) {
			tmpl->value -= tmpr->value;
			tmpl = tmpl->next;
			tmpr = tmpr->next;
		 }
		return *this;
	 }

	stack<T>& operator=(const stack<T>& s)
	{
		 // есть ли элементы в стеке?
		if (tail != nullptr) {
			size = 0;
			while (tail != nullptr)

			 {
				node<T> *tmp = tail->next;
				delete tail;
				tail = tmp;
			 }
			tail = nullptr;
		 };
		node<T> *tmp1, *tmp2, *tmp3;
		tail = nullptr;
		 tmp3 = nullptr;
		 tmp1 = s.tail;
		while (tmp1 != nullptr)
		 {
			
			 tmp2 = new node<T>;
			 tmp2->value = tmp1->value;
			 tmp2->next = nullptr;
			if (tail == nullptr)
			 {
				tail = tmp2;
				 tmp3 = tmp2;
			 }
			else
			 {
				 tmp3->next = tmp2;
				 tmp3 = tmp3->next;
			 }
			 tmp1 = tmp1->next;
		 }
		size = s.size;
		return *this;
	 }

	 T random() {
		 T n;
		if (typeid(n) == typeid(char)) {
			 n = rand() / T(RAND_MAX) * 20;
		 }
		else /*n = rand()%20;*/
		 n = (T)rand()*100/ RAND_MAX;
		return n;
	 }

	void push()
	{
		node<T> *ptr;
		tail = nullptr;
		cout<< "Введите размер стека-> ";
		cin>>size;
		inttmp = size;
		if (tmp> 0)
		{
			tail = new node<T>;
			ptr = tail;
		}
		while (--tmp>= 0)
		{
			ptr->value = random();
			cout<<ptr->value << " ";
			if (tmp != 0)
			{
				ptr->next = new node<T>;
				ptr = ptr->next;
			}
			else
				ptr->next = nullptr;
		}
	}

	void show()
	{
			node<T>* p;
			p = tail;
			while (p != nullptr)
			{
				cout<< p->value << " ";
				p = p->next;
			}
			cout<<endl;
		
	}
};
