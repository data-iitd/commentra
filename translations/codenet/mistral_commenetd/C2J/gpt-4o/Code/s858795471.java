import java.util.Scanner;

public class Main {
    // Function to search for a key in an array
    public static boolean search(int[] A, int n, int key) {
        int i = 0;
        // Add the key to the end of the array
        A[n] = key;
        // Search for the key in the array using a while loop
        while (A[i] != key) i++;
        // Return true if the key was found before the end of the array, otherwise return false
        return i != n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n; // Number of elements in the array
        int[] A = new int[10001]; // Array to store the elements (size 10000 + 1 for the key)
        int q; // Number of queries
        int key; // Key to be searched for
        int sum = 0; // Variable to store the number of keys found

        // Read the number of elements in the array from the user
        n = scanner.nextInt();
        // Read the elements of the array from the user
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        // Read the number of queries from the user
        q = scanner.nextInt();
        // For each query, search for the key in the array and if it is found, increment the sum
        for (int i = 0; i < q; i++) {
            key = scanner.nextInt(); // Read the key to be searched for
            // Call the search function to find the key in the array
            if (search(A, n, key)) sum++; // If the key is found, increment the sum
        }
        // Print the number of keys found
        System.out.println(sum);

        scanner.close();
    }
}

// <END-OF-CODE>
