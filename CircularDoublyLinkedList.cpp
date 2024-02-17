#include<iostream>


struct Node{
	int data;
	Node* next;
	Node* prev;


	Node():data(0), next(nullptr), prev(nullptr){}
};
class CircularLinkedList {
public:
	Node* head;
	
	CircularLinkedList() : head(nullptr) {}

	void append(int value);

	void display() {
		Node* current = head;
		std::cout << "Linked List is : " << std::endl;
		do {
			std::cout << current->data << " -> ";

			if (current->next == head) {
				std::cout << "Null" << std::endl;
			}
			current = current->next;
		} while (current != head);
    
	}

};
void CircularLinkedList::append(int value)
{
	Node* newnode = new Node;
	newnode->data = value;
	if (head == nullptr)
	{
		head = newnode;
		head->next = head;
		head->prev = head;
	}
	else
	{
		Node* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
		newnode->next = head;
	}
}
int main()
{
	CircularLinkedList mylist;
	mylist.append(1);
	mylist.append(2);
	mylist.append(3);
	mylist.append(4);

	mylist.display();

}