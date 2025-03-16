import java.util.*;

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
            return;
        }

        List<Integer> acc = new ArrayList<>();

        System.out.print("Inorder traversal: ");
        inorderTraversal(root, acc);
        System.out.println(String.join(" ", acc.stream().map(String::valueOf).collect(Collectors.toList())));

        acc.clear();
        System.out.print("Preorder traversal: ");
        preorderTraversal(root, acc);
        System.out.println(String.join(" ", acc.stream().map(String::valueOf).collect(Collectors.toList())));
    }

    private void inorderTraversal(Node node, List<Integer> acc) {
        if (node == null) {
            return;
        }

        inorderTraversal(node.left, acc);
        acc.add(node.key);
        inorderTraversal(node.right, acc);
    }

    private void preorderTraversal(Node node, List<Integer> acc) {
        if (node == null) {
            return;
        }

        acc.add(node.key);
        preorderTraversal(node.left, acc);
        preorderTraversal(node.right, acc);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        Tree tree = new Tree();

        for (int i = 0; i < n; i++) {
            String[] commandParts = scanner.nextLine().split(" ");
            String command = commandParts[0];

            switch (command) {
                case "insert":
                    int key = Integer.parseInt(commandParts[1]);
                    tree.insert(key);
                    break;
                case "print":
                    tree.print();
                    break;
                default:
                    throw new IllegalArgumentException("Unknown command: " + command);
            }
        }
    }
}
