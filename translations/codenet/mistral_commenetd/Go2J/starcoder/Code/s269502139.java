
package main;

import java.io.*;
import java.util.*;

// Define a node structure with key, previous and next pointers
class node {
	int key;
	node prev, next;

	// Initialize a new node with given key
	node(int key) {
		this.key = key;
	}

	// Recursive function to print the linked list in reverse order
	void rPrint(StringBuffer buf) {
		buf.append(key);
		if (next!= null) {
			// Recursively call rPrint function for next node
			buf.append(" ");
			next.rPrint(buf);
		}
		// Return from the function
		return;
	}

	// Function to delete a node from the linked list
	node Delete(node first, node last) {
		// Base case: if node is the first and last node
		if (prev == null && next == null) {
			return null;
		}

		// Base case: if node is the first node
		if (prev == null) {
			first = next;
			next.prev = null;
			return first;
		}

		// Base case: if node is the last node
		if (next == null) {
			last = prev;
			prev.next = null;
			return first;
		}

		// General case: swap the pointers of previous and next nodes
		prev.next = next;
		next.prev = prev;
		// Return the first and last nodes after deletion
		return first;
	}
}

// Main function to read commands from stdin and perform the corresponding actions
public class Main {
	// Initialize standard input scanner
	static Scanner stdin = new Scanner(System.in);
	// Initialize first and last pointers to null
	static node first = null, last = null;

	// Main function
	public static void main(String[] args) {
		// Read the first command from stdin
		stdin.nextLine();

		// Process each command until EOF is reached
		while (stdin.hasNextLine()) {
			String cmd = stdin.nextLine(); // Read the command from stdin

			// Switch statement to perform the corresponding action based on the command
			switch (cmd) {
			case "deleteFirst":
				// Delete the first node from the linked list
				first = first.Delete(first, last);
			case "deleteLast":
				// Delete the last node from the linked list
				first = last.Delete(first, last);
			default:
				// Split the command into parts using space as delimiter
				String[] xcmd = cmd.split(" ");
				// Parse the key from the second part of the command
				int k = Integer.parseInt(xcmd[1]);
				// Switch statement to perform the corresponding action based on the command prefix
				switch (xcmd[0]) {
				case "delete":
					// Search for the node with the given key in the linked list
					node a = first;
					while (a!= null) {
						// If the current node matches the given key, delete it
						if (a.key == k) {
							first = a.Delete(first, last);
							break;
						}
						a = a.next;
					}
				case "insert":
					// Create a new node with the given key
					node n = new node(k);
					// Insert the new node at the beginning of the linked list
					n.next = first;
					if (first!= null) {
						first.prev = n;
					}

					// Update the first and last pointers
					first = n;
					if (last == null) {
						last = n;
					}
				}
			}
		}
		// Print the linked list in reverse order
		StringBuffer buf = new StringBuffer();
		first.rPrint(buf);
		// Print the reversed linked list on the console
		System.out.println(buf.toString());
	}
}

