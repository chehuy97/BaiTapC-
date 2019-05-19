#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;

class MyString
{
public:
	char* MS;
	int size;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();
	friend MyString& operator+(MyString, MyString);
	MyString& operator=(const MyString);
	friend bool operator==(const MyString&, const MyString&);
	friend bool operator!=(const MyString&, const MyString&);
	friend bool operator>(const MyString&, const MyString&);
	friend bool operator<=(const MyString&, const MyString&);
	friend bool operator<(const MyString&, const MyString&);
	friend bool operator>=(const MyString&, const MyString&);
	friend ostream& operator<<(ostream&, MyString&);
	friend istream& operator>>(istream&, MyString&);
	char& operator[](const int);
};









