import java.util.Scanner;
public class Main {
    private Node root; // Root of the AVL tree
    private static class Node { // Inner class representing a node in the AVL tree
        private int key; // The key stored in the node
        private int balance; // Balance factor of the node
        private int height; // Height of the node
        private Node left; // Left child of the node
        private Node right; // Right child of the node
        private Node parent; // Parent node of the node
        Node(int k, Node p) { // Constructor to initialize the node
            key = k;
            parent = p;
        }
    }
    public boolean insert(int key) { // Inserts a new key into the AVL tree
        if (root == null) { // If the tree is empty, create a new root node
            root = new Node(key, null);
        } else { // Otherwise, traverse the tree to find the correct position
            Node n = root;
            Node parent;
            while (true) {
                if (n.key == key) { // If the key already exists, return false
                    return false;
                }
                parent = n;
                boolean goLeft = n.key > key; // Determine whether to go left or right
                n = goLeft ? n.left : n.right;
                if (n == null) { // If the correct position is found, insert the new node
                    if (goLeft) {
                        parent.left = new Node(key, parent);
                    } else {
                        parent.right = new Node(key, parent);
                    }
                    rebalance(parent); // Rebalance the tree if necessary
                    break;
                }
            }
        }
        return true; // Return true if the insertion is successful
    }
    public void delete(int delKey) { // Deletes a node with the specified key from the AVL tree
        if (root == null) { // If the tree is empty, return
            return;
        }
        Node node = root;
        Node child = root;
        while (child != null) { // Traverse the tree to find the node to delete
            node = child;
            child = delKey >= node.key ? node.right : node.left;
            if (delKey == node.key) { // If the node is found, delete it
                deleteNode(node);
                return;
            }
        }
    }
    private void deleteNode(Node node) { // Deletes the specified node from the AVL tree
        if (node.left == null && node.right == null) { // Case 1: node has no children
            if (node.parent == null) { // If the node is the root, set the root to null
                root = null;
            } else { // Otherwise, set the parent's child to null
                Node parent = node.parent;
                if (parent.left == node) {
                    parent.left = null;
                } else {
                    parent.right = null;
                }
                rebalance(parent); // Rebalance the tree if necessary
            }
            return;
        }
        Node child;
        if (node.left != null) { // Case 2: node has one child (left)
            child = node.left;
            while (child.right != null) { // Find the rightmost child of the left subtree
                child = child.right;
            }
        } else { // Case 3: node has one child (right)
            child = node.right;
            while (child.left != null) { // Find the leftmost child of the right subtree
                child = child.left;
            }
        }
        node.key = child.key; // Replace the node's key with the child's key
        deleteNode(child); // Delete the child node
    }
    public boolean search(int key) { // Searches for a node with the specified key in the AVL tree
        Node result = searchHelper(this.root, key);
        return result != null; // Return true if the node is found, otherwise false
    }
    private Node searchHelper(Node root, int key) { // Helper method for searching
        if (root == null || root.key == key) { // If the root is null or the key matches, return the root
            return root;
        }
        return key < root.key ? searchHelper(root.left, key) : searchHelper(root.right, key); // Traverse the tree recursively
    }
    public void display() { // Displays the keys of the nodes in the AVL tree in an in-order traversal
        displayHelper(this.root);
        System.out.println();
    }
    private void displayHelper(Node node) { // Helper method for displaying the tree
        if (node != null) {
            displayHelper(node.left); // Traverse the left subtree
            System.out.print(node.key + " "); // Print the current node's key
            displayHelper(node.right); // Traverse the right subtree
        }
    }
    private void rebalance(Node n) { // Rebalances the AVL tree after insertion or deletion
        setBalance(n);
        if (n.balance == -2) { // If the balance factor is -2, perform a right rotation or a left-then-right rotation
            if (height(n.left.left) >= height(n.left.right)) {
                n = rotateRight(n);
            } else {
                n = rotateLeftThenRight(n);
            }
        } else if (n.balance == 2) { // If the balance factor is 2, perform a left rotation or a right-then-left rotation
            if (height(n.right.right) >= height(n.right.left)) {
                n = rotateLeft(n);
            } else {
                n = rotateRightThenLeft(n);
            }
        }
        if (n.parent != null) { // Recursively rebalance the parent node
            rebalance(n.parent);
        } else { // If the node is the root, set it as the new root
            root = n;
        }
    }
    private Node rotateLeft(Node a) { // Performs a left rotation
        Node b = a.right;
        b.parent = a.parent;
        a.right = b.left;
        if (a.right != null) {
            a.right.parent = a;
        }
        b.left = a;
        a.parent = b;
        setBalance(a, b);
        return b;
    }
    private Node rotateRight(Node a) { // Performs a right rotation
        Node b = a.left;
        b.parent = a.parent;
        a.left = b.right;
        if (a.left != null) {
            a.left.parent = a;
        }
        b.right = a;
        a.parent = b;
        setBalance(a, b);
        return b;
    }
    private Node rotateLeftThenRight(Node n) { // Performs a left-then-right rotation
        n.left = rotateLeft(n.left);
        return rotateRight(n);
    }
    private Node rotateRightThenLeft(Node n) { // Performs a right-then-left rotation
        n.right = rotateRight(n.right);
        return rotateLeft(n);
    }
    private int height(Node n) { // Returns the height of the node
        return n == null ? -1 : n.height;
    }
    private void setBalance(Node... nodes) { // Sets the balance factor of the nodes
        for (Node n : nodes) {
            reheight(n);
            n.balance = height(n.right) - height(n.left);
        }
    }
    private void reheight(Node node) { // Sets the height of the node
        if (node != null) {
            node.height = 1 + Math.max(height(node.left), height(node.right));
        }
    }
    public static void main(String[] args) { // Main method to provide a simple command-line interface
        Main tree = new Main();
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine().trim();
            if (command.equalsIgnoreCase("exit")) {
                break;
            }
            String[] parts = command.split(" ");
            try {
                switch (parts[0]) {
                    case "insert":
                        int valueToInsert = Integer.parseInt(parts[1]);
                        tree.insert(valueToInsert);
                        System.out.println("Inserted: " + valueToInsert);
                        break;
                    case "delete":
                        int valueToDelete = Integer.parseInt(parts[1]);
                        tree.delete(valueToDelete);
                        System.out.println("Deleted: " + valueToDelete);
                        break;
                    case "search":
                        int valueToSearch = Integer.parseInt(parts[1]);
                        System.out.println(tree.search(valueToSearch) ? "Found" : "Not Found");
                        break;
                    case "display":
                        tree.display();
                        break;
                    default:
                        System.out.println("Unknown command");
                }
            } catch (Exception e) {
                System.out.println("Invalid command or input");
            }
        }
        scanner.close();
    }
}
