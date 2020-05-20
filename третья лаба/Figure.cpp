#include "Figure.h"
#include <iostream>
#include <fstream>

using namespace std;

Figure::~Figure()
{

}

void Figure::show()
{

}

void Figure::write()
{
	ofstream fout(way, ios_base::app); // почитать
	if (!fout.is_open())
	{
		cout << "Файл не может быть открыт!" << endl;
	}
	else
	{
		fout << result << "\n";
		fout.close();
	}
}
