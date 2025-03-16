

import java.util.Scanner;

class Treap {
    static class Node {
        int key;
        int priority;
        Node left, right;

        Node(int item, int priority) {
            key = item;
            this.priority = priority;
            left = right = null;
        }
    }

    static Node root;

    static int find(Node node, int key) {
        while (node!= null) {
            if (node.key == key)
                return 1;
            else if (node.key > key)
                node = node.left;
            else
                node = node.right;
        }
        return 0;
    }

    static void inorder(Node node) {
        if (node.left!= null)
            inorder(node.left);
        System.out.print(" " + node.key);
        if (node.right!= null)
            inorder(node.right);
    }

    static void preorder(Node node) {
        System.out.print(" " + node.key);
        if (node.left!= null)
            preorder(node.left);
        if (node.right!= null)
            preorder(node.right);
    }

    static void print(Node node) {
        inorder(node);
        System.out.println();
        preorder(node);
        System.out.println();
    }

    static Node newNode(int item, int priority) {
        Node temp = new Node(item, priority);
        temp.left = temp.right = null;
        return temp;
    }

    static Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;
        x.right = y;
        y.left = T2;
        return x;
    }

    static Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;
        y.left = x;
        x.right = T2;
        return y;
    }

    static Node insert(Node node, int key, int priority) {
        if (node == null)
            return (newNode(key, priority));
        if (key < node.key)
            node.left = insert(node.left, key, priority);
        else if (key > node.key)
            node.right = insert(node.right, key, priority);
        else
            return node;

        if (node.priority < node.left.priority)
            node = rightRotate(node);
        if (node.priority < node.right.priority)
            node = leftRotate(node);

        return node;
    }

    static Node delete(Node node, int key) {
        if (node == null)
            return node;

        if (key < node.key)
            node.left = delete(node.left, key);
        else if (key > node.key)
            node.right = delete(node.right, key);
        else {
            if (node.left == null) {
                Node temp = node.right;
                return temp;
            } else if (node.right == null) {
                Node temp = node.left;
                return temp;
            }

            if (node.left.priority > node.right.priority)
                node = rightRotate(node);
            else
                node = leftRotate(node);

            node.right = delete(node.right, key);
        }
        return node;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] arr = new char[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.next().charAt(0);
        }
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        root = null;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'i') {
                root = insert(root, x[i], y[i]);
            } else if (arr[i] == 'd') {
                root = delete(root, x[i]);
            } else if (arr[i] == 'f') {
                if (find(root, x[i]) == 1)
                    System.out.println("yes");
                else
                    System.out.println("no");
            } else {
                print(root);
            }
        }
    }
}

