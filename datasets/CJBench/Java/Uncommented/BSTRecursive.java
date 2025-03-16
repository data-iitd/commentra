
import java.util.Scanner;
public class BSTRecursive {
    static class Node {
        int data;
        Node left;
        Node right;
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    private Node root;
    public BSTRecursive() {
        root = null;
    }
    public Node getRoot() {
        return root;
    }
    private Node insert(Node node, int data) {
        if (node == null) {
            node = new Node(data);
        } else if (data < node.data) {
            node.left = insert(node.left, data);
        } else if (data > node.data) {
            node.right = insert(node.right, data);
        }
        return node;
    }
    public void add(int data) {
        root = insert(root, data);
    }
    private Node delete(Node node, int data) {
        if (node == null) {
            System.out.println("No such data present in BST.");
            return null;
        }
        if (data < node.data) {
            node.left = delete(node.left, data);
        } else if (data > node.data) {
            node.right = delete(node.right, data);
        } else {
            if (node.left == null && node.right == null) { 
                return null;
            } else if (node.left == null) { 
                return node.right;
            } else if (node.right == null) { 
                return node.left;
            } else { 
                Node temp = findMin(node.right);
                node.data = temp.data;
                node.right = delete(node.right, temp.data);
            }
        }
        return node;
    }
    public void remove(int data) {
        root = delete(root, data);
    }
    private Node findMin(Node node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }
    private boolean search(Node node, int data) {
        if (node == null) {
            return false;
        }
        if (data < node.data) {
            return search(node.left, data);
        } else if (data > node.data) {
            return search(node.right, data);
        } else {
            return true;
        }
    }
    public boolean find(int data) {
        boolean result = search(root, data);
        if (result) {
            System.out.println(data + " is present in the BST.");
        } else {
            System.out.println(data + " is not found.");
        }
        return result;
    }
    public void inOrderTraversal(Node node) {
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(node.data + " ");
            inOrderTraversal(node.right);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BSTRecursive bst = new BSTRecursive();
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: 
                    int insertValue = scanner.nextInt();
                    bst.add(insertValue);
                    break;
                case 2: 
                    int deleteValue = scanner.nextInt();
                    bst.remove(deleteValue);
                    break;
                case 3: 
                    int searchValue = scanner.nextInt();
                    bst.find(searchValue);
                    break;
                case 4: 
                    System.out.println("In-order Traversal of BST:");
                    bst.inOrderTraversal(bst.getRoot());
                    System.out.println();
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
        scanner.close();
    }
}
