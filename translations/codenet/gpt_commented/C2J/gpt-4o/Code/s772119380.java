import java.util.Scanner;

public class BubbleSort {
    public static void main(String[] args) {
        // Declare an array to hold up to 1000 integers and variables for size and counters
        int[] a = new int[1000];
        int n, d = 0;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements to be sorted
        n = scanner.nextInt();

        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Perform a bubble sort on the array
        for (int i = 0; i < n; i++) {
            // Inner loop for comparing adjacent elements
            for (int j = n - 1; j >= i + 1; j--) {
                // If the current element is less than the previous one, swap them
                if (a[j] < a[j - 1]) {
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    d++; // Increment the swap counter
                }
            }
        }

        // Print the sorted array
        System.out.print(a[0]); // Print the first element
        for (int i = 1; i < n; i++) {
            System.out.print(" " + a[i]); // Print the remaining elements
        }

        // Print the total number of swaps made during sorting
        System.out.println("\n" + d);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
