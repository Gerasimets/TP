#include "Tetrahedron.h"
#include <iostream>
#include "cmath"

using namespace std;

void Tetrahedron::enter()
{
	cout << "Введите данные" << endl;
	cout << "Ребро:";
	cin >> rib;
}

float Tetrahedron::space()
{
	result = rib * rib * sqrt(3.0);
	return result;
}

void Tetrahedron::read()
{

}

void Tetrahedron::write()
{

}
