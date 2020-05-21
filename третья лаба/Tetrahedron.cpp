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

float Tetrahedron::space()
{
	result = rib * rib * sqrt(3.0);
	return result;
}
