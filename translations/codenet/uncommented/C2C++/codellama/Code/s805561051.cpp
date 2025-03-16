# include<iostream>
# include<cstdio>

using namespace std;

struct BT{
  int parent;
  int right;
  int left;
};

BT bt[26];
int n;

void Preorder(int a){
  if(a == -1) return;

  cout<<" "<<a;
  Preorder(bt[a].left);
  Preorder(bt[a].right);

}

void Inorder(int a){
  if(a==-1)return;

  Inorder(bt[a].left);
  cout<<" "<<a;
  Inorder(bt[a].right);
}

void Postorder(int a){
  if(a==-1)return;

  Postorder(bt[a].left);
  Postorder(bt[a].right);
  cout<<" "<<a;
}

int main(){
  int i,j,num,depth = 0;
 

  
  cin>>n;

  for(i=0;i<n;++i) bt[i].parent = -1;

  for(i=0;i<n;i++){
    cin>>num;
    cin>>bt[num].left>>bt[num].right;

    if(bt[num].left != -1 &&bt[num].right != -1){
      bt[bt[num].left].parent = num;
      bt[bt[num].right].parent = num;
      
    }
    else if(bt[num].left != -1) bt[bt[num].left].parent = num;
    else if(bt[num].right != -1) bt[bt[num].right].parent = num;
  }

  for(i=0;bt[i].parent != -1;++i);
  
  cout<<"Preorder\n";
  Preorder(i);
  cout<<"\n";

  cout<<"Inorder\n";
  Inorder(i);
  cout<<"\n";

  cout<<"Postorder\n";
  Postorder(i);
  cout<<"\n";

  return 0;
}

