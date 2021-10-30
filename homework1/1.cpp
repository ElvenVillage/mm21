#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
	std::ifstream infile("in.txt");

	int x, y;
	
	int lx, rx, ly, ry;
	double _rcos, _lcos;
	_lcos = 1; _rcos = 1;

	int x0, y0;
	infile >> x0 >> y0;
	
	
	while (infile >> x >> y)
	{
		
		
		double cos = (x0*x+y0*y)/(sqrt(x*x+y*y)*sqrt(x0*x0+y0*y0));
        
		if (cos < _lcos && (y0*x < x0*y)) 
		{
			_lcos = cos;
			lx = x; ly = y;

		}
		if (cos < _rcos && (y0*x >= x0*y)) 
		{
			_rcos = cos;
			rx = x; ry = y;
		}
	}

	std::cout << "Leftmost: " << lx << " " << ly << "\n";
	std::cout << "Rightmost: " << rx << " " << ry << "\n";
}