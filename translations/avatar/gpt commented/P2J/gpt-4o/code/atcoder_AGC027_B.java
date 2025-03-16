import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // Read input values: N (number of elements), X (a constant), and A (the list of integers)
        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int[] A = new int[N];
        
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        
        // Calculate the cumulative sum of the list A
        long[] S = new long[N];
        S[0] = A[0];
        for (int i = 1; i < N; i++) {
            S[i] = S[i - 1] + A[i];
        }
        
        // Initialize the answer to a very large number (infinity)
        long ans = Long.MAX_VALUE;
        
        // Iterate through the cumulative sums with an index starting from 1
        for (int k = 1; k <= N / 2; k++) {
            long E = k * X;
            for (int j = N - 2 * k - 1; j >= 0; j -= k) {
                E += 2 * S[j];
            }
            // Update the answer with the minimum value found so far
            ans = Math.min(ans, E);
        }
        
        // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
        System.out.println(ans + N * X + 5 * S[N - 1]);
    }
}
// <END-OF-CODE>
