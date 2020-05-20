#include "Tetrahedron.h"
#include <iostream>
#include "cmath"
#include "Figure.h"
#include <string>

using namespace std;

Tetrahedron::Tetrahedron()
{
	way = "Tetrahedron.txt";
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
