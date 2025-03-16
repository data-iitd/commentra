
package main;

import java.util.Scanner;

class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    Node(int key) {
        this.key = key;
    }
}

class Tree {
    Node root;

    void insert(int key) {
        if (root == null) {
            root = new Node(key);
            return;
        }

        Node currentNode = root;
        Node prevNode = null;
        while (currentNode != null) {
            prevNode = currentNode;
            if (currentNode.key < key) {
                currentNode = currentNode.right;
            } else {
                currentNode = currentNode.left;
            }
        }

        Node newNode = new Node(key);
        newNode.parent = prevNode;
        if (prevNode.key < key) {
            prevNode.right = newNode;
        } else {
            prevNode.left = newNode;
        }
    }

    void print() {
        if (root == null) {
            System.out.println("");
            System.out.println("");
        } else {
            System.out.println(" " + isToAs(visitInorder(root, new int[0])));
            System.out.println(" " + isToAs(visitPreorder(root, new int[0])));
        }
    }

    int[] visitPreorder(Node node, int[] acc) {
        if (node == null) {
            return acc;
        }
        acc = append(acc, node.key);
        if (node.left != null) {
            acc = visitPreorder(node.left, acc);
        }
        if (node.right != null) {
            acc = visitPreorder(node.right, acc);
        }
        return acc;
    }

    int[] visitInorder(Node node, int[] acc) {
        if (node == null) {
            return acc;
        }
        if (node.left != null) {
            acc = visitInorder(node.left, acc);
        }
        acc = append(acc, node.key);
        if (node.right != null) {
            acc = visitInorder(node.right, acc);
        }
        return acc;
    }

    int[] append(int[] arr, int val) {
        int[] newArr = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            newArr[i] = arr[i];
        }
        newArr[arr.length] = val;
        return newArr;
    }

    String[] isToAs(int[] is) {
        int n = is.length;
        String[] as = new String[n];
        for (int i = 0; i < n; i++) {
            as[i] = String.valueOf(is[i]);
        }
        return as;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Tree tree = new Tree();
        for (int i = 0; i < n; i++) {
            String command = sc.next();
            switch (command) {
                case "insert":
                    int key = sc.nextInt();
                    tree.insert(key);
                    break;
                case "print":
                    tree.print();
                    break;
                default:
                    throw new IllegalArgumentException("unknown command: " + command);
            }
        }
    }
}

