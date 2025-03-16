import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);

        // Read the values of n and m from input
        int n = sc.nextInt(); // The total number of steps
        int m = sc.nextInt(); // The number of blocked steps
        int[] a = new int[m + 1]; // Array to store the blocked steps
        int[] cnt = new int[n + 1]; // Array to store the number of ways to reach each step
        cnt[0] = 1; // Base case: There is one way to stay at the ground (step 0)
        final int MOD = 1000000007; // Define a constant for modulo operation to prevent overflow

        // Read the blocked steps into the array a
        for (int i = 1; i < a.length; i++) {
            a[i] = sc.nextInt();
        }

        int num = 1; // Index to track the current blocked step
        // Check if there are any blocked steps
        if (m > 0) {
            // If the first step is blocked, set the count for step 1 to 0
            if (a[1] == 1) {
                cnt[1] = 0; // No way to reach step 1
                if (num < m) {
                    num++; // Move to the next blocked step
                }
            } else {
                cnt[1] = 1; // If step 1 is not blocked, there is one way to reach it
            }
        } else {
            cnt[1] = 1; // If no blocked steps, there is one way to reach step 1
        }

        // Calculate the number of ways to reach each step from 2 to n
        for (int i = 2; i < cnt.length; i++) {
            // The number of ways to reach step i is the sum of ways to reach step i-1 and i-2
            cnt[i] = cnt[i - 2] + cnt[i - 1];
            cnt[i] %= MOD; // Apply modulo to avoid overflow

            // Check if the current step i is blocked
            if (m > 0) {
                if (i == a[num]) {
                    cnt[i] = 0; // Set count to 0 if the step is blocked
                    if (num < m) {
                        num++; // Move to the next blocked step
                    }
                }
            }
        }

        // Output the number of ways to reach step n
        System.out.println(cnt[n]);
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
