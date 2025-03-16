
import java.util.*;

// Define a class for a doubly linked list node
class Node{
	int key; // Key value of the node
	Node next; // Pointer to the next node
	Node prev; // Pointer to the previous node
}

public class s858205159{
	static Node nil; // Sentinel node to represent the head and tail of the list

	// Function to search for a node with a specific key
	static Node listSearch(int key){
		Node cur = nil.next; // Start from the first node
		while (cur!= nil) { // Traverse until the sentinel node
			if (cur.key == key) break; // If the key is found, break the loop
			cur = cur.next; // Move to the next node
		}
		return cur; // Return the found node or sentinel if not found
	}

	// Function to initialize the linked list
	static void init(){
		nil = new Node(); // Allocate memory for the sentinel node
		nil.next = nil; // Point next of sentinel to itself
		nil.prev = nil; // Point prev of sentinel to itself
	}

	// Function to print all the keys in the linked list
	static void printList(){
		Node cur = nil.next; // Start from the first node
		int isf = 1; // Flag to manage spacing between numbers
		while (1){
			if (cur == nil) break; // Stop if we reach the sentinel node
			if (isf == 0)  System.out.print(" "); // Print space before the next number if not the first
			System.out.print(cur.key); // Print the key of the current node
			cur = cur.next; // Move to the next node
			isf = 0; // Set flag to indicate that we have printed at least one number
		}
		System.out.println(); // Print a new line after printing all keys
	}

	// Function to delete a specific node from the list
	static void deleteNode(Node t){
		if (t == nil) return; // Do nothing if the node is the sentinel
		t.prev.next = t.next; // Bypass the node in the next pointer of the previous node
		t.next.prev = t.prev; // Bypass the node in the prev pointer of the next node
	}

	// Function to delete the first node in the list
	static void deleteFirst(){
		Node t = nil.next; // Get the first node
		if (t == nil) return; // Do nothing if the list is empty
		deleteNode(t); // Delete the first node
	}

	// Function to delete the last node in the list
	static void deleteLast(){
		Node t = nil.prev; // Get the last node
		if (t == nil) return; // Do nothing if the list is empty
		deleteNode(t); // Delete the last node
	}

	// Function to delete a node with a specific key
	static void deleteKey(int key){
		Node t = listSearch(key); // Search for the node with the key
		if (t!= nil) deleteNode(t); // If found, delete the node
	}

	// Function to insert a new node with a specific key at the beginning of the list
	static void insert(int key){
		Node x = new Node(); // Pointer for the new node
		x.key = key; // Set the key of the new node
		x.prev = nil; // Set the previous pointer to the sentinel
		x.next = nil.next; // Set the next pointer to the current first node
		x.next.prev = x; // Update the previous pointer of the current first node to point to the new node
		nil.next = x; // Update the sentinel's next pointer to point to the new node
	}

	// s858205159 function to execute the program
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a scanner object to read input
		int key, n, i; // Variables for key, number of operations, and loop index
		int size = 0; // Variable to keep track of the size of the list
		String com; // Variable to store command strings
		int np = 0, nd = 0; // Counters for number of insertions and deletions
		n = sc.nextInt(); // Read the number of operations
		init(); // Initialize the linked list
		for (i = 0; i < n; i++){ // Loop through each operation
			com = sc.next(); // Read the command
			key = sc.nextInt(); // Read the key
			if (com.equals("insert")) { // If the command is 'insert'
				insert(key); np++; size++; // Insert the key and update counters
			}
			else if (com.equals("delete")) { // If the command is 'delete'
				if (com.length() > 6){ // Check if the command specifies 'First' or 'Last'
					if (com.charAt(6) == 'F') deleteFirst(); // Delete the first node
					else if (com.charAt(6) == 'L') deleteLast(); // Delete the last node
				}
				else {
					deleteKey(key); nd++; // Delete the node with the specified key
				}
				size--; // Decrease the size of the list
			}
		}

		printList(); // Print the final state of the list
		sc.close(); // Close the scanner object
	}
}

