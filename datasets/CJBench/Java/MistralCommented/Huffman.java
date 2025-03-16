
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Scanner;

// Class representing a node in the Huffman tree
class MainNode {
    char c; // Character represented by the node
    int data; // Frequency of the character
    MainNode left; // Left child node
    MainNode right; // Right child node

    // Constructor for a leaf node (character without frequency)
    MainNode(char c) {
        this.c = c;
        this.data = 0;
        this.left = null;
        this.right = null;
    }

    // Constructor for an internal node
    MainNode(char c, int data) {
        this.c = c;
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// Comparator class for sorting nodes based on their frequencies
class MyComparator implements Comparator<MainNode> {
    @Override
    public int compare(MainNode x, MainNode y) {
        // Compare nodes based on their frequencies
        return x.data - y.data;
    }
}

// Main class
public final class Main {
    private Main() {
    }

    // Function to print Huffman codes for each character
    public static void printCode(MainNode root, String s) {
        // Base case: if the node is a leaf node, print the character and its code
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ": " + s);
            return;
        }

        // Recursive case: print codes for left and right subtrees and append appropriate bit
        printCode(root.left, s + "0");
        printCode(root.right, s + "1");
    }

    public static void main(String[] args) {
        // Initialize scanner for reading input
        Scanner sc = new Scanner(System.in);

        // Read number of characters and their frequencies from input
        int n = sc.nextInt();
        sc.nextLine();
        char[] charArray = new char[n];
        int[] charfreq = new int[n];
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split(" ");
            charArray[i] = input[0].charAt(0);
            charfreq[i] = Integer.parseInt(input[1]);
        }

        // Create a priority queue to store nodes based on their frequencies
        PriorityQueue<MainNode> q = new PriorityQueue<>(n, new MyComparator());

        // Create nodes for each character and add them to the priority queue
        for (int i = 0; i < n; i++) {
            MainNode hn = new MainNode(charArray[i], charfreq[i]);
            q.add(hn);
        }

        // Build the Huffman tree by merging nodes with the smallest frequencies
        MainNode root = null;
        while (q.size() > 1) {
            MainNode x = q.poll();
            MainNode y = q.poll();

            // Create a new node as the root of the subtree merging x and y
            MainNode f = new MainNode('-', x.data + y.data);
            f.left = x;
            f.right = y;

            // Update the root of the tree
            root = f;

            // Add the new node to the priority queue
            q.add(f);
        }

        // Print Huffman codes for all characters
        printCode(root, "");

        // Close the scanner
        sc.close();
    }
}

