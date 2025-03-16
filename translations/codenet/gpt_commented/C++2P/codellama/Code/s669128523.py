/* Depth First Search (DFS) implementation
   This implementation does not use recursion stack.
*/

#include <iostream>
using namespace std;

#define N 100 // Maximum number of nodes
#define WHITE 0 // Color for unvisited nodes
#define GRAY 1 // Color for nodes being visited
#define BLACK 2 // Color for fully visited nodes

#define M 0 // Adjacency matrix
#define n 1 // Number of nodes
#define color 2 // Array to store colors
#define d 3 // Array to store discovery times
#define f 4 // Array to store finish times
#define tt 5 // Time counter

#define dfs_visit 0 // Function to visit nodes in DFS
#define dfs 1 // Function to perform DFS on the graph

#define u 0 // Current node
#define v 1 // Adjacent node
#define k 2 // Number of edges

#define i 0 // Loop counter
#define j 1 // Loop counter

#define cin 0 // Read the number of nodes
#define cout 1 // Output the discovery and finish times for each node

#define main 0 // Main function

#define end 0 // End of the program

#define END-OF-CODE "