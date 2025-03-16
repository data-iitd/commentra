
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {

        // Read the number of elements
        int n; 
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Initialize a vector to store the input values and a vector for prefix sums
        int[] a = new int[n];
        int[] acc = new int[n + 1];

        // Read input values and compute prefix sums modulo MOD
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            acc[i + 1] = acc[i] + a[i]; // Update prefix sum
            acc[i + 1] %= MOD; // Ensure the prefix sum is within MOD
        }

        // Initialize the answer variable
        long ans = 0;

        // Calculate the final answer using the prefix sums
        for (int i = 0; i < n; i++) {
            ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD; // Update answer based on current element and remaining sum
            ans %= MOD; // Ensure the answer is within MOD
        }

        // Output the final result
        System.out.println(ans);

        sc.close();
    }
}

