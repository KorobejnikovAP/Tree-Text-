#pragma once
#include <iostream>
#include <stack>
using namespace std;



struct Link {
	string val;
	Link* next;
	Link* down;

public:
	Link(string _val, Link* _next = nullptr, Link* _down = nullptr) : val(_val), next(_next)
		                                                            , down(_down) {};
};

class Text
{
	Link* root;
	Link* curr;
	stack<Link*> way;
public:
	Text(Link* _root = nullptr) : root(_root), curr(_root) {
		Link* l1 = new Link("l1");
		Link* l2 = new Link("l2");
		root = new Link("root", l1, l2);

		curr = root;
	};
	//Text(const Text& _t);
	//~Text();

	void next();
	void down();
	void top();

	//Text& operator=(const Text& _t);
	void addNext(string s);
	void addDown(string s);
	void delCurr();

	friend ostream& operator << (ostream& o, Text& _t);
};

