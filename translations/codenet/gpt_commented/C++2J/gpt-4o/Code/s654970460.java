import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable 'n' for the number of elements,
        // an array 'a' of size 101 to store the elements, and an integer 'i' for iteration.
        int n;
        int[] a = new int[101];
        int i;

        // Create a Scanner object to read input from the user.
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements 'n' from the user.
        n = scanner.nextInt();

        // Loop to read 'n' elements into the array 'a'.
        for (i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Output the last element of the array (a[n-1]).
        System.out.print(a[n - 1]);

        // Loop to output the elements of the array in reverse order,
        // starting from the second last element down to the first element.
        for (i = 1; i < n; i++) {
            System.out.print(" " + a[n - i - 1]);
        }

        // Print a newline character at the end of the output.
        System.out.println();

        // Close the scanner to prevent resource leaks.
        scanner.close();
    }
}

// <END-OF-CODE>
