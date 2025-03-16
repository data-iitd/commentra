

import java.util.Scanner;

public class s957555615{
    static Node root;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            if (command.equals("find")) {
                int key = scanner.nextInt();
                Node t = treeSearch(root, key);
                if (t!= null) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            } else if (command.equals("insert")) {
                int key = scanner.nextInt();
                insert(key);
            } else if (command.equals("print")) {
                inorder(root);
                System.out.println();
                preorder(root);
                System.out.println();
            } else if (command.equals("delete")) {
                int key = scanner.nextInt();
                treeDelete(treeSearch(root, key));
            }
        }
    }

    static Node treeMinimum(Node x) {
        while (x.left!= null) {
            x = x.left;
        }
        return x;
    }

    static Node treeMaximum(Node x) {
        while (x.right!= null) {
            x = x.right;
        }
        return x;
    }

    static Node treeSearch(Node u, int k) {
        if (u == null || k == u.key) {
            return u;
        }
        if (k < u.key) {
            return treeSearch(u.left, k);
        } else {
            return treeSearch(u.right, k);
        }
    }

    static Node treeSuccessor(Node x) {
        Node y;
        if (x.right!= null) {
            return treeMinimum(x.right);
        }
        y = x.parent;
        while (y!= null && x == y.right) {
            x = y;
            y = y.parent;
        }
        return y;
    }

    static void treeDelete(Node z) {
        Node y;
        Node x;
        if (z.left == null || z.right == null) {
            y = z;
        } else {
            y = treeSuccessor(z);
        }
        if (y.left!= null) {
            x = y.left;
        } else {
            x = y.right;
        }
        if (x!= null) {
            x.parent = y.parent;
        }
        if (y.parent == null) {
            root = x;
        } else if (y == y.parent.left) {
            y.parent.left = x;
        } else {
            y.parent.right = x;
        }
        if (y!= z) {
            z.key = y.key;
        }
    }

    static void insert(int k) {
        Node y = null;
        Node x = root;
        Node z = new Node();
        z.key = k;
        z.left = null;
        z.right = null;
        while (x!= null) {
            y = x;
            if (z.key < x.key) {
                x = x.left;
            } else {
                x = x.right;
            }
        }
        z.parent = y;
        if (y == null) {
            root = z;
        } else if (z.key < y.key) {
            y.left = z;
        } else {
            y.right = z;
        }
    }

    static void inorder(Node u) {
        if (u == null) {
            return;
        }
        inorder(u.left);
        System.out.print(" " + u.key);
        inorder(u.right);
    }

    static void preorder(Node u) {
        if (u == null) {
            return;
        }
        System.out.print(" " + u.key);
        preorder(u.left);
        preorder(u.right);
    }

    static class Node {
        Node left;
        Node right;
        Node parent;
        int key;
    }
}

