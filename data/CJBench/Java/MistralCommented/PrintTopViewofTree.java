
import java.util.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;

// Create a TreeNode class with key, left and right references
class TreeNode {
    int key;
    TreeNode left;
    TreeNode right;

    // Constructor for TreeNode with key and null left and right references
    TreeNode(int key) {
        this.key = key;
        left = null;
        right = null;
    }
}

// Create a QItem class with node and horizontal distance references
class QItem {
    TreeNode node;
    int hd;

    // Constructor for QItem with node and horizontal distance
    QItem(TreeNode n, int h) {
        node = n;
        hd = h;
    }
}

// Create a Tree class with root reference
class Tree {
    TreeNode root;

    // Constructor for Tree with root reference
    Tree(TreeNode n) {
        root = n;
    }

    // Method to print the top view of the binary tree
    public void printTopView() {
        if (root == null) { // Check if the root is null, if yes then return
            return;
        }

        // Create an empty HashSet and LinkedList
        HashSet<Integer> set = new HashSet<>();
        Queue<QItem> queue = new LinkedList<>();

        // Add root node to the queue with horizontal distance 0
        queue.add(new QItem(root, 0));

        // Traverse the tree level by level and print the nodes at the same horizontal distance
        while (!queue.isEmpty()) {
            QItem qi = queue.poll(); // Dequeue a QItem from the queue
            int hd = qi.hd; // Get the horizontal distance of the current node
            TreeNode n = qi.node; // Get the current node

            // If the node is not already present in the HashSet, print its key and add it to the HashSet
            if (!set.contains(hd)) {
                set.add(hd);
                System.out.print(n.key + " ");
            }

            // If the left child of the current node is not null, add it to the queue with horizontal distance decreased by 1
            if (n.left != null) {
                queue.add(new QItem(n.left, hd - 1));
            }

            // If the right child of the current node is not null, add it to the queue with horizontal distance increased by 1
            if (n.right != null) {
                queue.add(new QItem(n.right, hd + 1));
            }
        }
    }
}

// Main class to read input and call the printTopView method
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input

        // Read the number of nodes in the binary tree
        int n = scanner.nextInt();

        // Create a HashMap to store TreeNodes with their keys as keys
        Map<Integer, TreeNode> nodeMap = new HashMap<>();

        // Read the nodes of the binary tree and create TreeNodes, add them to the HashMap and link them together
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt();
            int left = scanner.nextInt();
            int right = scanner.nextInt();

            // Create a new TreeNode with the given key and add it to the HashMap with the key as its key
            nodeMap.putIfAbsent(key, new TreeNode(key));
            TreeNode currentNode = nodeMap.get(key);

            // If the left child is not null, create a new TreeNode with the given left key and add it to the HashMap, then link the current node with its left child
            if (left != -1) {
                nodeMap.putIfAbsent(left, new TreeNode(left));
                currentNode.left = nodeMap.get(left);
            }

            // If the right child is not null, create a new TreeNode with the given right key and add it to the HashMap, then link the current node with its right child
            if (right != -1) {
                nodeMap.putIfAbsent(right, new TreeNode(right));
                currentNode.right = nodeMap.get(right);
            }
        }

        // Read the root key and create a Tree object with the root node
        int rootKey = scanner.nextInt();
        Tree t = new Tree(nodeMap.get(rootKey));

        // Call the printTopView method of the Tree object to print the top view of the binary tree
        t.printTopView();

        // Close the Scanner object
        scanner.close();
    }
}