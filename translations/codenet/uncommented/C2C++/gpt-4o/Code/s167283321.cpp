#include <iostream>
#include <vector>
#define NIL -1

struct Node {
    int parent, left, right;
};

std::vector<Node> R(10000);
int n;

void preorder(int x);
void inorder(int x);
void postorder(int x);

void preorder(int x) {
    if (x == NIL)
        return;
    std::cout << " " << x;
    preorder(R[x].left);
    preorder(R[x].right);
}

void inorder(int x) {
    if (x == NIL)
        return;
    inorder(R[x].left);
    std::cout << " " << x;
    inorder(R[x].right);
}

void postorder(int x) {
    if (x == NIL)
        return;
    postorder(R[x].left);
    postorder(R[x].right);
    std::cout << " " << x;
}

int main() {
    int a, b, c, root;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        R[i].parent = NIL;

    for (int i = 0; i < n; i++) {
        std::cin >> a >> b >> c;
        R[a].left = b;
        R[a].right = c;
        if (b != NIL) R[b].parent = a;
        if (c != NIL) R[c].parent = a;
    }

    for (int i = 0; i < n; i++) {
        if (R[i].parent == NIL)
            root = i;
    }

    std::cout << "Preorder\n";
    preorder(root);
    std::cout << "\n";
    std::cout << "Inorder\n";
    inorder(root);
    std::cout << "\n";
    std::cout << "Postorder\n";
    postorder(root);
    std::cout << "\n";

    return 0;
}

// <END-OF-CODE>
