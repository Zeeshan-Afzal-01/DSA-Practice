#include<iostream>
class Node {
public:
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};
class Linkedlist {
public:
	Node* head;
	Node* tail;

	Linkedlist() : head(nullptr), tail(nullptr) {}

	void taiappend(int value) {
		Node* newnode = new Node(value);
		if (head == nullptr && tail == nullptr)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}

	}
	void headappend(int value) {
		Node* newnode = new Node(value);
		if (head == nullptr && tail == nullptr) {
			head = newnode;
			tail = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}
	
	void display() {
		Node* current = head;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	void asc()
	{
		Node* current = head;
		int count = 0;
		while (current != nullptr) {
			count++;
			current = current->next;
		}


		for (int i = 0; i < count; i++)
		{
			current = head;
			for (int j = i + 1; j < count; j++)
			{
				if (current->data > current->next->data)
				{
					int temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
				}
				current = current->next;
			}
		}
	}
	void removedup()
	{
		Node* current = head;

		while (current != nullptr)
		{
			Node* runner = current;
			while (runner->next != nullptr)
			{
				if (current->data == runner->next->data)
				{
					Node* temp = runner->next;
					runner->next = runner->next->next;
					delete temp;
				}
				else
				{
					runner = runner->next;
				}
			}
			current = current->next;
		}
	}

};
int main() {
	Linkedlist mylist;

	mylist.taiappend(0);
	mylist.taiappend(1);
	mylist.taiappend(2);
	mylist.taiappend(0);
	mylist.taiappend(1);
	mylist.taiappend(2);

	mylist.display();

	std::cout << std::endl << "Remove Duplicate" << std::endl;
	mylist.removedup();
	mylist.display();

	std::cout << std::endl << "Head Append" << std::endl;
	mylist.headappend(3);
	mylist.headappend(4);


	mylist.display();

	std::cout << std::endl << "After ascending " << std::endl;
	mylist.asc();
	mylist.display();




	return 0;
}