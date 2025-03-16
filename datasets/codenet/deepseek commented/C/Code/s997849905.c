#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the structure for a node in the circular doubly linked list
struct node{
  int key;          // Integer key stored in the node
  struct node *next; // Pointer to the next node in the list
  struct node *prev; // Pointer to the previous node in the list
};

// Define a type for a pointer to a node
typedef struct node *NodePointer;

// Declare a global variable N of type NodePointer
NodePointer N;

// Initialize the circular doubly linked list
void init(){
  N = malloc(sizeof(struct node)); // Allocate memory for the sentinel node
  N->next = N; // Set the next pointer of the sentinel node to itself
  N->prev = N; // Set the previous pointer of the sentinel node to itself
}

// Print the elements of the circular doubly linked list
void printList(){
  NodePointer cur = N->next; // Start from the first node
  int snl = 1; // Flag to determine if it's the first element
  while(cur != N){ // Iterate until the sentinel node is reached
    if ( snl == 0)  printf(" "); // Print a space before non-first elements
    printf("%d", cur->key); // Print the key of the current node
    cur = cur->next; // Move to the next node
    snl = 0; // Set the flag to indicate a non-first element
  }
  printf("\n"); // Print a newline at the end
}

// Delete the first node in the circular doubly linked list
void deleteFirst(){
  NodePointer t = N->next; // Store the first node
  N->next = t->next; // Update the next pointer of the sentinel node
  t->next->prev = N; // Update the previous pointer of the new first node
  free(t); // Free the memory of the deleted node
}

// Delete the last node in the circular doubly linked list
void deleteLast(){
  NodePointer delnode = N->prev; // Store the last node
  N->prev = delnode->prev; // Update the previous pointer of the sentinel node
  delnode->prev->next = N; // Update the next pointer of the new last node
  free(delnode); // Free the memory of the deleted node
}

// Delete a node with a specific key from the circular doubly linked list
void delete(int skey){
  int judge = 0; // Flag to indicate if the key was found
  NodePointer t; // Temporary pointer for node traversal
  NodePointer n; // Temporary pointer for node search

  // Iterate through the list to find the node with the specified key
  for(n = N->next; n != N; n = n->next){
    if(n->key == skey){
      judge = 1; // Set the flag if the key is found
    }
  }

  // If the key is found, remove the node
  if(judge == 1){
    n = N->next;
    while(n != N){
      if(n->key == skey)
	break;
      n = n->next;
    }
    t = n->prev;
    t->next = n->next;
    t->next->prev = t;
    free(n);
  }
}

// Insert a new node with a specific key into the circular doubly linked list
void insert(int skey){
  NodePointer new; // Pointer to the new node
  static int count = 0; // Static variable to track the number of nodes
  new = malloc(sizeof(struct node)); // Allocate memory for the new node
  new->key = skey; // Set the key of the new node

  // Special case: if the list is empty, set the new node as the only node
  if(count == 0){
    new->next = N;
    N->next = new;
    new->prev = N;
    N->prev = new;
    count++;
  }
  else{
    new->next = N->next; // Set the next pointer of the new node
    N->next->prev = new; // Update the previous pointer of the current first node
    N->next = new; // Update the next pointer of the sentinel node
    new->prev = N; // Set the previous pointer of the new node
    count++;
  }
}

// Main function to execute the operations on the circular doubly linked list
int main(){
  int key, n, i;
  char com[12]; // Array to store the command

  scanf("%d", &n); // Read the number of commands
  init(); // Initialize the circular doubly linked list
  for (i = 0; i < n; i++){ // Loop through the number of commands
    scanf("%s", com); // Read the command
    if(strcmp(com, "insert") == 0){ // If the command is to insert
      scanf("%d", &key); // Read the key to insert
      insert(key); // Insert the key into the list
    }
    else if(strcmp(com, "deleteFirst") == 0) // If the command is to delete the first node
      deleteFirst();
    else if(strcmp(com, "deleteLast") == 0) // If the command is to delete the last node
      deleteLast();
    else{ // If the command is to delete a specific node
      scanf("%d", &key); // Read the key to delete
      delete(key); // Delete the node with the specified key
    }
  }
  printList(); // Print the final state of the list
  return 0;
}
