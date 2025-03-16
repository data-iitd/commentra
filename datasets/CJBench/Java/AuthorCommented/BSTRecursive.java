
import java.util.Scanner;

/**
 *
 *
 * <h1>Binary Search Tree (Recursive)</h1>
 *
 * An implementation of BST recursively. In recursive implementation the checks
 * are down the tree First root is checked if not found then its children are
 * checked Binary Search Tree is a binary tree which satisfies three properties:
 * left child is less than root node, right child is grater than root node, both
 * left and right children must themselves be a BST.
 *
 * <p>
 * I have made public functions as methods and to actually implement recursive
 * approach I have used private methods
 *
 * @author [Lakhan Nad](<a href="https://github.com/Lakhan-Nad">git-Lakhan Nad</a>)
 */
public class BSTRecursive {

    /**
     * Represents a node in the binary search tree.
     */
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

    /**
     * Recursive insertion of value in BST.
     *
     * @param node to check if the data can be inserted in current node or its
     * subtree
     * @param data the value to be inserted
     * @return the modified value of the root parameter after insertion
     */
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

    /**
     * add in BST. if the value is not already present it is inserted or else no
     * change takes place.
     *
     * @param data the value to be inserted
     */
    public void add(int data) {
        root = insert(root, data);
    }

    /**
     * Recursive method to delete a data if present in BST.
     *
     * @param node the current node to search for data
     * @param data the value to be deleted
     * @return Node the updated value of root parameter after delete operation
     */
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
            // Node to delete found
            if (node.left == null && node.right == null) { // Leaf node
                return null;
            } else if (node.left == null) { // Only right child
                return node.right;
            } else if (node.right == null) { // Only left child
                return node.left;
            } else { // Both children
                Node temp = findMin(node.right);
                node.data = temp.data;
                node.right = delete(node.right, temp.data);
            }
        }
        return node;
    }

    /**
     * If data is present in BST delete it else do nothing.
     *
     * @param data the value to be removed
     */
    public void remove(int data) {
        root = delete(root, data);
    }

    private Node findMin(Node node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    /**
     * Search recursively if the given value is present in BST or not.
     *
     * @param node the current node to check
     * @param data the value to be checked
     * @return boolean if data is present or not
     */
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

    /**
     * To check if given value is present in tree or not.
     *
     * @param data the data to be found for
     */
    public boolean find(int data) {
        boolean result = search(root, data);
        if (result) {
            System.out.println(data + " is present in the BST.");
        } else {
            System.out.println(data + " is not found.");
        }
        return result;
    }

    // In-order traversal to display the tree
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
                case 1: // Insert
                    int insertValue = scanner.nextInt();
                    bst.add(insertValue);
                    break;

                case 2: // Delete
                    int deleteValue = scanner.nextInt();
                    bst.remove(deleteValue);
                    break;

                case 3: // Search
                    int searchValue = scanner.nextInt();
                    bst.find(searchValue);
                    break;

                case 4: // Display
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
