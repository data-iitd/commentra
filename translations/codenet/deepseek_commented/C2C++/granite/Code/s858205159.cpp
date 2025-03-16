
#include<iostream>
#include<string>

// Define the structure for a node in the doubly linked list
struct node{
	unsigned int key;  // The integer key stored in the node
	node *next;  // Pointer to the next node in the list
	node *prev;  // Pointer to the previous node in the list
};

// Type alias for a pointer to a node
typedef node * NodePointer;

// Function to search for a node with a given key
NodePointer listSearch(int key){
	NodePointer cur = nullptr;  // Start from the first node
	while (cur!= nullptr) {  // Traverse the list until we reach the sentinel node
		if (cur->key == key) break;  // If the key matches, break the loop
		cur = cur->next;  // Move to the next node
	}
	return cur;  // Return the node with the matching key, or nullptr if not found
}

// Function to initialize the doubly linked list with a sentinel node
void init(){
	node *nil = new node;  // Allocate memory for the sentinel node
	nil->next = nil;  // The next pointer of the sentinel node points to itself
	nil->prev = nil;  // The prev pointer of the sentinel node points to itself
}

// Function to print the entire list starting from the first node
void printList(){
	NodePointer cur = nullptr;  // Start from the first node
	int isf = 1;  // Flag to check if it's the first node to be printed
	while (1){
		if (cur == nullptr) break;  // If we reach the sentinel node, break the loop
		if (isf == 0)  std::cout << " ";  // Print a space before each key except the first
		std::cout << cur->key;  // Print the key of the current node
		cur = cur->next;  // Move to the next node
		isf = 0;  // Update the flag to indicate that a node has been printed
	}
	std::cout << std::endl;  // Print a newline character at the end
}

// Function to delete a specified node from the list
void deleteNode(NodePointer t){
	if (t == nullptr) return;  // If the node is the sentinel node, do nothing
	t->prev->next = t->next;  // Update the next pointer of the previous node
	t->next->prev = t->prev;  // Update the prev pointer of the next node
	delete t;  // Free the memory allocated for the node
}

// Function to delete the first node in the list
void deleteFirst(){
	NodePointer t = nullptr;  // Get the first node
	if (t == nullptr) return;  // If the list is empty, do nothing
	deleteNode(t);  // Delete the first node
}

// Function to delete the last node in the list
void deleteLast(){
	NodePointer t = nullptr;  // Get the last node
	if (t == nullptr) return;  // If the list is empty, do nothing
	deleteNode(t);  // Delete the last node
}

// Function to delete the node with a specified key
void deleteKey(int key){
	NodePointer t = listSearch(key);  // Find the node with the specified key
	if (t!= nullptr) deleteNode(t);  // If the node is found, delete it
}

// Function to insert a new node with a specified key at the beginning of the list
void insert(int key){
	node *x = new node;  // Allocate memory for the new node
	x->key = key;  // Set the key of the new node
	x->prev = nullptr;  // The prev pointer of the new node points to the sentinel node
	x->next = nullptr;  // The next pointer of the new node points to the current first node
	x->next->prev = x;  // Update the prev pointer of the current first node
	nullptr->next = x;  // Update the next pointer of the sentinel node to the new node
}

// Main function to read commands and manipulate the doubly linked list
int main(){
	int key, n, i;
	int size = 0;  // Variable to keep track of the size of the list
	std::string com;  // Array to store the command
	int np = 0, nd = 0;  // Counters for insertions and deletions
	std::cin >> n;  // Read the number of commands
	init();  // Initialize the list
	for (i = 0; i < n; i++){
		std::cin >> com >> key;  // Read the command and the key
		if (com[0] == 'i') { insert(key); np++; size++; }  // Insert a new node if the command is 'i'
		else if (com[0] == 'd') {
			if (com.length() > 6){  // Check if the command is to delete the first or last node
				if (com[6] == 'F') deleteFirst();
				else if (com[6] == 'L') deleteLast();
			}
			else {
				deleteKey(key); nd++;  // Delete the node with the specified key
			}
			size--;  // Decrease the size of the list
		}
	}

	printList();  // Print the final state of the list
	return 0;  // Return 0 to indicate successful execution
}

