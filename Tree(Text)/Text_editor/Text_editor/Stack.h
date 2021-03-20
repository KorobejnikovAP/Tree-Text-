#pragma once
#include <iostream>


using namespace std;

template <class T>
struct Link {
	T val;
	Link* next;
	Link* prev;
public:
	Link(T _val, Link* _prev = 0, Link* _next = 0) : val(_val), prev(_prev), next(_next) {}
};

template <class T>
class Stack {
	Link<T>* SP;
	Link<T>* root;

public:
	Stack() {};
	
	void Push_back(T _val) {
		if (root == nullptr) {
			root = new Link<T>(_val);
			SP = root;
			return;
		}
		
		Link<T>* tmp = new Link<T>(_val);
		tmp->prev = SP;
		SP->next = tmp;
		SP = tmp;
	}

	void pop() {
		if (root == nullptr)
			return;
		if (SP == root) {
			SP = root = nullptr;
			return;
		}
		Link<T>* tmp = SP;
		SP = tmp->prev;
		SP->next = nullptr;
		delete tmp;
	}

	friend ostream& operator << (ostream& o, const Stack<T>& st) {
		Link<T>* tmp = st.root;
		while (tmp != nullptr)
		{
			o << tmp->val << " ";
			tmp = tmp->next;
		}
		delete tmp;
		return o;
	}

};