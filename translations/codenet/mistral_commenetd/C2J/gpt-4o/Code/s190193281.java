import java.util.Scanner;

public class BinarySearchExample {
    static int n;
    static int[] S;
    static int[] T;

    // Function to perform binary search on an array
    static int binarySearch(int key) {
        int left = 0, right = n; // Initialize left and right pointers
        while (left < right) { // While the array is not yet searched completely
            int mid = (left + right) / 2; // Calculate the middle index
            if (S[mid] == key) return 1; // If key is found, return 1
            else if (key < S[mid]) right = mid; // If key is smaller, search in left half
            else left = mid + 1; // If key is greater, search in right half
        }
        return 0; // If key is not present in the array, return 0
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q, c = 0; // Initialize variables

        // Read the size of the array
        System.out.print("Enter the size of the array: ");
        n = scanner.nextInt();

        // Allocate memory for the array
        S = new int[n];

        // Read the elements of the array
        System.out.println("Enter " + n + " integers:");
        for (int i = 0; i < n; i++) {
            System.out.print("Element " + (i + 1) + ": ");
            S[i] = scanner.nextInt();
        }

        // Read the number of queries
        System.out.print("Enter the number of queries: ");
        q = scanner.nextInt();

        // Allocate memory for the queries
        T = new int[q];

        // Read the queries
        System.out.println("Enter " + q + " integers to be searched:");
        for (int i = 0; i < q; i++) {
            System.out.print("Query " + (i + 1) + ": ");
            T[i] = scanner.nextInt();

            // Check if the query is present in the array
            if (binarySearch(T[i]) == 1) c++;
        }

        // Print the number of queries present in the array
        System.out.println("Number of queries present in the array: " + c);

        scanner.close();
    }
}

// <END-OF-CODE>
