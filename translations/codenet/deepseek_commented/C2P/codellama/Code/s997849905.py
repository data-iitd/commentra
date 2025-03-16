#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000000

#define init() \
  N = malloc(sizeof(struct node)); \
  N->next = N; \
  N->prev = N;

#define printList() \
  cur = N->next; \
  snl = 1; \
  while(cur != N): \
    if ( snl == 0): \
      printf(" "); \
    printf("%d", cur->key); \
    cur = cur->next; \
    snl = 0; \
  printf("\n");

#define deleteFirst() \
  t = N->next; \
  N->next = t->next; \
  t->next->prev = N; \
  free(t);

#define deleteLast() \
  delnode = N->prev; \
  N->prev = delnode->prev; \
  delnode->prev->next = N; \
  free(delnode);

#define delete(skey) \
  judge = 0; \
  n = N->next; \
  while(n != N): \
    if(n->key == skey): \
      judge = 1; \
    n = n->next; \
  if(judge == 1): \
    n = N->next; \
    while(n != N): \
      if(n->key == skey): \
        break; \
      n = n->next; \
    t = n->prev; \
    t->next = n->next; \
    t->next->prev = t; \
    free(n);

#define insert(skey) \
  new = malloc(sizeof(struct node)); \
  new->key = skey; \
  if(count == 0): \
    new->next = N; \
    N->next = new; \
    new->prev = N; \
    N->prev = new; \
    count++; \
  else: \
    new->next = N->next; \
    N->next->prev = new; \
    N->next = new; \
    new->prev = N; \
    count++;

#define main() \
  scanf("%d", &n); \
  init(); \
  for (i = 0; i < n; i++): \
    scanf("%s", com); \
    if(strcmp(com, "insert") == 0): \
      scanf("%d", &key); \
      insert(key); \
    else if(strcmp(com, "deleteFirst") == 0): \
      deleteFirst(); \
    else if(strcmp(com, "deleteLast") == 0): \
      deleteLast(); \
    else: \
      scanf("%d", &key); \
      delete(key); \
  printList(); \
  return 0;

#define 