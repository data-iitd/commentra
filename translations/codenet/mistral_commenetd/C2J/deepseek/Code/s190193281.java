import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, q, c = 0;
        int[] S, T;

        // Read the size of the array
        System.out.print("Enter the size of the array: ");
        n = scanner.nextInt();

        // Allocate memory for the array
        S = new int[n];

        // Read the elements of the array
        System.out.printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++) {
            System.out.printf("Element %d: ", i + 1);
            S[i] = scanner.nextInt();
        }

        // Read the number of queries
        System.out.print("Enter the number of queries: ");
        q = scanner.nextInt();

        // Allocate memory for the queries
        T = new int[q];

        // Read the queries
        System.out.printf("Enter %d integers to be searched:\n", q);
        for (int i = 0; i < q; i++) {
            System.out.printf("Query %d: ", i + 1);
            T[i] = scanner.nextInt();

            // Check if the query is present in the array
            if (binarySearch(S, T[i]) == 1) c++;
        }

        // Print the number of queries present in the array
        System.out.printf("Number of queries present in the array: %d\n", c);

        // Free the allocated memory (no need in Java)
    }

    // Function to perform binary search on an array
    public static int binarySearch(int[] array, int key) {
        int left = 0, right = array.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (array[mid] == key) return 1;
            else if (key < array[mid]) right = mid;
            else left = mid + 1;
        }
        return 0;
    }
}
