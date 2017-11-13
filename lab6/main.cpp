#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Node
{
public:
	char value;
	Node* next;
	Node* prev;

	Node(){};
	Node(char v, Node* n = NULL)
	{
		value = v;
		next = n;
	}

	Node(Node* p, char v, Node* n = NULL)
	{
		value = v;
		prev = p;
		next = n;
	}
};

class Stack
{
protected:
	Node* stack_head;

public:
	Stack(){ stack_head = NULL; };
	~Stack()
	{
		Node* node_pointer = stack_head;

		while (node_pointer)
		{
			Node* node_delete = node_pointer;

			node_pointer = node_pointer->next;
			delete node_delete;
		}
	};
	void push(char temp);
	char peek();
	void pop();
};


void Stack::push(char temp)
{
	if (stack_head == NULL)
	{
		stack_head = new Node(temp);
	}
	else
	{
		stack_head = new Node(temp, stack_head);
	}
}

char Stack::peek()
{
	Node* node_pointer = stack_head;

	return node_pointer->value;
}
void Stack::pop()
{
	if (!stack_head)
	{
		cout << "Empty" << endl;
		return;
	}
	else
	{
		stack_head = stack_head->next;
	}
}

class Queue
{
protected:
	Node* queue_first;
	Node* queue_last;
public:
	Queue()
	{
		queue_first = NULL;
		queue_last = NULL;
	};
	~Queue()
	{
		Node* node_pointer = queue_first;

		while (node_pointer)
		{
			Node* node_delete = node_pointer;
			node_pointer = node_pointer->next;
			delete node_delete;
		}
	};
	void addBack(char temp);
	void removeFront();
	char peek();
};

void Queue::addBack(char temp)
{
	if (queue_first == NULL)
	{
		queue_first = new Node(temp);
		queue_last = queue_first;
	}
	else
	{

		Node* node_pointer = queue_first;

		while (node_pointer->next != NULL)
		{
			node_pointer = node_pointer->next;
		}

		node_pointer->next = new Node(node_pointer, temp, NULL);

		while (node_pointer->next != NULL)
		{
			node_pointer = node_pointer->next;
		}

		queue_last = node_pointer;
	}
}

char Queue::peek()
{

	Node* node_pointer = queue_first;

	return node_pointer->value;
}
void Queue::removeFront()
{
	if (!queue_first)
	{
		cout << "Empty" << endl;
		return;
	}
	else
	{
		queue_first = queue_first->next;

		if (queue_first)
		{
			queue_first->prev = NULL;
		}

		else
		{
			queue_first = NULL;
			queue_last = NULL;
		}
	}
}

int main()
{
	srand(time(NULL));
	
	return 0;
}
