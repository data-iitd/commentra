import java.util.Scanner;

// Class definition for Main with a constructor, instance variables, and methods
public class Main {
    private int[] segTree; // Segment tree array
    private int n; // Size of the array
    private int[] arr; // Input array

    // Constructor for initializing the segment tree
    public Main(int n, int[] arr) {
        this.n = n;
        int x = (int) (Math.ceil(Math.log(n) / Math.log(2))); // Calculate the log base 2 of the array size
        int segSize = 2 * (int) Math.pow(2, x) - 1; // Calculate the size of the segment tree
        this.segTree = new int[segSize]; // Initialize the segment tree array
        this.arr = arr; // Assign the input array
        constructTree(arr, 0, n - 1, 0); // Construct the segment tree
    }

    // Method to construct the segment tree recursively
    private int constructTree(int[] arr, int start, int end, int index) {
        // Base case: leaf node
        if (start == end) {
            this.segTree[index] = arr[start]; // Set the value of the current node to the value of the leaf node
            return arr[start]; // Return the value of the leaf node
        }

        // Recursive case: internal node
        int mid = start + (end - start) / 2; // Calculate the middle index
        this.segTree[index] = constructTree(arr, start, mid, index * 2 + 1) // Construct the left subtree
                + constructTree(arr, mid + 1, end, index * 2 + 2); // Construct the right subtree
        return this.segTree[index]; // Return the sum of the left and right subtrees
    }

    // Method to update a value in the array and the segment tree
    private void updateTree(int start, int end, int index, int diff, int segIndex) {
        // Base case: leaf node
        if (index < start || index > end) {
            return; // Exit the method if the index is out of range
        }

        // Update the value in the array
        arr[index] += diff;

        // Recursive case: internal node
        this.segTree[segIndex] += diff; // Update the value of the current node
        if (start != end) { // If the current node is not a leaf node
            int mid = start + (end - start) / 2;
            updateTree(start, mid, index, diff, segIndex * 2 + 1); // Update the left subtree
            updateTree(mid + 1, end, index, diff, segIndex * 2 + 2); // Update the right subtree
        }
    }

    // Method to update a value in the array
    public void update(int index, int value) {
        // Check if the index is valid
        if (index < 0 || index >= n) {
            return;
        }

        // Update the value in the array and call the updateTree method to update the segment tree
        int diff = value - arr[index];
        arr[index] = value;
        updateTree(0, n - 1, index, diff, 0);
    }

    // Method to calculate the sum of a range in the segment tree
    private int getSumTree(int start, int end, int qStart, int qEnd, int segIndex) {
        // Base case: leaf node
        if (qStart <= start && qEnd >= end) {
            return this.segTree[segIndex]; // Return the sum of the current node
        }

        // Recursive case: internal node
        int mid = start + (end - start) / 2;
        return (getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) // Sum of the left subtree
                + getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2)); // Sum of the right subtree
    }

    // Method to calculate the sum of a range in the array
    public int getSum(int start, int end) {
        // Check if the start and end indices are valid
        if (start < 0 || end >= n || start > end) {
            return 0;
        }

        // Calculate the sum of the range in the segment tree
        return getSumTree(0, n - 1, start, end, 0);
    }

    // Main method for reading input and calling the methods
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize the scanner for reading input

        // Read the size of the array and initialize the array
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt(); // Read each element of the array
        }

        // Create an instance of the Main class and pass the array as an argument
        Main segmentTree = new Main(n, arr);

        // Read the number of queries and call the appropriate methods for each query
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int choice = scanner.nextInt(); // Read the type of query (1 for sum, 2 for update)
            if (choice == 1) { // Sum query
                int start = scanner.nextInt();
                int end = scanner.nextInt();
                System.out.println("Sum of range [" + start + ", " + end + "] is: " + segmentTree.getSum(start, end));
            } else if (choice == 2) { // Update query
                int index = scanner.nextInt();
                int value = scanner.nextInt();
                segmentTree.update(index, value);
                System.out.println("Value updated.");
            } else { // Invalid query
                System.out.println("Invalid operation.");
            }
        }

        scanner.close(); // Close the scanner
    }
}
