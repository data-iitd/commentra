import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read input for n
        int m = scanner.nextInt(); // Read input for m
        int k, a; // Declare variables k and a for intermediate calculations
        int[] x = new int[31]; // Initialize an array x of size 31 with zeros

        // Process each input value for n times
        for (int i = 0; i < n; ++i) {
            k = scanner.nextInt(); // Read the number of elements in the current input

            // Process each element in the current input
            for (int j = 0; j < k; ++j) {
                a = scanner.nextInt(); // Read the value of the current element
                x[a]++; // Increment the count of the current value in the array x
            }
        }

        // Initialize answer variable to zero
        int ans = 0;

        // Check each value from 1 to m and increment the answer if the count is equal to n
        for (int i = 1; i <= m; ++i) {
            if (x[i] == n) { // Check if the count of the current value is equal to n
                ans++; // Increment the answer if true
            }
        }

        // Output the final answer
        System.out.println(ans);
    }
}
