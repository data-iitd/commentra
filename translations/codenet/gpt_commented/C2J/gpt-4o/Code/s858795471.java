import java.util.Scanner;

public class Main {
    // Function to search for a key in the array A of size n
    public static boolean search(int[] A, int n, int key) {
        int i = 0; // Initialize index to 0
        A[n] = key; // Sentinel value: place the key at the end of the array
        // Loop until the key is found in the array
        while (A[i] != key) i++; // Increment index until the key is found
        // Return true if the key was found before the sentinel, false otherwise
        return i != n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, q, key, sum = 0; // Declare variables

        // Read the number of elements in the array
        n = scanner.nextInt();
        int[] A = new int[n + 1]; // Declare the array with an extra space for the sentinel

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Read the number of queries
        q = scanner.nextInt();
        // Process each query
        for (int i = 0; i < q; i++) {
            key = scanner.nextInt(); // Read the key to search for
            // If the key is found in the array, increment the sum
            if (search(A, n, key)) sum++;
        }

        // Output the total count of found keys
        System.out.println(sum);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
