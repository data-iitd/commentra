import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Method to compute the minimum total distance to a median value
    public static void solve(Scanner sc) {
        // Read the number of elements
        int n = sc.nextInt();
        // Read the integer array of size n
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }

        // Create a new array to store adjusted values
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            // Adjust each element by subtracting its index and adding 1
            xs[i] = as[i] - i + 1;
        }
        // Sort the adjusted values
        Arrays.sort(xs);

        // Find the median value from the sorted array
        int b = xs[n / 2];
        long ans = 0;
        // Calculate the total distance from each element to the median
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        // Output the result
        System.out.println(ans);
    }

    // Main method initializes input/output and calls the solve function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Call the solve function to perform the main logic
        solve(sc);
        sc.close();
    }
}

// <END-OF-CODE>
