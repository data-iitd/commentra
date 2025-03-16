package main;

import java.util.Scanner;

// Define a structure for a node in the binary tree
class node {
	int key; // The key value of the node
	node parent; // Pointer to the parent node
	node left; // Pointer to the left child node
	node right; // Pointer to the right child node
}

// Define a structure for the binary tree
class tree {
	node root; // Pointer to the root node of the tree
}

// Insert a new key into the binary tree
void insert(tree tree, int key) {
	// If the tree is empty, create a new root node
	if (tree.root == null) {
		tree.root = new node();
		tree.root.key = key;
		return;
	}

	node currentNode, prevNode;
	currentNode = tree.root;
	// Traverse the tree to find the correct position for the new key
	while (currentNode!= null) {
		prevNode = currentNode;
		if (currentNode.key < key) {
			currentNode = currentNode.right; // Move to the right child
		} else {
			currentNode = currentNode.left; // Move to the left child
		}
	}

	// Create a new node for the key and set its parent
	node newNode = new node();
	newNode.key = key;
	newNode.parent = prevNode;
	// Attach the new node to the correct position in the tree
	if (prevNode.key < key) {
		prevNode.right = newNode; // Insert as right child
	} else {
		prevNode.left = newNode; // Insert as left child
	}
}

// Print the keys in the tree in both inorder and preorder traversal
void print(tree tree) {
	if (tree.root == null) {
		System.out.println("");
		System.out.println("");
	} else {
		// Print inorder traversal
		System.out.println(" " + String.join(isToAs(visitInorder(tree.root, new int[0])), " "));
		// Print preorder traversal
		System.out.println(" " + String.join(isToAs(visitPreorder(tree.root, new int[0])), " "));
	}
}

// Perform a preorder traversal of the tree
int[] visitPreorder(node node, int[] acc) {
	if (node == null) {
		return acc; // Return accumulated keys if node is null
	}
	acc = Arrays.copyOf(acc, acc.length + 1); // Add the current node's key
	acc[acc.length - 1] = node.key;
	if (node.left!= null) {
		acc = visitPreorder(node.left, acc); // Traverse left subtree
	}
	if (node.right!= null) {
		acc = visitPreorder(node.right, acc); // Traverse right subtree
	}
	return acc;
}

// Perform an inorder traversal of the tree
int[] visitInorder(node node, int[] acc) {
	if (node == null) {
		return acc; // Return accumulated keys if node is null
	}
	if (node.left!= null) {
		acc = visitInorder(node.left, acc); // Traverse left subtree
	}
	acc = Arrays.copyOf(acc, acc.length + 1); // Add the current node's key
	acc[acc.length - 1] = node.key;
	if (node.right!= null) {
		acc = visitInorder(node.right, acc); // Traverse right subtree
	}
	return acc;
}

// Main function to read commands and manipulate the binary tree
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a new scanner for standard input
		int n = sc.nextInt(); // Read the number of commands
		tree tree = new tree(); // Initialize a new binary tree
		// Process each command
		for (int i = 0; i < n; i++) {
			String command = sc.next(); // Read the command
			switch (command) {
			case "insert":
				int key = sc.nextInt(); // Read the key to insert
				tree.insert(key); // Insert the key into the tree
				break;
			case "print":
				tree.print(); // Print the tree's keys
				break;
			default:
				System.err.println("unknown command: " + command); // Handle unknown commands
			}
		}
	}
}

// Read the next text input from the scanner
String nextText(Scanner sc) {
	sc.next(); // Scan the next token
	return sc.next(); // Return the scanned text
}

// Read the next integer input from the scanner
int nextInt(Scanner sc) {
	return Integer.parseInt(nextText(sc)); // Convert the scanned text to an integer
}

// Convert a slice of integers to a slice of strings
String[] isToAs(int[] is) {
	int n = is.length;
	String[] as = new String[n]; // Create a new slice of strings
	for (int i = 0; i < n; i++) {
		as[i] = Integer.toString(is[i]); // Convert each integer to a string
	}
	return as; // Return the slice of strings
}

