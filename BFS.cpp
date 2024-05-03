/*---------------------------------------------------
Pr no : 06
Title : Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify  the prominent land marks as nodes and perform DFS and BFS on that
-----------------------------------------------------*/

/*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

 GROUP-C-13. Represent a given graph using adjacency matrix/list to perform DFS and
 using adjacency list to perform BFS.
 a) Represent Graph using Adjacency Matrix
 b) Represent Graph using Adjacency List
 c) DFS Traversal on Adjacency Matrix Representation
 d) BFS Traversal on Adjacency List Representation
*/
//header files
#include <iostream>
using namespace std;

int adjMTX[4][4];  //for adjacency matrix
int row = 4;
int col = 4;

struct Node  //for adjancency list
{
    char data;
    struct Node *down, *next;
} *Head;

char vertex(int val)   //function to return vertex name
{
    if (val == 0)
    {
        return 'A';
    }
    else if (val == 1)
    {
        return 'B';
    }
    else if (val == 2)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}
//function to create adjacency matrix
void createAdjMTX()
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout<<"\n Edge from vertex "<<vertex(i)<<" to "<<vertex(j)<<" : ";
            cin>>adjMTX[i][j];
        }
    }
}
//function to display adjacency matrix
void displayAdjMTX()
{
    int i,j;
    for(i = 0;i<row;i++)
    {
        cout<<"\n";
        for(j=0;j<col;j++)
        {
            cout<<"\t"<<adjMTX[i][j];
        }
    }
}

//function to create adjacency list 
void createAdjList()
{
    struct Node *Newnode, *move, *p;
    int i;
    int nodes;
    int edges;

    cout<<"\n\n How many vertices in graph : ";
    cin>>nodes;

    for(i=0;i<nodes;i++)
    {
        Newnode = new struct Node;

        Newnode->data = vertex(i);
        Newnode->down = NULL;
        Newnode->next = NULL;

        if(Head == NULL)
        {
            Head = Newnode;
            move = Head;
        }
        else
        {
            move->down = Newnode;
            move = move->down;
        }
    }

    move = Head;
    p = Head;
    while(move != NULL)
    {
        cout<<"\n How many adjacent vertices for "<<move->data<<":";
        cin>>edges;

        for(i=0;i<edges;i++)
        {
            Newnode = new struct Node;
            cout<<"\n\t Enter an adjacent vertext : ";
            cin>>Newnode->data;
            Newnode->down = NULL;
            Newnode->next = NULL;

            p->next = Newnode;
            p = p->next;
        }

        move = move->down;
        p = move;
    }
}

//function to display adjacency list
void displayAdjList()
{
    struct Node *move,*p;

    move = Head;

    while(move != NULL)
    {
        cout<<"\n\t | "<<move->data<<"|-->";
        p = move->next;
        while (p!=NULL)
        {
            cout<<p->data<<"-->";
            p = p->next;
        }
        cout<<"NULL";
        move = move->down;
        p = move;
    }
}
//main function
int main()
{
    cout<<"\n\n A C++ Program to represent Graph Data Structure using Adjacency Matrix ";
    cout<<"\n\n 1. Creating Adjacency Matrix :";
    createAdjMTX();
    cout<<"\n\n 2. Display Adjacency Matrix :";
    displayAdjMTX();
    cout<<"\n\n 3. Creating Adjacency List :";
    Head = NULL;
    createAdjList();
    cout<<"\n\n 4. Display Adjacency List : ";
    displayAdjList();
    return 0;    
}

// Let's explore Breadth-First Search (BFS) and Depth-First Search (DFS), two fundamental algorithms for traversing graphs.

// **What is a Graph?**

// Before diving in, it's helpful to remember that a graph is a data structure comprising:

// * **Nodes (or Vertices):** The individual points representing items in the graph.
// * **Edges:** The connections or relationships between the nodes.

// **Breadth-First Search (BFS)**

// * **Concept:** BFS explores a graph level by level. 
// * **Analogy:**  Imagine spreading out like a ripple from a central point in a pond.
// * **How It Works:**
//     1. **Start at a node:** Choose a starting node.
//     2. **Visit immediate neighbors:**  Visit all direct neighbors of the starting node. Mark them as visited.
//     3. **Explore level-by-level:**  
//        *  For each of the newly visited neighbors, visit *their* unvisited neighbors and mark them.
//        *  Continue this process, moving outwards from the starting point layer by layer.
//     4. **Queue:**  Often uses a queue to keep track of nodes to visit in order.

// **Depth-First Search (DFS)**

// * **Concept:** DFS prioritizes going deeper into a graph along a single path as far as possible before backtracking. 
// * **Analogy:**  Imagine venturing into a maze, always turning right until you reach a dead end, then going back until you can take a new right turn.
// * **How It Works:**
//     1. **Start at a node:** Choose a starting node.
//     2. **Go as deep as possible:**
//        *  Visit an unvisited adjacent node and mark it as visited.
//        *  Repeat this from the new node, always choosing an unvisited neighbor. 
//     3. **Backtrack:** When no unvisited neighbors exist, backtrack to the previous node and continue.  
//     4. **Stack:**  Often uses a stack to keep track of the path for backtracking.

// **Illustrative Example**

// Consider this graph:

// ```
//      A
//    /   \
//   B --- C
//  / \   /
// D   E- F
// ```

// * **BFS (starting at A):** Might visit nodes in the order A, B, C, D, E, F. 
// * **DFS (starting at A):** Might visit nodes in the order A, B, D, E, C, F. 

// **Common Uses**

// * **BFS:**
//     * **Shortest Path** (unweighted graphs)
//     * **Finding connected components**
//     * **Peer-to-peer networks**

// * **DFS:**
//      * **Finding connected components**
//      * **Topological sorting** (determining dependencies)
//      * **Detecting Cycles**
//      * **Solving puzzles with a limited number of solutions**

// **Which to Choose?**

// The choice between BFS and DFS depends on the problem you're solving and the structure of your graph:

// * **Explore all possibilities, prioritize depth:** DFS
// * **Finding shortest paths:** BFS
// * **Dense vs. Sparse Graphs:** If the graph is sparse (few edges), DFS tends to be more space-efficient than BFS. 

// **Let me know if you'd like a step-by-step visualization of either algorithm or examples of real-world scenarios where each is applied!**



// Absolutely! Let's break down this C++ code which demonstrates graph representation using both adjacency matrices and adjacency lists.

// **Global Variables**

// * `adjMTX[4][4]`: A 4x4 matrix to represent the adjacency matrix. It's fixed in size, implying a graph with a maximum of 4 nodes.
// * `row`, `col`: Integers to store the dimensions of the adjacency matrix (both 4 in this case).
// * `Head`: A pointer to the head node of the adjacency list.

// **Data Structures**

// * **`Node` struct:**  Represents a single node in the adjacency list:
//     * `data`:  Stores the vertex identifier (a character).
//     * `down`: Pointer to the next node in the same column (linked list for adjacent vertices).
//     * `next`:  Pointer to the next node in a row (represents one vertex's adjacency list).

// **Functions**

// * **`vertex(int val)`**
//     * Utility function to convert an integer index into a character label  ('A', 'B', 'C', 'D').

// * **`createAdjMTX()`**
//     1. Takes input from the user to determine whether an edge exists between a pair of vertices.
//     2. Populates the `adjMTX` adjacency matrix accordingly.

// * **`displayAdjMTX()`**
//     * Prints the adjacency matrix in a table-like format.

// * **`createAdjList()`**
//     1. Takes the number of vertices as input from the user.
//     2. Creates an array of `Node` structures where each index corresponds to a vertex.
//     3. Takes input for adjacent vertices of each node and builds linked lists to represent the adjacency list.

// * **`displayAdjList()`**
//     * Traverses the linked lists within the adjacency list and displays them.

// **Main Function**

// The `main()` function drives the program:

// 1. Presents a menu to the user.
// 2. Calls `createAdjMTX()` and then `displayAdjMTX()` to handle the adjacency matrix operations.
// 3. Resets `Head` to NULL, calls `createAdjList()` and then `displayAdjList()` to handle the adjacency list operations.

// **Breakdown: Adjacency Matrix vs. Adjacency List**

// * **Adjacency Matrix:**
//    * Uses a 2D matrix.
//    * `adjMTX[i][j]` has a value of 1 to indicate an edge exists between vertex 'i' and vertex 'j' (assuming unweighted edges).
//    * **Pros:** Easy to check for an edge. 
//    * **Cons:** Space inefficient for sparse graphs (graphs with few edges compared to the number of vertices).

// * **Adjacency List:**
//    * Uses linked lists.
//    * Each vertex has a linked list of its adjacent vertices.
//    * **Pros:**  Space-efficient for sparse graphs.
//    * **Cons:** Checking for the existence of an edge takes slightly longer. 

// **Key Points**

// * **Limited Graph Size:**  The code assumes a maximum of 4 vertices due to the fixed size of the adjacency matrix.
// * **Simple Character Labels:**  Labels vertices as 'A', 'B'...
// * **No Graph Traversal:** Code focuses on representation, not algorithms like DFS or BFS.

// **Let's Enhance!**

// * **Dynamic Memory:**  Use dynamic memory allocation to allow graphs of arbitrary size.
// * **Graph Algorithms:**  Implement DFS or BFS functions to operate on these representations.

// **Feel free to ask if you'd like a deeper explanation of a specific function or data structure!** 
