

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Link {
	int val;
	Link* l;
	Link* r;

	Link(int _a = 0, Link * _l = 0, Link * _r = 0) :
		val(_a), l(_l), r(_r) {}
};

void TLR(Link* curr) {
	if (curr == 0)
		return;
	cout << curr->val << " ";
	TLR(curr->l);
	TLR(curr->r);
}

void LTR(Link* curr) {
	if (curr == 0)
		return;
	LTR(curr->l);
	cout << curr->val << " ";
	LTR(curr->r);
}

void TLR_itr_1(Link* root) {
	Link* curr;
	stack<Link*> st;
	curr = root;
	while (true) {
		if (curr != NULL) {
			cout << curr->val << " ";
			st.push(curr);
			curr = curr->l;
		}
		else if (st.empty()) {
			break;
		}
		else {
			curr = st.top();
			st.pop();
			curr = curr->r;
		}
	}
}

void TLR_itr_2(Link* root) {
	Link* curr;
	queue<Link*> q;
	if (root != 0) q.push(root);
	
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		cout << curr->val << " ";
		if (curr->l != NULL) q.push(curr->l);
		if (curr->r != NULL) q.push(curr->r);
	}
}

class Iterator {
	Link* curr;
	queue<Link*> q;
public:
	Iterator(Link* root) {
		if (root != 0) q.push(root);
	}
	bool hasNext() {
		return !q.empty();
	}
	int next() {
		curr = q.front();
		q.pop();
		if (curr->l != NULL) q.push(curr->l);
		if (curr->r != NULL) q.push(curr->r);
		return curr->val;
	}
};

void LTR_itr_2(Link* root) {
	Link* curr;
	stack<Link*> st;
	curr = root;
	while (curr != 0 || !st.empty()) {
		if (!st.empty()) {
			curr = st.top();
			st.pop();
			cout << curr->val << " ";
			if (curr->r != NULL) curr = curr->r;
			else curr = 0;
		}
		while (curr != 0) {
			st.push(curr);
			curr = curr->l;
		}
	}
}

class Iterator2 {
	Link* curr;
	stack<Link*> st;
public:
	Iterator2(Link* root) {
		curr = root;
	}
	bool hasNext() {
		return curr != 0 || !st.empty();
	}
	int next() {
		while (curr != 0) {
			st.push(curr);
			curr = curr->l;
		}
		if (!st.empty()) {
			Link* res = st.top();
			curr = st.top();
			st.pop();
			if (curr->r != NULL) curr = curr->r;
			else curr = 0;
			return res->val;
		}
	}
};

int main()
{
   
	Link* l6 = new Link(6);
	Link* l5 = new Link(5);
	Link* l4 = new Link(4, NULL, l6);
	Link* l3 = new Link(3, l4, l5);
	Link* l2 = new Link(2);
	Link* l1 = new Link(1, l2, l3);

	Link* root = l1;

	TLR(root);
	cout << endl;

	LTR(root);
	cout << endl;

	TLR_itr_1(root);
	cout << endl;

	TLR_itr_2(root);
	cout << endl;

	Iterator it(root);
	while (it.hasNext()) {
		cout << it.next() << " ";
	}
	cout << endl;

	LTR_itr_2(root);
	cout << endl;

	Iterator2 it2(root);
	while (it2.hasNext()) {
		cout << it2.next() << " ";
	}
	cout << endl;
}

