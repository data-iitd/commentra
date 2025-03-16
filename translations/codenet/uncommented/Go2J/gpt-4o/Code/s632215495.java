import java.util.ArrayList;
import java.util.List;
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
            System.out.println(" " + String.join(" ", isToAs(visitInorder(root, new ArrayList<>()))));
            System.out.println(" " + String.join(" ", isToAs(visitPreorder(root, new ArrayList<>()))));
        }
    }

    List<Integer> visitPreorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc;
        }
        acc.add(node.key);
        visitPreorder(node.left, acc);
        visitPreorder(node.right, acc);
        return acc;
    }

    List<Integer> visitInorder(Node node, List<Integer> acc) {
        if (node == null) {
            return acc;
        }
        visitInorder(node.left, acc);
        acc.add(node.key);
        visitInorder(node.right, acc);
        return acc;
    }

    List<String> isToAs(List<Integer> is) {
        List<String> as = new ArrayList<>();
        for (Integer i : is) {
            as.add(String.valueOf(i));
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
        sc.close();
    }
}

// <END-OF-CODE>
