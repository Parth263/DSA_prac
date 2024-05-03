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
// Let's dive deeper into the code, explaining each variable and its purpose:

// 1. **Node Class (`node`):**
//    - `int data`: Represents the value stored in the node.
//    - `node *left, *right`: Pointers to the left and right child nodes.
//    - `int lbit, rbit`: Flags indicating whether the left and right pointers are threads or actual child pointers. `lbit` and `rbit` are set to `0` for child pointers and `1` for threads.

// 2. **Threaded Binary Tree Class (`TBT`):**
//    - `node *root`: Pointer to the root node of the binary tree.
//    - `node *head`: Pointer to a special node called the head node, which is used as a sentinel for traversal.

// 3. **`create_TBT()` Function:**
//    - `int flag`: Flag variable used for iteration control.
//    - `char ans`: Stores the user's choice to continue adding nodes.
//    - `new_node`: Pointer to a newly created node.
//    - `temp`: Temporary pointer used for traversal and insertion.
//    - The function first creates the head node with a special value (`-999`) and initializes its pointers and flags.
//    - It then creates the root node based on user input and initializes its pointers and flags.
//    - Inside a do-while loop, it repeatedly creates new nodes, inserts them into the tree based on their values, and updates the tree's structure and thread flags accordingly.
//    - The loop continues as long as the user chooses to add more nodes (`ans == 'Y' || ans == 'y'`).

// 4. **`inorder()` Function:**
//    - `temp`: Temporary pointer used for traversal.
//    - `flag`: Flag variable used for controlling the traversal direction.
//    - The function performs an inorder traversal of the tree, starting from the root.
//    - It checks the `lbit` flag to decide whether to move to the left child or not.
//    - If the `lbit` flag is `1`, it moves to the left child.
//    - If the `lbit` flag is `0`, it prints the current node's value, moves to the right child if the `rbit` flag is `1`, and updates the `flag` accordingly.

// 5. **`preorder()` Function:**
//    - `temp`: Temporary pointer used for traversal.
//    - `flag`: Flag variable used for controlling the traversal direction.
//    - Similar to the `inorder()` function, but it prints the current node's value before moving to its children.
//    - The function checks the `flag` variable to determine whether to print the current node's value before moving to the left child or right child.

// 6. **`main()` Function:**
//    - `TBT t`: Creates an instance of the `TBT` class.
//    - `int choice`: Stores the user's menu choice.
//    - The function presents a menu to the user with options to insert elements, display inorder traversal, display preorder traversal, and exit the program.
//    - It uses a do-while loop to repeatedly display the menu and process the user's choice until the user chooses to exit.

// This code implements a threaded binary tree and provides functionality to create the tree, and traverse it in inorder and preorder. The use of threaded pointers (`lbit` and `rbit`) allows for efficient traversal without using recursion or an explicit stack.

// Certainly! Let's delve deeper into the concepts of Threaded Binary Trees (TBT) and their types, focusing on Inorder Threaded Binary Trees (ITBT) and Preorder Threaded Binary Trees (PTBT):

// // **Threaded Binary Tree (TBT)**:
// // A TBT is a binary tree where every node can have one or two additional threads (pointers) that facilitate traversal without using recursion or a stack. These threads are used to point to other nodes in a specific order, such as inorder or preorder. The primary purpose of using threads is to make traversal more efficient by eliminating the need for stack space or recursive calls.

// **Types of TBT**:
// 1. **Inorder Threaded Binary Tree (ITBT)**:
//    - In an ITBT, each node's left thread points to its inorder predecessor, and the right thread points to its inorder successor.
//    - The inorder predecessor of a node is the node that would appear immediately before it in an inorder traversal of the tree.
//    - The inorder successor of a node is the node that would appear immediately after it in an inorder traversal.

// 2. **Preorder Threaded Binary Tree (PTBT)**:
//    - In a PTBT, each node's left thread points to its preorder predecessor, and the right thread points to its preorder successor.
//    - The preorder predecessor of a node is the node that would appear immediately before it in a preorder traversal of the tree.
//    - The preorder successor of a node is the node that would appear immediately after it in a preorder traversal.

// **Traversal in TBT**:
// 1. **Inorder Traversal**:
//    - In an ITBT, we can perform an inorder traversal without recursion or a stack by following the threaded pointers.
//    - We start from the leftmost node and follow the right thread to move to the next node in the inorder sequence.
//    - This process continues until we reach the rightmost node, which will have its right thread pointing to the head node or null.

// 2. **Preorder Traversal**:
//    - In a PTBT, we can perform a preorder traversal without recursion or a stack by following the threaded pointers.
//    - We start from the root node and move to its left child, printing each node's value along the way.
//    - If a node has no left child, we follow its right thread to move to the next node in the preorder sequence.

// **Advantages of TBT**:
//    - Efficient traversal: TBT allows for efficient traversal of the tree without using recursion or a stack, reducing space complexity.
//    - Simplified algorithms: Traversal and other operations become simpler and more intuitive with the use of threaded pointers.

// In summary, TBTs are binary trees with additional threads that enable efficient traversal. ITBTs and PTBTs use different types of threads to store predecessor and successor nodes, facilitating different types of traversal algorithms.