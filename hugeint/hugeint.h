#ifndef HUGE_I
#define HUGE_I

#include <vector>
#include <string>
#include <cstdlib> //для использования exit() в случае ошибочных данных

typedef unsigned long long LL;

class hugeint{
private:
	std::vector<unsigned short> huge;
public:
	hugeint();
	hugeint(std::string s);
	hugeint(LL num); //для чисел <= 2^64
	~hugeint();
	// перегрузка операторов для случая, когда оба операнда hugeint, или второй - число
	hugeint operator+(const hugeint& a) const; // сложение 2х длинных чисел
	void operator+=(const hugeint& a); //huge += huge;

	void operator=(const hugeint& a); //huge = huge;
	bool operator==(const hugeint& a) const; //huge == huge

	friend bool operator>(const hugeint& a, const hugeint& b); //huge > huge
	bool operator>=(const hugeint& a) const;
	//перегрузка операторов для случая, когда первый операнд число, а второй - hugeint
	friend hugeint operator+(const LL& a, const hugeint& b); // число + huge
	

	friend std::ostream& operator<<(std::ostream& os, const hugeint& a);// вывод с использованием cout или в файл через <fstream>
	int size() const;
	void show() const;
};		

#endif