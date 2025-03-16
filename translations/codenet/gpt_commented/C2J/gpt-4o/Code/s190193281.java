import java.util.Scanner;

public class Main {
    static final int N = 1000000;  // Maximum size for the array S
    static final int Q = 50000;     // Maximum size for the array T

    static int n;                   // Number of elements in the sorted array
    static int[] S = new int[N];    // Sorted array
    static int[] T = new int[Q];    // Query array

    // Function to perform binary search on the sorted array S
    static int binarySearch(int key) {
        int left = 0, right = n;  // Initialize left and right pointers for the search range
        while (left < right) {     // Continue searching while the range is valid
            int mid = (left + right) / 2;  // Calculate the middle index
            if (S[mid] == key) return 1;    // If the key is found, return 1
            else if (key < S[mid]) right = mid;  // Narrow the search to the left half
            else left = mid + 1;  // Narrow the search to the right half
        }
        return 0;  // If the key is not found, return 0
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int c = 0;  // Count of found keys

        // Read the number of elements in the sorted array S
        n = scanner.nextInt();

        // Read the elements into the sorted array S
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }

        // Read the number of queries
        int q = scanner.nextInt();

        // Process each query to check if it exists in the sorted array S
        for (int i = 0; i < q; i++) {
            T[i] = scanner.nextInt();  // Read the query element into array T
            if (binarySearch(T[i]) == 1) c++;  // If the element is found, increment the count
        }

        // Output the total count of found elements
        System.out.println(c);

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
