// Importing necessary packages
import java.util.Scanner;

// Defining node and tree structures
class node {
	int key;
	node left, right, parent;
}

class tree {
	node root;

	// Method to insert a new node into the tree
	void insert(int key) {
		// Base case: If the tree is empty, create a new root node
		if (root == null) {
			root = new node(key);
			return;
		}

		// Variables to keep track of current and previous nodes
		node currentNode = root, prevNode = null;

		// Traverse the tree to find the correct position for the new node
		while (currentNode!= null) {
			prevNode = currentNode;
			if (currentNode.key < key) {
				currentNode = currentNode.right;
			} else {
				currentNode = currentNode.left;
			}
		}

		// Create a new node with the given key
		node newNode = new node(key);

		// Set the new node's parent to the previous node
		newNode.parent = prevNode;

		// If the previous node's key is less than the new node's key,
		// set the previous node's right child to the new node
		if (prevNode.key < key) {
			prevNode.right = newNode;
		} else {
			// Otherwise, set the previous node's left child to the new node
			prevNode.left = newNode;
		}
	}

	// Method to print the tree in inorder and preorder traversals
	void print() {
		// Base case: If the tree is empty, print an empty tree
		if (root == null) {
			System.out.println("");
			System.out.println("");
			return;
		}

		// Variable to store the visited nodes in inorder traversal
		ArrayList<Integer> acc = new ArrayList<Integer>();

		// Print the tree in inorder and preorder traversals
		System.out.println("Inorder traversal: " + Arrays.toString(isToAs(visitInorder(root, acc))));
		System.out.println("Preorder traversal: " + Arrays.toString(isToAs(visitPreorder(root, acc))));
	}

	// Helper functions for depth-first traversals of the tree
	ArrayList<Integer> visitPreorder(node node, ArrayList<Integer> acc) {
		// Base case: If the node is null, return the accumulator array
		if (node == null) {
			return acc;
		}

		// Add the current node's key to the accumulator array
		acc.add(node.key);

		// Recursively traverse the left and right subtrees
		if (node.left!= null) {
			acc = visitPreorder(node.left, acc);
		}
		if (node.right!= null) {
			acc = visitPreorder(node.right, acc);
		}

		// Return the updated accumulator array
		return acc;
	}

	ArrayList<Integer> visitInorder(node node, ArrayList<Integer> acc) {
		// Base case: If the node is null, return the accumulator array
		if (node == null) {
			return acc;
		}

		// Recursively traverse the left subtree and add its keys to the accumulator array
		if (node.left!= null) {
			acc = visitInorder(node.left, acc);
		}

		// Add the current node's key to the accumulator array
		acc.add(node.key);

		// Recursively traverse the right subtree and add its keys to the accumulator array
		if (node.right!= null) {
			acc = visitInorder(node.right, acc);
		}

		// Return the updated accumulator array
		return acc;
	}
}

// Main function to read input and call the appropriate methods
public class Main {
	public static void main(String[] args) {
		// Creating a new scanner to read input from stdin
		Scanner sc = new Scanner(System.in);

		// Reading the number of nodes in the tree
		int n = sc.nextInt();

		// Creating a new tree object
		tree tree = new tree();

		// Reading the commands and calling the appropriate methods
		for (int i = 0; i < n; i++) {
			String command = sc.next();
			switch (command) {
			case "insert":
				int key = sc.nextInt();
				tree.insert(key);
				break;
			case "print":
				tree.print();
				break;
			default:
				System.out.println("unknown command: " + command);
			}
		}
	}
}

// Helper functions to read text and integers from the scanner
public static String nextText(Scanner sc) {
	sc.next();
	return sc.next();
}

public static int nextInt(Scanner sc) {
	return Integer.parseInt(nextText(sc));
}

// Helper function to convert an integer array to a string array
public static String[] isToAs(ArrayList<Integer> is) {
	int n = is.size();
	String[] as = new String[n];
	for (int i = 0; i < n; i++) {
		as[i] = Integer.toString(is.get(i));
	}
	return as;
}

