#include <iostream>
#define NIL -1
using namespace std;
struct Node{
  int parent,left,right;
};
Node R[10000];
int n;
void preorder(int);
void inorder(int);
void postorder(int);

void preorder(int x){
  if(x==NIL)
    return;
  cout<<" "<<x;
  preorder(R[x].left);
  preorder(R[x].right);
}
void inorder(int x){
  if(x==NIL)
    return;
  inorder(R[x].left);
  cout<<" "<<x;
  inorder(R[x].right);
}
void postorder(int x){
  if(x==NIL)
    return;
  postorder(R[x].left);
  postorder(R[x].right);
  cout<<" "<<x;
}

int main(){
  int i,a,b,c,root;
  cin>>n;
  for(i=0;i<n;i++)
    R[i].parent=NIL;
  for(i=0;i<n;i++){
    cin>>a>>b>>c;
    R[a].left=b;
    R[a].right=c;
    if(b!=NIL)R[b].parent=a;
    if(c!=NIL)R[c].parent=a;
  }
  for(i=0;i<n;i++){
    if(R[i].parent==NIL)
      root=i;
  }
  cout<<"Preorder\n";
  preorder(root);
  cout<<"\n";
  cout<<"Inorder\n";
  inorder(root);
  cout<<"\n";
  cout<<"Postorder\n";
  postorder(root);
  cout<<"\n";
  return 0;
}

