package main;

import java.io.*;
import java.util.*;

// Define a doubly linked list node structure
class node {
	int key; // The value of the node
	node prev; // Pointer to the previous node
	node next; // Pointer to the next node
}

// Method to recursively print the keys of the linked list starting from the current node
public void rPrint(node n, StringBuilder buf) {
	buf.append(n.key); // Append the current node's key to the buffer
	if (n.next!= null) {
		buf.append(" "); // Add a space if there is a next node
		rPrint(n.next, buf); // Recursively print the next node
	}
}

// Method to delete the current node from the linked list
public node Delete(node first, node last) {
	if (n.prev!= null && n.next!= null) {
		// Node is in the middle; update pointers of adjacent nodes
		n.prev.next = n.next;
		n.next.prev = n.prev;
		return first; // Return unchanged first and last pointers
	}

	if (n.next == null && n.prev == null) {
		// Node is the only node in the list
		return null; // Return nil for both first and last
	}

	if (n.prev == null) {
		// Node is the first node
		first = n.next; // Update first to the next node
		n.next.prev = null; // Set the previous pointer of the new first node to nil
	}

	if (n.next == null) {
		// Node is the last node
		last = n.prev; // Update last to the previous node
		n.prev.next = null; // Set the next pointer of the new last node to nil
	}

	return first; // Return updated first and last pointers
}

// Function to initialize a new node with a given key
public node initNode(int key) {
	return new node(key); // Set the key of the new node
}

// Main function to execute the program
public static void main(String[] args) {
	Scanner stdin = new Scanner(System.in); // Create a scanner to read input from standard input
	node first = null; // Initialize pointers for the first and last nodes of the list
	stdin.nextLine(); // Read the first line of input (not used)

	// Loop to process each command from the input
	while (stdin.hasNextLine()) {
		String cmd = stdin.nextLine(); // Get the current command
		switch (cmd) {
		case "deleteFirst":
			// Command to delete the first node
			first = Delete(first, null);
		case "deleteLast":
			// Command to delete the last node
			first = Delete(null, first);
		default:
			// Handle commands that involve inserting or deleting specific keys
			String[] xcmd = cmd.split(" "); // Split the command into parts
			int k = Integer.parseInt(xcmd[1]); // Convert the second part to an integer
			int k32 = (int) k; // Convert the integer to int32
			switch (xcmd[0]) {
			case "delete":
				// Command to delete a node with a specific key
				node a = first;
				while (a!= null) {
					if (a.key == k32) {
						first = Delete(a, null); // Delete the node and update first and last
						break;
					}
					a = a.next;
				}
			case "insert":
				// Command to insert a new node at the beginning of the list
				node n = initNode(k32); // Initialize a new node
				n.next = first; // Set the new node's next pointer to the current first node
				if (first!= null) {
					first.prev = n; // Update the previous pointer of the current first node
				}

				first = n; // Update first to the new node
				if (last == null) {
					last = n; // If the list was empty, set last to the new node
				}
			}
		}
	}
	StringBuilder buf = new StringBuilder();
	rPrint(first, buf); // Print the keys of the linked list starting from the first node
	System.out.println(buf.toString()); // Output the result
}

