#include "hugeint.h"
#include <string>
#include <iostream>

void hugeint::getPoint(const LL & a)
{
	if (huge[a - 1] == 0)
	{
		this->getPoint(a - 1);
	}
	huge[a - 1] -= 1;
	huge[a] += 10;	
};

void hugeint::delZero()
{
	while (this->huge[0] == 0)
	{
		this->huge.erase(this->huge.begin());
	}
}

hugeint::hugeint()
{
	huge.push_back(0);
};

hugeint::hugeint(std::string s)
{
	long i=0;
	while ( (s[i]=='0') && (i<s.size()) )
	{
		i++;
	};

	if(i>=s.size())
	{
		huge.push_back(0);
	}
	else{
		for( ; i<s.size(); i++)
		{
			huge.push_back(int(s[i] - '0'));
		}
	};
};

hugeint::hugeint(LL num)
{
	if(num<=0)
	{
		huge.push_back(0);
		return;
	}
	while(num>0)
	{
		huge.insert(huge.begin(), num%10);
		num/=10;
	}
};

hugeint::~hugeint()
{};

int hugeint::size() const
{
	return huge.size();
};

void hugeint::show() const
{
	for(int i=0; i<huge.size(); i++)
	{
		std::cout<<huge[i];
	}
};

hugeint hugeint::operator+(const hugeint& a) const
{
	hugeint res, a1;
	a1 = a;
	res.huge.erase(res.huge.begin());
	short ost=0;
	if(this->size()<a1.size())
	{
		return a1 + *this;
	}
	else{
		while(a1.size()<this->size())
		{
			a1.huge.insert(a1.huge.begin(), 0);
		};

		for (int i = this->size() - 1; i >= 0; i--)
		{
			res.huge.insert(res.huge.begin(), ((this->huge[i] + a1.huge[i] + ost)%10));
			ost = (this->huge[i] + a1.huge[i] + ost)/10;
		};
		
		if(ost!=0)
		{
			res.huge.insert(res.huge.begin(), ost);
		};
		return res;
	}
};

void hugeint::operator=(const hugeint & a)
{
	this->huge = a.huge;
};

void hugeint::operator+=(const hugeint & a)
{
	*this = *this + a;
};

hugeint hugeint::operator-(const hugeint & a) const
{
	if (*this < a)
	{
		std::cout << "Error 101: hugeint can't contains negative value" << std::endl;
		system("PAUSE");
		exit(101);
	}

	hugeint a1 = a, 
			this1 = *this,
			res;
	res.huge.erase(res.huge.begin());
	int temp;

	if (a1.size() < this1.size()) 
	{
		while (a1.size()<this1.size())
		{
			a1.huge.insert(a1.huge.begin(), 0);
		};
	}

	for (int i = a1.size() - 1; i >= 0; i--)
	{	
		if (this1.huge[i] < a1.huge[i])
		{
			this1.getPoint(i);
			if (this1.huge[0] == 0)
			{
				this1.huge.erase(this1.huge.begin());
				a1.huge.erase(a1.huge.begin());
				i--;
			}
		}
		temp = this1.huge[i] - a1.huge[i];
		res.huge.insert(res.huge.begin(), temp);
	}
	res.delZero();
	return res;
}
void hugeint::operator-=(const hugeint & a)
{
	*this = *this - a;
};


bool hugeint::operator==(const hugeint& a) const
{
	if(this->size() != a.size())
	{
		return false;
	}
	for(int i=0; i < a.size(); i++)
	{
		if(this->huge[i] != a.huge[i])
		{
			return false;
		}
	}

	return true;
};

bool operator>(const hugeint & a, const hugeint& b)
{
	if (a.size() > b.size())
	{
		return true;
	}
	if (a.size() < b.size())
	{
		return false;
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (a.huge[i] > b.huge[i])
		{
			return true;
		}
		if (a.huge[i] < b.huge[i])
		{
			return false;
		}
	}

	return false;
}

bool hugeint::operator>=(const hugeint & a) const
{
	if (*this == a)
	{
		return true;
	}
	
	return (*this > a);
}

bool hugeint::operator<(const hugeint & a) const
{
	if (*this == a)
	{
		return false;
	}
	return !(*this>a);
}

bool hugeint::operator<=(const hugeint & a) const
{
	if (*this == a)
	{
		return true;
	}
	return (*this < a);
}

hugeint operator+(const LL& a, const hugeint& b)
{
	return b + a;
};

hugeint operator-(const LL & a, const hugeint & b)
{
	return (hugeint(a) - b);
};

//void operator=(LL & a, const hugeint & b)
//{
//};

std::ostream& operator<<(std::ostream& os, const hugeint& a)
{
	for(int i=0; i<a.huge.size(); i++)
	{
		os<<a.huge[i];
	}
	return os;
};