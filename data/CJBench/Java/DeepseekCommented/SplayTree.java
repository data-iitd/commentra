import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Define a constant for in-order traversal
    public static final TreeTraversal IN_ORDER = new InOrderTraversal();
    
    // The root node of the tree
    private Node root;

    // Check if the tree is empty
    public boolean isEmpty() {
        return root == null;
    }

    // Insert a new key into the tree
    public void insert(final int key) {
        root = insertRec(root, key);
        root = splay(root, key); // Splay the tree to place the new node at the root
    }

    // Search for a key in the tree
    public boolean search(int key) {
        root = splay(root, key); // Splay the tree to bring the searched key to the root
        return root != null && root.key == key;
    }

    // Delete a key from the tree
    public void delete(final int key) {
        if (isEmpty()) {
            throw new EmptyTreeException("Cannot delete from an empty tree");
        }
        root = splay(root, key); // Splay the tree to bring the key to the root
        if (root.key != key) {
            return; // Key not found, do nothing
        }
        if (root.left == null) {
            root = root.right; // If no left child, replace root with right child
        } else {
            Node temp = root;
            root = splay(root.left, findMax(root.left).key); // Splay the left subtree to find max and make it new root
            root.right = temp.right; // Attach the right subtree of the original root to the new root
        }
    }

    // Traverse the tree in a specified order
    public List<Integer> traverse(TreeTraversal traversal) {
        List<Integer> result = new ArrayList<>();
        traversal.traverse(root, result);
        return result;
    }

    // Helper method to find the node with the maximum key in the tree
    private Node findMax(Node root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }

    // Helper method to perform a right rotation
    private Node rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        return y;
    }

    // Helper method to perform a left rotation
    private Node rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        return y;
    }

    // Splay the tree to bring a key to the root
    private Node splay(Node root, final int key) {
        if (root == null || root.key == key) {
            return root;
        }
        if (root.key > key) {
            if (root.left == null) {
                return root;
            }
            if (root.left.key > key) {
                root.left.left = splay(root.left.left, key); // Double rotation needed
                root = rotateRight(root);
            } else if (root.left.key < key) {
                root.left.right = splay(root.left.right, key); // Double rotation needed
                if (root.left.right != null) {
                    root.left = rotateLeft(root.left);
                }
            }
            return (root.left == null) ? root : rotateRight(root);
        } else {
            if (root.right == null) {
                return root;
            }
            if (root.right.key > key) {
                root.right.left = splay(root.right.left, key); // Double rotation needed
                if (root.right.left != null) {
                    root.right = rotateRight(root.right);
                }
            } else if (root.right.key < key) {
                root.right.right = splay(root.right.right, key); // Double rotation needed
                root = rotateLeft(root);
            }
            return (root.right == null) ? root : rotateLeft(root);
        }
    }

    // Recursive method to insert a new key into the tree
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

    // Main method to run the application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Main splayTree = new Main();
        int n = scanner.nextInt();
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

    // Inner class representing a node in the tree
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

    // Custom exception for empty tree
    public static class EmptyTreeException extends RuntimeException {
        public EmptyTreeException(String message) {
            super(message);
        }
    }

    // Custom exception for duplicate keys
    public static class DuplicateKeyException extends RuntimeException {
        public DuplicateKeyException(String message) {
            super(message);
        }
    }

    // Interface for tree traversal
    public interface TreeTraversal {
        void traverse(Node root, List<Integer> result);
    }

    // Concrete implementation of in-order traversal
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
