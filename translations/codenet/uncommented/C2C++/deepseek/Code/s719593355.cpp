#include <iostream>
#include <string>
#include <cstdlib>

struct node{
  unsigned int key;
  node *next;
  node *prev;
};

typedef node* NodePointer;

NodePointer nil;

NodePointer listSearch(int);
void init(void);
void printList(void);
void deleteNode(NodePointer);
void deleteFirst(void);
void deleteLast(void);
void delete(int);
void insert(int);

int main(){
  int key, n, i;
  int size = 0;
  std::string com;
  int np = 0, nd = 0;
  
  std::cin >> n;
  
  init();
  
  for (i = 0;i < n;i++){
    std::cin >> com >> key;
    
    if (com[0] == 'i') {
      insert(key); np++;
      size++;
    }
    
    else if (com[0] == 'd') {
      if (com.length() > 6){
	if (com[6] == 'F')
	  deleteFirst();
	
	else if (com[6] == 'L')
	  deleteLast();
      }
      
      else 
	delete(key); nd++; 
      
      
      size--;
	
    }
    
  }

  printList();
  
  return 0;
}

NodePointer listSearch(int key){
  NodePointer cur = nil->next;

  while (cur != nil && cur->key != key)
    cur = cur->next;

  return cur;
}

void init(void){
  nil = new node;
  nil->next = nil;
  nil->prev = nil;
}

void printList(void){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  std::cout << " ";
    std::cout << cur->key;
    cur = cur->next;
    isf = 0;
  }
  std::cout << std::endl;
}

void deleteNode(NodePointer t){
  t->prev->next = t->next;
  t->next->prev = t->prev;
  delete t;
}

void deleteFirst(void){
  NodePointer t = nil->next;
  if ( t == nil )
    return;
  
  deleteNode(t);
}

void deleteLast(void){
  NodePointer t = nil->prev;
  if (t == nil)
    return;
  
  deleteNode(t);
}

void delete(int key){
  NodePointer t = listSearch(key);

  if (t == nil)
    return;

  deleteNode(t);
}


void insert(int key){
  NodePointer x;
  x = new node;
  x->key = key;

  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;

}

