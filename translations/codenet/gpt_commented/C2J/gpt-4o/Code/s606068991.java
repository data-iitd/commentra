import java.util.Scanner;

public class InsertionSort {

    // Function to print the array elements
    public static void white(int n, int[] A) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " "); // Print each element followed by a space
        }
        System.out.println(A[n - 1]); // Print the last element followed by a newline
    }

    // Function to perform insertion sort on the array
    public static void insertionsort(int n, int[] A) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If the current element is smaller, swap it with the previous element
                if (A[i] < A[j]) {
                    int a = A[i];
                    A[i] = A[j];
                    A[j] = a; // Swap the elements
                }
            }
            // Print the current state of the array after each insertion
            white(n, A);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements from user input
        int[] A = new int[100]; // Declare the array

        // Read the elements of the array from user input
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Call the insertion sort function to sort the array
        insertionsort(n, A);
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
