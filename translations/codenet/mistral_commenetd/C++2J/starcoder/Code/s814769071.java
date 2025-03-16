
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int MOD = 1000000007;

        // Calculate the maximum number of unique elements in a subset of size k from 1 to n
        int mx = n * (n + 1) / 2 - (n - k)*(n - k + 1) / 2;

        // Calculate the minimum number of unique elements in a subset of size k from 1 to n
        int mn = k * (k - 1) / 2;

        // Initialize result variable
        int res = 0;

        // Iterate through all possible subset sizes from k to n+1
        for (int i = k; i <= n + 1; ++i)
        {
            // Calculate the number of unique elements in the current subset
            res += mx - mn + 1;

            // Update the maximum and minimum number of unique elements for the next iteration
            mx += n - i;
            mn += i;

            // Update the result variable
            res %= MOD;
        }

        // Print the final result
        System.out.println(res);
    }
}

