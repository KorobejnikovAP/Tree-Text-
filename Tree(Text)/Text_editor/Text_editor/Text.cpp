#include "Text.h"

ostream& operator<<(ostream& o, Text& _t)
{
	print(o, _t.root, _t.curr, 0);
	return o;
}

void Text::next()
{
	if (curr == nullptr) throw "no elem";
	if (curr->next == nullptr) throw "curr->next == 0";
	way.push(curr);
	curr = curr->next;
}

void Text::down()
{
	if (curr == nullptr) throw "no elem";
	if (curr->down == nullptr) throw "curr->down == 0";
	way.push(curr);
	curr = curr->down;
}

void Text::top()
{
	if (curr == nullptr) throw "no elem";
	if (way.empty()) throw "no way";
	curr = way.top();
	way.pop();
}

void Text::addNext(string s)
{
	if (root == 0) {
		root = curr = new Link(s);
		return;
	}
	Link* tmp = new Link(s, curr->next);
	curr->next = tmp;
}

void Text::addDown(string s)
{
	if (root == 0) {
		root = curr = new Link(s);
		return;
	}
	Link* tmp = new Link(s, curr->down);
	curr->down = tmp;
}

void Text::delCurr()
{
	if (curr == nullptr)
		return;
	if (curr == root) {
		root = root->next;
		curr->next = nullptr;
		FreeTree(curr);
		curr = root;
	}
	else {
		Link* tmp = root;
		TLR(tmp, curr);
		if (tmp->next == curr) {
			tmp->next = curr->next;
			curr->next = nullptr;
			FreeTree(curr);
			curr = tmp;
		}
		else {
			tmp->down = curr->next;
			curr->next = nullptr;
			FreeTree(curr);
			curr = tmp;
		}
	}

}
