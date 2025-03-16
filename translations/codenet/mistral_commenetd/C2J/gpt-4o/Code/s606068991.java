import java.util.Scanner;

public class InsertionSort {

    // Function to print the first n-1 elements of an array
    public static void white(int n, int[] A) {
        // Loop to print the first n-1 elements of the array
        for (int i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " ");
        }
        // Print the last element of the array
        System.out.println(A[n - 1]);
    }

    // Function to implement insertion sort algorithm
    public static void insertionsort(int n, int[] A) {
        // Loop to sort the array using insertion sort algorithm
        for (int i = 0; i < n; i++) {
            // Inner loop to find the position of the current element in sorted array
            for (int j = 0; j < i; j++) {
                // Swap if current element is smaller than the previous one
                if (A[i] < A[j]) {
                    // Swap the elements
                    int a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
            // Call the white function to print the sorted array after each iteration
            white(n, A);
        }
    }

    // Main function to take input and call the insertion sort function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[100];
        // Take the elements of the array as input
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        // Call the insertion sort function to sort the array
        insertionsort(n, A);
        scanner.close();
    }
}

// <END-OF-CODE>
