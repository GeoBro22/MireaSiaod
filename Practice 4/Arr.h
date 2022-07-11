#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <malloc.h>
#include "Vector.h"
using namespace std;



struct nman {
	int n, size;
	man* table;
};

void show_note(nman& tek) {
	for (int i = 0; i < tek.n; i++) {
		cout << "�����: " << tek.table[i].number <<"; ���: " << tek.table[i].name<<"; �������: "<< tek.table[i].surname<<"; ���� ��������: " << tek.table[i].day << "."<< tek.table[i].month << "."<< tek.table[i].year <<"; �����: "<< tek.table[i].adress << "." << endl;
	}
}

void add_man(nman& tek, man& t) {
	int i = 0;
	if (tek.n == tek.size) {
		man* temp = new man[tek.size + 1];
		for (int k = 0; k < tek.n; k++)
			temp[k] = tek.table[k];
		tek.table = temp;
		tek.size++;
	}
	while (i < tek.n && (tek.table[i].surname[0] != tek.table[i].surname[0])) i++;
	for (int k = tek.n; k > i; k--)
		tek.table[k] = tek.table[k - 1];
	tek.table[i] = t;
	tek.n++;
}

void delete_man(nman& tek, string number) {
	bool flag = false;
	for (int i = 0; i < tek.n; i++) {
		if (tek.table[i].number == number) {
			for (int k = i; k < tek.n - 1; k++) tek.table[k] = tek.table[k + 1];
			tek.n--;
			flag = true;
			break;
		}
	}
	if (!flag) cout << "������ �������� ���\n";
}

void show_man_to(nman& tek, int month) {
	bool flag = false;
	for (int i = 0; i < tek.n; i++) {
		if (tek.table[i].month == month) { cout << "�����: " << tek.table[i].number << "; ���: " << tek.table[i].name << "; �������: " << tek.table[i].surname << "; ���� ��������: " << tek.table[i].day << "." << tek.table[i].month << "." << tek.table[i].year << "; �����: " << tek.table[i].adress << "." << endl; flag = true; }
	}
	if (!flag) cout << "������ �������� ���\n";
}

void find_date_num(nman& tek, string sur) {
	bool flag = false;
	for (int i = 0; i < tek.n; i++) {
		if (tek.table[i].surname == sur) { cout << "�����: " << tek.table[i].number <<"; ���� ��������: " << tek.table[i].day << "." << tek.table[i].month << "." << tek.table[i].year << endl; flag = true; }
	}
	if (!flag) cout << "������ �������� ���\n";
}
