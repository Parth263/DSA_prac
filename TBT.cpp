#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    int lbit, rbit;
};
class TBT
{
public:
    node *root, *head, *temp, *new_node;
    TBT()
    {
        root = NULL;
        head = NULL;
    }
    void preorder();
    void inorder();
    void create_TBT();
};
void TBT::create_TBT()
{
    int flag;
    char ans;
    head = new node();
    head->data = -999;
    head->left = head;
    head->right = head;
    head->lbit = 0;
    head->rbit = 0;
    root = new node();
    cout << "Enter root node: ";
    cin >> root->data;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;
    do
    {
        new_node = new node();
        cout << "Enter the node value: ";
        cin >> new_node->data;
        new_node->lbit = 0;
        new_node->rbit = 0;
        temp = root;
        flag = 0;
        while (flag == 0)
        {
            if (new_node->data < temp->data)
            {
                if (temp->lbit == 0)
                {
                    new_node->left = temp->left;
                    temp->left = new_node;
                    temp->lbit = 1;
                    new_node->right = temp;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (new_node->data > temp->data)
            {
                if (temp->rbit == 0)
                {
                    new_node->right = temp->right;
                    temp->right = new_node;
                    temp->rbit = 1;
                    new_node->left = temp;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                cout << "Data already exist.....!!!";
            }
        }
        cout << "Do you want to continue:";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');
}
void TBT::inorder()
{
    node *temp;
    temp = root;
    int flag = 0;
    if (root == NULL)
    {
        cout << "Tree is empty...!";
    }
    else
    {
        while (temp != head)
        {
            if (temp->lbit == 1 && flag == 0)
            {
                temp = temp->left;
            }
            else
            {
                cout << " " << temp->data;
                if (temp->rbit == 1)
                {
                    temp = temp->right;
                    flag = 0;
                }
                else
                {
                    temp = temp->right;
                    flag = 1;
                }
            }
        }
    }
}
void TBT::preorder()
{
    node *temp;
    temp = root;
    int flag = 0;
    if (root == NULL)
    {
        cout << "Tree is empty...!";
    }
    else
    {
        while (temp != head)
        {
            if (flag == 0)
            {
                cout << " " << temp->data;
            }
            if (temp->lbit == 1 && flag == 0)
            {
                temp = temp->left;
            }
            else
            {
                if (temp->rbit == 1)
                {
                    temp = temp->right;
                    flag = 0;
                }
                else
                {
                    temp = temp->right;
                    flag = 1;
                }
            }
        }
    }
}
int main()
{
    TBT t;
    int choice;
    do
    {
        cout << "\n1.Insert element \n";
        cout << "2.inorder display of threaded binary tree\n";
        cout << "3.preorder display of threded binary tree \n";
        cout << "4.Exit \n";
        cout << "\nEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.create_TBT();
            break;
        case 2:
            cout << "Inorder is: ";
            t.inorder();
            break;
        case 3:
            cout << "Preorder is: ";
            t.preorder();
            break;
        case 4:
            cout << "Exit";
            break;
        }
    } while (choice != 4);
}
//OUTPUT
/*1.Insert element 
2.inorder display of threaded binary tree
3.preorder display of threded binary tree 
4.Exit 

Enter your choice:1
Enter root node: 5
Enter the node value: 4
Do you want to continue:y
Enter the node value: 7
Do you want to continue:y
Enter the node value: 6
Do you want to continue:n

1.Insert element 
2.inorder display of threaded binary tree
3.preorder display of threded binary tree 
4.Exit 

Enter your choice:2
Inorder is:  4 5 6 7
1.Insert element
2.inorder display of threaded binary tree
3.preorder display of threded binary tree
4.Exit

Enter your choice:3
Preorder is:  5 4 7 6
1.Insert element
2.inorder display of threaded binary tree
3.preorder display of threded binary tree
4.Exit

Enter your choice:4
Exit*/

// This C++ program defines and manipulates a Threaded Binary Tree (TBT). A Threaded Binary Tree is a binary tree variant where `NULL` pointers are replaced with links to the in-order predecessor and successor nodes, which facilitates more efficient in-order traversal. The program uses a class structure to encapsulate the operations of the tree, including insertion and tree traversal (in-order and pre-order). Here is an explanation of the code:

// ### Class Definitions

// #### 1. `node`
// ```cpp
// class node
// {
// public:
//     int data;       // Data part of the node (stores integer values)
//     node *left;     // Pointer to the left child
//     node *right;    // Pointer to the right child
//     int lbit, rbit; // Left and right thread indicators (1 indicates a thread, 0 indicates a child)
// };
// ```
// This class represents a node in the threaded binary tree. Each node contains data, pointers to its children, and flags (`lbit`, `rbit`) that indicate whether the pointers are pointing to children (`0`) or to in-order predecessors or successors (`1`).

// #### 2. `TBT`
// ```cpp
// class TBT
// {
// public:
//     node *root, *head, *temp, *new_node;
//     TBT();          // Constructor that initializes the tree
//     void preorder(); // Function to display the tree in preorder
//     void inorder();  // Function to display the tree in inorder
//     void create_TBT(); // Function to create the threaded binary tree
// };
// ```
// This class manages the threaded binary tree. It includes the root and head pointers (the head acts as a dummy node to facilitate easier management of the tree edges), and methods for creating the tree and displaying its contents in order.

// ### Methods Explanation

// #### `create_TBT()`
// ```cpp
// void TBT::create_TBT()
// {
//     // Initialization and node creation logic
//     // Loop to accept new nodes until user decides to stop
//     // Nodes are linked as per the threaded binary tree rules
// }
// ```
// This function initializes the tree, creates the head (dummy) node, and repeatedly accepts input from the user to add nodes to the tree. For each new node, it places it correctly in the tree based on its value and updates pointers and thread indicators according to the tree's structure.

// #### `inorder()`
// ```cpp
// void TBT::inorder()
// {
//     // Logic to traverse the tree in in-order using threads
//     // Handles the special cases when reaching end of threads
// }
// ```
// This function performs an in-order traversal of the tree using threads instead of traditional recursive traversal, which is usually more efficient since it doesn't require stack or recursion.

// #### `preorder()`
// ```cpp
// void TBT::preorder()
// {
//     // Logic to traverse the tree in pre-order using threads
//     // Similar to in-order but visits nodes in "root-left-right" order
// }
// ```
// This function traverses the tree in pre-order. While a fully threaded tree typically facilitates easy in-order traversal, this function is adjusted to follow the pre-order sequence using threads where possible.

// ### Main Function
// ```cpp
// int main()
// {
//     // Menu-driven interaction to perform operations on the threaded binary tree
//     // Users can insert nodes, perform in-order or pre-order traversal, or exit
// }
// ```
// The `main()` function provides a user interface that allows inserting nodes into the tree, performing in-order and pre-order traversals, and exiting the program. It keeps running until the user chooses to exit.

// ### Execution Flow
// The program starts by creating an instance of the `TBT` class. It then presents a menu to the user to insert nodes, display the tree in order or pre-order, or exit. The user can insert multiple nodes to construct the tree as desired, then display the tree's contents in in-order or pre-order, verifying the tree structure through the traversals.

// Overall, this program is a practical implementation of threaded binary trees, showcasing how they can be used to simplify in-order traversal without the need for stack or recursion, leveraging the threads to move efficiently between nodes.