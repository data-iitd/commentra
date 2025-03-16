import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements in the array A
        long[] A = new long[N];
        for (int i = 0; i < N; ++i) {
            A[i] = scanner.nextLong(); // Read the elements of the array A
        }
        Arrays.sort(A); // Sort the array A in ascending order
        long max = Long.MAX_VALUE; // Initialize max with a large value
        int index = -1;
        
        // Iterate through the array to find the optimal pair
        for (int i = 1; i < N; ++i) {
            if (max > Math.abs(A[N - 1] - 2 * A[i])) { // Check if the current difference is smaller than the previous minimum
                max = Math.abs(A[N - 1] - 2 * A[i]); // Update the minimum difference
                index = i; // Store the index of the current element
            }
        }
        System.out.println(A[N - 1] + " " + A[index]); // Output the first and the found optimal pair
        scanner.close();
    }
}
// <END-OF-CODE>
