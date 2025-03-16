
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct node{
  int key;
  node *next;
  node *prev;
};

typedef node *NodePointer;
NodePointer N;

void init(){
  N = new node;
  N->next = N;
  N->prev = N;
}

void printList(){
  NodePointer cur = N->next;
  int snl = 1;
  while(cur!= N){
    if ( snl == 0)  cout << " ";
    cout << cur->key;
    cur = cur->next;
    snl = 0;
  }
  cout << endl;
}

void deleteFirst(){
  NodePointer t = N->next;
  N->next = t->next;
  t->next->prev = N;
}
 
void deleteLast(){
 
  NodePointer delnode = N->prev;
 
  N->prev = delnode->prev;
  delnode->prev->next = N;
  delete delnode;
}
 
void delete(int skey){
  int judge = 0;
  NodePointer t;
  NodePointer n; 

  for(n = N->next;n!= N;n = n->next){
    if(n->key == skey){
      judge = 1;
    }
  }

  if(judge == 1){
    n = N->next;
    while(n!= N){
      if(n->key == skey)
	break;
      n=n->next;
    }
    t = n->prev;
    t->next = n->next;
    t->next->prev = t;
    delete n;
  }
}

void insert(int skey){
  NodePointer new;
  static int count = 0;
  new = new node;
  new->key = skey;
 
  if(count == 0){
  new->next = N;
  N->next = new;
  new->prev = N;
  N->prev = new;
  count++;
  }
 
  else{
    new->next = N->next;
    N->next->prev = new;
    N->next = new;
    new->prev = N;
    count++;
  }
}

int main(){
  int key, n, i;
  string com;
   
  cin >> n;
  init();
  for ( i = 0; i < n; i++ ){
    cin >> com;
    if(com == "insert"){
      cin >> key;
      insert(key);
    }
    else if(com == "deleteFirst")
      deleteFirst();
    else if(com == "deleteLast")
      deleteLast();
    else{
      cin >> key;
      delete(key);
    }
  }
  printList();
  return 0;
}
