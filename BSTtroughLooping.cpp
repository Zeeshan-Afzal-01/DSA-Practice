#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;

	node()
	{
		data = 0;
		left = nullptr;
		right = nullptr;
	}
};
class bst {
public:
	node* root;

	bst()
	{
		root = nullptr;
	}

	void insert(int data)
	{
		node* newnode = new node;
		newnode->data = data;

		if (root == nullptr)
		{
			root = newnode;
			return;
		}
		else
		{
			node* temp = root;

			while (true)
			{
				if (data < temp->data)
				{
					if (temp->left == nullptr)
					{
						temp->left = newnode;
						break;
					}
					else
					{
						temp = temp->left;
					}
				}
				else if (data > temp->data)
				{
					if (temp->right == nullptr)
					{
						temp->right = newnode;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
			}
		}
	}
	void findmin()
	{
		node* current = root;
		while (1)
		{
			if (current->left == nullptr)
			{
				cout << "The Minimum value in BST: " << current->data;
				break;
			}
			else
			{
				current = current->left;
			}
		}
	}
	void findax()
	{
		node* current = root;
		while (1)
		{
			if (current->right == nullptr)
			{
				cout << "The Maximum value in BST: " << current->data;
				break;
			}
			else
			{
				current = current->right;
			}
		}
	}
	void FindMaxMin()
	{
		node* current = root;
		int max = 0;
		int min = 0;
		while (1)
		{
			if (current->right == nullptr)
			{
				max = current->data;
				break;
			}
			else
			{
				current = current->right;
			}
		}
		current = root;
		while (1)
		{
			if (current->left == nullptr)
			{
				min = current->data;
				break;
			}
			else
			{
				current = current->left;
			}
		}

		cout << "The Sum of Max and Min of BST Value is: " << max + min;

	}

	void search(int key)
	{
		node* current = root;
		while (1)
		{
			if (current == nullptr)
				return;
			else if (current->data == key)
			{
				cout << key << " is Found in BST ";
				break;
			}
			else if (current->data > key)
			{
				if (current->data == key)
				{
					cout << key << " is Found in BST ";
					break;
				}
				else if (current->left == nullptr)
				{
					cout << key << " is not found in BST";
					break;
				}
				else
				{
					current = current->left;
				}
			}
			else if (current->data < key)
			{
				if (current->data == key)
				{
					cout << key << " is Found in BST ";
					break;
				}
				else if (current->right == nullptr)
				{
					cout << key << " is not found in BST";
					break;
				}
				else
				{
					current = current->right;
				}
			}
		}

	}
	void deletenode(int key)
	{
		node* parent = nullptr;
		node* current = root;
		bool found = false;

		// Find the node to delete and its parent
		while (current != nullptr)
		{
			if (current->data == key)
			{
				found = true;
				break;
			}
			parent = current;
			if (key < current->data)
				current = current->left;
			else
				current = current->right;
		}

		if (!found)
		{
			cout << "Key not found in BST" << endl;
			return;
		}

		// Case 1: Node to be deleted has no children
		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent == nullptr)
				root = nullptr;
			else if (parent->left == current)
				parent->left = nullptr;
			else
				parent->right = nullptr;
			delete current;
		}
		// Case 2: Node to be deleted has one child
		else if (current->left == nullptr)
		{
			if (parent == nullptr)
				root = current->right;
			else if (parent->left == current)
				parent->left = current->right;
			else
				parent->right = current->right;
			delete current;
		}
		else if (current->right == nullptr)
		{
			if (parent == nullptr)
				root = current->left;
			else if (parent->left == current)
				parent->left = current->left;
			else
				parent->right = current->left;
			delete current;
		}
		else
		{
			node* successorParent = current;
			node* successor = current->right;
			while (successor->left != nullptr)
			{
				successorParent = successor;
				successor = successor->left;
			}
			current->data = successor->data;
			// Now, we need to delete the successor, which could have at most one right child
			if (successorParent == current)
				successorParent->right = successor->right;
			else
				successorParent->left = successor->right;
			delete successor;
		}
	}



	void displaybst(node* current)
	{
		if (current != nullptr)
		{
			//inorder traversal
			displaybst(current->left);
			cout << current->data << " ";
			displaybst(current->right);

		}
	}
	void display()
	{
		displaybst(root);
	}
};
int main()
{
	bst b1;
	b1.insert(50);
	b1.insert(30);
	b1.insert(20);
	b1.insert(40);
	b1.insert(70);
	b1.insert(60);
	b1.insert(55);
	b1.insert(80);
	b1.insert(75);
	b1.insert(89);


	b1.display();

	cout << "\n";
	b1.findmin();

	cout << "\n";
	b1.findax();

	cout << "\n";
	b1.FindMaxMin();

	cout << "\n";
	b1.search(22);

	cout << "\n";
	b1.search(60);

	cout << "\n";
	b1.deletenode(80);

	b1.display();
	return 0;
}