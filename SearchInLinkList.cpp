#include <iostream>

struct Node {
    int data;
    Node* next;
        bool isKeyFound = false;
    Node() : data(0), next(nullptr) {}
};

class SinglyLinkedList {

private:
    Node* head;
    Node* tail;
bool isKeyFound = false;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void search(int key)
    {
        Node* current = head;
        int length = 0;
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }

        current = head;
        for (int i = 0; i < length; i++)
        {
            for (int j = i+1; j < length ; j++)
            {
                if (current->data > current->next->data)
                {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                }
                current = current->next;
            }
            current = head;
        }

        current = head;

        while (current != nullptr)
        {
            if (current->data == key)
            {
                isKeyFound = true;
                break;
            }
            current = current->next;
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
		  if (isKeyFound)
            std::cout << "Key is Found" << std::endl;
        else
            std::cout << "Key is Not Found" << std::endl;
    }
};

int main()
{
    std::cout << "\t\t\tDSA Assignment 1 (Task - 3) \n  Name: Zeeshan Afzal \n Regno. L1S22BSSE0174 \n" << std::endl;

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

    int key = 0;
    std::cout << "Enter the Value to Search in LinkedList: ";
    std::cin >> key;
    mylist.search(key);

    mylist.display();

    return 0;
}
