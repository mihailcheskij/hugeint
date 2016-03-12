#ifndef HUGE_I
#define HUGE_I

#include <vector>
#include <string>
#include <cstdlib> //��� ������������� exit() � ������ ��������� ������
#include <limits> //��������� ������������ �������� ����, ��� (����� = hugeint)

typedef unsigned long long LL;

class hugeint{
private:
	std::vector<unsigned short> huge;
	void getPoint(const LL& a);
	void delZero();
	LL toInt();
public:
	hugeint();
	hugeint(std::string s);
	hugeint(LL num); //��� ����� <= 2^64
	~hugeint();
	// ���������� ���������� ��� ������, ����� ��� �������� hugeint, ��� ������ - �����
	hugeint operator+(const hugeint& a) const; // �������� 2� ������� �����
	void operator+=(const hugeint& a); //huge += huge;
	hugeint operator-(const hugeint& a) const; // huge - huge
	void operator-=(const hugeint& a); //huge -= huge;

	void operator=(const hugeint& a); //huge = huge;
	bool operator==(const hugeint& a) const; //huge == huge

	friend bool operator>(const hugeint& a, const hugeint& b); //�������� ���������
	bool operator>=(const hugeint& a) const;
	bool operator<(const hugeint& a)const;
	bool operator<=(const hugeint& a)const;

	//���������� ���������� ��� ������, ����� ������ ������� �����, � ������ - hugeint 
	//P.S. ���������� hugeint (����� "op"=, �������� +=)
	friend hugeint operator+(const LL& a, const hugeint& b); // ����� + huge
	friend hugeint operator-(const LL& a, const hugeint& b); // ����� - huge
	friend void operator+=(LL& a, const hugeint& b);

	friend std::ostream& operator<<(std::ostream& os, const hugeint& a);// ����� � �������������� cout ��� � ���� ����� <fstream>
	int size() const;
	void show() const;
};		

#endif