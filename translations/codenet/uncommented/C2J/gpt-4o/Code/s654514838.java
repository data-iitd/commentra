import java.util.Scanner;

class Node {
    int key;
    int priority;
    Node right, left;

    Node(int key, int priority) {
        this.key = key;
        this.priority = priority;
        this.left = null;
        this.right = null;
    }
}

public class Treap {
    private static final Node NIL = null;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        Node root = NIL;

        for (int i = 0; i < num; i++) {
            String command = scanner.next();
            switch (command.charAt(0)) {
                case 'i':
                    int x = scanner.nextInt();
                    int y = scanner.nextInt();
                    root = insert(root, x, y);
                    break;
                case 'd':
                    x = scanner.nextInt();
                    root = delete(root, x);
                    break;
                case 'f':
                    x = scanner.nextInt();
                    System.out.println(find(root, x) ? "yes" : "no");
                    break;
                case 'p':
                    print(root);
                    break;
            }
        }
        scanner.close();
    }

    static boolean find(Node p, int x) {
        while (p != NIL) {
            if (p.key == x) return true;
            else if (p.key > x) p = p.left;
            else p = p.right;
        }
        return false;
    }

    static void inorder(Node a) {
        if (a != NIL) {
            inorder(a.left);
            System.out.print(" " + a.key);
            inorder(a.right);
        }
    }

    static void preorder(Node p) {
        if (p != NIL) {
            System.out.print(" " + p.key);
            preorder(p.left);
            preorder(p.right);
        }
    }

    static void print(Node p) {
        inorder(p);
        System.out.println();
        preorder(p);
        System.out.println();
    }

    static Node rightRotate(Node p) {
        Node q = p.left;
        p.left = q.right;
        q.right = p;
        return q;
    }

    static Node leftRotate(Node p) {
        Node q = p.right;
        p.right = q.left;
        q.left = p;
        return q;
    }

    static Node insert(Node t, int key, int priority) {
        if (t == NIL) {
            return new Node(key, priority);
        }
        if (t.key == key) {
            return t; // Ignore duplicate keys
        }

        if (key < t.key) {
            t.left = insert(t.left, key, priority);
            if (t.priority < t.left.priority) {
                t = rightRotate(t);
            }
        } else {
            t.right = insert(t.right, key, priority);
            if (t.priority < t.right.priority) {
                t = leftRotate(t);
            }
        }
        return t;
    }

    static Node delete(Node t, int key) {
        if (t == NIL) {
            return NIL;
        }

        if (key < t.key) {
            t.left = delete(t.left, key);
        } else if (key > t.key) {
            t.right = delete(t.right, key);
        } else {
            return deleteNode(t);
        }
        return t;
    }

    static Node deleteNode(Node t) {
        if (t.left == NIL && t.right == NIL) {
            return NIL; // Leaf node
        } else if (t.left == NIL) {
            return leftRotate(t); // Only right child
        } else if (t.right == NIL) {
            return rightRotate(t); // Only left child
        } else {
            if (t.left.priority > t.right.priority) {
                t = rightRotate(t);
            } else {
                t = leftRotate(t);
            }
        }
        return delete(t, t.key);
    }
}

// <END-OF-CODE>
