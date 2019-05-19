#include"Person.h"
#include<iostream>
#include<string>

Person::Person()
{
	this->MaPS = 0;
	this->ten = "";
	this->tuoi = 0;
	this->diachi = "";
	this->gioitinh = true;
}
Person::Person(int maps, string ten, int tuoi, string diachi, bool gioitinh) {
	this->MaPS = maps;
	this->ten = ten;
	this->tuoi = tuoi;
	this->diachi = diachi;
	this->gioitinh = gioitinh;
}
Person::Person(const Person& per) {
	this->MaPS = per.MaPS;
	this->ten = per.ten;
	this->tuoi = per.tuoi;
	this->diachi = per.diachi;
	this->gioitinh = per.gioitinh;
}
Person::~Person() {};

void Person::setMaPerson(int maps) {
	this->MaPS = maps;
}

int Person::getMaPerson() {
	return this->MaPS;
}

void Person::setTen(string ten) {
	this->ten = ten;
}

string Person::getTen() {
	return this->ten;
}

void Person::setTuoi(int tuoi) {
	this->tuoi = tuoi;
}

int Person::getTuoi() {
	return this->tuoi;
}

void Person::setDiachi(string diachi) {
	this->diachi = diachi;
}

string Person::getDiachi() {
	return this->diachi;
}

void Person::setGioitinh(bool gioitinh) {
	this->gioitinh = gioitinh;
}

bool Person::getGioitinh() {
	return this->gioitinh;
}

istream &operator>>(istream& in, Person& per) {
	cout << "Nhap ma person: ";
	int maps;
	in >> maps;
	per.setMaPerson(maps);
	cout << "Nhap ho ten person: ";
	in.ignore();
	string ten;
	getline(in, ten);
	per.setTen(ten);
	cout << "Nhap tuoi person: ";
	int tuoi;
	in >> tuoi;
	per.setTuoi(tuoi);
	cout << "Nhap dia chi person: ";
	in.ignore();
	string diachi;
	getline(in, diachi);
	per.setDiachi(diachi);
	cout << "Nhap gioi tinh person(1.nam/0.nu): ";
	int gioitinh;
	in >> gioitinh;
	if (gioitinh == 1) {
		per.setGioitinh(true);
	}
	if (gioitinh == 0) {
		per.setGioitinh(false);
	}
	return in;
}
ostream &operator<<(ostream& out, Person& per) {
	string str = "";
	if (per.getGioitinh() == true) str = "Nam";
	if (per.getGioitinh() == false) str = "Nu";
	out << "Ma Person : " << per.getMaPerson() << ", Ten: " << per.getTen() << ", Tuoi : " << per.getTuoi() << ", Dia Chi :" << per.getDiachi() << ", Gioi Tinh : " << str << endl;
	return out;
}