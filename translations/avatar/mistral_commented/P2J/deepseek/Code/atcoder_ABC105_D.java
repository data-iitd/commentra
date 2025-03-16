import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        String[] A_input = reader.readLine().split(" ");
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(A_input[i]);
        }

        long[] cum_remainders = new long[N + 1];
        cum_remainders[0] = 0;
        for (int i = 1; i <= N; i++) {
            cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
        }

        Map<Long, Integer> remainder_counts = new HashMap<>();
        for (long remainder : cum_remainders) {
            remainder_counts.put(remainder, remainder_counts.getOrDefault(remainder, 0) + 1);
        }

        long combinations = 0;
        for (int count : remainder_counts.values()) {
            combinations += (long) count * (count - 1) / 2;
        }

        System.out.println(combinations);
    }
}
