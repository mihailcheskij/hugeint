#include <iostream>
#include "hugeint.h"
#include <string>

int main()
{
	std::string b,b1;
	int z;
	std::cin>>b>>z;
	hugeint a(b), c(z), d;
	std::cout<<std::endl<<z+a;

	//a.show();
	system("PAUSE");
	return 0;
}