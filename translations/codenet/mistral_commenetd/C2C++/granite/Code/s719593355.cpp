

#include <iostream>
#include <string>
#include <cstdlib>

// Define a structure for a node in the linked list
struct node{
  unsigned int key;
  node *next;
  node *prev;
};

// Define a typedef for a pointer to a node
typedef node * NodePointer;

// Initialize the linked list with a nil node
NodePointer nil;

// Function to search for a node with a given key in the list
NodePointer listSearch(int key){
  NodePointer cur = nil->next; // Initialize a pointer to the first node in the list

  // Search for the node with the given key
  while (cur!= nil && cur->key!= key)
    cur = cur->next;

  // Return the found node or nil if not found
  return cur;
}

// Initialize the linked list with a nil node
void init(void){
  nil = (NodePointer)malloc(sizeof(node)); // Allocate memory for the nil node
  nil->next = nil; // Set the next pointer of the nil node to itself
  nil->prev = nil; // Set the prev pointer of the nil node to itself
}

// Print the contents of the linked list
void printList(void){
  NodePointer cur = nil->next; // Initialize a pointer to the first node in the list
  int isf = 1; // Flag to indicate if this is the first node to be printed

  // Traverse the list and print each node
  while(1){
    if ( cur == nil ) break; // If we have reached the end of the list, exit the loop
    if ( isf == 0)  std::cout << " "; // If this is not the first node, print a space before the key
    std::cout << cur->key; // Print the key of the current node
    cur = cur->next; // Move to the next node
    isf = 0; // Reset the flag for the next iteration
  }
  std::cout << std::endl; // Print a newline at the end
}

// Delete a node from the linked list
void deleteNode(NodePointer t){
  t->prev->next = t->next; // Set the next pointer of the previous node to the next node of the node to be deleted
  t->next->prev = t->prev; // Set the prev pointer of the next node to the previous node of the node to be deleted
  free(t); // Free the memory occupied by the node to be deleted
}

// Delete and free the first node in the list
void deleteFirst(void){
  NodePointer t = nil->next; // Initialize a pointer to the first node in the list

  // If the list is empty, return
  if ( t == nil )
    return;

  // Delete and free the first node
  deleteNode(t);
}

// Delete and free the last node in the list
void deleteLast(void){
  NodePointer t = nil->prev; // Initialize a pointer to the last node in the list

  // If the list is empty, return
  if (t == nil)
    return;

  // Delete and free the last node
  deleteNode(t);
}

// Delete a node with the given key from the list
void delete(int key){
  NodePointer t = listSearch(key); // Search for the node with the given key

  // If the node is not found, return
  if (t == nil)
    return;

  // Delete and free the node
  deleteNode(t);
}

// Allocate memory for a new node and insert it into the list
void insert(int key){
  NodePointer x; // Allocate memory for the new node
  x = (NodePointer)malloc(sizeof(node));

  // Initialize the new node with the given key
  x->key = key;

  // Insert the new node at the end of the list
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

// Main function to read commands from standard input and perform the corresponding actions
int main(){
  int key, n, i; // Declare variables to store the number of commands, the current command, and a counter
  int size = 0; // Initialize a variable to store the current size of the list
  std::string com; // Declare a string to store the command
  int np = 0, nd = 0; // Initialize counters for the number of insert and delete operations

  // Read the number of commands from standard input
  std::cin >> n;

  // Initialize the linked list
  init();

  // Process each command in the input
  for (i = 0;i < n;i++){
    std::cin >> com >> key; // Read the command and the key (if any) from standard input

    // If the command is an insert command, increment the np counter and insert the key into the list
    if (com == "insert") {
      insert(key); np++;
      size++;
    }

    // If the command is a delete command, increment the nd counter and delete the node with the given key from the list
    else if (com == "delete") {
      if (com.length() > 6){ // If the command is a delete first or delete last command, process it accordingly
	if (com[6] == 'F')
	  deleteFirst();
	
	else if (com[6] == 'L')
	  deleteLast();
      }
      
      else  // If the command is a delete command with a key, delete the node with the given key from the list
	delete(key); nd++; 
      
      
      size--; // Decrement the size of the list after the delete operation
	
    }

  }

  // Print the final size of the list and the number of insert and delete operations
  std::cout << "Size: " << size << ", Number of insert operations: " << np << ", Number of delete operations: " << nd << std::endl;

  // Free the memory occupied by the linked list
  while(nil->next!= nil){
    NodePointer t = nil->next;
    nil->next = nil->next->next;
    free(t);
  }

  return 0;
}

