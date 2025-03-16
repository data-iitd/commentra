import java.util.Scanner;

public class Main {
    public static int search(int[] A, int n, int key) {
        int i = 0;
        // Add the key to the end of the array to handle the case where the key is not found
        A[n] = key;
        // Loop until the key is found in the array
        while (A[i] != key) i++;
        // Return 1 if the key is found, otherwise return 0
        return i != n ? 1 : 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[10000 + 1];
        int q, key, sum = 0;

        // Read the array elements
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        // Read the number of queries
        q = scanner.nextInt();
        // Process each query
        for (int i = 0; i < q; i++) {
            key = scanner.nextInt();
            // Perform the search operation for the current query element
            if (search(A, n, key) == 1) sum++;
        }
        // Print the count of successful searches
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
