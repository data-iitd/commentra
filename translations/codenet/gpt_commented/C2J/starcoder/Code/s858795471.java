
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, A[] = new int[10000 + 1], q, key, sum = 0;
        int i;

        // Read the number of elements in the array
        n = sc.nextInt();
        // Read the elements of the array
        for (i = 0; i < n; i++) A[i] = sc.nextInt();
        
        // Read the number of queries
        q = sc.nextInt();
        // Process each query
        for (i = 0; i < q; i++) {
            key = sc.nextInt(); // Read the key to search for
            // If the key is found in the array, increment the sum
            if (search(A, n, key)) sum++;
        }
        
        // Output the total count of found keys
        System.out.println(sum);
    }

    // Function to search for a key in the array A of size n
    public static boolean search(int A[], int n, int key) {
        int i = 0; // Initialize index to 0
        A[n] = key; // Sentinel value: place the key at the end of the array
        // Loop until the key is found in the array
        while (A[i]!= key) i++; // Increment index until the key is found
        // Return true if the key was found before the sentinel, false otherwise
        return i!= n;
    }
}

