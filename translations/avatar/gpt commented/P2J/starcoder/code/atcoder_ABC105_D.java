import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the values of N and M from standard input
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Read the array A from standard input and convert it to a NumPy array of int64 type
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        long[] A_long = new long[N];
        for (int i = 0; i < N; i++) {
            A_long[i] = (long) A[i];
        }
        long[] A_mod_M = new long[N];
        for (int i = 0; i < N; i++) {
            A_mod_M[i] = A_long[i] % M;
        }

        // Calculate cumulative remainders of the array A when divided by M
        // Start with a 0 to handle the case of subarrays starting from index 0
        long[] cum_remainders = new long[N + 1];
        for (int i = 0; i < N; i++) {
            cum_remainders[i + 1] = cum_remainders[i] + A_mod_M[i];
        }

        // Count the occurrences of each remainder using Counter
        Map<Long, Integer> remainder_counts = new HashMap<Long, Integer>();
        for (int i = 0; i < N; i++) {
            remainder_counts.put(cum_remainders[i + 1], remainder_counts.getOrDefault(cum_remainders[i + 1], 0) + 1);
        }

        // Initialize a variable to count the number of valid combinations
        int combinations = 0;

        // Calculate the number of combinations of indices that have the same remainder
        for (int count : remainder_counts.values()) {
            combinations += count * (count - 1) / 2; // Combinations of 2 from count
        }

        // Output the total number of combinations found
        System.out.println(combinations);
    }
}

