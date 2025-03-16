int main(){
  // Declare and initialize variables
  int n,i,id,l,r;
  int p;

  // Read the number of nodes in the tree
  scanf("%d" ,&n);

  // Initialize the tree
  init(n);

  // Read the input and build the tree
  for(i = 0 ; i < n ; i++){
    // Read the id, left child, and right child of the current node
    scanf("%d%d%d" ,&id ,&l ,&r);

    // If the left child is not -1, assign it to the left child of the current node
    if(l != -1){
      N[id].l = l;
      N[l].par = id;
    }

    // If the right child is not -1, assign it to the right child of the current node
    if(r != -1){
      N[id].r = r;
      N[r].par = id;
    }
  }

  // Find the root node and perform tree traversals
  for(i = 0 ; i < n ; i++){
    if(N[i].par == -1){
      p = i;
      break;
    }
  }

  // Print the tree traversals in Preorder, Inorder, and Postorder
  puts("Preorder");
  Preorder(p);
  puts("");

  puts("Inorder");
  Inorder(p);
  puts("");

  puts("Postorder");
  Postorder(p);
  puts("");

  return 0;
}

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.
