import java.util.Scanner;

public class BubbleSort {
    public static void main(String[] args) {
        // Declare variables
        int[] a = new int[1000];
        int n, d = 0;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        n = scanner.nextInt();

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Bubble sort algorithm to sort the array in ascending order
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i + 1; j--) {
                if (a[j] < a[j - 1]) {
                    // Swap the elements if they are in the wrong order
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    // Increment the swap counter
                    d++;
                }
            }
        }

        // Print the sorted array
        System.out.print(a[0]);
        for (int i = 1; i < n; i++) {
            System.out.print(" " + a[i]);
        }
        System.out.println();

        // Print the number of swaps made during the sorting process
        System.out.println(d);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
