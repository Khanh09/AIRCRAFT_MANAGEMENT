#include<iostream>
using namespace std;


template<class _Ty>
class Node {
public:
	_Ty name;
	Node<_Ty>* next;
public:
	Node()
	{

		next = NULL;
	}
	Node(int d)
	{
		name = 3;
	}
	Node(_Ty k)
	{
		name = k;
		next = NULL;
	}
	void printNode() {
		cout << name;
	}
	friend ostream& operator <<(ostream& os, Node<_Ty>* node)
	{
		os << node->name;
		return os;
	}


};