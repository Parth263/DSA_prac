#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
};

class BST
{

public:
	node *root;
	int cnt;

	BST()
	{
		root = NULL;
		cnt = 0;
	}

	void insert();
	int search(int key);
	void inorder(node *root);
	void smallest();
	void largest();
	void mirror(node *r);
	int height(node *r);
};

void BST::insert()
{
	node *new_node, *temp;
	int flag = 0;
	new_node = new node();

	new_node->left = NULL;
	new_node->right = NULL;

	cout << "\n ENter the Node value";
	cin >> new_node->data;

	if (root == NULL)
	{
		root = new_node;
	}
	else
	{
		temp = root;

		while (flag == 0)
		{
			if (new_node->data < temp->data)
			{

				if (temp->left == NULL)
				{
					temp->left = new_node;
					flag = 1;
				}
				else
				{
					temp = temp->left;
				}
			}
			else if (new_node->data > temp->data)
			{
				if (temp->right == NULL)
				{

					temp->right = new_node;
					flag = 1;
				}
				else
				{
					temp = temp->right;
				}
			}
			else
			{
				cout << "data  already exits";
			}
		}
	}
}

int BST::search(int key)
{
	node *temp;
	temp = root;

	while (1)
	{
		if (key < temp->data)
		{
			if (temp->left != NULL)
			{
				temp = temp->left;
			}
			else
				return (0);
		}
		else if (key > temp->data)
		{
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			else
				return (0);
		}
		else
		{
			return 1;
		}
	}
}

void BST::inorder(node *temp)
{
	if (temp != NULL)
	{
		inorder(temp->left);
		cout << temp->data << " ";
		inorder(temp->right);
	}
}

void BST::largest()
{
	node *temp;
	temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	cout << temp->data;
}
void BST::smallest()
{
	node *temp;
	temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	cout << temp->data;
}
void BST::mirror(node *r)
{
	if (r != NULL)
	{
		node *temp;
		temp = r->left;
		r->left = r->right;
		r->right = temp;
		mirror(r->left);
		mirror(r->right);
	}
}

int BST::height(node *r)
{
	int left_height, right_height;
	if (r == NULL)
		return 0;
	if (r->left == NULL && r->right == NULL)
		return 0;

	left_height = height(r->left);
	right_height = height(r->right);

	if (left_height > right_height)
		return (left_height + 1);

	else
		return (right_height + 1);
}

int main()
{
	BST b;
	int ch, key;

	do
	{
		cout << "\n======Menu======";
		cout << "\n 1.insert";
		cout << "\n 2.search";
		cout << "\n 3.display inorder";
		cout << "\n 4.display preorder";
		cout << "\n 5.display postorder";
		cout << "\n 6.smallest node";
		cout << "\n 7.largest node";
		cout << "\n 8.Mirror of tree";
		cout << "\n 9.height of tree";

		cout << "\n exit";

		cout << "\n Enter your choice";
		cin >> ch;

		switch (ch)
		{
		case 1:
			b.insert();
			break;

		case 2:
			cout << "\n Enter Element to be search";
			cin >> key;

			if (b.search(key))
			{
				cout << "ELement found";
			}
			else
			{
				cout << "ELement not found";
			}
			break;

		case 3:
			cout << "Inorder";
			b.inorder(b.root);
			break;

		case 4:
			cout << "preorder";
			break;

		case 5:
			cout << "postorder";
			break;

		case 6:
			cout << "Smallest node: ";
			b.smallest();
			break;

		case 7:
			cout << "Largest node: ";
			b.largest();
			break;

		case 8:
			cout << "Mirror nodes: ";
			b.mirror(b.root);
			b.inorder(b.root);

			break;

		case 9:
			cout << "Height of tree";
			cout << "height of tree :  " << b.height(b.root);
			break;
		default:
			break;
		}
	} while (ch <= 8);

	return 0;
}

//OUTPUT
/*======Menu======
 1.insert
 2.search
 3.display inorder
 4.display preorder
 5.display postorder
 6.smallest node
 7.largest node
 8.Mirror of tree
 9.height of tree
 exit
 Enter your choice1

 ENter the Node value5

======Menu======
 1.insert
 2.search
 3.display inorder
 4.display preorder
 5.display postorder
 6.smallest node
 7.largest node
 8.Mirror of tree
 9.height of tree
 exit
 Enter your choice1

 ENter the Node value4

======Menu======
 1.insert
 2.search
 3.display inorder
 4.display preorder
 5.display postorder
 6.smallest node
 7.largest node
 8.Mirror of tree
 9.height of tree
 exit
 Enter your choice1

 ENter the Node value9

======Menu======
 1.insert
 2.search
 3.display inorder
 4.display preorder
 5.display postorder
 6.smallest node
 7.largest node
 8.Mirror of tree
 9.height of tree
 exit
 Enter your choice3
Inorder4 5 9
======Menu======
 1.insert
 2.search
 3.display inorder
 4.display preorder
 5.display postorder
 6.smallest node
 7.largest node
 8.Mirror of tree
 9.height of tree
 exit
 Enter your choice6
Smallest node: 4
======Menu======
 1.insert
 2.search
 3.display inorder
 4.display preorder
 5.display postorder
 6.smallest node
 7.largest node
 8.Mirror of tree
 9.height of tree
 exit
 Enter your choice9
Height of treeheight of tree :  1*/

// This C++ program implements a basic hash table using a simple linear probing technique for collision resolution. It is organized into two classes: `Hashtable` to represent individual entries in the hash table and `Hashing` to manage the hash table itself. Let's walk through the code step-by-step:

// ### Class Definitions

// #### 1. Class `Hashtable`
// ```cpp
// class Hashtable
// {
// public:
//     int key;          // Stores the key of the hash entry
//     long int mob_number; // Stores the mobile number, which acts as the value in the hash table
// };
// ```
// This class contains two data members:
// - `key`: an integer that represents the index position in the hash table.
// - `mob_number`: a long integer that holds the mobile number associated with the key.

// #### 2. Class `Hashing`
// ```cpp
// class Hashing
// {
//     Hashtable t[10]; // Array of `Hashtable` objects, effectively the hash table with 10 slots
//     int i;           // Utility variable used for loops

// public:
//     Hashing();       // Constructor to initialize the hash table
//     void insert();   // Method to insert a mobile number into the hash table
//     void display();  // Method to display the contents of the hash table
//     void search();   // Search method declaration (not implemented in the provided code)
// };
// ```
// This class manages the hash table operations:
// - `t[10]`: This array holds the hash table entries.
// - The `Hashing()` constructor initializes the hash table with default values.
// - The `insert()` and `display()` methods manage data insertion and visualization respectively.

// ### Constructor `Hashing()`
// ```cpp
// Hashing()
// {
//     for (i = 0; i < 10; i++)
//     {
//         t[i].key = i;        // Set key as the index position
//         t[i].mob_number = -1; // Initialize with -1 indicating empty slots
//     }
// }
// ```
// The constructor sets each slot's key to its index and initializes `mob_number` to -1, indicating that the slot is empty.

// ### Method `display()`
// ```cpp
// void Hashing::display()
// {
//     cout << "Key\t" << "number\n";
//     for (int i = 0; i < 10; i++)
//     {
//         cout << t[i].key << " \t " << t[i].mob_number << "\n";
//     }
// }
// ```
// This method prints the keys and their corresponding mobile numbers. If a mobile number is `-1`, it indicates that the slot is empty.

// ### Method `insert()`
// ```cpp
// void Hashing::insert()
// {
//     long int temp_num;
//     int position;
//     cout << "\n Enter your mobile number ";
//     cin >> temp_num;
//     position = temp_num % 10;  // Hash function: mod 10

//     if (t[position].mob_number == -1)
//     {
//         t[position].mob_number = temp_num; // If no collision, place the number
//     }
//     else
//     {
//         cout << "collision occur";
//         int original_position = temp_num % 10;
//         int position = (original_position + 1) % 10;
//         while (position != original_position && t[position].mob_number != -1)
//         {
//             position = (position + 1) % 10; // Linear probing to find an empty slot
//         }
//         if (position == original_position)
//         {
//             cout << "\nHashTable is Full";
//         }
//         t[position].mob_number = temp_num; // Place the number in the found slot
//     }
// }
// ```
// This method prompts the user for a mobile number and uses `temp_num % 10` as a simple hash function to determine the array index:
// - If there is no collision (the slot is empty), it stores the number.
// - If there is a collision, it uses linear probing to find an empty slot, wrapping around if necessary. If it wraps around to the original position, it declares the table full.

// ### `main()` Function
// ```cpp
// int main()
// {
//     Hashing h;
//     int ch;
//     do
//     {
//         cout << "\n 1.Insert";
//         cout << "\n 2.display";
//         cout << "\n Enter a choice";
//         cin >> ch;
//         switch (ch)
//         {
//             case 1:
//                 h.insert();
//                 break;
//             case 2:
//                 h.display();
//                 break;
//             default:
//                 cout << "\n Invalid choice";
//         }
//     } while (ch <= 2);
//     return 0;
// }
// ```
// The `main()` function creates an instance of `Hashing` and provides a basic menu for the user to insert mobile numbers or display the hash table. It continues to present the menu as long as the user selects either `1` (Insert) or `2` (Display).

// ### Output Example
// The provided output example