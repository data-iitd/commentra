
#include<stdio.h>
#include<stdlib.h>

#define NIL NULL

#define LEFT(x) x->l
#define RIGHT(x) x->r
#define PARENT(x) x->p

#define IS_NIL(x) (x == NIL)
#define IS_LEAF(x) (x!= NIL and x->l == NIL and x->r == NIL)
#define IS_LEFT_CHILD(x) (PARENT(x)!= NIL and PARENT(x)->l == x)
#define IS_RIGHT_CHILD(x) (PARENT(x)!= NIL and PARENT(x)->r == x)

#define MIN(x,y) (x < y? x : y)

#define HEIGHT(x) (IS_NIL(x)? -1 : x->h)
#define UPDATE_HEIGHT(x) (x->h = MAX(HEIGHT(x->l), HEIGHT(x->r)) + 1)

#define BALANCE(x) (IS_NIL(x)? 0 : HEIGHT(x->l) - HEIGHT(x->r))

#define LEFT_ROTATE(x) { \
  NodePointer y = x->r; \
  x->r = y->l; \
  if(y->l!= NIL) y->l->p = x; \
  y->p = x->p; \
  if(x->p == NIL) r = y; \
  else if(x == x->p->l) x->p->l = y; \
  else x->p->r = y; \
  y->l = x; \
  x->p = y; \
  UPDATE_HEIGHT(x); \
  UPDATE_HEIGHT(y); \
}

#define RIGHT_ROTATE(x) { \
  NodePointer y = x->l; \
  x->l = y->r; \
  if(y->r!= NIL) y->r->p = x; \
  y->p = x->p; \
  if(x->p == NIL) r = y; \
  else if(x == x->p->l) x->p->l = y; \
  else x->p->r = y; \
  y->r = x; \
  x->p = y; \
  UPDATE_HEIGHT(x); \
  UPDATE_HEIGHT(y); \
}

#define LEFT_RIGHT_ROTATE(x) { \
  LEFT_ROTATE(x->l); \
  RIGHT_ROTATE(x); \
}

#define RIGHT_LEFT_ROTATE(x) { \
  RIGHT_ROTATE(x->r); \
  LEFT_ROTATE(x); \
}

#define REBALANCE(x) { \
  if(BALANCE(x) == 2) { \
    if(BALANCE(x->l) == -1) { \
      LEFT_ROTATE(x); \
    } else { \
      LEFT_RIGHT_ROTATE(x); \
    } \
  } else if(BALANCE(x) == -2) { \
    if(BALANCE(x->r) == 1) { \
      RIGHT_ROTATE(x); \
    } else { \
      RIGHT_LEFT_ROTATE(x); \
    } \
  } \
}

typedef struct node{
  int key;
  int h;
  struct node *l;
  struct node *r;
  struct node *p;
} Node;

Node *r = NIL, *NIL = (Node *)malloc(sizeof(Node));

Node *find(Node *x, int k){
  while(x!= NIL and k!= x->key){
    if(k < x->key){
      x = x->l;
    }else{
      x = x->r;
    }
  }
  return x;
}

void insert(int k){
  Node *y = NIL, *x = r;
  Node *z = (Node *)malloc(sizeof(Node));

  z->key = k;
  z->l = NIL;
  z->r = NIL;

  while(x!= NIL){
    y = x;
    if(z->key < x->key){
      x = x->l;
    }else{
      x = x->r;
    }
  }

  z->p = y;

  if(y == NIL){
    r = z;
  }else if(z->key < y->key){
    y->l = z;
  }else{
    y->r = z;
  }

  z->h = 0;
  UPDATE_HEIGHT(z);

  while(z->p!= NIL){
    REBALANCE(z);
    z = z->p;
  }
}

void inorder(Node *u){
  if(u == NIL) return;
  inorder(u->l);
  printf(" %d",u->key);
  inorder(u->r);
}

void preorder(Node *u){
  if(u == NIL) return;
  printf(" %d",u->key);
  preorder(u->l);
  preorder(u->r);
}

void print(){
  inorder(r);
  puts("");
  preorder(r);
  puts("");
}

int main(){
  int n,i,j,z,x;
  char s[10];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",s);

    if(s[0] == 'f'){
      scanf("%d",&x);
      Node *t = find(r,x);
      if(t == NIL){
        printf("no\n");
      }else{
        printf("yes\n");
      }

    }else if(s[0] == 'i'){
      scanf("%d",&z);
      insert(z);

    }else{
      print();
    }
  }

  return 0;
}

