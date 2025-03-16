
#include <iostream>

#define MAX 25

using namespace std;

struct node{
  int l,r,par;
};

node N[MAX];

void init(int);
void Preorder(int);
void Inorder(int);
void Postorder(int);

int main(){
  int n,i,id,l,r;
  int p;

  cin >> n;
  init(n);

  for(i = 0 ; i < n ; i++){
    cin >> id >> l >> r;

    if(l!= -1){
      N[id].l = l;
      N[l].par = id;
    }
    if(r!= -1){
      N[id].r = r;
      N[r].par = id;
    }
  }

  for(i = 0 ; i < n ; i++){
    if(N[i].par == -1){
      p = i;
      break;}
}

cout << "Preorder" << endl;
Preorder(p);
cout << endl;

cout << "Inorder" << endl;
Inorder(p);
cout << endl;

cout << "Postorder" << endl;
Postorder(p);
cout << endl;

return 0;
}

void init(int n){
  int i;

  for(i = 0 ; i < n ; i++){
    N[i].par = N[i].l = N[i].r = -1;
  }
}

void Preorder(int p){
  if(p!= -1){
    cout << " " << p;
    Preorder(N[p].l);
    Preorder(N[p].r);
  }
}

void Inorder(int p){
  if(p!= -1){
    Inorder(N[p].l);
    cout << " " << p;
    Inorder(N[p].r);
  }
}

void Postorder(int p){
  if(p!= -1){
    Postorder(N[p].l);
    Postorder(N[p].r);
    cout << " " << p;
  }
}

