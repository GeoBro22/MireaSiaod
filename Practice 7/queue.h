#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;
class queueM {
	string* m;
	int sizem;
public:
	queueM(string*,int);
	void push();
	void kick();
	void findlast();
	void CleanUp();
	void isClean();
};

class queueS {
	int sizem;
public:
	struct node {
		string data;
		node* next;
	};
	node* L;
	queueS(node*&,int);
	void set();
	void push();
	void kick();
	void findlast();
	void CleanUp();
	void isClean();
};
#endif