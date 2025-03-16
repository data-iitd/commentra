import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        int[] A = new int[100]; // An array of integers with a maximum size of 100
        int n; // The number of elements in the array
        int sw = 0; // Variable to count the number of swaps

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        n = scanner.nextInt(); // Read the number of elements from the standard input

        System.out.println("Enter " + n + " integers:");
        for (int i = 0; i < n; i++) { // Read n integers from the standard input and store them in the array A
            A[i] = scanner.nextInt();
        }

        System.out.println("Sorting the array using Selection Sort algorithm:");
        for (int i = 0; i < n; i++) { // The outer loop runs n times
            int mini = i; // Initialize mini as i
            for (int j = i; j < n; j++) { // The inner loop finds the minimum element in the unsorted part of the array
                if (A[j] < A[mini]) { // If A[j] is smaller than A[mini], update mini
                    mini = j;
                }
            }
            // Swap A[i] with the minimum element
            int t = A[i];
            A[i] = A[mini];
            A[mini] = t;

            if (i != mini) sw++; // Increment sw only if a swap is made
        }

        System.out.print("Sorted array: ");
        for (int i = 0; i < n; i++) { // Print the sorted array to the standard output
            if (i > 0) System.out.print(" ");
            System.out.print(A[i]);
        }
        System.out.println();

        System.out.println("Number of swaps: " + sw);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
