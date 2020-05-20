#include "Tetrahedron.h"
#include <iostream>
#include "cmath"
#include "Figure.h"

using namespace std;

Tetrahedron::Tetrahedron()
{

}

Tetrahedron::~Tetrahedron()
{

}

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
