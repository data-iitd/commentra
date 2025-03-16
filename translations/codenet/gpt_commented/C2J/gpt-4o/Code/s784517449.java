import java.util.Scanner;

public class BinarySearchExample {
    static int[] A = new int[1000000]; // Declare an array A to hold up to 1,000,000 integers
    static int n; // Variable for the number of elements

    /* 二分探索 (Binary Search) */
    static int binarySearch(int key) {
        int left = 0; // Initialize the left boundary of the search range
        int right = n; // Initialize the right boundary of the search range

        // Continue searching while the left boundary is less than the right boundary
        while (left < right) {
            int mid = (left + right) / 2; // Calculate the midpoint index
            if (key == A[mid]) return 1; // If the key is found, return 1
            if (key > A[mid]) left = mid + 1; // If the key is greater, search in the right half
            else right = mid; // If the key is smaller, search in the left half
        }
        return 0; // If the key is not found, return 0
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = 0; // Declare a sum counter

        // Read the number of elements in the array
        n = scanner.nextInt();

        // Read the elements into the array A
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Read the number of queries
        int q = scanner.nextInt();

        // Process each query
        for (int i = 0; i < q; i++) {
            int k = scanner.nextInt(); // Read the key to search for
            if (binarySearch(k) == 1) // Perform binary search for the key
                sum++; // Increment the sum if the key is found
        }

        // Output the total number of keys found in the array
        System.out.println(sum);
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
