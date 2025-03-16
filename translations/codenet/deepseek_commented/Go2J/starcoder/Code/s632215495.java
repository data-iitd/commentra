package main;

import java.util.Scanner;

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
                    throw new RuntimeException("unknown command: " + command);
            }
        }
    }
}

class Tree {
    private Node root;

    public Tree() {
    }

    public void insert(int key) {
        if (root == null) {
            root = new Node(key);
            return;
        }

        Node currentNode = root;
        while (currentNode!= null) {
            if (currentNode.key < key) {
                if (currentNode.right == null) {
                    currentNode.right = new Node(key);
                    currentNode.right.parent = currentNode;
                    return;
                }
                currentNode = currentNode.right;
            } else {
                if (currentNode.left == null) {
                    currentNode.left = new Node(key);
                    currentNode.left.parent = currentNode;
                    return;
                }
                currentNode = currentNode.left;
            }
        }
    }

    public void print() {
        if (root == null) {
            System.out.println("");
            System.out.println("");
        } else {
            System.out.println(" " + isToAs(visitInorder(root, new int[0])));
            System.out.println(" " + isToAs(visitPreorder(root, new int[0])));
        }
    }

    private int[] visitPreorder(Node node, int[] acc) {
        if (node == null) {
            return acc;
        }
        acc = append(acc, node.key);
        if (node.left!= null) {
            acc = visitPreorder(node.left, acc);
        }
        if (node.right!= null) {
            acc = visitPreorder(node.right, acc);
        }
        return acc;
    }

    private int[] visitInorder(Node node, int[] acc) {
        if (node == null) {
            return acc;
        }
        if (node.left!= null) {
            acc = visitInorder(node.left, acc);
        }
        acc = append(acc, node.key);
        if (node.right!= null) {
            acc = visitInorder(node.right, acc);
        }
        return acc;
    }

    private String isToAs(int[] is) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < is.length; i++) {
            if (i > 0) {
                sb.append(" ");
            }
            sb.append(is[i]);
        }
        return sb.toString();
    }
}

class Node {
    int key;
    Node parent;
    Node left;
    Node right;

    public Node(int key) {
        this.key = key;
    }
}

