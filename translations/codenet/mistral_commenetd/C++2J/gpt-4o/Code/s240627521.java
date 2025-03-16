import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int N = scanner.nextInt(); // Read the number of elements
        long[] A = new long[N]; // Declare and initialize an array A of size N
        for (int i = 0; i < N; ++i) { // Iterate through the range [0, N) and read each element into the array
            A[i] = scanner.nextLong();
        }
        Arrays.sort(A); // Sort the array A in ascending order
        long max = Long.MAX_VALUE; // Initialize the maximum difference to a large value
        int index = -1; // Variable to store the index of the second smallest element
        for (int i = 1; i < N; ++i) { // Iterate through the range [1, N)
            long diff = Math.abs(A[N - 1] - 2 * A[i]); // Calculate the difference
            if (max > diff) { // Check if the current difference is greater than the maximum difference
                max = diff; // Update the maximum difference if it is
                index = i; // Update the index of the second smallest element
            }
        }
        System.out.println(A[N - 1] + " " + A[index]); // Output the largest and the second smallest elements
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
