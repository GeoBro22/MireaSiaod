#include "queue.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

////////////////////////////////////////////////

queueM::queueM(string* m,int sizem) {
	this->m = m;
	this->sizem = sizem;
}
void queueM::push() 
{
	string nelem;
	cout << "¬ведите элемент, который хотите добавить(0-добавить пустую €чейку): ";
	cin >> nelem;
	for (int i = sizem - 2; i >=0; i--)
		m[i + 1]=m[i];
	if (nelem != "0")
		m[0] = nelem;
	else
		m[0] = "_";
	cout << "“еперь очередь выгл€дит так: ";
	for (int i = 0; i < sizem; i++) {
		cout<< m[i] << " ";
	}
	cout << endl;
}
void queueM::kick()
{
	int num,k;
	cout << "¬ведите номер €чйки, которую хотите выкинуть: ";
	cin >> num;
	k = sizem - num;
	for (int j = 0; j < k; j++) 
	{
		for (int i = sizem - 2; i >=0; i--)
			m[i + 1]= m[i];
		m[0] = "_";
	}
	cout << "“еперь очередь выгл€дит так: ";
	for (int i = 0; i < sizem; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
void queueM::findlast() 
{
	cout <<"Ёлемент в вершине-" << m[sizem - 1]<<endl;

}
void queueM::CleanUp()
{
	for (int i = 0; i < sizem; i++) {
		m[i] = "_";
	}
	cout << "ќчередь очищена\n";
}
void queueM::isClean() 
{
	int k = 0;
	for (int i = 0; i < sizem; i++) {
		if (m[i] == "_")
			k++;
	}
	if (k == sizem) 
		cout << "ќчередь пуста\n";
	else 
		cout << "ќчередь не пуста\n";	
}
/////////////////////////////////////////////////////////////
queueS::queueS(node*& L, int sizem) {
	this->L = L;
	this->sizem = sizem;
}
void queueS::set() {
	for (int i = 0; i < sizem; i++) {
		string d = "_";
		node* n = new node;
		if (n != NULL) {
			n->data = d;
			n->next = NULL;
			if (L == NULL)
				L = n;
			else {
				node* tmp = L;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = n;
			}
		}
	}
}
void queueS::push()
{
	string nelem;
	cout << "¬ведите элемент, который хотите добавить(0-добавить пустую €чейку): ";
	cin >> nelem;
	string m = L->data;
	node* tmp = L;
	tmp = tmp->next;
	while (tmp) {
		swap(m, tmp->data);
		tmp = tmp ->next;
	}
	if (nelem != "0")
		L->data = nelem;
	else
		L->data = "_";
	cout << "“еперь очередь выгл€дит так: ";
	node* p = L;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void queueS::kick()
{
	int num, k;
	cout << "¬ведите номер €чйки, которую хотите выкинуть: ";
	cin >> num;
	k = sizem - num;
	for (int j = 0; j < k; j++)
	{
		string m = L->data;
		node* tmp = L;
		tmp = tmp->next;
		while (tmp) {
			swap(m, tmp->data);
			tmp = tmp->next;
		}
		L->data = "_";
	}
	cout << "“еперь очередь выгл€дит так: ";
	node* p = L;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void queueS::findlast()
{
	node* tmp = L;
	tmp = tmp->next;
	while (tmp->next) {
		tmp = tmp->next;
	}
	cout << "Ёлемент в вершине-" << tmp->data << endl;
}
void queueS::CleanUp()
{
	node* tmp = L;
	tmp = tmp->next;
	while (tmp) {
		tmp->data = "_";
		tmp = tmp->next;
	}
	cout << "ќчередь очищена\n";
}
void queueS::isClean()
{
	int k = 0;
	node* tmp = L;
	tmp = tmp->next;
	while (tmp) {
		if (tmp->data == "_")
			k++;
		tmp = tmp->next;
	}
	if (k == sizem)
		cout << "ќчередь пуста\n";
	else
		cout << "ќчередь не пуста\n";
}
//////////////////////////////////////////////////////////////////////////