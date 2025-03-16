import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new scanner to read input from standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int N = scanner.nextInt();
        // Initialize arrays to hold the original values and a sorted copy
        int[] X = new int[N];
        int[] Y = new int[N];
        
        // Read N integers into array X and copy them to array Y
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            Y[i] = X[i];
        }
        
        // Sort the array Y to find the median values
        Arrays.sort(Y);
        // Calculate the two middle values (medians) for even-sized arrays
        int m1 = Y[N / 2 - 1]; // First median
        int m2 = Y[N / 2];     // Second median
        
        // For each element in X, print the appropriate median based on its value
        for (int i = 0; i < N; i++) {
            if (X[i] <= m1) {
                System.out.println(m2); // If X[i] is less than or equal to m1, print m2
            } else {
                System.out.println(m1); // Otherwise, print m1
            }
        }
        
        scanner.close(); // Close the scanner
    }
}
