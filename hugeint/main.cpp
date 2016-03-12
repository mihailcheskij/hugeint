#include <iostream>
#include "hugeint.h"
#include <string>

int main()
{
	std::string b,b1;
	LL z=0;
	std::cin>>b;
	hugeint a(b), c, d;
	
	z+=a;
	std::cout<<z;
	//a.show();
	system("PAUSE");
	return 0;
}