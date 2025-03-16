import java.util.Scanner;

public class Main {
    // Function to search for a key in an array
    static int search(int[] A, int n, int key) {
        int i = 0;
        // Add the key to the end of the array
        A[n] = key;
        // Search for the key in the array using a while loop
        while (A[i] != key) i++;
        // Return 1 if the key was found before the end of the array, otherwise return 0
        return i != n ? 1 : 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, // Number of elements in the array
            q, // Number of queries
            key, // Key to be searched for
            sum = 0, // Variable to store the number of keys found
            i; // Loop counter

        // Read the number of elements in the array from the user
        n = scanner.nextInt();
        // Read the elements of the array from the user
        int[] A = new int[10000 + 1];
        for (i = 0; i < n; i++) A[i] = scanner.nextInt();
        // Read the number of queries from the user
        q = scanner.nextInt();
        // For each query, search for the key in the array and if it is found, increment the sum
        for (i = 0; i < q; i++) {
            key = scanner.nextInt(); // Read the key to be searched for
            // Call the search function to find the key in the array
            if (search(A, n, key) == 1) sum++; // If the key is found, increment the sum
        }
        // Print the number of keys found
        System.out.println(sum);
    }
}
