import java.util.Scanner;

public class LinearSearch {

    // Function to perform linear search on an array
    public static int linearSearch(int[] S, int n, int key) {
        int i = 0; // Initialize index variable i to 0

        // Search for the key in the array S until it is found or the end of the array is reached
        while (i < n) {
            if (S[i] == key) {
                return 0; // If key is found, return 0 to indicate that it was found
            }
            i++; // Increment i by 1 for each iteration
        }

        // If key is not found in the array, return 1
        return 1;
    }

    // Main function to read input and call linearSearch function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, q, count = 0; // Initialize count variable to 0

        // Read the size of the array S from the user
        System.out.print("Enter the size of the array S: ");
        n = scanner.nextInt();
        int[] S = new int[n]; // Declare array S with size n

        // Read the elements of array S from the user
        System.out.println("Enter " + n + " integers for array S:");
        for (int i = 0; i < n; i++) {
            System.out.print("Enter integer S[" + i + "]: ");
            S[i] = scanner.nextInt();
        }

        // Read the number of queries from the user
        System.out.print("Enter the number of queries: ");
        q = scanner.nextInt();
        int[] T = new int[q]; // Declare array T with size q

        // Read the elements of array T from the user
        System.out.println("Enter " + q + " integers for array T:");
        for (int j = 0; j < q; j++) {
            System.out.print("Enter integer T[" + j + "]: ");
            T[j] = scanner.nextInt();
        }

        // Call linearSearch function for each element of array T and increment count if key is not found
        for (int j = 0; j < q; j++) {
            int key = T[j]; // Assign the current element of array T to key variable
            if (linearSearch(S, n, key) == 1) { // Call linearSearch function and check if count is 1 (key not found)
                count++; // Increment count if key is not found
            }
        }

        // Print the final count to the user
        System.out.println("Number of integers in array S that are not present in array T: " + count);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
