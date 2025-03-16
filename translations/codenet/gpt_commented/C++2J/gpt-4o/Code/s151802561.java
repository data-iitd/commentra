import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        // Declare an array to hold up to 100 integers and other necessary variables
        int[] A = new int[100];
        int n, i, j, t, sw = 0, mini;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements to be sorted
        n = scanner.nextInt();

        // Read the elements into the array A
        for (i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Selection sort algorithm to sort the array A
        for (i = 0; i < n; i++) {
            mini = i; // Assume the minimum is the first element of the unsorted part
            // Find the index of the minimum element in the unsorted part
            for (j = i; j < n; j++) {
                if (A[j] < A[mini]) {
                    mini = j; // Update mini if a smaller element is found
                }
            }
            // Swap the found minimum element with the first element of the unsorted part
            t = A[i];
            A[i] = A[mini];
            A[mini] = t;

            // Count the number of swaps made
            if (i != mini) {
                sw++;
            }
        }

        // Print the sorted array
        for (i = 0; i < n; i++) {
            if (i > 0) {
                System.out.print(" "); // Print a space before each element except the first
            }
            System.out.print(A[i]); // Print the current element
        }
        System.out.println(); // Print a newline after the array

        // Print the total number of swaps made during sorting
        System.out.println(sw);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
