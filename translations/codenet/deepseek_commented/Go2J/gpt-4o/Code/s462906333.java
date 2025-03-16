import java.util.Scanner;

public class Main {
    static final int INF = (int) 1e14; // Define a large value to represent infinity for cost comparisons

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new scanner for input
        int n = scanner.nextInt(); // Read the number of elements
        int x = scanner.nextInt(); // Read some parameter x
        int[] a = new int[n]; // Initialize the array a with size n
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Fill the array a with integers from input
        }
        int[] v = a.clone(); // Create a copy of array a named v
        int ans = INF; // Initialize the answer with a large value
        for (int k = 0; k < n; k++) { // Iterate over possible values of k
            int kans = 0; // Initialize the temporary answer for the current k
            for (int i = 0; i < n; i++) { // Iterate over each element in the array
                if (i - k < 0) { // If the index is out of bounds, wrap around
                    v[i] = Math.min(v[i], a[n + i - k]); // Update the value in v
                } else {
                    v[i] = Math.min(v[i], a[i - k]); // Update the value in v
                }
                kans += v[i]; // Add the updated value to the temporary answer
            }
            ans = Math.min(ans, kans + k * x); // Update the final answer with the minimum cost
        }

        System.out.println(ans); // Print the minimum cost found
    }
}
