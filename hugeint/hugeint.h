#ifndef HUGE_I
#define HUGE_I

#include <vector>
#include <string>

typedef unsigned long long LL;

class hugeint{
private:
	std::vector<unsigned short> huge;
public:
	hugeint();
	hugeint(std::string s);
	hugeint(LL num); //��� ����� <= 2^64
	~hugeint();
	// ���������� ���������� ��� ������, ����� ��� �������� hugeint
	hugeint operator+(const hugeint& a) const; // �������� 2� ������� �����
	void operator+=(const hugeint& a); //huge += huge;
	void operator=(const hugeint& a); //huge = huge;
	bool operator==(const hugeint& a) const; //huge == huge

	//���������� ���������� ��� ������, ����� ������ ������� hugeint, � ������ - �����
	hugeint operator+(const LL& a) const; // huge + �����
	void operator+=(const LL& a); //huge += �����;
	void operator=(const LL& a); //huge = �����;
	bool operator==(const LL& a) const; //huge == �����

	//���������� ���������� ��� ������, ����� ������ ������� �����, � ������ - hugeint
	friend hugeint operator+(LL a, hugeint b); // ����� + huge

	friend std::ostream& operator<<(std::ostream& os, const hugeint& a);// ����� � �������������� cout ��� � ���� ����� <fstream>
	int size() const;
	void show() const;
};


#endif