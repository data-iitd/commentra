
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Declare a constant for the In-Order tree traversal
    public static final TreeTraversal IN_ORDER = new InOrderTraversal();

    // Initialize the root node to null
    private Node root;

    // Check if the tree is empty
    public boolean isEmpty() {
        return root == null;
    }

    // Insert a new node into the tree
    public void insert(final int key) {
        root = insertRec(root, key); // Recursively insert the new node
        root = splay(root, key); // Splay the tree to maintain balance
    }

    // Search for a node with the given key
    public boolean search(int key) {
        root = splay(root, key); // Splay the tree to bring the searched node to the root
        return root != null && root.key == key;
    }

    // Delete a node with the given key
    public void delete(final int key) {
        if (isEmpty()) {
            throw new EmptyTreeException("Cannot delete from an empty tree");
        }
        root = splay(root, key); // Splay the tree to bring the node to be deleted to the root

        // Check if the root node matches the key
        if (root.key != key) {
            return;
        }

        // If the root node has no children, simply set the root to null
        if (root.left == null) {
            root = root.right;
        } else {
            // If the root node has a left child, find the maximum value in the left subtree
            Node temp = root;
            root = splay(root.left, findMax(root.left).key);

            // Replace the root's right pointer with the deleted node's right pointer
            root.right = temp.right;
        }
    }

    // Traverse the tree using a given traversal method
    public List<Integer> traverse(TreeTraversal traversal) {
        List<Integer> result = new ArrayList<>();
        traversal.traverse(root, result); // Traverse the tree recursively
        return result;
    }

    // Find the node with the maximum key in the left subtree
    private Node findMax(Node root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }

    // Rotate the tree right around the given node
    private Node rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        return y;
    }

    // Rotate the tree left around the given node
    private Node rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        return y;
    }

    // Splay the tree to bring the node with the given key to the root
    private Node splay(Node root, final int key) {
        if (root == null || root.key == key) {
            return root;
        }

        // Determine which subtree the node to be splayed is in
        if (root.key > key) {
            if (root.left == null) {
                return root;
            }

            // Perform left rotations until the node to be splayed is in the left subtree
            if (root.left.key > key) {
                root.left = splay(root.left, key);
                root = rotateRight(root);
            } else if (root.left.key < key) {
                root.left.right = splay(root.left.right, key);

                // If the right subtree of the left child is not empty, perform a left rotation
                if (root.left.right != null) {
                    root.left = rotateLeft(root.left);
                }
            }

            // Perform a right rotation to bring the node to the root
            return (root.left == null) ? root : rotateRight(root);
        } else {
            // Similar logic for the right subtree
            if (root.right == null) {
                return root;
            }

            if (root.right.key > key) {
                root.right = splay(root.right, key);
                root = rotateLeft(root);
            } else if (root.right.key < key) {
                root.right.left = splay(root.right.left, key);
                root = rotateRight(root);
            }

            return (root.right == null) ? root : rotateLeft(root);
        }
    }

    // Recursively insert a new node into the tree
    private Node insertRec(Node root, final int key) {
        if (root == null) {
            return new Node(key);
        }

        if (key < root.key) {
            root.left = insertRec(root.left, key);
        } else if (key > root.key) {
            root.right = insertRec(root.right, key);
        } else {
            throw new DuplicateKeyException("Duplicate key: " + key);
        }

        return root;
    }

    // Main method to read user input and perform tree operations
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main splayTree = new Main();
        int n = scanner.nextInt();

        // Initialize the splay tree object
        for (int i = 0; i < n; i++) {
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    int valueToInsert = scanner.nextInt();
                    splayTree.insert(valueToInsert);
                    System.out.println("Inserted " + valueToInsert);
                    break;
                case 2:
                    int valueToDelete = scanner.nextInt();
                    try {
                        splayTree.delete(valueToDelete);
                        System.out.println("Deleted " + valueToDelete);
                    } catch (EmptyTreeException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3:
                    int valueToSearch = scanner.nextInt();
                    boolean found = splayTree.search(valueToSearch);
                    System.out.println(found ? "Found " + valueToSearch : "Not found");
                    break;
                case 4:
                    System.out.println("In-order traversal:");
                    System.out.println(splayTree.traverse(IN_ORDER));
                    break;
                default:
                    System.out.println("Invalid operation.");
            }
        }

        scanner.close();
    }

    // Define a private static class for the Node
    private static class Node {
        final int key;
        Node left;
        Node right;

        Node(int key) {
            this.key = key;
            left = null;
            right = null;
        }
    }

    // Define custom exceptions for empty tree and duplicate keys
    public static class EmptyTreeException extends RuntimeException {
        public EmptyTreeException(String message) {
            super(message);
        }
    }

    public static class DuplicateKeyException extends RuntimeException {
        public DuplicateKeyException(String message) {
            super(message);
        }
    }

    // Define the TreeTraversal interface
    public interface TreeTraversal {
        void traverse(Node root, List<Integer> result);
    }

    // Implement the InOrderTraversal class that implements the TreeTraversal interface
    private static final class InOrderTraversal implements TreeTraversal {
        public void traverse(Node root, List<Integer> result) {
            if (root != null) {
                traverse(root.left, result);
                result.add(root.key);
                traverse(root.right, result);
            }
        }
    }
}