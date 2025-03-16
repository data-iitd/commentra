import java.util.Scanner;

public class LinearSearch {

    // Function to perform linear search on an array
    public static int linearSearch(int[] S, int n, int key) {
        int i = 0; // Initialize index for searching
        int count = 0; // Initialize count to track if the key is found

        // Loop until the key is found or the end of the array is reached
        while (i < n && S[i] != key) {
            i++; // Move to the next index
        }
        // If the index exceeds the size of the array, the key is not found
        if (i >= n) {
            count = 1; // Set count to indicate the key was not found
        }
        return count; // Return count (0 if key is found)
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, q, count = 0; // Initialize count for missing keys
        int[] S = new int[10000]; // Declare array S
        int[] T = new int[10000]; // Declare array T

        // Read the number of elements in the first array
        n = scanner.nextInt();
        // Read the elements into the first array S
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }

        // Read the number of queries
        q = scanner.nextInt();
        // Read the elements into the second array T (the keys to search for)
        for (int j = 0; j < q; j++) {
            T[j] = scanner.nextInt();
        }

        // Loop through each key in T to check if it exists in S
        for (int j = 0; j < q; j++) {
            int key = T[j]; // Get the current key to search
            // If the key is not found in S, increment the count
            if (linearSearch(S, n, key) == 0) {
                count++; // Increment count for each missing key
            }
        }

        // Print the total count of keys that were not found in S
        System.out.println(count);
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
