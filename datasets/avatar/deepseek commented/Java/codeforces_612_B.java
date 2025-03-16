import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in); // Creating a Scanner object to read input
        int n = s.nextInt(); // Reading the integer n from the input
        int dp[] = new int[200001]; // Initializing an array to store positions

        // Storing positions of the integers in the array dp
        for (int i = 0; i < n; i++) {
            dp[s.nextInt()] = i;
        }

        long ans = 0; // Initializing the answer variable to 0

        // Calculating the sum of absolute differences between consecutive positions
        for (int i = 2; i <= n; i++) {
            ans += Math.abs(dp[i] - dp[i - 1]);
        }

        System.out.println(ans); // Printing the final answer
    }
}
