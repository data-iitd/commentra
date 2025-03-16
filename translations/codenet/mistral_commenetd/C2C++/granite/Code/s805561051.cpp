

# include<iostream>
# include<cstdio>

// Define a structure for a binary tree node
struct BT{
  int parent; // Parent node index
  int right; // Index of right child
  int left; // Index of left child
};

BT bt[26]; // Initialize an array of size 26 to store binary tree nodes
int n; // Number of nodes in the binary tree

// Recursive function to print tree in preorder traversal
void Preorder(int a){
  // Base case: if current node index is -1, return
  if(a == -1) return;

  // Print the current node value
  printf(" %d",a);

  // Recursively call for left and right subtrees
  Preorder(bt[a].left);
  Preorder(bt[a].right);
}

// Recursive function to print tree in inorder traversal
void Inorder(int a){
  // Base case: if current node index is -1, return
  if(a==-1)return;

  // Recursively call for left subtree
  Inorder(bt[a].left);

  // Print the current node value
  printf(" %d",a);

  // Recursively call for right subtree
  Inorder(bt[a].right);
}

// Recursive function to print tree in postorder traversal
void Postorder(int a){
  // Base case: if current node index is -1, return
  if(a==-1)return;

  // Recursively call for left and right subtrees
  Postorder(bt[a].left);
  Postorder(bt[a].right);

  // Print the current node value
  printf(" %d",a);
}

// Main function to read input and print tree traversals
int main(){
  int i,j,num; // Initialize variables
  int depth = 0; // Initialize depth variable

  // Read number of nodes in the binary tree
  scanf("%d",&n);

  // Initialize all nodes as root
  for(i=0;i<n;++i) bt[i].parent = -1;

  // Read node values and their left and right children
  for(i=0;i<n;i++){
    scanf("%d",&num); // Read node value

    // Initialize left and right children as -1
    bt[num].left = -1;
    bt[num].right = -1;

    // Read left and right child indices if they exist
    if(scanf("%d%d",&(bt[num].left),&(bt[num].right))!= 2) break;

    // Set parent of left and right children to current node
    if(bt[num].left!= -1 &&bt[num].right!= -1){
      bt[bt[num].left].parent = num;
      bt[bt[num].right].parent = num;
    }
    // Set parent of left child if it exists
    else if(bt[num].left!= -1) bt[bt[num].left].parent = num;
    // Set parent of right child if it exists
    else if(bt[num].right!= -1) bt[bt[num].right].parent = num;
  }

  // Find the index of the last node (root) in the tree
  for(i=0;bt[i].parent!= -1;++i);

  // Print tree traversals
  printf("Preorder\n");
  Preorder(i);
  printf("\n");

  printf("Inorder\n");
  Inorder(i);
  printf("\n");

  printf("Postorder\n");
  Postorder(i);
  printf("\n");

  return 0;
}

