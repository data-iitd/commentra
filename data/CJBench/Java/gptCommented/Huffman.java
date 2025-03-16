import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Scanner;

// Class representing a node in the Huffman tree
class MainNode {
    int data; // Frequency of the character
    char c;   // Character
    MainNode left;  // Left child
    MainNode right; // Right child
}

// Comparator class to compare MainNode objects based on their frequency
class MyComparator implements Comparator<MainNode> {
    @Override
    public int compare(MainNode x, MainNode y) {
        return x.data - y.data; // Compare based on frequency
    }
}

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Recursive method to print the Huffman codes for each character
    public static void printCode(MainNode root, String s) {
        // Base case: if the node is a leaf node (no children)
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ": " + s); // Print the character and its code
            return;
        }
        // Traverse left and append '0' to the code
        printCode(root.left, s + "0");
        // Traverse right and append '1' to the code
        printCode(root.right, s + "1");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of characters
        int n = sc.nextInt();
        sc.nextLine(); // Consume the newline character
        
        // Arrays to hold characters and their frequencies
        char[] charArray = new char[n];
        int[] charfreq = new int[n];
        
        // Read characters and their frequencies from input
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split(" ");
            charArray[i] = input[0].charAt(0); // Store the character
            charfreq[i] = Integer.parseInt(input[1]); // Store the frequency
        }
        
        // Priority queue to build the Huffman tree
        PriorityQueue<MainNode> q = new PriorityQueue<>(n, new MyComparator());
        
        // Create a leaf node for each character and add it to the priority queue
        for (int i = 0; i < n; i++) {
            MainNode hn = new MainNode();
            hn.c = charArray[i]; // Set character
            hn.data = charfreq[i]; // Set frequency
            hn.left = null; // Initialize left child
            hn.right = null; // Initialize right child
            q.add(hn); // Add node to the priority queue
        }
        
        MainNode root = null; // Root of the Huffman tree
        
        // Build the Huffman tree
        while (q.size() > 1) {
            // Remove the two nodes of lowest frequency
            MainNode x = q.poll();
            MainNode y = q.poll();
            
            // Create a new internal node with these two nodes as children
            MainNode f = new MainNode();
            f.data = x.data + y.data; // Frequency of the new node
            f.c = '-'; // Internal node does not represent a character
            f.left = x; // Set left child
            f.right = y; // Set right child
            
            root = f; // Update the root to the new internal node
            q.add(f); // Add the new node to the priority queue
        }
        
        // Print the Huffman codes for each character
        printCode(root, "");
        sc.close(); // Close the scanner
    }
}
