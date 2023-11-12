#include<iostream>
struct Node {
	int data;
	Node* next;

	Node() : data(NULL), next(nullptr) {}
};
class SinglyLinkedList {

private:
	Node* head;
	Node* tail;
public:
	SinglyLinkedList() : head(nullptr), tail(nullptr) {}

	void append(int value)
	{
		Node* NewNode = new Node;
		NewNode->data = value;
		NewNode->next = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			head = NewNode;
			tail = NewNode;
		}
		else
		{
			tail->next = NewNode;
			tail = NewNode;
		}

	}

	void DeleteMiddle()
	{
		Node* current = head;
		int length = 0;

		while (current != nullptr)
		{
			length++;
			current = current->next;
		}

		delete current;
		current = head;

		for (int i = 0; i < length / 2; i++)
		{
			current = current->next;
		}

		Node* MiddleNode = current;
		Node* temp = head;




		if (length % 2 == 0)
		{

			while (temp->next->next != MiddleNode)
			{
				temp = temp->next;
			}
			Node* DeleteSecondNode = temp->next;
			temp->next = MiddleNode->next;

			delete MiddleNode;
			delete DeleteSecondNode;

		}
		else
		{
			while (temp->next != MiddleNode)
			{
				temp = temp->next;
			}
			temp->next = MiddleNode->next;
			delete MiddleNode;
		}
	}

	void display()
	{
		Node* current = head;
		std::cout << "Linked List is : " << std::endl;
		while (current != nullptr)
		{
			std::cout << current->data << " -> ";

			if (current->next == nullptr)
			{
				std::cout << "Null" << std::endl;
			}
			current = current->next;
		}
		delete current;

	}
};



int main()
{


	SinglyLinkedList mylist;


	std::cout << "Enter the Value for Linked List (For Exit Press -1) :" << std::endl;
	int i = 0;
	while (1) {
		int value;
		std::cout << "Enter " << i + 1 << " Value: ";
		std::cin >> value;
		i++;

		if (value == -1)
			break;

		mylist.append(value);
	}






	mylist.DeleteMiddle();


	mylist.display();



}