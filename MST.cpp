/*---------------------------------------------------------
Assignment : 07
Title : You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your office with a minimum total cost. Solve the problem by suggesting appropriate data structures.
(Minimum Spanning Tree)
-----------------------------------------------------------*/

#include<iostream>
using namespace std;


class snode // edge in the graph
{ 
  public:        // data structure for sparse matrix.
   char u1,u2;
   int wt;
};

class test
{
	 int n,m,x;
	 snode arr[10],res[10];
public:
	test()
	{
		n=0;
		m=1;
	}
   
     void inputsparse();
     void displaysparse();
     void bsort();
     void prims();
     void dispmst();
};

 // Function to Display result
void test::dispmst()    
{
    for(int i=0;i<m;i++)
     {
         cout<<res[i].u1<<" "<<res[i].u2<<" "<<res[i].wt<<endl;
     }
}

// Function to find minimum spanning tree.
 void test::prims()
{
	int cnt=0;
	int flag1,flag2,i;
     res[0]=arr[0];
     m=1;
    cnt=1;
 
 	do
 	{
         for(i=1; i<n  ; i++) //arr
         {
            flag1=0;
            flag2=0;
	        for(int j=0;j<m;j++)
	         {  			 
		      if((arr[i].u1==res[j].u1 || arr[i].u1==res[j].u2 ) && flag1==0) 
		      {
		          flag1++;		
		      }
		      if((arr[i].u2==res[j].u1 || arr[i].u2==res[j].u2 ) && flag2==0) 
		      {
		          flag2++;		        
		      }
		 	}		
		 			 
			if(flag1!=1  ^ flag2 !=1) // ^ Exore operation. 
			{

				 	res[m++]=arr[i];
				 			 				
			}		 		 		 	
			 
		 	
            }
            cnt = x-1;
    }while(m!=cnt)       ;
}           
           
         
// Function tio Read input graph. 
 void test::inputsparse()
 {
 
 cout<<"ENTER NO OF EDGES: ";
 cin>>n;
 cout<<"ENTER NO OF VERTICES: ";
 cin>>x;
  for(int i=0;i<n;i++)
  {
      	cout<<"ENTER 1ST VERTEX: ";
     	cin>>arr[i].u1;
       	cout<<"ENTER 2ND VERTEX: ";
      	cin>>arr[i].u2;
       	cout<<"ENTER WEIGHT: ";
      	cin>>arr[i].wt;
      	cout<<endl;
    }  
    bsort();
 }

void test::displaysparse()
{
       for(int i=0;i<n;i++)
     {
         cout<<arr[i].u1<<" "<<arr[i].u2<<" "<<arr[i].wt<<endl;
     }
}


//Sort the given edges of the graph using bubble sort
void test::bsort()
{
  snode temp;
     for(int i=0;i<n-1;i++)
     {
           for(int j=0;j<n-1-i;j++)
           {
               if(arr[j].wt>arr[j+1].wt)
               {
                   temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
           }
     }

}


int main()
{
   test obj;
   obj.inputsparse();
   obj.displaysparse();
   obj.prims();
   cout<<"RESULT:"<<endl;
   obj.dispmst();
return 0;
}


// This C++ program is designed to solve a problem using the concept of a Minimum Spanning Tree (MST), which finds the minimum cost needed to connect all offices (represented as vertices) using phone lines (represented as weighted edges between vertices). The specific implementation appears to be an attempt to use Prim's algorithm. Here's a breakdown of each part of the program:

// ### Classes and Structures

// 1. **snode**: A simple class to represent an edge in a sparse graph. Each edge is represented by two vertices (`u1` and `u2`) and a weight (`wt`).

// 2. **test**: This class manages the graph's edges and the MST algorithm. It includes:
//    - **arr[10]**: An array of `snode` objects representing the graph's edges.
//    - **res[10]**: An array of `snode` objects that will store the result, i.e., the edges included in the MST.
//    - **n**: The number of edges.
//    - **m**: Initially set to 1, but used as a counter for the number of edges added to the MST.
//    - **x**: The number of vertices.

// ### Member Functions

// 1. **inputsparse()**: This function reads the graph's edges from the user. It sorts the edges by weight using `bsort()` to facilitate the MST creation.

// 2. **displaysparse()**: Displays all the edges in the graph.

// 3. **bsort()**: Implements a bubble sort on the array of edges (`arr`) based on the edge weight. This sorting is critical for Prim's algorithm, which needs to process the lowest weight edges first.

// 4. **prims()**: Implements a variant of Prim's algorithm to construct the MST. The process is as follows:
//    - Initialize the MST with the smallest edge.
//    - Iterate over the remaining edges. For each edge, check if adding the edge to the MST would form a cycle by using a simple check (`flag1` and `flag2`) to see if both vertices of the edge are already included in the MST.
//    - The condition `if(flag1!=1  ^ flag2 !=1)` uses a bitwise XOR to ensure that exactly one of the vertices of the edge is already in the MST, which avoids forming cycles.

// 5. **dispmst()**: Displays the edges that are included in the MST.

// ### Main Function

// - It creates an instance of the `test` class, inputs the graph, displays it, computes the MST using Prim’s algorithm, and finally displays the MST.

// ### Algorithmic Correctness and Issues

// - **Algorithm Choice**: The method labeled as `prims()` in the code is misleading. The actual implementation seems to be a hybrid or incorrect version of Prim's algorithm. Proper Prim’s algorithm maintains a priority queue to always extend the MST with the minimum weight edge to a new vertex. The method used here is a naive and potentially incorrect implementation, as it does not properly check for cycles.
  
// - **Cycle Detection**: The cycle detection method used (`flag1` and `flag2`) is simplistic and may not correctly handle all cases, especially for graphs that are not connected or have complex topologies.

// - **Edge Case Handling**: There is no error checking for input values or handling of special cases like disconnected graphs or graphs with no edges.

// ### Summary

// This program is an attempt to solve the MST problem using an improvised and potentially incorrect variant of Prim's algorithm. For a reliable solution, it's recommended to use a well-defined algorithm like Kruskal's or the proper Prim's algorithm, with a priority queue and a union-find structure for cycle detection. This would ensure correctness and efficiency, especially for larger and more complex graphs.


// MST stands for **Minimum Spanning Tree**. It is a fundamental concept in graph theory, used extensively in network design, circuit design, clustering, and various other fields that require an efficient, minimum-cost connection between multiple points.

// ### Definition
// A **spanning tree** of a graph is a subgraph that is a tree and connects all the vertices together. A **minimum spanning tree (MST)** is then defined as the spanning tree with the weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights assigned to each edge of the spanning tree.

// ### Properties
// 1. **Minimum Weight**: The total weight of all the edges in the MST is the smallest possible among all spanning trees for the graph.
// 2. **Connectivity without Cycles**: The MST connects all vertices of the graph without any cycles, making it a tree.
// 3. **Unique and Non-Unique**: For a graph with distinct edge weights, the MST is unique. However, if multiple edges have the same weight, there can be several different MSTs.
// 4. **Subset of Graph**: The MST is a subset of the edges of the graph that forms a tree including every vertex.

// ### Use Cases
// - **Network Design**: Designing minimal cost networks like telecommunication networks, computer networks, or road networks.
// - **Cluster Analysis**: In clustering data, the MST can be used to decide where to "cut" the tree to form meaningful clusters.
// - **Approximation Algorithms for NP-hard problems**: Used in approximate algorithms for problems that are otherwise computationally difficult, such as the traveling salesman problem.

// ### Algorithms
// There are several algorithms to find the MST of a given graph, with the most well-known being:

// 1. **Kruskal's Algorithm**: Adds edges in order of increasing weight, using a union-find data structure to detect cycles.
// 2. **Prim's Algorithm**: Starts with a single vertex and grows the MST by adding the cheapest edge from the tree to a vertex not yet in the tree.
// 3. **Boruvka’s Algorithm**: Another efficient algorithm, especially useful in parallel computation for finding MSTs.

// Each algorithm has its advantages depending on the graph's structure and the specific needs of the application, such as whether the graph is dense or sparse, or if the solution needs to be parallelized.


// The code implements Prim's algorithm, a greedy approach to finding a Minimum Spanning Tree (MST) in a connected, weighted graph. Here's a breakdown of the theory behind it:

// **Minimum Spanning Tree (MST)**

// * A connected and acyclic (cycle-free) subgraph of a weighted graph.
// * Spans all vertices of the original graph.
// * The sum of the edge weights in the MST is the minimum possible compared to all other spanning trees of that graph.

// **Prim's Algorithm**

// Prim's algorithm is an iterative process that builds the MST one edge at a time. Here's a step-by-step explanation:

// 1. **Initialization:** Choose any vertex in the graph as the starting point. Add it to the MST and mark it as visited.

// 2. **Iteration:**
//     * Among the **unvisited** vertices adjacent to the vertices in the current MST, find the edge with the **minimum weight**.
//     * Add this edge and its **unvisited** endpoint vertex to the MST.
//     * Mark the newly added vertex as visited.

// 3. **Repeat Step 2** until all vertices are included in the MST.

// **Greedy Choice**

// Prim's algorithm makes a locally optimal choice at each step by picking the minimum weight edge that connects the growing MST to an unvisited vertex. This localized approach guarantees finding the global minimum spanning tree for the entire graph.

// **Why it Works**

// Prim's algorithm leverages a key property of MSTs:

// * **Cut Property:** In any graph, for any cut (division into two sub-graphs) separating the MST from the rest of the graph, there must exist an edge in the MST that has a weight less than or equal to all other edges crossing the cut.

// Using this property, Prim's algorithm ensures that at each step, the chosen edge has a weight no greater than any edge that could potentially connect the MST to an unvisited vertex later. This progressively builds a minimum weight spanning tree.

// **Time Complexity**

// The time complexity of Prim's algorithm using an adjacency matrix implementation is O(V^2), where V is the number of vertices. However, using a priority queue to efficiently find the minimum weight edge during each iteration can improve the complexity to O(E log V), where E is the number of edges.

// **Applications of MSTs**

// * **Networking:**  Designing a cost-effective communication network between cities.
// * **Image Segmentation:** Grouping connected pixels in an image to identify objects.
// * **Cluster Analysis:** Grouping data points based on similarity measures.

// **Let me know if you'd like to see an example of Prim's algorithm applied to a graph or if you have any further questions about the code's implementation!**