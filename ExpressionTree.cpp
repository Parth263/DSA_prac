#include <iostream>
#include<string>
using namespace std;
class node
{
public:
	char data;
	node *left;
	node *right;
};
class stack
{
public:
	int top;
	node *a[20];
	stack()
	{
		top = -1;
	}
	void push(node *temp)
	{
		if (!isfull())
		{
			a[++top] = temp;
		}
		else
		{
			cout << "Stack is full...!";
		}
	}
	node *pop()
	{
		if (!isempty())
		{
			return (a[top--]);
		}
		else
		{
			cout << "Stack is empty...!";
		}
	}

	int isfull()
	{
		if (top == 19)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	int isempty()
	{
		if (top == -1)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
};
class Exp_Tree
{
public:
	node *root;
	Exp_Tree()
	{
		root = NULL;
	}
	void create_exp_tree();
	void infix(node *temp);
	void prefix(node *temp);
	void postfix(node *temp);
	void del(node *temp);
};
void Exp_Tree::create_exp_tree()
{
	char ch;
	node *new_node, *temp;
	string str;
	int i;
	stack s;

	cout << "\nEnter a Prefix expression:";
	cin >> str;
	for (i = (str.length() - 1); i >= 0; i--)
	{
		ch = str[i];
		new_node = new node();
		new_node->data = ch;
		new_node->left = NULL;
		new_node->right = NULL;

		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			s.push(new_node);
		}
		else
		{
			temp = s.pop();
			new_node->left = temp;
			temp = s.pop();
			new_node->right = temp;
			s.push(new_node);
		}
	}
	root = s.pop();
}
void Exp_Tree::prefix(node *temp)
{
	if (temp != NULL)
	{

		cout << " " << temp->data;
		prefix(temp->left);
		prefix(temp->right);
	}
}
void Exp_Tree::infix(node *temp)
{
	if (temp != NULL)
	{
		infix(temp->left);
		cout << "" << temp->data;
		infix(temp->right);
	}
}
void Exp_Tree::postfix(node *temp)
{
	if (temp != NULL)
	{
		postfix(temp->left);
		postfix(temp->right);
		cout << "" << temp->data;
	}
}
void Exp_Tree::del(node *temp)
{
	// temp=root;
	if (temp == NULL)
		return;
	{
		del(temp->left);
		del(temp->right);
		cout << "\n deleting node " << temp->data;
		delete (temp);
	}
}
int main()
{
	Exp_Tree ext;
	ext.create_exp_tree();
	cout << "\nPrefix expression is: ";
	ext.prefix(ext.root);
	cout << endl;

	cout << "\n Infix expression is :";
	ext.infix(ext.root);
	cout << endl;

	cout << "\n Postfix expression is :";
	ext.postfix(ext.root);
	cout << endl;

	cout << "\n Deleted expression is :";
	ext.del(ext.root);
	cout << endl;
}
//OUTPUT
/*Enter a Prefix expression:++-ab*c+ef/abc

Prefix expression is:  + + - a b * c + e f / a b

 Infix expression is :a-b+c*e+f+a/b

 Postfix expression is :ab-cef+*+ab/+

 Deleted expression is :
 deleting node a
 deleting node b
 deleting node -
 deleting node c
 deleting node e
 deleting node f
 deleting node +
 deleting node *
 deleting node +
 deleting node a
 deleting node b
 deleting node /
 deleting node +

 */


// Let's break down the concept of expression trees:

// **What is an Expression Tree?**

// * **Tree Representation:** An expression tree is a special type of binary tree used to represent mathematical or logical expressions.
// * **Nodes:**  The tree has two types of nodes:
//     * **Operator Nodes:**  Internal nodes of the tree representing operators such as +, -, *, /, %, etc.
//     * **Operand Nodes:** Leaf nodes of the tree representing values (numbers or variables).

// **Structure**

// * **Priority:** Operators deeper in the tree typically have lower precedence than operators higher up.
// * **Sub-expressions:** Each subtree represents a sub-expression within the larger expression.

// **Example**

// Consider the expression: `(5 + 8) * 3`

// Its expression tree would look like this:

// ```
//         *
//        / \
//       +   3
//      / \
//     5   8 
// ```

// **How Are They Constructed?**

// Expression trees are often built using the following concepts:

// * **Infix, Prefix, and Postfix Notations:** An expression tree can be constructed from any of these notations that describe the order in which to apply operators.
// * **Stacks and Parsing:** Stacks can be used to parse expressions and build the tree accordingly.

// **Why Use Expression Trees?**

// * **Evaluation:**  Expression trees provide a structured format for evaluating expressions. You can evaluate the value of the expression by traversing the tree (often in post-order).
// * **Translation:** Expression trees help in translating expressions between different notations (like from infix to postfix).
// * **Optimization:** Compilers can analyze expression trees to optimize how expressions are evaluated by the computer.

// **Applications**

// * **Compilers and Interpreters:**  Building and evaluating expressions.
// * **Formula Editors:**  Representing and manipulating mathematical formulas in spreadsheets or other applications. 
// * **Symbolic Mathematics:** In symbolic computation systems.

// **Let me know if you'd like to delve into the construction of expression trees or a specific application in more detail!** 

// This C++ program defines and manipulates an expression tree from a given prefix (Polish notation) expression. The program consists of several classes and functions designed to construct the tree, traverse it in different orders (prefix, infix, and postfix), and finally delete it. Let's walk through the code step-by-step:

// ### Class Definitions

// #### 1. `node`
// ```cpp
// class node
// {
// public:
//     char data;     // Character to hold the data (operator or operand)
//     node *left;    // Pointer to the left child
//     node *right;   // Pointer to the right child
// };
// ```
// This class represents a single node in the expression tree, which can store a character and has pointers to its left and right children.

// #### 2. `stack`
// ```cpp
// class stack
// {
// public:
//     int top;       // Index of the top element in the stack
//     node *a[20];   // Array of pointers to nodes, representing the stack
//     stack();       // Constructor to initialize the stack
//     void push(node *temp);  // Method to push a node pointer onto the stack
//     node *pop();            // Method to pop a node pointer from the stack
//     int isfull();           // Check if the stack is full
//     int isempty();          // Check if the stack is empty
// };
// ```
// This class manages a stack of node pointers, which is used in the creation of the expression tree. It provides methods for pushing and popping node pointers, as well as checking if the stack is full or empty.

// #### 3. `Exp_Tree`
// ```cpp
// class Exp_Tree
// {
// public:
//     node *root;    // Pointer to the root of the expression tree
//     Exp_Tree();    // Constructor to initialize the expression tree
//     void create_exp_tree(); // Creates an expression tree from a prefix expression
//     void infix(node *temp); // In-order traversal of the tree
//     void prefix(node *temp); // Pre-order traversal of the tree
//     void postfix(node *temp); // Post-order traversal of the tree
//     void del(node *temp);    // Deletes all nodes in the tree
// };
// ```
// This class handles the expression tree. It includes methods for building the tree from a prefix expression, performing different tree traversals, and deleting the tree.

// ### Methods Explanation

// #### `create_exp_tree()`
// ```cpp
// void Exp_Tree::create_exp_tree()
// {
//     char ch;
//     node *new_node, *temp;
//     string str;
//     int i;
//     stack s;

//     cout << "\nEnter a Prefix expression:";
//     cin >> str;
//     for (i = (str.length() - 1); i >= 0; i--)
//     {
//         ch = str[i];
//         new_node = new node();
//         new_node->data = ch;
//         new_node->left = NULL;
//         new_node->right = NULL;

//         if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
//         {
//             s.push(new_node);
//         }
//         else
//         {
//             temp = s.pop();
//             new_node->left = temp;
//             temp = s.pop();
//             new_node->right = temp;
//             s.push(new_node);
//         }
//     }
//     root = s.pop();
// }
// ```
// This function builds an expression tree from a user-inputted prefix expression. It reads the expression from right to left, creating new nodes for each character. If the character is an operand, it is pushed onto the stack. If it is an operator, it pops two nodes from the stack, assigns them as children, and pushes the new sub-tree back onto the stack. The last node on the stack becomes the root of the tree.

// #### Tree Traversal Methods (`prefix()`, `infix()`, `postfix()`)
// These functions recursively traverse the tree:
// - **Prefix**: Visits the root first, then the left subtree, then the right subtree.
// - **Infix**: Visits the left subtree first, then the root, then the right subtree.
// - **Postfix**: Visits the left subtree first, then the right subtree, then the root.

// #### `del()`
// ```cpp
// void Exp_Tree::del(node *temp)
// {
//     if (temp == NULL)
//         return;
//     {
//         del(temp->left);
//         del(temp->right);
//         cout << "\n deleting node " << temp->data;
//         delete (temp);
//     }
// }
// ```
// This function recursively deletes all nodes in the tree starting from the given node. It first deletes both children and then the node itself, displaying a message for each deletion.

// ### Main Function
// ```cpp
// int main()
// {
//     Exp_Tree ext;
//     ext.create_exp_tree();
//     cout << "\nPrefix expression is: ";
//     ext.prefix(ext.root);
//     cout << endl;

//     cout << "\n Infix expression is :";
//     ext.infix(ext.root