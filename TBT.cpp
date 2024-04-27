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

// Absolutely! Let's revisit in-order, pre-order, and post-order tree traversals. Here's a breakdown of each, including their specific order and common use cases.

// **Core Concept**

// These traversals are different ways to systematically visit all nodes in a tree. Their names refer to the order in which the **root node (N)** is visited relative to its **left (L)** and **right (R)** subtrees.

// **1. In-Order Traversal (L, N, R)**

// * **Process:**
//     1. Traverse the left subtree recursively.
//     2. Visit the root node.
//     3. Traverse the right subtree recursively.

// * **Key Feature:** In a Binary Search Tree (BST), in-order traversal visits nodes in ascending order of their values.

// * **Common Uses:**
//     * Retrieve elements of a BST in sorted order.
//     * Convert a BST into a doubly linked list.

// **2. Pre-Order Traversal (N, L, R)**

// * **Process:**
//     1. Visit the root node.
//     2. Traverse the left subtree recursively.
//     3. Traverse the right subtree recursively.

// * **Key Feature:** Pre-order traversal can help replicate or copy a tree.

// * **Common Uses:**
//     * Create a prefix expression from an expression tree.
//     * Serialize a tree (convert it into a format for saving or transferring).

// **3. Post-Order Traversal (L, R, N)**

// * **Process:**
//     1. Traverse the left subtree recursively.
//     2. Traverse the right subtree recursively.
//     3. Visit the root node.

// * **Key Feature:** Post-order traversal is useful when you need to process child nodes before the parent.

// * **Common Uses:**
//     * Create a postfix expression from an expression tree.
//     * Delete a tree (ensuring children are deleted before parents).

// **Example**

// Consider the following tree:

// ```
//         8
//        / \
//       3   10
//      / \
//     1   6
// ```

// * **In-order:** 1, 3, 6, 8, 10
// * **Pre-order:** 8, 3, 1, 6, 10
// * **Post-order:** 1, 6, 3, 10, 8

// **Let me know if you'd like a code example demonstrating any of these traversals or have a specific application you'd like to discuss!** 


// Absolutely! Let's delve into the concept of threaded binary trees.

// **What is a Threaded Binary Tree?**

// A threaded binary tree is a modification of the standard binary tree that aims to make tree traversals more efficient and to overcome some of the space wastage of regular binary trees. Here's how:

// * **Null Pointers? Not Anymore!** Normally, in a binary tree, if a node doesn't have a left or right child, its corresponding pointer fields are set to NULL. Threaded binary trees utilize these NULL pointers to store additional information for easier traversal.

// * **Threads:** A thread is a pointer that connects a node to its successor (for in-order traversal) or predecessor (for reverse in-order traversal), depending on the type of threading.

// **Types of Threaded Binary Trees**

// 1. **Single Threaded (Right Threaded):** 
//    * If a node's right child is NULL, the right pointer instead points to the in-order successor of that node.

// 2. **Double Threaded:**  
//    * If a node's left child is NULL, the left pointer points to the in-order predecessor.
//    * If the right child is NULL, it points to the in-order successor. 

// **Structure Modification**

// Along with the standard left and right child pointers, a node in a threaded binary tree includes a boolean flag to indicate whether a pointer is a normal child pointer or a thread:

// ```c++
// struct Node {
//   int data;
//   Node *left, *right;
//   bool isThread; // true if the pointer is a thread, false otherwise
// };
// ```

// **Advantages of Threaded Binary Trees**

// * **Faster Traversal:** In-order traversal (and sometimes reverse in-order) can be done without the need for recursion or a stack, making traversals more time and space efficient.
// * **Space Utilization:**  Threaded binary trees can slightly improve space usage by replacing some NULL pointers with useful information.

// **Disadvantages**

// * **Increased Complexity:** Implementation and code maintenance are more complex than in regular binary trees.
// * **Limited Applicability:** The benefits are primarily seen in in-order traversals. Other types of traversals don't necessarily gain the same advantages.

// **When Are They Used?**

// Threaded binary trees are less common in modern use cases. They can be helpful in situations where:

// * In-order traversals are extremely frequent.
// * Memory is a major constraint.

// **Let me know if you'd like to explore a specific type of threaded binary tree with an illustration or code example, or if you want to compare them to standard binary trees!**




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