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
	node* pop()
{
    if (!isempty())
    {
        return (a[top--]);
    }
    else
    {
        cout << "Stack is empty...!";
        return NULL; // or throw an exception
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







// An expression tree is a binary tree used to represent expressions in a way that facilitates their evaluation. In an expression tree, each leaf node represents an operand (such as a variable or a constant), and each internal node represents an operator.

// For example, consider the infix expression `(A + B) * (C - D)`. It can be represented by the following expression tree:

// ```
//         *
//        / \\
//       +   -
//      / \\ / \\
//     A  B C  D

// ```

// ### Operations on Expression Trees:

// 1. **Creating an Expression Tree from an Expression:**
//     - To create an expression tree from an infix expression, we can use the following steps:
//         1. Convert the infix expression to a postfix expression.
//         2. Use a stack to build the expression tree from the postfix expression.
//     - For example, the infix expression `(A + B) * (C - D)` can be converted to the postfix expression `A B + C D - *`, which can then be used to create the expression tree.
// 2. **Traversal of Expression Tree:**
//     - There are three common ways to traverse an expression tree:
//         1. **Pre-order traversal:** Visit the root node first, then recursively do a pre-order traversal of the left subtree, followed by a pre-order traversal of the right subtree.
//         2. **In-order traversal:** Recursively do an in-order traversal of the left subtree, visit the root node, and then do an in-order traversal of the right subtree. In an expression tree, this gives the infix notation of the expression.
//         3. **Post-order traversal:** Recursively do a post-order traversal of the left subtree, followed by a post-order traversal of the right subtree, and then visit the root node. In an expression tree, this gives the postfix notation of the expression.
// 3. **Evaluating an Expression Tree:**
//     - To evaluate an expression tree, we can use a recursive approach:
//         1. If the current node is a leaf node (operand), return its value.
//         2. Otherwise, evaluate the left and right subtrees recursively and apply the operator at the current node to the results.
// 4. **Deleting an Expression Tree:**
//     - To delete an expression tree, we can use a post-order traversal:
//         1. Recursively delete the left subtree.
//         2. Recursively delete the right subtree.
//         3. Delete the current node.

// ### Example:

// Consider the infix expression `((A+B)*C)-(D/E)`.

// 1. **Conversion to Postfix:**
//     - The postfix expression is `AB+C*DE/-`.
// 2. **Expression Tree:**
//     - The expression tree for the postfix expression is:

// ```
//         -
//        / \\
//       *   /
//      / \\ / \\
//     +   C  E
//    / \\
//   A   B

// ```

// 1. **Traversal:**
//     - Pre-order traversal: `*+ABC/DE`
//     - In-order traversal: `A+B*C-D/E`
//     - Post-order traversal: `AB+C*DE/-`
// 2. **Evaluation:**
//     - If A=2, B=3, C=4, D=5, E=6:
//         - ((2+3)*4)-(5/6) = (5*4) - (5/6) = 20 - 0.8333 = 19.1667
// 3. **Deletion:**
//     - Delete the expression tree nodes in a post-order manner.

// Expression trees are useful in compilers, where they are used to convert infix expressions to postfix or prefix forms, and in evaluating mathematical expressions efficiently.

// This C++ code implements an expression tree using a stack data structure. It allows the user to enter a prefix expression, constructs an expression tree from it, and then performs pre-order, in-order, and post-order traversals of the tree.

// Here's a detailed explanation of the code:

// 1. **Node Class (`node`):**
//     - Represents a node in the expression tree.
//     - Contains a `char` data member to store the operator or operand.
//     - Has `left` and `right` pointers to point to the left and right child nodes.
// 2. **Stack Class (`stack`):**
//     - Implements a stack data structure to store nodes of the expression tree.
//     - Contains an array `a` to store nodes and a `top` variable to keep track of the top element.
//     - Provides methods like `push` to push a node onto the stack, `pop` to pop a node from the stack, and `isfull` and `isempty` to check if the stack is full or empty.
// 3. **Expression Tree Class (`Exp_Tree`):**
//     - Manages the creation and traversal of the expression tree.
//     - Contains a `root` pointer to the root of the expression tree.
//     - Provides methods like `create_exp_tree` to create the expression tree from a given prefix expression, `prefix`, `infix`, and `postfix` to perform pre-order, in-order, and post-order traversal of the tree, and `del` to delete the expression tree.
// 4. **Main Function:**
//     - Creates an instance of the `Exp_Tree` class (`ext`).
//     - Calls the `create_exp_tree` method to create the expression tree from a prefix expression entered by the user.
//     - Prints the prefix, infix, and postfix expressions of the created tree using the `prefix`, `infix`, and `postfix` methods.
//     - Deletes the expression tree using the `del` method.

// **Step-by-Step Execution:**

// 1. The user is prompted to enter a prefix expression.
// 2. The code reads the prefix expression and creates an expression tree from it using a stack.
// 3. It iterates through each character of the prefix expression from right to left:
//     - If the character is an operand (A-Z or a-z), it creates a new node and pushes it onto the stack.
//     - If the character is an operator, it pops two nodes from the stack, sets them as the left and right children of the new node, and pushes the new node back onto the stack.
// 4. After processing all characters, the root of the expression tree is the only node left in the stack.
// 5. The code then performs pre-order, in-order, and post-order traversals of the expression tree and prints the corresponding expressions.
// 6. Finally, it deletes the expression tree to free up memory.

// **Example Output:**

// ```
// Enter a Prefix expression: *+AB-CD
// Prefix expression is: * + A B - C D
// Infix expression is: A + B * C - D
// Postfix expression is: A B + C D - *
// Deleted expression is: deleting node * deleting node + deleting node A deleting node B deleting node - deleting node C deleting node D

// ```

// This explanation provides a detailed understanding of how the code works and how it constructs and traverses an expression tree from a prefix expression.