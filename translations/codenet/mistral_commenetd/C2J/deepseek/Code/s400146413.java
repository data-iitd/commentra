import java.util.Scanner;

public class LinearSearch {
    // Function to perform linear search on an array
    public static int linearsearch(int S[], int n, int key) {
        int i = 0; // Initialize index variable i to 0
        int count = 0; // Initialize count variable to 0

        // Search for the key in the array S until it is found or the end of the array is reached
        while (S[i] != key) {
            i++; // Increment i by 1 for each iteration
            if (i >= n) { // Check if the end of the array has been reached
                count = 1; // Set count to 1 if key is not found in the array
                return count; // Return count to the calling function
            }
        }

        // If key is found, return 0 to indicate that it was found
        return 0;
    }

    // Main function to read input and call linearsearch function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, j, n, q; // Declare and initialize variables
        int[] S = new int[10000];
        int[] T = new int[10000];
        int count = 0; // Initialize count variable to 0

        // Read the size of the array S from the user
        System.out.print("Enter the size of the array S: ");
        n = scanner.nextInt();

        // Read the elements of array S from the user
        System.out.printf("Enter %d integers for array S:\n", n);
        for (i = 0; i < n; i++) {
            System.out.printf("Enter integer S[%d]: ", i);
            S[i] = scanner.nextInt();
        }

        // Read the number of queries from the user
        System.out.print("Enter the number of queries: ");
        q = scanner.nextInt();

        // Read the elements of array T from the user
        System.out.printf("Enter %d integers for array T:\n", q);
        for (j = 0; j < q; j++) {
            System.out.printf("Enter integer T[%d]: ", j);
            T[j] = scanner.nextInt();
        }

        // Call linearsearch function for each element of array T and increment count if key is not found
        for (j = 0; j < q; j++) {
            int key = T[j]; // Assign the current element of array T to key variable
            if (linearsearch(S, n, key) == 1) { // Call linearsearch function and check if count is 1 (key not found)
                count++; // Increment count if key is not found
            }
        }

        // Print the final count to the user
        System.out.printf("Number of integers in array S that are not present in array T: %d\n", count);

        // Return 0 to indicate successful execution of the program
        scanner.close();
    }
}
