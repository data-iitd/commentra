#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the structure for a node in the circular doubly linked list
class Node{
  int key;          // Integer key stored in the node
  Node next; // Pointer to the next node in the list
  Node prev; // Pointer to the previous node in the list

  public Node(int key, Node next, Node prev){
    this.key = key;
    this.next = next;
    this.prev = prev;
  }
}

// Define a type for a pointer to a node
class NodePointer{
  Node node;

  public NodePointer(Node node){
    this.node = node;
  }
}

// Declare a global variable N of type NodePointer
NodePointer N;

// Initialize the circular doubly linked list
void init(){
  N = new NodePointer(new Node(0, null, null)); // Allocate memory for the sentinel node
  N.node.next = N.node; // Set the next pointer of the sentinel node to itself
  N.node.prev = N.node; // Set the previous pointer of the sentinel node to itself
}

// Print the elements of the circular doubly linked list
void printList(){
  NodePointer cur = N.node.next; // Start from the first node
  int snl = 1; // Flag to determine if it's the first element
  while(cur != N.node){ // Iterate until the sentinel node is reached
    if ( snl == 0)  System.out.print(" "); // Print a space before non-first elements
    System.out.print(cur.node.key); // Print the key of the current node
    cur = cur.node.next; // Move to the next node
    snl = 0; // Set the flag to indicate a non-first element
  }
  System.out.println(); // Print a newline at the end
}

// Delete the first node in the circular doubly linked list
void deleteFirst(){
  NodePointer t = N.node.next; // Store the first node
  N.node.next = t.node.next; // Update the next pointer of the sentinel node
  t.node.next.prev = N.node; // Update the previous pointer of the new first node
  t = null; // Free the memory of the deleted node
}

// Delete the last node in the circular doubly linked list
void deleteLast(){
  NodePointer delnode = N.node.prev; // Store the last node
  N.node.prev = delnode.node.prev; // Update the previous pointer of the sentinel node
  delnode.node.prev.next = N.node; // Update the next pointer of the new last node
  delnode = null; // Free the memory of the deleted node
}

// Delete a node with a specific key from the circular doubly linked list
void delete(int skey){
  int judge = 0; // Flag to indicate if the key was found
  NodePointer t; // Temporary pointer for node traversal
  NodePointer n; // Temporary pointer for node search

  // Iterate through the list to find the node with the specified key
  for(n = N.node.next; n != N.node; n = n.node.next){
    if(n.node.key == skey){
      judge = 1; // Set the flag if the key is found
    }
  }

  // If the key is found, remove the node
  if(judge == 1){
    n = N.node.next;
    while(n != N.node){
      if(n.node.key == skey)
	break;
      n = n.node.next;
    }
    t = n.node.prev;
    t.node.next = n.node.next;
    t.node.next.prev = t;
    n = null;
  }
}

// Insert a new node with a specific key into the circular doubly linked list
void insert(int skey){
  NodePointer new; // Pointer to the new node
  static int count = 0; // Static variable to track the number of nodes
  new = new NodePointer(new Node(skey, null, null)); // Allocate memory for the new node

  // Special case: if the list is empty, set the new node as the only node
  if(count == 0){
    new.node.next = N.node;
    N.node.next = new.node;
    new.node.prev = N.node;
    N.node.prev = new.node;
    count++;
  }
  else{
    new.node.next = N.node.next; // Set the next pointer of the new node
    N.node.next.prev = new.node; // Update the previous pointer of the current first node
    N.node.next = new.node; // Update the next pointer of the sentinel node
    new.node.prev = N.node; // Set the previous pointer of the new node
    count++;
  }
}

// Main function to execute the operations on the circular doubly linked list
int main(){
  int key, n, i;
  String com; // Array to store the command

  scanf("%d", &n); // Read the number of commands
  init(); // Initialize the circular doubly linked list
  for (i = 0; i < n; i++){ // Loop through the number of commands
    scanf("%s", com); // Read the command
    if(com.equals("insert")){ // If the command is to insert
      scanf("%d", &key); // Read the key to insert
      insert(key); // Insert the key into the list
    }
    else if(com.equals("deleteFirst")) // If the command is to delete the first node
      deleteFirst();
    else if(com.equals("deleteLast")) // If the command is to delete the last node
      deleteLast();
    else{ // If the command is to delete a specific node
      scanf("%d", &key); // Read the key to delete
      delete(key); // Delete the node with the specified key
    }
  }
  printList(); // Print the final state of the list
  return 0;
}

