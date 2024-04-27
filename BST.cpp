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





// Absolutely! Let's break down the provided `BST::insert()` function and explain its purpose within a Binary Search Tree (BST).

// **Understanding BSTs**

// Before diving into the code, here's a quick refresher on Binary Search Trees:

// * **BST Property:** A BST is a special type of binary tree where nodes are arranged in a specific order:
//     * **Left Subtree:** All nodes in the left subtree of a node have values less than the node's value.
//     * **Right Subtree:** All nodes in the right subtree of a node have values greater than the node's value.
// * **Purpose:** This organized structure makes searching, insertion, and deletion efficient in BSTs.

// **Code Breakdown**

// The `BST::insert()` function is designed to insert a new node with a given value into the correct position within a BST, maintaining the BST property. Here's how it works:

// 1. **Node Creation:**
//    * `node *new_node, *temp;` : Declares two node pointers, `new_node` for the node to be inserted, and `temp` for traversing the tree.
//    * `new_node = new node();` :  Allocates memory for the new node.
//    * `new_node->left = NULL; new_node->right = NULL;`: Initializes the new node's left and right child pointers to NULL.
//    * `cout << "\n Enter the Node value"; cin >> new_node->data;` : Prompts the user to enter the value and stores it in the `data` field of the new node.

// 2. **Empty Tree Case:**
//    * `if (root == NULL)` : Checks if the tree is empty (i.e., has no root node). If it is, the new node becomes the root of the tree.

// 3. **Tree Traversal and Insertion:**
//    * `else`: If the tree is not empty, a `while` loop is used to find the appropriate location to insert the new node.
//    * `temp = root` : The traversal starts from the root node.
//    * **Inside the while loop:**
//       *  **Comparison:** Compares the value in `new_node` with the current `temp` node:
//            * `new_node->data < temp->data` : If the new node's value is less, move to the left subtree (`temp = temp->left`).
//            * `new_node->data > temp->data` : If the new node's value is greater, move to the right subtree (`temp = temp->right`).
//       *  **Insertion Point:** If either `temp->left` or `temp->right` is NULL, it means the correct position to insert the new node has been found. It  assigns the `new_node` to the appropriate child of `temp`.

// 4.  **Duplicate Handle:**
//      * `else { cout << "data already exists"; }`:  This part (optional) handles the case where a duplicate value is attempted to be inserted. 

// **Key Idea:** The `insert` function ensures that after the insertion is completed, the tree still adheres to the fundamental properties of a Binary Search Tree. 

// **Let me know if you want to explore other BST operations (like searching or deletion) or discuss alternative insertion approaches!** 


// The `search` function in the `BST` (Binary Search Tree) class is designed to check whether a given integer value (`key`) exists in the tree. This function returns `1` if the key is found and `0` if it is not found. Here's a detailed breakdown of the logic:

// ### Function Definition

// ```cpp
// int BST::search(int key)
// {
//     node *temp;
//     temp = root;

//     while (1)
//     {
//         if (key < temp->data)
//         {
//             if (temp->left != NULL)
//             {
//                 temp = temp->left;
//             }
//             else
//                 return (0);
//         }
//         else if (key > temp->data)
//         {
//             if (temp->right != NULL)
//             {
//                 temp = temp->right;
//             }
//             else
//                 return (0);
//         }
//         else
//         {
//             return 1;
//         }
//     }
// }
// ```

// ### Step-by-Step Logic

// 1. **Initialize Node Pointer**:
//    - `temp` is initialized to point to the `root` of the BST. This is the starting point for the search.

// 2. **Infinite Loop**:
//    - The function uses a `while (1)` loop, which is an infinite loop that will continue until explicitly broken out of with a `return` statement.

// 3. **Key Comparison**:
//    - Inside the loop, the function first checks if the `key` is less than the `data` stored at the current node (`temp->data`).

// 4. **Traverse Left**:
//    - If `key < temp->data`, the function then checks if there is a left child (`temp->left != NULL`):
//      - If there is a left child, it updates `temp` to point to this child, effectively moving left down the tree.
//      - If there is no left child (`temp->left == NULL`), it means the key cannot be present in the tree (since it would have to be in the left subtree of this node), so the function returns `0`.

// 5. **Traverse Right**:
//    - If `key > temp->data`, the function similarly checks if there is a right child:
//      - If there is a right child, `temp` is updated to point to this child, moving right down the tree.
//      - If there is no right child (`temp->right == NULL`), this also means the key is not present in the tree, and it returns `0`.

// 6. **Key Found**:
//    - If `key == temp->data`, the function finds that the current node holds the key value being searched for. Therefore, it returns `1`, indicating the key is found.

// ### Key Points

// - **Efficiency**: The time complexity of searching in a BST is O(h), where h is the height of the tree. In the best case (balanced tree), this is O(log n), and in the worst case (degenerated tree, similar to a linked list), it is O(n).
// - **Unconditional Loop**: The use of `while (1)` is based on the assumption that the search will always conclude by either finding the node or reaching a leaf node (null child). It would be safer in practice to guard against possible errors by checking if `temp` itself is not null before trying to access `temp->data`.
// - **Return Values**: The function uses integer return values (0 and 1) to indicate false and true conditions, which could also be implemented using a boolean type for clarity (`true` for found, `false` for not found).

// This search method is fundamental for many operations in a BST, such as deletion, balancing operations, and data retrieval, providing a foundational mechanism for navigating and manipulating the tree based on ordered binary search properties.



// Absolutely! Let's analyze each of the functions within your BST implementation.

// **1. `BST::inorder(node *temp)`**

// * **Purpose:** Performs an in-order traversal of the Binary Search Tree.
// * **Mechanism:**
//    * **Base Case:** `if(temp != NULL)`: If the current node is not empty... 
//    * **Recursion:**
//       * `inorder(temp->left)`: Traverse the left subtree recursively.
//       * `cout << temp->data << " ";`: Print the value of the current node.
//       * `inorder(temp->right)`: Traverse the right subtree recursively.

// **2. `BST::largest()`**

// * **Purpose:** Finds the node with the largest value in the BST.
// * **Mechanism:**
//     * **Initialization:** `temp = root`: Start from the root node.
//     * **Traversal:** `while (temp->right != NULL) { temp = temp->right;}` : In a BST, the largest value is always in the rightmost node. So, traverse down the rightmost path until you find a node with no right child.
//     * **Output:**  `cout << temp->data;` : Print the value of this rightmost node.

// **3. `BST::smallest()`**

// * **Purpose:** Finds the node with the smallest value in the BST.
// * **Mechanism:**
//     * **Initialization:** `temp = root`: Start from the root node.
//     * **Traversal:** `while (temp->left != NULL) { temp = temp->left;}` :  In a BST, the smallest value is in the leftmost node. So, traverse down the leftmost path until you find a node with no left child.
//     * **Output:**  `cout << temp->data;` : Print the value of this leftmost node.

// **4. `BST::mirror(node *r)`** 

// * **Purpose:** Creates the mirror image of the BST. (Left and right subtrees are swapped for each node.)
// * **Mechanism:**
//     * **Base Case:** `if (r != NULL)`: If the current node is not empty...
//     * **Swapping:**  
//        * `temp = r->left; r->left = r->right; r->right = temp;`: Swap the left and right subtrees of the current node.
//     * **Recursion:** `mirror(r->left); mirror(r->right);` : Recursively mirror the left and right subtrees. 

// **5. `BST::height(node *r)`**

// * **Purpose:**  Calculates the height of the BST (or a subtree). The height is the number of edges along the longest path from the root to a leaf node.
// * **Mechanism:**
//     * **Base Case 1:**  `if (r == NULL) return 0;` : If the current node is empty, the height is 0. 
//     * **Base Case 2:** `if (r->left == NULL && r->right == NULL) return 0;` : If the node is a leaf (no children), the height is 0.
//     * **Recursion:**
//       * `left_height = height(r->left);` : Calculate the height of the left subtree.
//       * `right_height = height(r->right);` : Calculate the height of the right subtree.
//     * **Height Calculation:**  Compares the heights of the left and right subtrees, and  returns 1 plus the height of the taller subtree.

// **Feel free to ask if you'd like a more detailed explanation of a specific function or want to explore how these functions work together within the larger BST context!** 
