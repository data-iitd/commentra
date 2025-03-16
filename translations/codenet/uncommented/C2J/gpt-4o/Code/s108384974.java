import java.util.Scanner;

class Node {
    int key;
    Node p;
    Node l;
    Node r;

    Node(int key) {
        this.key = key;
        this.l = null;
        this.r = null;
    }
}

public class BinarySearchTree {
    private Node r;
    private Node NIL;

    public BinarySearchTree() {
        NIL = null; // Represents the null node
        r = NIL; // Initially, the tree is empty
    }

    private Node find(Node x, int k) {
        while (x != NIL && k != x.key) {
            if (k < x.key) {
                x = x.l;
            } else {
                x = x.r;
            }
        }
        return x;
    }

    public void insert(int k) {
        Node y = NIL;
        Node x = r;

        Node z = new Node(k);

        while (x != NIL) {
            y = x;
            if (z.key < x.key) {
                x = x.l;
            } else {
                x = x.r;
            }
        }
        z.p = y;

        if (y == NIL) {
            r = z;
        } else if (z.key < y.key) {
            y.l = z;
        } else {
            y.r = z;
        }
    }

    private void inorder(Node u) {
        if (u == NIL) {
            return;
        }
        inorder(u.l);
        System.out.print(" " + u.key);
        inorder(u.r);
    }

    private void preorder(Node u) {
        if (u == NIL) {
            return;
        }
        System.out.print(" " + u.key);
        preorder(u.l);
        preorder(u.r);
    }

    public void print() {
        inorder(r);
        System.out.println();
        preorder(r);
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree bst = new BinarySearchTree();
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            if (command.charAt(0) == 'f') {
                int x = scanner.nextInt();
                Node t = bst.find(bst.r, x);
                if (t == bst.NIL) {
                    System.out.println("no");
                } else {
                    System.out.println("yes");
                }
            } else if (command.charAt(0) == 'i') {
                int z = scanner.nextInt();
                bst.insert(z);
            } else {
                bst.print();
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
