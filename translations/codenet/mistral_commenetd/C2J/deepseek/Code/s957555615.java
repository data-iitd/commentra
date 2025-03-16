public class AVLTree {
    // Define a node structure for AVL tree
    static class Node {
        Node right; // pointer to the right child
        Node left;  // pointer to the left child
        Node parent; // pointer to the parent node
        int key;    // key value of the node

        Node(int key) {
            this.key = key;
        }
    }

    static Node root; // Initialize root as NULL

    // Function to find the minimum node in the tree
    public static Node treeMinimum(Node x) {
        // Traverse to the left most node
        while (x.left != null) x = x.left;
        // Return the minimum node
        return x;
    }

    // Function to find the maximum node in the tree
    public static Node treeMaximum(Node x) {
        // Traverse to the right most node
        while (x.right != null) x = x.right;
        // Return the maximum node
        return x;
    }

    public static void main(String[] args) {
        // Example usage
        Node node1 = new Node(10);
        Node node2 = new Node(20);
        Node node3 = new Node(30);

        node1.right = node2;
        node2.parent = node1;
        node2.right = node3;
        node3.parent = node2;

        root = node1;

        Node minNode = treeMinimum(root);
        System.out.println("Minimum node key: " + minNode.key);

        Node maxNode = treeMaximum(root);
        System.out.println("Maximum node key: " + maxNode.key);
    }
}
