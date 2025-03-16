import java.util.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;

// Class representing a node in the binary tree
class TreeNode {
    int key; // Value of the node
    TreeNode left; // Left child of the node
    TreeNode right; // Right child of the node

    // Constructor to initialize a node with a key
    TreeNode(int key) {
        this.key = key;
        left = null; // Initialize left child as null
        right = null; // Initialize right child as null
    }
}

// Class representing an item in the queue for level order traversal
class QItem {
    TreeNode node; // The tree node
    int hd; // Horizontal distance from the root

    // Constructor to initialize a queue item with a node and its horizontal distance
    QItem(TreeNode n, int h) {
        node = n;
        hd = h;
    }
}

// Class representing the binary tree
class Tree {
    TreeNode root; // Root node of the tree

    // Constructor to initialize the tree with a root node
    Tree(TreeNode n) {
        root = n;
    }

    // Method to print the top view of the binary tree
    public void printTopView() {
        // If the tree is empty, return
        if (root == null) {
            return;
        }

        // Set to keep track of horizontal distances that have been printed
        HashSet<Integer> set = new HashSet<>();
        // Queue for level order traversal
        Queue<QItem> queue = new LinkedList<>();
        // Start with the root node at horizontal distance 0
        queue.add(new QItem(root, 0));

        // Process nodes in the queue until it's empty
        while (!queue.isEmpty()) {
            QItem qi = queue.poll(); // Get the front item from the queue
            int hd = qi.hd; // Get the horizontal distance
            TreeNode n = qi.node; // Get the tree node

            // If this horizontal distance has not been printed yet, print the node's key
            if (!set.contains(hd)) {
                set.add(hd); // Mark this horizontal distance as printed
                System.out.print(n.key + " "); // Print the node's key
            }

            // If there is a left child, add it to the queue with horizontal distance -1
            if (n.left != null) {
                queue.add(new QItem(n.left, hd - 1));
            }
            // If there is a right child, add it to the queue with horizontal distance +1
            if (n.right != null) {
                queue.add(new QItem(n.right, hd + 1));
            }
        }
    }
}

// Main class to execute the program
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Scanner for input
        int n = scanner.nextInt(); // Read the number of nodes

        // Map to store nodes by their keys
        Map<Integer, TreeNode> nodeMap = new HashMap<>();
        
        // Read each node's key and its children
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt(); // Read the node key
            int left = scanner.nextInt(); // Read the left child key
            int right = scanner.nextInt(); // Read the right child key
            
            // Create the current node if it does not exist in the map
            nodeMap.putIfAbsent(key, new TreeNode(key));
            TreeNode currentNode = nodeMap.get(key); // Get the current node
            
            // If there is a left child, create it and link it to the current node
            if (left != -1) {
                nodeMap.putIfAbsent(left, new TreeNode(left));
                currentNode.left = nodeMap.get(left);
            }
            // If there is a right child, create it and link it to the current node
            if (right != -1) {
                nodeMap.putIfAbsent(right, new TreeNode(right));
                currentNode.right = nodeMap.get(right);
            }
        }

        // Read the key of the root node
        int rootKey = scanner.nextInt();
        // Create the tree with the specified root
        Tree t = new Tree(nodeMap.get(rootKey));

        // Print the top view of the binary tree
        System.out.println("Top view of the binary tree:");
        t.printTopView(); // Call the method to print the top view

        scanner.close(); // Close the scanner
    }
}
