#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure for a doubly linked list node
struct node{
  int key;                // Key value of the node
  struct node *next;     // Pointer to the next node
  struct node *prev;     // Pointer to the previous node
};

// Define a pointer type for the node structure
typedef struct node *NodePointer;
NodePointer N; // Head of the doubly linked list

// Function to initialize the doubly linked list
void init(){
  N = malloc(sizeof(struct node)); // Allocate memory for the head node
  N->next = N;                     // Point next of head to itself (circular)
  N->prev = N;                     // Point prev of head to itself (circular)
}

// Function to print the elements of the list
void printList(){
  NodePointer cur = N->next; // Start from the first node
  int snl = 1;               // Flag to manage spacing
  while(cur != N){           // Traverse until we reach the head again
    if ( snl == 0)  printf(" "); // Print space before the next number
    printf("%d", cur->key); // Print the key of the current node
    cur = cur->next;        // Move to the next node
    snl = 0;                // Set flag to indicate that we have printed at least one element
  }
  printf("\n");             // Print a newline after the list
}

// Function to delete the first node in the list
void deleteFirst(){
  NodePointer t = N->next; // Node to be deleted (first node)
  N->next = t->next;       // Update head's next to the second node
  t->next->prev = N;       // Update the new first node's prev to head
}

// Function to delete the last node in the list
void deleteLast(){
  NodePointer delnode = N->prev; // Node to be deleted (last node)
  N->prev = delnode->prev;       // Update head's prev to the second last node
  delnode->prev->next = N;       // Update the new last node's next to head
  free(delnode);                  // Free the memory of the deleted node
}

// Function to delete a node with a specific key
void delete(int skey){
  int judge = 0;                // Flag to check if the key exists
  NodePointer t;                // Temporary pointer for node manipulation
  NodePointer n;                // Pointer for traversal

  // Traverse the list to check if the key exists
  for(n = N->next; n != N; n = n->next){
    if(n->key == skey){
      judge = 1;                // Key found
    }
  }

  // If the key exists, proceed to delete the node
  if(judge == 1){
    n = N->next;               // Start from the first node
    while(n != N){             // Traverse until we find the key
      if(n->key == skey)
        break;                 // Break if key is found
      n=n->next;               // Move to the next node
    }
    t = n->prev;               // Get the previous node
    t->next = n->next;         // Bypass the node to be deleted
    t->next->prev = t;         // Update the next node's prev pointer
    free(n);                   // Free the memory of the deleted node
  }
}

// Function to insert a new node with a specific key
void insert(int skey){
  NodePointer new;             // Pointer for the new node
  static int count = 0;       // Static variable to track the number of nodes
  new = malloc(sizeof(struct node)); // Allocate memory for the new node
  new->key = skey;            // Set the key of the new node

  // If this is the first node being inserted
  if(count == 0){
    new->next = N;            // Point new node's next to head
    N->next = new;           // Update head's next to new node
    new->prev = N;            // Point new node's prev to head
    N->prev = new;            // Update head's prev to new node
    count++;                  // Increment the count of nodes
  }
  // If there are already nodes in the list
  else{
    new->next = N->next;     // Point new node's next to the first node
    N->next->prev = new;     // Update the first node's prev to new node
    N->next = new;           // Update head's next to new node
    new->prev = N;            // Point new node's prev to head
    count++;                  // Increment the count of nodes
  }
}

// Main function to execute the program
int main(){
  int key, n, i;              // Variables for key, number of operations, and loop index
  char com[12];               // Array to store command input

  scanf("%d", &n);            // Read the number of operations
  init();                     // Initialize the doubly linked list
  for ( i = 0; i < n; i++ ){  // Loop through each operation
    scanf("%s",com);          // Read the command
    if(strcmp(com,"insert") == 0){ // Check if command is 'insert'
      scanf("%d",&key);       // Read the key to insert
      insert(key);            // Call insert function
    }
    else if(strcmp(com,"deleteFirst") == 0) // Check if command is 'deleteFirst'
      deleteFirst();          // Call deleteFirst function
    else if(strcmp(com,"deleteLast") == 0)  // Check if command is 'deleteLast'
      deleteLast();           // Call deleteLast function
    else{                     // If command is 'delete'
      scanf("%d",&key);       // Read the key to delete
      delete(key);            // Call delete function
    }
  }
  printList();                // Print the final state of the list
  return 0;                   // Return success
}

