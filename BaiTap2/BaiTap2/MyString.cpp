#include"MyString.h"
#include<iostream>





MyString::MyString() {
	size = 0;
	this->MS = new char[size];
}

MyString::MyString(const char* mst)
{
	int l = 0;
	while (mst[l] != '\0')
		l++;
	this->size = l;
	this->MS = new char[this->size];
	for (int i = 0; i < this->size; i++)
		this->MS[i] = mst[i];
}

MyString::MyString(const MyString& mst) {
	size = mst.size;
	MS = new char[size];
	for (int i = 0; i < size; i++)
		this->MS[i] = mst.MS[i];
}

MyString::~MyString() {};

ostream& operator<<(ostream& out, MyString mst) {
	for (int i = 0; i < mst.size; i++)
		out << mst.MS[i];
	return out;
}

istream& operator>>(istream& in, MyString mst) {
	in >> mst.MS;
	return in;
}

char& MyString::operator [](const int i) {
	static char temp;
	return (i >= 0 && i < this->size) ? *(this->MS + i) : temp;
}

MyString& operator+(MyString mstA, MyString mstB) {
	MyString mstC;
	mstC.MS = new char[mstA.size + mstC.size];
		for (int i = 0; i < mstA.size; i++)
		{
			mstC.MS[i] = mstA.MS[i];
		}
		for (int i = 0; i < mstB.size; i++)
		{
			mstC.MS[i+mstA.size] = mstA.MS[i];
		}
		return mstC;
}

MyString& MyString::operator=(const MyString mst) {
	MyString m = MyString(mst);
	return m;
}

bool operator==(const MyString& mstA,const MyString& mstB)
{
	if (mstA.size!=mstB.size)
	{
		return false;
	}
	for (int i = 0; i < mstA.size; i++)
	{
		if (mstA.MS[i]!=mstB.MS[i])
		{
			return false;
		}

	}
	return true;
}

bool operator!=(const MyString& mstA, const MyString& mstB)
{
	if (mstA.size != mstB.size)
	{
		return true;
	}
	for (int i = 0; i < mstA.size; i++)
	{
		if (mstA.MS[i] != mstB.MS[i])
		{
			return true;
		}

	}
	return false;
}
//thu tu uu tien theo tu dien :  khoang cach>ktu dac biet>so>chuhoa>chuthuong
int TestWord(char);
int TestWord(char w) {
	if (w == 32) return 5;//khoang cach
	if (w >= 48 && w <= 57) return 3;//so
	if (w >= 65 && w <= 90) return 2;//chu hoa
	if (w >= 97 && w <= 122) return 1;//chu thuong
	return 4;//ki tu con lai
}

bool operator>(const MyString& mstA, const MyString& mstB) {
	int len = (mstA.size > mstB.size) ? mstA.size : mstB.size;
	for (int i = 0; i < len; i++)
	{	
		if (TestWord(mstA.MS[i])<TestWord(mstB.MS[i]))//true neu do uu tien A cao hon B
		{
			return false;
		}
		if (TestWord(mstA.MS[i]) > TestWord(mstB.MS[i]))//false neu do uu tien A  thap hon B
		{
			return true;
		}
		if (mstA.MS[i] < mstB.MS[i]);
		{
			return true;
			break;
		}
	}
	return false;
}

bool operator<=(const MyString& mstA, const MyString& mstB) {

	return !operator>(mstA,mstB);
}

bool operator<(const MyString& mstA, const MyString& mstB) {
	int len = (mstA.size > mstB.size) ? mstA.size : mstB.size;
	for (int i = 0; i < len; i++)
	{
		if (TestWord(mstA.MS[i]) < TestWord(mstB.MS[i]))
		{
			return true;
		}
		if (TestWord(mstA.MS[i]) > TestWord(mstB.MS[i]))
		{
			return false;
		}
		if (mstA.MS[i] > mstB.MS[i]);
		{
			return true;
		}
	}
	return false;
}


bool operator>=(const MyString& mstA, const MyString& mstB) {
	return !operator<(mstA,mstB);
}
