import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the values of N and M from the standard input
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Read the array A from the standard input
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Calculate the cumulative remainders of the array A modulo M
        // Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
        long[] cum_remainders = new long[N + 1];
        cum_remainders[0] = 0;
        for (int i = 0; i < N; i++) {
            cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
        }

        // Count the occurrences of each remainder
        Map<Long, Integer> remainder_counts = new HashMap<>();
        for (long r : cum_remainders) {
            remainder_counts.put(r, remainder_counts.getOrDefault(r, 0) + 1);
        }

        // Initialize the number of combinations
        long combinations = 0;

        // Calculate the number of combinations where the difference between two remainders is a multiple of M
        for (int count : remainder_counts.values()) {
            combinations += count * (count - 1) / 2;
        }

        // Print the number of combinations
        System.out.println(combinations);
    }
}

