
import java.util.*;

// Define a structure for a node
class Node{
	int key; // Key value of the node
	Node next; // Pointer to the next node
	Node prev; // Pointer to the previous node
}

// Initialize nil node with null pointers
Node nil = null;

// Function to search a node with given key
Node listSearch(int key){
	Node cur = nil.next; // Initialize current node as the first node after nil
	while (cur!= nil){ // Traverse the list until nil is reached
		if (cur.key == key) break; // If the current node's key matches the given key, break the loop
		cur = cur.next; // Move to the next node
	}
	return cur; // Return the found node or null if not found
}

// Initialize the linked list with a nil node
void init(){
	nil = new Node(); // Allocate memory for the nil node
	nil.next = nil; // Initialize next pointer of nil to itself
	nil.prev = nil; // Initialize prev pointer of nil to itself
}

// Function to print the linked list
void printList(){
	Node cur = nil.next; // Initialize current node as the first node after nil
	int isf = 1; // Initialize isFirst flag to 1
	while (1){ // Traverse the list until nil is reached
		if (cur == nil) break; // If the current node is nil, break the loop
		if (isf == 1) System.out.print("[ " + cur.key + " ] "); // If it's the first node, print its key with an index
		else System.out.print(" " + cur.key); // Otherwise, print only the key
		cur = cur.next; // Move to the next node
		isf = 0; // Set isFirst flag to 0
	}
	System.out.println(); // Print a newline after the list is printed
}

// Function to delete a node from the linked list
void deleteNode(Node t){
	if (t == nil) return; // Return if the node to be deleted is nil
	t.prev.next = t.next; // Update the next pointer of the previous node to point to the next node
	t.next.prev = t.prev; // Update the prev pointer of the next node to point to the previous node
	t = null; // Free the memory allocated to the deleted node
}

// Function to delete the first node from the linked list
void deleteFirst(){
	Node t = nil.next; // Initialize the node to be deleted as the first node
	if (t == nil) return; // Return if the list is empty
	deleteNode(t); // Delete the first node
}

// Function to delete the last node from the linked list
void deleteLast(){
	Node t = nil.prev; // Initialize the node to be deleted as the last node
	if (t == nil) return; // Return if the list is empty
	deleteNode(t); // Delete the last node
}

// Function to delete a node with the given key from the linked list
void deleteKey(int key){
	Node t = listSearch(key); // Search for the node with the given key
	if (t!= nil) deleteNode(t); // Delete the node if it's found
}

// Function to insert a new node with the given key into the linked list
void insert(int key){
	Node x; // Allocate memory for the new node
	x = new Node();
	x.key = key; // Set the key value of the new node
	x.prev = nil; // Set the prev pointer of the new node to nil
	x.next = nil.next; // Set the next pointer of the new node to the first node after nil
	nil.next.prev = x; // Update the prev pointer of the first node after nil to point to the new node
	nil.next = x; // Update the next pointer of nil to point to the new node
}

// Main function to read commands and perform the corresponding actions
public class Main{
	public static void main(String[] args){
		int key, n, i; // Initialize variables for reading commands and list size
		int size = 0; // Initialize the current size of the list
		String com = new String(); // Initialize a string to store the command
		int np = 0, nd = 0; // Initialize counters for number of insertions and deletions
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); // Read the number of commands
		init(); // Initialize the linked list
		for (i = 0; i < n; i++){ // Traverse the commands
			com = sc.next(); // Read the command
			key = sc.nextInt(); // Read the key value
			if (com.charAt(0) == 'i') { // If the command is 'i', insert a new node
				insert(key);
				np++;
				size++;
			}
			else if (com.charAt(0) == 'd') { // If the command is 'd', delete a node
				if (com.length() > 6){ // If the command is 'd F' or 'd L', delete the first or last node
					if (com.charAt(6) == 'F') deleteFirst();
					else if (com.charAt(6) == 'L') deleteLast();
				}
				else { // Otherwise, delete a node with the given key
					deleteKey(key);
					nd++;
				}
				size--;
			}
		}

		printList(); // Print the updated linked list
	}

	// Function to print the linked list
	void printList(){
		Node cur = nil.next; // Initialize current node as the first node after nil
		int isf = 1; // Initialize isFirst flag to 1
		while (1){ // Traverse the list until nil is reached
			if (cur == nil) break; // If the current node is nil, break the loop
			if (isf == 1) System.out.print("[ " + cur.key + " ] "); // If it's the first node, print its key with an index
			else System.out.print(" " + cur.key); // Otherwise, print only the key
			cur = cur.next; // Move to the next node
			isf = 0; // Set isFirst flag to 0
		}
		System.out.println(); // Print a newline after the list is printed
	}

	// Function to delete a node from the linked list
	void deleteNode(Node t){
		if (t == nil) return; // Return if the node to be deleted is nil
		t.prev.next = t.next; // Update the next pointer of the previous node to point to the next node
		t.next.prev = t.prev; // Update the prev pointer of the next node to point to the previous node
		t = null; // Free the memory allocated to the deleted node
	}

	// Function to delete the first node from the linked list
	void deleteFirst(){
		Node t = nil.next; // Initialize the node to be deleted as the first node
		if (t == nil) return; // Return if the list is empty
		deleteNode(t); // Delete the first node
	}

	// Function to delete the last node from the linked list
	void deleteLast(){
		Node t = nil.prev; // Initialize the node to be deleted as the last node
		if (t == nil) return; // Return if the list is empty
		deleteNode(t); // Delete the last node
	}

	// Function to delete a node with the given key from the linked list
	void deleteKey(int key){
		Node t = listSearch(key); // Search for the node with the given key
		if (t!= nil) deleteNode(t); // Delete the node if it's found
	}

	// Function to insert a new node with the given key into the linked list
	void insert(int key){
		Node x; // Allocate memory for the new node
		x = new Node();
		x.key = key; // Set the key value of the new node
		x.prev = nil; // Set the prev pointer of the new node to nil
		x.next = nil.next; // Set the next pointer of the new node to the first node after nil
		nil.next.prev = x; // Update the prev pointer of the first node after nil to point to the new node
		nil.next = x; // Update the next pointer of nil to point to the new node
	}

	// Initialize the linked list with a nil node
	void init(){
		nil = new Node(); // Allocate memory for the nil node
		nil.next = nil; // Initialize next pointer of nil to itself
		nil.prev = nil; // Initialize prev pointer of nil to itself
	}

	// Function to search a node with given key
	Node listSearch(int key){
		Node cur = nil.next; // Initialize current node as the first node after nil
		while (cur!= nil){ // Traverse the list until nil is reached
			if (cur.key == key) break; // If the current node's key matches the given key, break the loop
			cur = cur.next; // Move to the next node
		}
		return cur; // Return the found node or null if not found
	}
}

