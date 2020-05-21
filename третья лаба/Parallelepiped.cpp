#include "Parallelepiped.h"
#include <iostream>
#include <string>
#include "Figure.h"

using namespace std;

Parallelepiped::Parallelepiped()
{
	way = "Parallelepiped.txt";
}

Parallelepiped::~Parallelepiped()
{

}

float Parallelepiped::space()
{
	result = 2 * (length * width + width * height + length * height);
	return result;
}
