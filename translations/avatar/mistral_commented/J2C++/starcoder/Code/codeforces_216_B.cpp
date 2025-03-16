
#include <bits/stdc++.h>
using namespace std;

class Main {
 int count; // Declaring and initializing the count variable to 0.
 bool* seen; // Declaring and initializing the seen array to keep track of visited nodes.
 int path = 0, cycle = 1; // Declaring and initializing the path and cycle variables.
 vector<vector<int>> graph; // Declaring and initializing the graph as a 2D vector.

 public int dfs(int child, int par) {
 if (seen[child] == true) { // Checking if the current node has already been visited.
 return cycle; // If it has, then there is a cycle in the graph and we return 1.
 }
 seen[child] = true; // Marking the current node as visited.

 for (int i : graph[child]) { // Iterating through the neighbors of the current node.
 if (i!= par) { // Checking if the neighbor is not the parent node.
 this.count++; // Incrementing the count of edges traversed.
 if (dfs(i, child) == cycle) { // Recursively calling the dfs function on the neighbor.
 return cycle; // If there is a cycle, then we return 1.
 }
 }
 }
 return path; // If there is no cycle, then we return 0.
 }

 public static void main(String[] args) {
 int m, n; // Declaring and initializing the number of nodes and edges in the graph.
 cin >> m >> n; // Reading the number of nodes and edges in the graph.
 Main ft = new Main(); // Creating a new instance of the Main class.
 ft.graph = vector<vector<int>>(m + 1, vector<int>()); // Initializing the graph as a 2D vector of size (m+1)x(m+1).
 ft.seen = new bool[m + 1]; // Initializing the seen array as a boolean array of size (m+1).

 for (int i = 0; i <= m; i++) { // Initializing the graph with empty vectors for each node.
 }

 for (int i = 0; i < n; i++) { // Reading the edges from the input and adding them to the graph.
 int x, y;
 cin >> x >> y;
 ft.graph[x].push_back(y); // Adding an edge from x to y.
 ft.graph[y].push_back(x); // Adding an edge from y to x.
 }

 int toremove = 0; // Initializing the toremove variable to 0.
 for (int i = 1; i <= m; i++) { // Iterating through all the nodes in the graph.
 if (!ft.seen[i]) { // If the current node has not been visited.
 ft.count = 0; // Resetting the count of edges traversed to 0.
 if (ft.dfs(i, 0) == ft.cycle) { // If there is a cycle in the subgraph rooted at the current node.
 if (ft.count % 2 == 1) { // If the number of edges traversed is odd.
 toremove++; // Increment the toremove variable.
 }
 }
 }
 }

 if ((m - toremove) % 2 == 1) { // Checking if the number of nodes is odd.
 toremove++; // If it is, then increment the toremove variable.
 }

 cout << toremove << endl; // Printing the result.
 }
}

