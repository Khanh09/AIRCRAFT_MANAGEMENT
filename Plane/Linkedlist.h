#pragma once
#ifndef Linkedlist_H
#define Linkedlist_H
#include<iostream>
#include"Node.h"
using namespace std;
template<typename _Ty>
class LinkedList : protected Node<_Ty> {
private:
	Node<_Ty>* head;
	Node<_Ty>* trace;

public:
	int size = 0;
	LinkedList() {
		head = NULL;
		trace = NULL;
	}
	~LinkedList() {};
	_Ty& operator [](int index)
	{
		Node<_Ty>* temp = this->head;
		if (index<0 || index>size)
		{
			throw new exception();
		}
		int j = 0;
		while (j != index)
		{
			temp = temp->next;
			j++;
		}
		return temp->name;
	}
	void clear()
	{
		while (head != NULL)
		{
			Node<_Ty>* temp = head;head = head->next;
			delete temp;
			
		}
		LinkedList();
	}
	void RemoveAt(int index)
	{
		if (index<1 || index>size)
		{
			cout << "Out of bound!";
		}
		else
		{
			if (head == nullptr)
			{
				cout << "No element!";

			}
			else
			{
				if (index == 1)
				{
					head = head->next; size--;
				}
				else if (index == size)
				{
					this->PopBack();
				}
				else if (head == trace)
				{
					head = trace = NULL; size--;
				}
				else
				{
					Node<_Ty>* temp = head;
					int j = 1;
					while (j != index - 1)
					{

						temp = temp->next;
						j++;
					}
					temp->next = temp->next->next; size--;
				}

			}
		}
	}

	void PopBack() {
		Node<_Ty>* temp = head;
		while (temp->next != trace)
		{
			temp = temp->next;
		}
		trace = temp;
		size--;
		delete temp->next;
	}
	int Count()
	{
		return this->size;
	}
	void print()
	{
		Node<_Ty>* temp = head;
		while (temp != trace)
		{
			temp->printNode();
			temp = temp->next;
		}
		temp->printNode();
	}
	void Push_Back(_Ty d) {
		Node<_Ty>* data = new Node<_Ty>(d);
		if (trace == NULL)
		{
			trace = data;
			head = trace;
			size++;
			return;
		}
		trace->next = data;
		trace = trace->next;
		size++;
	}
	void Push_Back(Node<_Ty>* data) {
		if (trace == NULL)
		{
			trace = data;
			head = trace;
			size++;
			return;
		}
		trace->next = data;
		trace = trace->next;
		size++;
	}
	_Ty front()
	{
		return this->head->name;
	}
};
#endif // !Linkedlist_H



