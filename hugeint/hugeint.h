#ifndef HUGE_I
#define HUGE_I

#include <vector>
#include <string>
#include <cstdlib> //дл€ использовани€ exit() в случае ошибочных данных
#include <limits> //константы максимальных значений тпов, дл€ (число = hugeint)

typedef unsigned long long LL;

class hugeint{
private:
	std::vector<unsigned short> huge;
	void getPoint(const LL& a);
	void delZero();
public:
	hugeint();
	hugeint(std::string s);
	hugeint(LL num); //дл€ чисел <= 2^64
	~hugeint();
	// перегрузка операторов дл€ случа€, когда оба операнда hugeint, или второй - число
	hugeint operator+(const hugeint& a) const; // сложение 2х длинных чисел
	void operator+=(const hugeint& a); //huge += huge;
	hugeint operator-(const hugeint& a) const; // huge - huge
	void operator-=(const hugeint& a); //huge -= huge;

	void operator=(const hugeint& a); //huge = huge;
	bool operator==(const hugeint& a) const; //huge == huge

	friend bool operator>(const hugeint& a, const hugeint& b); //операции сравнени€
	bool operator>=(const hugeint& a) const;
	bool operator<(const hugeint& a)const;
	bool operator<=(const hugeint& a)const;

	//перегрузка операторов дл€ случа€, когда первый операнд число, а второй - hugeint
	friend hugeint operator+(const LL& a, const hugeint& b); // число + huge
	friend hugeint operator-(const LL& a, const hugeint& b); // ƒќƒ≈Ћј“№
	friend void operator=(LL& a, const hugeint& b);

	friend std::ostream& operator<<(std::ostream& os, const hugeint& a);// вывод с использованием cout или в файл через <fstream>
	int size() const;
	void show() const;
};		

#endif