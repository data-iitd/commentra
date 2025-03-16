import java.util.Scanner; // Import Scanner for input

public class BubbleSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int N = scanner.nextInt(); // Read the size of the array
        int[] A = new int[100]; // Declare an array of size 100
        int count = 0; // Initialize swap counter

        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Read the elements of the array
        }

        // Implement Bubble Sort
        for (int i = 0; i < N - 1; i++) {
            for (int j = N - 1; j > i; j--) {
                if (A[j] < A[j - 1]) {
                    int tmp = A[j]; // Swap A[j] and A[j-1]
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;
                    count++; // Increment the swap counter
                }
            }
        }

        for (int i = 0; i < N; i++) {
            System.out.print(A[i]); // Print the sorted array elements
            if (i < N - 1) System.out.print(" "); // Print a space between elements, but not after the last element
        }

        System.out.println(); // Print a newline character to end the line
        System.out.println(count); // Print the number of swaps

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
