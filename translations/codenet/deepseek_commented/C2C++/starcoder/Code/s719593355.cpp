#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil; // A dummy node used for easier list manipulation

// Searches for a node with the specified key in the list
NodePointer listSearch(int key){
  NodePointer cur = nil->next;

  while (cur!= nil && cur->key!= key)
    cur = cur->next;

  return cur;
}

// Initializes the list by creating a dummy node and setting its next and prev pointers to point to itself
void init(void){
  nil = (NodePointer)malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

// Prints the entire list from the first node to the last node
void printList(void){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}

// Deletes the specified node from the list
void deleteNode(NodePointer t){
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

// Deletes the first node in the list
void deleteFirst(void){
  NodePointer t = nil->next;
  if ( t == nil )
    return;
  
  deleteNode(t);
}

// Deletes the last node in the list
void deleteLast(void){
  NodePointer t = nil->prev;
  if (t == nil)
    return;
  
  deleteNode(t);
}

// Deletes the node with the specified key from the list
void delete(int key){
  NodePointer t = listSearch(key);

  if (t == nil)
    return;

  deleteNode(t);
}

// Inserts a new node with the given key at the beginning of the list
void insert(int key){
  NodePointer x;
  x = (NodePointer)malloc(sizeof(struct node));
  x->key = key;

  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;

}

int main(){
  int key, n, i;
  int size = 0; // Keeps track of the number of elements in the list
  char com[20];
  int np = 0, nd = 0; // Counters for insertions and deletions
  
  cin >> n;
  
  init(); // Initialize the list
  
  for (i = 0;i < n;i++){
    cin >> com >> key;
    
    if (com[0] == 'i') { // Insert a new node with the specified key
      insert(key); np++;
      size++;
    }
    
    else if (com[0] == 'd') { // Delete a node with the specified key or the first/last node
      if (strlen(com) > 6){
	if (com[6] == 'F') // Delete the first node
	  deleteFirst();
	
	else if (com[6] == 'L') // Delete the last node
	  deleteLast();
      }
      
      else 
	delete(key); nd++; 
      
      
      size--;
	
    }
    
  }

  printList(); // Print the final list
  
  return 0;
}

