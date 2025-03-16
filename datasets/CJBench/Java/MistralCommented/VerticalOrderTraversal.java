import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

class BinaryTree {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
}

// Main class for the vertical traversal of a binary tree
public class Main {

    // Function to perform vertical traversal of a binary tree
    public static ArrayList<Integer> verticalTraversal(BinaryTree.Node root) {
        // Base case: if root is null, return an empty list
        if (root == null) {
            return new ArrayList<>();
        }

        // Initialize queues for nodes and their corresponding indices
        Queue<BinaryTree.Node> queue = new LinkedList<>();
        Queue<Integer> index = new LinkedList<>();

        // Initialize a map to store the data at each index
        Map<Integer, ArrayList<Integer>> map = new HashMap<>();

        // Initialize minimum and maximum indices
        int max = 0, min = 0;

        // Enqueue the root node and its index in the queues
        queue.offer(root);
        index.offer(0);

        // BFS traversal using queues
        while (!queue.isEmpty()) {
            // Dequeue a node and its corresponding index
            BinaryTree.Node node = queue.poll();
            int idx = index.poll();

            // Add the node's data to the map at the corresponding index
            map.putIfAbsent(idx, new ArrayList<>());
            map.get(idx).add(node.data);

            // Update the minimum and maximum indices
            max = Math.max(max, idx);
            min = Math.min(min, idx);

            // Enqueue the left and right children and their indices
            if (node.left != null) {
                queue.offer(node.left);
                index.offer(idx - 1);
            }
            if (node.right != null) {
                queue.offer(node.right);
                index.offer(idx + 1);
            }
        }

        // Create an empty result list
        ArrayList<Integer> result = new ArrayList<>();

        // Add all the data from the map to the result list
        for (int i = min; i <= max; i++) {
            result.addAll(map.get(i));
        }

        // Return the result list
        return result;
    }

    // Main method to read input and call the verticalTraversal function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes in the binary tree
        int n = scanner.nextInt();

        // Create an array of nodes for the binary tree
        BinaryTree.Node[] nodes = new BinaryTree.Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new BinaryTree.Node(i);
        }

        // Read the edges and their directions from the input
        for (int i = 0; i < n - 1; i++) {
            int parent = scanner.nextInt();
            int child = scanner.nextInt();
            String direction = scanner.next();

            // Connect the parent and child nodes based on the direction
            if (direction.equals("L")) {
                nodes[parent].left = nodes[child];
            } else if (direction.equals("R")) {
                nodes[parent].right = nodes[child];
            }
        }

        // Call the verticalTraversal function on the root node and print the result
        ArrayList<Integer> result = verticalTraversal(nodes[1]);
        for (int value : result) {
            System.out.print(value + " ");
        }

        // Close the scanner
        scanner.close();
    }
}
