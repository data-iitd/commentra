import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a scanner to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array from the input
        int N = scanner.nextInt();
        // Allocate memory for two arrays X and Y of size N
        int[] X = new int[N];
        int[] Y = new int[N];

        // Read N integers from the input and store them in X and Y arrays
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            // Store the current element of X in Y array for sorting
            Y[i] = X[i];
        }

        // Sort the Y array in ascending order
        Arrays.sort(Y);

        // Find the median of Y array
        int m1 = Y[N / 2 - 1];
        int m2 = Y[N / 2];

        // Iterate through each element of X array and print the corresponding median value
        for (int i = 0; i < N; i++) {
            if (X[i] <= m1) {
                // If X[i] is smaller than m1, print m2 as the answer
                System.out.println(m2);
            } else {
                // If X[i] is greater than m1, print m1 as the answer
                System.out.println(m1);
            }
        }

        scanner.close();
    }

    // Function to find the maximum of two integers
    public static int max(int a, int b) {
        // If a is smaller than b, return b
        return (a < b) ? b : a;
    }

    // Function to find the minimum of two integers
    public static int min(int a, int b) {
        // If a is greater than b, return b
        return (a > b) ? b : a;
    }

    // Function to find the absolute value of an integer
    public static int abs(int a) {
        // If a is negative, return the negative of a
        return (a < 0) ? -a : a;
    }
}

// <END-OF-CODE>
