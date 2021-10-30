#include <iostream>
#include <fstream>


int main()
{
	std::ifstream infile("in.txt");
	int a, b;

	while (infile >> a >> b)
	{
		std::cout << a;
	}
}