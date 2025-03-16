#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
  int key;
  node *p;
  node *l;
  node *r;
};

typedef node *NodePointer;

NodePointer r,NIL;

NodePointer find(NodePointer x,int k){
  while(x != NIL && k != x->key){
    if(k < x->key){
      x = x->l;
    }else{
      x = x->r;
    }
  }
  return x;
}

void insert(int k){
  NodePointer y = NIL;
  NodePointer x = r;

  NodePointer z = new node;
  z->key = k;
  z->l = NIL;
  z->r = NIL;

  while(x != NIL){
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
}

void inorder(NodePointer u){
  if(u == NIL){
    return;
  }
  inorder(u->l);
  cout << " " << u->key;
  inorder(u->r);
}

void preorder(NodePointer u){
  if(u == NIL){
    return;
  }
  cout << " " << u->key;
  preorder(u->l);
  preorder(u->r);
}

void print(){
  inorder(r);
  cout << endl;
  preorder(r);
  cout << endl;
}

int main(){
  int n,i,j,z,x;
  char s[10];

  cin >> n;
  for(i=0;i<n;i++){
    cin >> s;
    if(s[0] == 'f'){
      cin >> x;
      NodePointer t = find(r,x);
      if(t == NIL)cout << "no" << endl;
      else cout << "yes" << endl;

    }else if(s[0] == 'i'){
      cin >> z;
      insert(z);
    }else{
      print();
    }
  }

  return 0;
}

