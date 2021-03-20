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

inline void TLR(Link*& curr, Link*& curr_next) {
	if (curr->next == curr_next || curr->down == curr_next)
		return;
	TLR(curr->next, curr_next);
	TLR(curr->down, curr_next);
}

inline void print(ostream& o, Link* root, Link* curr, int lvl) {
	if (root == nullptr)
		return;
	if (root == curr)
		o << '*';
	else o << '|';

	for (int i = 0; i < lvl; ++i)
		o << "  ";
	o << root->val << endl;
	print(o, root->down, curr, lvl + 1);
	print(o, root->next, curr, lvl);
}

inline void FreeTree(Link*& root) {
	if (root->next)  FreeTree(root->next);
	if (root->down)  FreeTree(root->down);
	
	root = nullptr;
}

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

