#include"ListPerson.h"
#include"person.h"
#include<iostream>


ListPerson::ListPerson() {
	this->size = 4;
	this->L = new Person[this->size];
	ListPerson::init();
}
void ListPerson::init() {
	this->L[0].setMaPerson(1);
	this->L[0].setTen("Nguyen Van An");
	this->L[0].setTuoi(21);
	this->L[0].setDiachi("12 Pham Hung");
	this->L[0].setGioitinh(1);

	this->L[1].setMaPerson(3);
	this->L[1].setTen("Le Thi Binh");
	this->L[1].setTuoi(18);
	this->L[1].setDiachi("67 Ton Dan");
	this->L[1].setGioitinh(0);

	this->L[2].setMaPerson(4);
	this->L[2].setTen("Ngo Hung Cuong");
	this->L[2].setTuoi(22);
	this->L[2].setDiachi("31 Ngu Binh");
	this->L[2].setGioitinh(1);

	this->L[3].setMaPerson(2);
	this->L[3].setTen("Le My Dung");
	this->L[3].setTuoi(22);
	this->L[3].setDiachi("76 Huy Can");
	this->L[3].setGioitinh(0);

}

ListPerson::~ListPerson() {};

Person& ListPerson::operator [](const int i) {
	static Person temp;
	return (i >= 0 && i < this->size) ? *(this->L + i) : temp;
}

void ListPerson::showPerson() {
	cout << "DANH SACH PERSON" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < this->size; i++)
	{
		cout << *(this->L + i);
	}
	cout << "-------------------------------------------------------------------" << endl;
}

void ListPerson::addPerson() {
	int n;
		cout << "nhap vi tri muon nhap(1.dau/2.cuoi/3.batky) :";
		cin >> n;
		switch (n)
		{
		case 1:
			ListPerson::addFirstPerson();
			break;
		case 2:
			ListPerson::addLastPerson();
			break;
		case 3:
			ListPerson::addAnytPerson();
			break;
		default:
			cout << "ban nhap sai !!!" << endl;
			break;
		}
}

void ListPerson::addFirstPerson() {
	Person *tmp = new Person[this->size + 1];
	Person per;
	cin >> per;
	tmp[0] = per;
	for (int i = 0; i < this->size; i++)
	{
		tmp[i + 1] = this->L[i];
	}
	this->size++;
	this->L = tmp;
}

void ListPerson::addAnytPerson() {
	Person *tmp = new Person[this->size + 1];
	int n;
	cout << "Nhap vi tri muon them:";
	cin >> n;
	Person per;
	cin >> per;
	tmp[n - 1] = per;
	for (int i = 0; i <= this->size; i++)
	{
		if (i < n - 1) {
			tmp[i] = this->L[i];
		}
		if (i > n - 1) {
			tmp[i] = this->L[i - 1];
		}
	}
	this->size++;
	this->L = tmp;
}

void ListPerson::addLastPerson() {
	Person *tmp = new Person[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->L[i];
	}

	Person per;
	cin >> per;
	tmp[this->size] = per;
	this->size++;
	this->L = tmp;
}

void ListPerson::updatePerson() {
	int maps;
	cout << "Nhap ma person muon cap nhat thong tin : " << endl;
	cin >> maps;
	for (int i = 0; i < this->size; i++)
	{
		if ((*(this->L + i)).getMaPerson() == maps) {
			cin >> *(this->L + i);
		}
	}
	cout << "khong co thong tin ban muon tim kiem." << endl;
}


void ListPerson::deletePerson() {
	int n;
		cout << "ban muon xoa vi tri nao ?(1.dau/2.cuoi/3.bat ky)" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			ListPerson::deleteFirstPerson();
			break;
		case 2:
			ListPerson::deleteLastPerson();
			break;
		case 3:
			ListPerson::deleteAnyPerson();
			break;
		default:
			cout << "ban nhap sai moi ban nhap lai!!!" << endl;
			break;
		}
}

void ListPerson::deleteFirstPerson() {
	Person *tmp = new Person[this->size - 1];
	for (int i = 0; i < this->size - 1; i++)
	{
		tmp[i] = this->L[i + 1];
	}
	this->size--;
	this->L = tmp;
}

void ListPerson::deleteLastPerson() {
	Person *tmp = new Person[this->size - 1];
	for (int i = 0; i < this->size - 1; i++)
	{
		tmp[i] = this->L[i];
	}
	this->size--;
	this->L = tmp;
}

void ListPerson::deleteAnyPerson() {
	int n;
	cout << "nhap vi tri muon xoa:";
	cin >> n;
	Person *tmp = new Person[this->size - 1];
	for (int i = 0; i < this->size - 1; i++)
	{
		if (i < n) {
			tmp[i] = this->L[i];
		}
		if (i >= n) {
			tmp[i] = this->L[i + 1];
		}
	}
	this->size--;
	this->L = tmp;
}

void ListPerson::searchPerson() {
	int search;
	cout << "Nhap ma person can tim kiem: " << endl;
	cin >> search;
	Person *tmp = new Person[this->size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->L[i];
	}
	MergeSort(tmp, 0, this->size - 1, 1);
	int index = ListPerson::BinarySearch(tmp, this->size, search);
	if (index == -1) {
		cout << "Khong co thong tin can tim." << endl;
	}
	else {
		cout << "Thong tin person can tim la :" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << *(tmp + index);
		cout << "--------------------------------------------------" << endl;
	}

}
int ListPerson::BinarySearch(Person *a, int n, int x) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == a[mid].getMaPerson())
			return mid;
		else if (x < a[mid].getMaPerson())
			right = mid - 1;
		else if (x > a[mid].getMaPerson())
			left = mid + 1;
	}
	return -1;
}

void ListPerson::sortPerson() {
	cout << "Ban muon sap xep(1.tangdan/0.giamdan): ";
	int n;
	cin >> n;
	MergeSort(this->L, 0, this->size - 1, n);
}
void MergeAscending(Person *a, int left, int mid, int right);
void MergeDescending(Person *a, int left, int mid, int right);

void ListPerson::MergeSort(Person *a, int left, int right, int n) {
	void(*lps)(Person*, int, int, int);
	if (right > left)
	{
		int mid;
		mid = (left + right) / 2;
		MergeSort(a, left, mid, n);
		MergeSort(a, mid + 1, right, n);
		if (n == 1) {
			lps = MergeAscending;
			(*lps)(a, left, mid, right);
		}
		if (n == 0) {
			lps = MergeDescending;
			(*lps)(a, left, mid, right);
		}
	}
}
void MergeAscending(Person *a, int left, int mid, int right) {
	Person *tmp;
	int i = left;
	int j = mid + 1;

	tmp = new Person[right - left + 1];

	for (int k = 0; k <= right - left; k++)
	{
		if (a[i].getMaPerson() < a[j].getMaPerson())
		{
			tmp[k] = a[i];
			i++;
		}
		else
		{
			tmp[k] = a[j];
			j++;
		}

		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				tmp[k] = a[j];
				j++;
			}
			break;
		}

		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				tmp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++)
		a[left + k]=tmp[k];
}

void MergeDescending(Person *a, int left, int mid, int right) {
	Person *tmp;
	int i = left;
	int j = mid + 1;

	tmp = new Person[right - left + 1];

	for (int k = 0; k <= right - left; k++)
	{
		if (a[i].getMaPerson() > a[j].getMaPerson())
		{
			tmp[k] = a[i];
			i++;
		}
		else
		{
			tmp[k] = a[j];
			j++;
		}

		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				tmp[k] = a[j];
				j++;
			}
			break;
		}

		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				tmp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++)
		a[left + k]=tmp[k];
}
