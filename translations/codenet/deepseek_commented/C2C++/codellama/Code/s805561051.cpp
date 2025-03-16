# include<iostream>
# include<cstdio>

using namespace std;

struct BT{
  int parent;  // To store the parent node index
  int right;   // To store the index of the right child
  int left;    // To store the index of the left child
};

BT bt[26];     // Array to hold the nodes of the binary tree
int n;         // Number of nodes in the binary tree

// Function to perform preorder traversal of the binary tree
void Preorder(int a){
  if(a == -1) return;  // Base case: if the node is -1, return

  cout<<" "<<a;      // Print the current node
  Preorder(bt[a].left); // Recursively call Preorder on the left child
  Preorder(bt[a].right);// Recursively call Preorder on the right child
}

// Function to perform inorder traversal of the binary tree
void Inorder(int a){
  if(a == -1) return;  // Base case: if the node is -1, return

  Inorder(bt[a].left);  // Recursively call Inorder on the left child
  cout<<" "<<a;      // Print the current node
  Inorder(bt[a].right); // Recursively call Inorder on the right child
}

// Function to perform postorder traversal of the binary tree
void Postorder(int a){
  if(a == -1) return;  // Base case: if the node is -1, return

  Postorder(bt[a].left); // Recursively call Postorder on the left child
  Postorder(bt[a].right);// Recursively call Postorder on the right child
  cout<<" "<<a;      // Print the current node
}

// Main function to read the number of nodes, initialize the tree, and print traversals
int main(){
  int i, j, num;

  scanf("%d", &n);  // Read the number of nodes

  // Initialize all parent nodes to -1
  for(i = 0; i < n; ++i) bt[i].parent = -1;

  // Read the left and right children for each node
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    scanf("%d%d", &(bt[num].left), &(bt[num].right));

    // Update the parent pointers of the left and right children
    if(bt[num].left != -1 && bt[num].right != -1){
      bt[bt[num].left].parent = num;
      bt[bt[num].right].parent = num;
    }
    else if(bt[num].left != -1) bt[bt[num].left].parent = num;
    else if(bt[num].right != -1) bt[bt[num].right].parent = num;
  }

  // Find the root node (the node with no parent)
  for(i = 0; bt[i].parent != -1; ++i);

  // Print the preorder, inorder, and postorder traversals of the binary tree
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

