
// Define a structure for a doubly linked list node
class Node{
  int key;                // Key value of the node
  Node next;              // Pointer to the next node
  Node prev;              // Pointer to the previous node
}

// Define a pointer type for the node structure
Node N; // Head of the doubly linked list

// Function to initialize the doubly linked list
void init(){
  N = new Node(); // Allocate memory for the head node
  N.next = N;     // Point next of head to itself (circular)
  N.prev = N;     // Point prev of head to itself (circular)
}

// Function to print the elements of the list
void printList(){
  Node cur = N.next; // Start from the first node
  int snl = 1;       // Flag to manage spacing
  while(cur!= N){   // Traverse until we reach the head again
    if ( snl == 0)  System.out.print(" "); // Print space before the next number
    System.out.print(cur.key); // Print the key of the current node
    cur = cur.next;  // Move to the next node
    snl = 0;          // Set flag to indicate that we have printed at least one element
  }
  System.out.println(); // Print a newline after the list
}

// Function to delete the first node in the list
void deleteFirst(){
  Node t = N.next; // Node to be deleted (first node)
  N.next = t.next; // Update head's next to the second node
  t.next.prev = N; // Update the new first node's prev to head
}

// Function to delete the last node in the list
void deleteLast(){
  Node delnode = N.prev; // Node to be deleted (last node)
  N.prev = delnode.prev; // Update head's prev to the second last node
  delnode.prev.next = N; // Update the new last node's next to head
  delnode = null;         // Free the memory of the deleted node
}

// Function to delete a node with a specific key
void delete(int skey){
  int judge = 0;    // Flag to check if the key exists
  Node t;          // Temporary pointer for node manipulation
  Node n;          // Pointer for traversal

  // Traverse the list to check if the key exists
  for(n = N.next; n!= N; n = n.next){
    if(n.key == skey){
      judge = 1;    // Key found
    }
  }

  // If the key exists, proceed to delete the node
  if(judge == 1){
    n = N.next;     // Start from the first node
    while(n!= N){   // Traverse until we find the key
      if(n.key == skey)
        break;       // Break if key is found
      n=n.next;     // Move to the next node
    }
    t = n.prev;     // Get the previous node
    t.next = n.next; // Bypass the node to be deleted
    t.next.prev = t; // Update the next node's prev pointer
    n = null;       // Free the memory of the deleted node
  }
}

// Function to insert a new node with a specific key
void insert(int skey){
  Node new;         // Pointer for the new node
  static int count = 0; // Static variable to track the number of nodes
  new = new Node(); // Allocate memory for the new node
  new.key = skey;   // Set the key of the new node

  // If this is the first node being inserted
  if(count == 0){
    new.next = N;    // Point new node's next to head
    N.next = new;   // Update head's next to new node
    new.prev = N;    // Point new node's prev to head
    N.prev = new;    // Update head's prev to new node
    count++;        // Increment the count of nodes
  }
  // If there are already nodes in the list
  else{
    new.next = N.next; // Point new node's next to the first node
    N.next.prev = new; // Update the first node's prev to new node
    N.next = new;     // Update head's next to new node
    new.prev = N;      // Point new node's prev to head
    count++;          // Increment the count of nodes
  }
}

// Main function to execute the program
public static void main(String[] args){
  int key, n, i;      // Variables for key, number of operations, and loop index
  String com;         // Variable to store command input

  Scanner sc = new Scanner(System.in);
  n = sc.nextInt();    // Read the number of operations
  init();             // Initialize the doubly linked list
  for ( i = 0; i < n; i++ ){  // Loop through each operation
    com = sc.next();       // Read the command
    if(com.equals("insert")){ // Check if command is 'insert'
      key = sc.nextInt();   // Read the key to insert
      insert(key);          // Call insert function
    }
    else if(com.equals("deleteFirst")) // Check if command is 'deleteFirst'
      deleteFirst();        // Call deleteFirst function
    else if(com.equals("deleteLast"))  // Check if command is 'deleteLast'
      deleteLast();         // Call deleteLast function
    else{                   // If command is 'delete'
      key = sc.nextInt();   // Read the key to delete
      delete(key);          // Call delete function
    }
  }
  printList();          // Print the final state of the list
}

