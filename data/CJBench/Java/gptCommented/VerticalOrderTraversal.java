import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

// Class representing a binary tree
class BinaryTree {
    // Inner class representing a node in the binary tree
    static class Node {
        int data; // Value of the node
        Node left, right; // Pointers to left and right children

        // Constructor to initialize the node with data
        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
}

public class Main {
    // Method to perform vertical traversal of the binary tree
    public static ArrayList<Integer> verticalTraversal(BinaryTree.Node root) {
        // If the root is null, return an empty list
        if (root == null) {
            return new ArrayList<>();
        }

        // Queues to hold nodes and their corresponding vertical indices
        Queue<BinaryTree.Node> queue = new LinkedList<>();
        Queue<Integer> index = new LinkedList<>();
        
        // Map to hold lists of node values at each vertical index
        Map<Integer, ArrayList<Integer>> map = new HashMap<>();
        
        // Variables to track the maximum and minimum vertical indices
        int max = 0, min = 0;

        // Start with the root node at index 0
        queue.offer(root);
        index.offer(0);

        // Perform a level-order traversal of the tree
        while (!queue.isEmpty()) {
            BinaryTree.Node node = queue.poll(); // Get the current node
            int idx = index.poll(); // Get the corresponding index

            // Add the node's value to the list for the current index
            map.putIfAbsent(idx, new ArrayList<>());
            map.get(idx).add(node.data);

            // Update the maximum and minimum indices
            max = Math.max(max, idx);
            min = Math.min(min, idx);

            // Add left child to the queue with index decremented by 1
            if (node.left != null) {
                queue.offer(node.left);
                index.offer(idx - 1);
            }
            // Add right child to the queue with index incremented by 1
            if (node.right != null) {
                queue.offer(node.right);
                index.offer(idx + 1);
            }
        }

        // Prepare the result list for vertical traversal output
        ArrayList<Integer> result = new ArrayList<>();
        // Collect values from the map in order of vertical indices
        for (int i = min; i <= max; i++) {
            result.addAll(map.get(i));
        }
        return result; // Return the final result list
    }

    public static void main(String[] args) {
        // Create a scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes in the binary tree
        int n = scanner.nextInt();
        
        // Array to hold references to the nodes
        BinaryTree.Node[] nodes = new BinaryTree.Node[n + 1];
        
        // Initialize nodes with their respective values
        for (int i = 1; i <= n; i++) {
            nodes[i] = new BinaryTree.Node(i);
        }
        
        // Read the edges and construct the binary tree
        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt(); // Parent node value
            int child = scanner.nextInt(); // Child node value
            String direction = scanner.next(); // Direction (L or R)

            // Link the child to the parent based on the direction
            if (direction.equals("L")) {
                nodes[parent].left = nodes[child]; // Set left child
            } else if (direction.equals("R")) {
                nodes[parent].right = nodes[child]; // Set right child
            }
        }

        // Perform vertical traversal starting from the root node
        ArrayList<Integer> result = verticalTraversal(nodes[1]);
        
        // Print the result of the vertical traversal
        for (int value : result) {
            System.out.print(value + " ");
        }
        
        // Close the scanner
        scanner.close();
    }
}
