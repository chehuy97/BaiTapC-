#pragma once
#include"Person.h"
#include<iostream>
#include<string>

class ListPerson
{
	int size;
	Person *L;
public:
	ListPerson();
	~ListPerson();
	void init();
	void addPerson();
	void addFirstPerson();
	void addLastPerson();
	void addAnytPerson();
	void showPerson();
	void updatePerson();
	void deletePerson();
	void deleteFirstPerson();
	void deleteLastPerson();
	void deleteAnyPerson();
	void searchPerson();
	int BinarySearch(Person[], int, int);
	void sortPerson();
	void MergeSort(Person[], int, int, int);
	Person& operator[](const int);
};

