#include <iostream>
#include <vector>

#define MAX 25

struct Node {
    int l, r, par;
};

Node N[MAX];

void init(int n);
void Preorder(int p);
void Inorder(int p);
void Postorder(int p);

int main() {
    int n, id, l, r;
    int p;

    std::cin >> n;
    init(n);

    for (int i = 0; i < n; i++) {
        std::cin >> id >> l >> r;

        if (l != -1) {
            N[id].l = l;
            N[l].par = id;
        }
        if (r != -1) {
            N[id].r = r;
            N[r].par = id;
        }
    }

    for (int i = 0; i < n; i++) {
        if (N[i].par == -1) {
            p = i;
            break;
        }
    }

    std::cout << "Preorder";
    Preorder(p);
    std::cout << std::endl;

    std::cout << "Inorder";
    Inorder(p);
    std::cout << std::endl;

    std::cout << "Postorder";
    Postorder(p);
    std::cout << std::endl;

    return 0;
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        N[i].par = N[i].l = N[i].r = -1;
    }
}

void Preorder(int p) {
    if (p != -1) {
        std::cout << " " << p;
        Preorder(N[p].l);
        Preorder(N[p].r);
    }
}

void Inorder(int p) {
    if (p != -1) {
        Inorder(N[p].l);
        std::cout << " " << p;
        Inorder(N[p].r);
    }
}

void Postorder(int p) {
    if (p != -1) {
        Postorder(N[p].l);
        Postorder(N[p].r);
        std::cout << " " << p;
    }
}

// <END-OF-CODE>
