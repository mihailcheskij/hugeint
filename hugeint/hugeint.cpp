#include "hugeint.h"
#include <string>
#include <iostream>

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

hugeint hugeint::operator+(const LL& a) const
{
	hugeint temp(a);
	return *this + temp;
};

void hugeint::operator+=(const LL& a)
{
	hugeint temp(a);
	*this = *this + temp;
};

void hugeint::operator=(const LL & a)
{
	hugeint temp(a);
	*this = temp;
};

bool hugeint::operator==(const LL & a) const
{
	hugeint temp(a);
	return *this == temp;
};

hugeint operator+(LL a, hugeint b)
{
	return b + a;
};

std::ostream& operator<<(std::ostream& os, const hugeint& a)
{
	for(int i=0; i<a.huge.size(); i++)
	{
		os<<a.huge[i];
	}
	return os;
};