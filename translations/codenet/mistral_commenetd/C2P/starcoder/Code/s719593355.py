
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil 0

#define NodePointer struct node*

struct node{
  unsigned int key;
  NodePointer next;
  NodePointer prev;
};

NodePointer nil;

NodePointer listSearch(int key){
  NodePointer cur = nil->next;

  while (cur!= nil and cur->key!= key)
    cur = cur->next;

  return cur;
}

void init(void){
  nil = (NodePointer)malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

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

void deleteNode(NodePointer t){
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
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
  x = (NodePointer)malloc(sizeof(struct node));

  x->key = key;

  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;

  scanf("%d", &n);

  init();

  for (i = 0;i < n;i++){
    scanf("%s%d", com, &key);

    if (com[0] == 'i') {
      insert(key); np++;
      size++;
    }

    else if (com[0] == 'd') {
      if (strlen(com) > 6){
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

  printf("Size: %d, Number of insert operations: %d, Number of delete operations: %d\n", size, np, nd);

  while(nil->next!= nil){
    NodePointer t = nil->next;
    nil->next = nil->next->next;
    free(t);
  }

  return 0;
}

