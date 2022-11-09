#include"lib.h"

Stack::Stack()
{
	size = 0;
	top = nullptr;
}

Stack::Node::Node(Data data,Node* pNext=nullptr)
{
	this->data = data;
	this->pNext = pNext;
}

void Stack::add(Data data)
{
	if (top == nullptr)
	{
		top = new Node(data);
		size = 1;
	}
	else
	{
		Node* curr= top;
		while (curr->pNext != nullptr)
		{
			curr = curr->pNext;
		}
		curr->pNext = new Node(data);
		size++;
	}
}

bool Stack::pop()
{


	Node* curr_del = top;
	Node* curr= top;

	if (top == nullptr)
	{
		return false;
	}

	if (top->pNext == nullptr)
	{
		curr_del = top;

		delete curr_del;
		top = nullptr;

		return false;
	}

	while (curr_del->pNext != nullptr)
	{

		curr = curr_del;
		curr_del = curr_del->pNext;

	}


	curr->pNext = nullptr;

	delete curr_del;

	return true;

}

void Stack::MakeNull()
{
	Node* curr = top;


	while (pop())
	{}

}

Data Stack::Retrieve(int pos)
{
	int cx = 0;
	Node* curr = top;
	Data data_error;
	data_error.value = 0;

	while (cx != pos)
	{
		curr = curr->pNext;

		cx++;
		if (cx == size)
		{
			return (data_error);
		}
	}

	return(curr->data);
}


void Stack::Display()
{

	Node* curr = top;
	int cx = 0;

	if (curr == nullptr)
	{
		return;
	}
	else
	{
		while (curr != nullptr)
		{
			cout << cx << ": ";
			curr->data.Display();
			cout << endl;

			cx++;
			curr = curr->pNext;
		}
	}
}