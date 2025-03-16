
#include<iostream>
#include<vector>

// Define a structure for a binary tree node
struct BT {
    int parent; // Parent node index
    int right;  // Right child index
    int left;   // Left child index
};

// Function to perform preorder traversal of the binary tree
void Preorder(int a, std::vector<BT>& bt) {
    // Base case: if the node index is -1, return
    if (a == -1) return;

    // Print the current node index
    std::cout << " " << a;
    // Recursively traverse the left subtree
    Preorder(bt[a].left, bt);
    // Recursively traverse the right subtree
    Preorder(bt[a].right, bt);
}

// Function to perform inorder traversal of the binary tree
void Inorder(int a, std::vector<BT>& bt) {
    // Base case: if the node index is -1, return
    if (a == -1) return;

    // Recursively traverse the left subtree
    Inorder(bt[a].left, bt);
    // Print the current node index
    std::cout << " " << a;
    // Recursively traverse the right subtree
    Inorder(bt[a].right, bt);
}

// Function to perform postorder traversal of the binary tree
void Postorder(int a, std::vector<BT>& bt) {
    // Base case: if the node index is -1, return
    if (a == -1) return;

    // Recursively traverse the left subtree
    Postorder(bt[a].left, bt);
    // Recursively traverse the right subtree
    Postorder(bt[a].right, bt);
    // Print the current node index
    std::cout << " " << a;
}

int main() {
    int i, j, num, depth = 0;

    // Read the number of nodes in the binary tree
    std::cin >> n;

    // Initialize the parent of each node to -1 (indicating no parent)
    std::vector<BT> bt(n);
    for (i = 0; i < n; ++i) bt[i].parent = -1;

    // Read the tree structure from input
    for (i = 0; i < n; i++) {
        // Read the current node index
        std::cin >> num;
        // Read the left and right child indices
        std::cin >> bt[num].left >> bt[num].right;

        // Update the parent index for the left and right children if they exist
        if (bt[num].left!= -1 && bt[num].right!= -1) {
            bt[bt[num].left].parent = num;
            bt[bt[num].right].parent = num;
        } else if (bt[num].left!= -1) {
            bt[bt[num].left].parent = num;
        } else if (bt[num].right!= -1) {
            bt[bt[num].right].parent = num;
        }
    }

    // Find the root of the binary tree (the node with no parent)
    for (i = 0; bt[i].parent!= -1; ++i);

    // Perform and print preorder traversal
    std::cout << "Preorder\n";
    Preorder(i, bt);
    std::cout << "\n";

    // Perform and print inorder traversal
    std::cout << "Inorder\n";
    Inorder(i, bt);
    std::cout << "\n";

    // Perform and print postorder traversal
    std::cout << "Postorder\n";
    Postorder(i, bt);
    std::cout << "\n";

    return 0; // Return success
}

