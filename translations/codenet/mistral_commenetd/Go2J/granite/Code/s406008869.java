
// Package main is the entry point of the program
package main;

import java.util.*;

// Define a 2D array 'e' to store the edges of the graph
static int[][] e;

// Define variables 'n' and'm' to store the number of nodes and edges respectively
static int n, m;

// Function 'printEdge' to print the edges of the graph
static void printEdge() {
	// Iterate through each node in the graph
	for (int i = 1; i <= n; i++) {
		// Print the node number and its connected nodes
		System.out.printf("%d: ", i);
		for (int v : e[i]) {
			System.out.printf("%d ", v);
		}
		System.out.println();
	}
}

// Function 'dfs' to perform Depth First Search traversal
static int dfs(int v, boolean[] visited) {
	// Initialize a boolean array 'visited' to keep track of visited nodes
	// visited[v] = true;
	// System.out.println(v + " " + Arrays.toString(visited));

	// Check if all nodes are visited, if yes then it's a strongly connected component
	boolean comp = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			comp = false;
			break;
		}
	}

	// If all nodes are visited, return 1 for this strongly connected component
	if (comp) {
		return 1;
	}

	// Initialize a counter 'count' to store the size of the strongly connected component
	int count = 0;
	// Iterate through the neighbors of the current node 'v'
	for (int ne : e[v]) {
		// If the neighbor is already visited, skip it
		if (visited[ne]) {
			continue;
		}
		// Mark the neighbor as visited
		visited[ne] = true;
		// Recursively call 'dfs' on the neighbor and add its size to the counter
		// int rst = dfs(ne, visited, count);
		// count += rst;
		int rst = dfs(ne, visited);
		count += rst;
		// Mark the neighbor as unvisited
		visited[ne] = false;
	}
	// Return the size of the strongly connected component
	return count;
}

// Function'main' to read input and call the 'printEdge' and 'dfs' functions
public class s406008869{
	public static void main(String[] args) {
		// Read the number of nodes and edges from the standard input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();

		// Initialize a 2D array 'e' of size (n+1)x(n+1) to store the edges of the graph
		e = new int[n+1][];
		for (int i = 1; i <= n; i++) {
			// Initialize an empty arraylist for each node
			e[i] = new ArrayList<Integer>();
		}
		// Read the edges of the graph from the standard input and add them to the 'e' array
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			// Add the edge to the 'e' array for both nodes
			e[a].add(b);
			e[b].add(a);
		}
		// Call the 'printEdge' function to print the edges of the graph
		// printEdge();

		// Initialize a boolean array 'visited' of size (n+1) to keep track of visited nodes
		boolean[] visited = new boolean[n+1];
		// Mark the first node as visited
		visited[1] = true;
		// Call the 'dfs' function on the first node and print the size of the strongly connected component
		int count = dfs(1, visited);
		System.out.println(count);
	}
}
