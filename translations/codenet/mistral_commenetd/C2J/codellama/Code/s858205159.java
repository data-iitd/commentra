
// Define a structure for a node
class Node{
	int key; // Key value of the node
	Node next; // Pointer to the next node
	Node prev; // Pointer to the previous node

	// Constructor to initialize a node
	Node(int key){
		this.key = key;
		this.next = null;
		this.prev = null;
	}
}

// Typedef a NodePointer as a pointer to the node structure
class NodePointer{
	Node node;

	// Constructor to initialize a node pointer
	NodePointer(Node node){
		this.node = node;
	}
}

// Initialize nil node with NULL pointers
NodePointer nil = new NodePointer(null);

// Function to search a node with given key
NodePointer listSearch(int key){
	NodePointer cur = nil.node.next; // Initialize current node as the first node after nil
	while (cur != nil.node) { // Traverse the list until nil is reached
		if (cur.node.key == key) break; // If the current node's key matches the given key, break the loop
		cur = cur.node.next; // Move to the next node
	}
	return cur; // Return the found node or NULL if not found
}

// Initialize the linked list with a nil node
void init(){
	nil.node = new Node(0); // Allocate memory for the nil node
	nil.node.next = nil.node; // Initialize next pointer of nil to itself
	nil.node.prev = nil.node; // Initialize prev pointer of nil to itself
}

// Function to print the linked list
void printList(){
	NodePointer cur = nil.node.next; // Initialize current node as the first node after nil
	int isf = 1; // Initialize isFirst flag to 1
	while (1){ // Traverse the list until nil is reached
		if (cur.node == nil.node) break; // If the current node is nil, break the loop
		if (isf == 1) System.out.print("[" + cur.node.key + "] "); // If it's the first node, print its key with an index
		else System.out.print(" " + cur.node.key); // Otherwise, print only the key
		cur = cur.node.next; // Move to the next node
		isf = 0; // Set isFirst flag to 0
	}
	System.out.println(); // Print a newline after the list is printed
}

// Function to delete a node from the linked list
void deleteNode(NodePointer t){
	if (t.node == nil.node) return; // Return if the node to be deleted is nil
	t.node.prev.next = t.node.next; // Update the next pointer of the previous node to point to the next node
	t.node.next.prev = t.node.prev; // Update the prev pointer of the next node to point to the previous node
	t.node = null; // Free the memory allocated to the deleted node
}

// Function to delete the first node from the linked list
void deleteFirst(){
	NodePointer t = nil.node.next; // Initialize the node to be deleted as the first node
	if (t.node == nil.node) return; // Return if the list is empty
	deleteNode(t); // Delete the first node
}

// Function to delete the last node from the linked list
void deleteLast(){
	NodePointer t = nil.node.prev; // Initialize the node to be deleted as the last node
	if (t.node == nil.node) return; // Return if the list is empty
	deleteNode(t); // Delete the last node
}

// Function to delete a node with the given key from the linked list
void deleteKey(int key){
	NodePointer t = listSearch(key); // Search for the node with the given key
	if (t.node != nil.node) deleteNode(t); // Delete the node if it's found
}

// Function to insert a new node with the given key into the linked list
void insert(int key){
	NodePointer x = new NodePointer(new Node(key)); // Allocate memory for the new node
	x.node.prev = nil.node; // Set the prev pointer of the new node to nil
	x.node.next = nil.node.next; // Set the next pointer of the new node to the first node after nil
	nil.node.next.prev = x.node; // Update the prev pointer of the first node after nil to point to the new node
	nil.node.next = x.node; // Update the next pointer of nil to point to the new node
}

// Main function to read commands and perform the corresponding actions
void main(){
	int key, n, i; // Initialize variables for reading commands and list size
	int size = 0; // Initialize the current size of the list
	String com; // Initialize a string to store the command
	int np = 0, nd = 0; // Initialize counters for number of insertions and deletions
	Scanner sc = new Scanner(System.in); // Initialize a scanner to read input
	n = sc.nextInt(); // Read the number of commands
	init(); // Initialize the linked list
	for (i = 0; i < n; i++){ // Traverse the commands
		com = sc.next(); // Read the command
		key = sc.nextInt(); // Read the key value
		if (com.equals("i")) { // If the command is 'i', insert a new node
			insert(key);
			np++;
			size++;
		}
		else if (com.equals("d")) { // If the command is 'd', delete a node
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
	System.out.println("Number of insertions: " + np); // Print the number of insertions
	System.out.println("Number of deletions: " + nd); // Print the number of deletions
}

