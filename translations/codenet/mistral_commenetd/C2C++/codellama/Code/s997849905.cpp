
#include<iostream>
#include<cstdlib>
#include<cstring>

// Define a structure for a node
struct node{
  int key; // Key value of the node
  struct node *next; // Pointer to the next node
  struct node *prev; // Pointer to the previous node
};

// Typedef a NodePointer as a pointer to a node
typedef struct node *NodePointer;
NodePointer N; // Initialize a pointer to the first node

// Initialize the linked list
void init(){
  N = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the first node
  N->next = N; // Initialize next pointer of the first node to itself
  N->prev = N; // Initialize prev pointer of the first node to itself
}

// Print the contents of the linked list
void printList(){
  NodePointer cur = N->next; // Initialize a pointer to traverse the list
  int snl = 1; // Set a flag to control the printing of spaces between numbers
  while(cur != N){ // Traverse the list until the end is reached
    if ( snl == 0) // If a space is not required before the number, print a space
      std::cout << " ";
    std::cout << cur->key; // Print the key value of the current node
    cur = cur->next; // Move to the next node
    snl = 0; // Reset the flag for the next iteration
  }
  std::cout << std::endl; // Print a newline at the end
}

// Delete the first node from the list
void deleteFirst(){
  NodePointer t = N->next; // Initialize a pointer to the second node
  N->next = t->next; // Update the next pointer of the first node to point to the third node
  t->next->prev = N; // Update the prev pointer of the third node to point to the first node
}

// Delete the last node from the list
void deleteLast(){
  NodePointer delnode = N->prev; // Initialize a pointer to the second last node
  N->prev = delnode->prev; // Update the prev pointer of the second last node to point to the node before it
  delnode->prev->next = N; // Update the next pointer of the second last node to point to the first node
  free(delnode); // Free the memory occupied by the last node
}

// Delete a node with the given key from the list
void delete(int skey){
  int judge = 0; // Initialize a flag to check if the node to be deleted exists
  NodePointer t, n; // Initialize two pointers to traverse the list

  for(n = N->next;n != N;n = n->next){ // Traverse the list to find the node to be deleted
    if(n->key == skey){ // If the key matches, set the flag
      judge = 1;
      break;
    }
  }

  if(judge == 1){ // If the node exists, delete it
    n = N->next; // Initialize a pointer to the node after the node to be deleted
    t = n->prev; // Initialize a pointer to the node before the node to be deleted
    t->next = n->next; // Update the next pointer of the previous node to point to the next node after the deleted node
    t->next->prev = t; // Update the prev pointer of the next node to point to the previous node
    free(n); // Free the memory occupied by the deleted node
  }
}

// Insert a new node with the given key into the list
void insert(int skey){
  NodePointer new; // Initialize a pointer to the new node
  static int count = 0; // Initialize a counter to keep track of the number of nodes in the list

  new = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
  new->key = skey; // Set the key value of the new node

  if(count == 0){ // If the list is empty, initialize the first node
    new->next = N;
    N->next = new;
    new->prev = N;
    N->prev = new;
    count++;
  }

  else{ // If the list is not empty, insert the new node at the end
    new->next = N->next;
    N->next->prev = new;
    N->next = new;
    new->prev = N;
    count++;
  }
}

// Main function to read commands and perform the corresponding operations
int main(){
  int key, n, i;
  char com[12]; // Initialize an array to store the command string

  std::cin >> n; // Read the number of operations to be performed
  init(); // Initialize the linked list

  for ( i = 0; i < n; i++ ){ // Perform each operation in the loop
    std::cin >> com; // Read the command string
    if(strcmp(com,"insert") == 0){ // If the command is to insert a node
      std::cin >> key;
      insert(key);
    }
    else if(strcmp(com,"deleteFirst") == 0)
      deleteFirst(); // If the command is to delete the first node
    else if(strcmp(com,"deleteLast") == 0)
      deleteLast(); // If the command is to delete the last node
    else{ // If the command is to delete a node with a given key
      std::cin >> key;
      delete(key);
    }
  }
  printList(); // Print the updated list after performing all the operations
  return 0;
}

