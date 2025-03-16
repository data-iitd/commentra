
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node{
  int key;
  Node next;
  Node prev;
};

class List{
  Node nil; // A dummy node used for easier list manipulation
  
  // Searches for a node with the specified key in the list
  Node listSearch(int key);
  
  // Initializes the list by creating a dummy node and setting its next and prev pointers
  void init(void);
  
  // Prints the entire list from the first node to the last node
  void printList(void);
  
  // Deletes the specified node from the list
  void deleteNode(Node t);
  
  // Deletes the first node in the list
  void deleteFirst(void);
  
  // Deletes the last node in the list
  void deleteLast(void);
  
  // Deletes the node with the specified key from the list
  void delete(int key);
  
  // Inserts a new node with the given key at the beginning of the list
  void insert(int key);
  
  public static void main(String[] args){
    int key, n, i;
    int size = 0; // Keeps track of the number of elements in the list
    String com;
    int np = 0, nd = 0; // Counters for insertions and deletions
    
    scanf("%d", &n);
    
    init(); // Initialize the list
    
    for (i = 0;i < n;i++){
      scanf("%s%d", com, &key);
      
      if (com.equals("i")) { // Insert a new node with the specified key
	insert(key); np++;
	size++;
      }
      
      else if (com.equals("d")) { // Delete a node with the specified key or the first/last node
	if (com.length() > 6){
	  if (com.charAt(6) == 'F') // Delete the first node
	    deleteFirst();
	  
	  else if (com.charAt(6) == 'L') // Delete the last node
	    deleteLast();
	}
	
	else 
	  delete(key); nd++; 
	
	
	size--;
	
      }
      
    }

    printList(); // Print the final list
    
  }
  
  // Searches for a node with the specified key in the list
  Node listSearch(int key){
    Node cur = nil.next;

    while (cur != nil && cur.key != key)
      cur = cur.next;

    return cur;
  }

  // Initializes the list by creating a dummy node and setting its next and prev pointers to point to itself
  void init(void){
    nil = new Node();
    nil.next = nil;
    nil.prev = nil;
  }

  // Prints the entire list from the first node to the last node
  void printList(void){
    Node cur = nil.next;
    int isf = 1;
    while(1){
      if ( cur == nil ) break;
      if ( isf == 0)  printf(" ");
      printf("%d", cur.key);
      cur = cur.next;
      isf = 0;
    }
    printf("\n");
  }

  // Deletes the specified node from the list
  void deleteNode(Node t){
    t.prev.next = t.next;
    t.next.prev = t.prev;
    free(t);
  }

  // Deletes the first node in the list
  void deleteFirst(void){
    Node t = nil.next;
    if ( t == nil )
      return;
    
    deleteNode(t);
  }

  // Deletes the last node in the list
  void deleteLast(void){
    Node t = nil.prev;
    if (t == nil)
      return;
    
    deleteNode(t);
  }

  // Deletes the node with the specified key from the list
  void delete(int key){
    Node t = listSearch(key);

    if (t == nil)
      return;

    deleteNode(t);
  }

  // Inserts a new node with the given key at the beginning of the list
  void insert(int key){
    Node x;
    x = new Node();
    x.key = key;

    x.next = nil.next;
    nil.next.prev = x;
    nil.next = x;
    x.prev = nil;

  }

}

