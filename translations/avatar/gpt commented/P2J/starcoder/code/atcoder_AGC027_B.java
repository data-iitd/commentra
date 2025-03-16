import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read input values: N (number of elements), X (a constant), and A (the list of integers)
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Calculate the cumulative sum of the list A
        int[] S = new int[N];
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                S[i] = A[i];
            } else {
                S[i] = S[i - 1] + A[i];
            }
        }

        // Initialize the answer to a very large number (infinity)
        int ans = Integer.MAX_VALUE;

        // Iterate through the cumulative sums with an index starting from 1
        for (int k = 1; k <= N; k++) {
            // Calculate the expression E based on the current index k and the cumulative sums
            int E = k * X + 2 * sum(S[j] for j in range(N - 2 * k - 1, -1, -k));

            // Update the answer with the minimum value found so far
            ans = Math.min(ans, E);
        }

        // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
        System.out.println(ans + N * X + 5 * S[N - 1]);
    }
}

