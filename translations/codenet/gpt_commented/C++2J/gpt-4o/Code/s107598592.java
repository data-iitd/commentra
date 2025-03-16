import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize two arrays to store the input values
        int[] X = new int[N];
        int[] Y = new int[N];

        // Read input values into array X and copy them to array Y
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            Y[i] = X[i];
        }

        // Sort array Y to find the median
        Arrays.sort(Y);

        // Find the median value (middle element for odd N, or lower middle for even N)
        int y = Y[N / 2];

        // Output the appropriate median value for each element in X
        for (int i = 0; i < N; i++) {
            // If the current element in X is less than the median
            if (X[i] < Y[N / 2]) {
                System.out.println(Y[N / 2]); // Output the upper median
            } else {
                System.out.println(Y[N / 2 - 1]); // Output the lower median
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
