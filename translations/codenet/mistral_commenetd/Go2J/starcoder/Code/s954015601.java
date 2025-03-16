// Depth-first search
package main;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	// Function to generate unique id based on two integers
	public static int genid(int a, int b) {
		if (b < a) {
			a = b + a;
			b = a - b;
			a = a - b;
		}
		// Multiply the larger number by 100000 and add the smaller number
		return a*100000 + b;
	}

	// Main function
	public static void main(String[] args) {
		// Read the number of edges in the graph
		int N = readInt();

		// Initialize an adjacency list and a 2D array to store the edges between nodes
		int[][] ab = new int[N-1][2];
		List<Integer>[] edges = new ArrayList[N];
		for (int i = 0; i < N-1; i++) {
			// Read two integers representing the nodes connected by an edge
			int a = readInt() - 1;
			int b = readInt() - 1;
			// Store the nodes and their indices in the ab array
			ab[i][0] = a;
			ab[i][1] = b;
			// Add the edge to the adjacency list
			if (edges[a] == null) {
				edges[a] = new ArrayList<Integer>();
			}
			edges[a].add(b);
			if (edges[b] == null) {
				edges[b] = new ArrayList<Integer>();
			}
			edges[b].add(a);
		}

		// Initialize a map to store the colors of each connected component
		Map<Integer, Integer> colors = new HashMap<Integer, Integer>();
		// Initialize a queue to perform DFS
		List<int[]> q = new ArrayList<int[]>();
		// Add the first node to the queue with initial color and parent node set to -1
		q.add(new int[]{0, -1, -1});
		while (q.size()!= 0) {
			// Dequeue the current node, its color, and its parent node
			int[] currentNode = q.get(q.size() - 1);
			q.remove(q.size() - 1);
			int usedColor = currentNode[1];
			int parentNode = currentNode[2];
			// Set the color of the current node to the next available color
			int color = 1;
			for (int childNode : edges[currentNode[0]]) {
				if (childNode == parentNode) {
					continue;
				}
				// If the color of the current node is the same as the color of the child node, increment the color
				if (color == usedColor) {
					color++;
				}
				// Assign the color to the child node and add it to the queue with the current node as its parent node
				colors.put(genid(currentNode[0], childNode), color);
				q.add(new int[]{childNode, color, currentNode[0]});
				// Increment the color for the next iteration
				color++;
			}
		}

		// Initialize a variable to store the maximum number of edges in a connected component
		int K = -1;
		// Iterate through all nodes in the graph and update the maximum number of edges if necessary
		for (int i = 0; i < N; i++) {
			int t = edges[i].size();
			if (t > K) {
				K = t;
			}
		}
		// Print the maximum number of edges in a connected component
		System.out.println(K);

		// Iterate through all edges in the graph and print their colors
		for (int i = 0; i < N-1; i++) {
			System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
		}
	}

	// Constants for input buffer size and standard input scanner
	private static final int ioBufferSize = 1 * 1024 * 1024; // 1 MB

	// Function to read from standard input using a pre-initialized scanner
	private static final Scanner stdinScanner = new Scanner(System.in, "UTF-8").useDelimiter("\\s");

	// Function to read a single string from standard input
	private static String readString() {
		stdinScanner.useDelimiter("\\n");
		return stdinScanner.next();
	}

	// Function to read a single integer from standard input
	private static int readInt() {
		return Integer.parseInt(readString());
	}

}

