#pragma once
#include<iostream>


using namespace std;

class Data
{
public:
	int value;

	void Display();
	void EnterData();
};

class Stack
{
public:

	Stack();
	
	class Node
	{
	public:
		Node(Data data,Node *pNext);
		Node *pNext;
		Data data;
	};

	void add(Data data);
	
	bool pop();

	void MakeNull();

	Data Retrieve(int pos);

	void Display();

private:
	Node* top;
	int size;

};