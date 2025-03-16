// Package main is the entry point of the program
package main;

import java.util.Scanner;

// Define a 2D array 'e' to store the edges of the graph
public class Main {
	public static int[][] e;

	// Define variables 'n' and'm' to store the number of nodes and edges respectively
	public static int n, m;

	// Function 'printEdge' to print the edges of the graph
	public static void printEdge(int[][] e) {
		// Iterate through each node in the graph
		for (int i = 1; i < n+1; i++) {
			// Print the node number and its connected nodes
			System.out.print(i + ": ");
			for (int v : e[i]) {
				System.out.print(v + " ");
			}
			System.out.println();
		}
	}

	// Function 'dfs' to perform Depth First Search traversal
	public static int dfs(int v, boolean[] visited) {
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
			count += dfs(ne, visited);
			// Mark the neighbor as unvisited
			visited[ne] = false;
		}
		// Return the size of the strongly connected component
		return count;
	}

	// Function'main' to read input and call the 'printEdge' and 'dfs' functions
	public static void main(String[] args) {
		// Read the number of nodes and edges from the standard input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();

		// Initialize a 2D array 'e' of size (n+1)x(n+1) to store the edges of the graph
		e = new int[n+1][n+1];
		for (int i = 1; i < n+1; i++) {
			// Initialize an empty array for each node
			e[i] = new int[0];
		}
		// Read the edges of the graph from the standard input and add them to the 'e' array
		for (int i = 0; i < m; i++) {
			int a, b;
			// Read the nodes of an edge from the standard input
			a = sc.nextInt();
			b = sc.nextInt();
			// Add the edge to the 'e' array for both nodes
			e[a] = append(e[a], b);
			e[b] = append(e[b], a);
		}
		// Call the 'printEdge' function to print the edges of the graph
		// printEdge(e);

		// Initialize a boolean array 'visited' of size (n+1) to keep track of visited nodes
		boolean[] visited = new boolean[n+1];
		// Mark the first node as visited
		visited[1] = true;
		// Call the 'dfs' function on the first node and print the size of the strongly connected component
		int count = dfs(1, visited);
		System.out.println(count);
	}
}

