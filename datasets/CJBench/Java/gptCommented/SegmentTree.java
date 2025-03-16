import java.util.Scanner;

public class Main {
    // Segment tree array to store the sums
    private int[] segTree;
    // Number of elements in the input array
    private int n;
    // Original input array
    private int[] arr;

    // Constructor to initialize the segment tree
    public Main(int n, int[] arr) {
        this.n = n;
        // Calculate the height of the segment tree
        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
        // Maximum size of the segment tree
        int segSize = 2 * (int) Math.pow(2, x) - 1;
        this.segTree = new int[segSize];
        this.arr = arr;
        // Construct the segment tree from the input array
        constructTree(arr, 0, n - 1, 0);
    }

    // Recursive function to construct the segment tree
    private int constructTree(int[] arr, int start, int end, int index) {
        // If the range represents a single element, store it in the segment tree
        if (start == end) {
            this.segTree[index] = arr[start];
            return arr[start];
        }
        // Calculate the mid-point of the current range
        int mid = start + (end - start) / 2;
        // Recursively construct the left and right subtrees and store their sums
        this.segTree[index] = constructTree(arr, start, mid, index * 2 + 1) +
                constructTree(arr, mid + 1, end, index * 2 + 2);
        return this.segTree[index];
    }

    // Recursive function to update the segment tree when an element is changed
    private void updateTree(int start, int end, int index, int diff, int segIndex) {
        // If the index to update is outside the current range, return
        if (index < start || index > end) {
            return;
        }
        // Update the current segment tree node
        this.segTree[segIndex] += diff;
        // If the range has more than one element, continue updating the children
        if (start != end) {
            int mid = start + (end - start) / 2;
            updateTree(start, mid, index, diff, segIndex * 2 + 1);
            updateTree(mid + 1, end, index, diff, segIndex * 2 + 2);
        }
    }

    // Public method to update the value at a specific index
    public void update(int index, int value) {
        // Check for valid index
        if (index < 0 || index >= n) {
            return;
        }
        // Calculate the difference between the new and old value
        int diff = value - arr[index];
        // Update the original array
        arr[index] = value;
        // Update the segment tree with the difference
        updateTree(0, n - 1, index, diff, 0);
    }

    // Recursive function to get the sum of a given range
    private int getSumTree(int start, int end, int qStart, int qEnd, int segIndex) {
        // If the current range is completely within the query range, return the sum
        if (qStart <= start && qEnd >= end) {
            return this.segTree[segIndex];
        }
        // If the current range is completely outside the query range, return 0
        if (qStart > end || qEnd < start) {
            return 0;
        }
        // Calculate the mid-point of the current range
        int mid = start + (end - start) / 2;
        // Return the sum of the left and right children
        return (getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) +
                getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2));
    }

    // Public method to get the sum of elements in a given range
    public int getSum(int start, int end) {
        // Check for valid range
        if (start < 0 || end >= n || start > end) {
            return 0;
        }
        // Call the recursive function to get the sum
        return getSumTree(0, n - 1, start, end, 0);
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements
        int n = scanner.nextInt();
        int[] arr = new int[n];
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        // Initialize the segment tree with the input array
        Main segmentTree = new Main(n, arr);
        // Read the number of queries
        int q = scanner.nextInt();
        // Process each query
        for (int i = 0; i < q; i++) {
            int choice = scanner.nextInt();
            if (choice == 1) {
                // Query for the sum of a range
                int start = scanner.nextInt();
                int end = scanner.nextInt();
                System.out.println("Sum of range [" + start + ", " + end + "] is: " + segmentTree.getSum(start, end));
            } else if (choice == 2) {
                // Update the value at a specific index
                int index = scanner.nextInt();
                int value = scanner.nextInt();
                segmentTree.update(index, value);
                System.out.println("Value updated.");
            } else {
                // Handle invalid operation
                System.out.println("Invalid operation.");
            }
        }
        // Close the scanner
        scanner.close();
    }
}
