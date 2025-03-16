import java.util.Scanner;

public class Main {
    // Define a constant for a large number to represent infinity
    private static final double INF = 10000000000.0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        int n = scanner.nextInt();

        // Initialize an array to hold the input values
        int[] arrA = new int[n];
        // Read the input values into the array
        for (int i = 0; i < n; i++) {
            arrA[i] = scanner.nextInt();
        }

        // Create a cumulative sum array to store the cumulative sums of arrA
        int[] cumSumA = new int[n + 1];
        cumSumA[0] = 0; // The first element is 0 (sum of zero elements)
        // Calculate the cumulative sums
        for (int i = 0; i < n; i++) {
            cumSumA[i + 1] = cumSumA[i] + arrA[i];
        }

        // Initialize the answer variable to a large value
        double ans = INF;
        // Iterate through the cumulative sums to find the minimum difference
        for (int i = 1; i < n; i++) {
            // Calculate the absolute difference between the total sum and twice the current cumulative sum
            double difference = Math.abs(cumSumA[n] - (cumSumA[i] * 2));
            if (difference < ans) {
                // Update the answer if the current difference is smaller
                ans = difference;
            }
        }

        // Print the final answer as an integer
        System.out.println((int) ans);
    }
}
// <END-OF-CODE>
