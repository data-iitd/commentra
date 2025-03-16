#include <iostream>
#include <vector>

using namespace std;

struct BT {
    int parent;
    int right;
    int left;
};

vector<BT> bt(26);
int n;

void Preorder(int a) {
    if (a == -1) return;

    cout << " " << a;
    Preorder(bt[a].left);
    Preorder(bt[a].right);
}

void Inorder(int a) {
    if (a == -1) return;

    Inorder(bt[a].left);
    cout << " " << a;
    Inorder(bt[a].right);
}

void Postorder(int a) {
    if (a == -1) return;

    Postorder(bt[a].left);
    Postorder(bt[a].right);
    cout << " " << a;
}

int main() {
    int num;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        bt[i].parent = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        cin >> bt[num].left >> bt[num].right;

        if (bt[num].left != -1 && bt[num].right != -1) {
            bt[bt[num].left].parent = num;
            bt[bt[num].right].parent = num;
        } else if (bt[num].left != -1) {
            bt[bt[num].left].parent = num;
        } else if (bt[num].right != -1) {
            bt[bt[num].right].parent = num;
        }
    }

    int root;
    for (root = 0; bt[root].parent != -1; ++root);

    cout << "Preorder\n";
    Preorder(root);
    cout << "\n";

    cout << "Inorder\n";
    Inorder(root);
    cout << "\n";

    cout << "Postorder\n";
    Postorder(root);
    cout << "\n";

    return 0;
}

// <END-OF-CODE>
