#include <iostream>
#include "hugeint.h"
#include <string>

int main()
{
	std::string b,b1;
	std::string z;
	std::cin>>b>>z;
	hugeint a(b), c(z), d;
	
	a -= c;
	std::cout << a;
	
	//a.show();
	system("PAUSE");
	return 0;
}