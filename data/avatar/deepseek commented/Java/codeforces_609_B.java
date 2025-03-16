
import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Create a Scanner object to read input
        int n = in.nextInt(); // Read the first integer n from input
        int m = in.nextInt(); // Read the second integer m from input

        int arr[] = new int[n]; // Declare and initialize an array to store n integers
        int gen[] = new int[11]; // Declare and initialize an array to count occurrences of integers

        // Read n integers from input and store them in arr, and count their occurrences in gen
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
            gen[arr[i]]++;
        }

        long ans = 0; // Declare a variable to store the result

        // Calculate the number of pairs (i, k) where i ≠ k and gen[i] and gen[k] are non-zero
        for (int i = 1; i <= m; i++) {
            for (int k = 1; k <= m; k++) {
                if (i != k) {
                    ans += (long) gen[i] * gen[k];
                }
            }
        }

        // Print the result, which is half of the calculated pairs
        System.out.println(ans / 2);
    }
}
