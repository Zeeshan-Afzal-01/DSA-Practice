#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
	
};
class queue {
public:
	node* front;
	node* rear;

	queue(): front(nullptr), rear (nullptr) {}

	bool isempty()
	{
		return front == nullptr;
	}

	void enqueue(int val)
	{
		node* newnode = new node;
		newnode->data = val;
		newnode->next = nullptr;

		if (isempty())
		{
			front = newnode;
			rear = newnode;

		}
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}
	void dequeue()
	{
		if (!isempty())
		{
			node* temp = front;
			front = temp->next;
			delete temp;
		}
		else
		{
			cout << "queue is Empty!" << endl;
		}
	}
	int peek()
	{
		return front->data;
	}
};

int main()
{
	queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);

	cout << "Top element of Queue is: " << q1.peek() << endl;

	q1.dequeue();
	q1.dequeue();

	cout << "Top element of Queue is: " << q1.peek() << endl;


	return 0;
}