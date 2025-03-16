import java.util.Scanner;

class Node {
    Node right;
    Node left;
    Node parent;
    int key;

    Node(int key) {
        this.key = key;
        this.left = null;
        this.right = null;
        this.parent = null;
    }
}

public class BinaryTree {
    private Node root;

    public Node treeMinimum(Node x) {
        while (x.left != null) {
            x = x.left;
        }
        return x;
    }

    public Node treeMaximum(Node x) {
        while (x.right != null) {
            x = x.right;
        }
        return x;
    }

    public Node treeSearch(Node u, int k) {
        if (u == null || k == u.key) {
            return u;
        }
        if (k < u.key) {
            return treeSearch(u.left, k);
        } else {
            return treeSearch(u.right, k);
        }
    }

    public Node treeSuccessor(Node x) {
        Node y;
        if (x.right != null) {
            return treeMinimum(x.right);
        }
        y = x.parent;
        while (y != null && x == y.right) {
            x = y;
            y = y.parent;
        }
        return y;
    }

    public void treeDelete(Node z) {
        Node y; // node to be deleted
        Node x; // child of y

        if (z.left == null || z.right == null) {
            y = z;
        } else {
            y = treeSuccessor(z);
        }

        if (y.left != null) {
            x = y.left;
        } else {
            x = y.right;
        }

        if (x != null) {
            x.parent = y.parent;
        }

        if (y.parent == null) {
            root = x;
        } else if (y == y.parent.left) {
            y.parent.left = x;
        } else {
            y.parent.right = x;
        }

        if (y != z) {
            z.key = y.key;
        }
    }

    public void insert(int k) {
        Node y = null;
        Node x = root;
        Node z = new Node(k);

        while (x != null) {
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

    public void inorder(Node u) {
        if (u == null) return;
        inorder(u.left);
        System.out.print(" " + u.key);
        inorder(u.right);
    }

    public void preorder(Node u) {
        if (u == null) return;
        System.out.print(" " + u.key);
        preorder(u.left);
        preorder(u.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinaryTree tree = new BinaryTree();
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            String command = scanner.next();
            if (command.charAt(0) == 'f') {
                int x = scanner.nextInt();
                Node t = tree.treeSearch(tree.root, x);
                if (t != null) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            } else if (command.charAt(0) == 'i') {
                int x = scanner.nextInt();
                tree.insert(x);
            } else if (command.charAt(0) == 'p') {
                tree.inorder(tree.root);
                System.out.println();
                tree.preorder(tree.root);
                System.out.println();
            } else if (command.charAt(0) == 'd') {
                int x = scanner.nextInt();
                tree.treeDelete(tree.treeSearch(tree.root, x));
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
