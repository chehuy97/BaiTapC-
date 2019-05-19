#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
	int MaPS;
	string ten;
	int tuoi;
	string diachi;
	bool gioitinh;
public:
	Person();
	Person(int, string, int, string, bool);
	Person(const Person &);
	~Person();
	void setMaPerson(int);
	int getMaPerson();
	void setTen(string);
	string getTen();
	void setTuoi(int);
	int getTuoi();
	void setDiachi(string);
	string getDiachi();
	void setGioitinh(bool);
	bool getGioitinh();
	friend istream& operator>>(istream&, Person&);
	friend ostream& operator<<(ostream&, Person&);
};


