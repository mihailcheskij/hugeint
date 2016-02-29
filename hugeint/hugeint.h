#ifndef HUGE_I
#define HUGE_I

#include <vector>
#include <string>
#include <cstdlib> //��� ������������� exit() � ������ ��������� ������

typedef unsigned long long LL;

class hugeint{
private:
	std::vector<unsigned short> huge;
public:
	hugeint();
	hugeint(std::string s);
	hugeint(LL num); //��� ����� <= 2^64
	~hugeint();
	// ���������� ���������� ��� ������, ����� ��� �������� hugeint, ��� ������ - �����
	hugeint operator+(const hugeint& a) const; // �������� 2� ������� �����
	void operator+=(const hugeint& a); //huge += huge;

	void operator=(const hugeint& a); //huge = huge;
	bool operator==(const hugeint& a) const; //huge == huge

	friend bool operator>(const hugeint& a, const hugeint& b); //huge > huge
	bool operator>=(const hugeint& a) const;
	//���������� ���������� ��� ������, ����� ������ ������� �����, � ������ - hugeint
	friend hugeint operator+(const LL& a, const hugeint& b); // ����� + huge
	

	friend std::ostream& operator<<(std::ostream& os, const hugeint& a);// ����� � �������������� cout ��� � ���� ����� <fstream>
	int size() const;
	void show() const;
};		

#endif