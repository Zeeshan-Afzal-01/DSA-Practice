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

	Linkedlist() : head(nullptr), tail(nullptr){}

	void taiappend(int value){
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
};
int main() {
	Linkedlist mylist;

	mylist.taiappend(0);
	mylist.taiappend(1);
	mylist.taiappend(2);
	

	mylist.display();

	std::cout << std::endl << "Head Append" << std::endl;
	mylist.headappend(1);
	mylist.headappend(2);

	mylist.display();
	return 0;
}