import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.IntStream;
import java.util.stream.Collectors;
import java.util.Map;
import java.util.HashMap;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        scanner.close();

        // Calculate the cumulative remainders of the array A modulo M
        // Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
        int[] cum_remainders = new int[N + 1];
        cum_remainders[0] = 0;
        for (int i = 1; i <= N; i++) {
            cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
        }

        // Count the occurrences of each remainder
        Map<Integer, Integer> remainder_counts = new HashMap<>();
        for (int remainder : cum_remainders) {
            remainder_counts.put(remainder, remainder_counts.getOrDefault(remainder, 0) + 1);
        }

        // Calculate the number of combinations where the difference between two remainders is a multiple of M
        long combinations = 0;
        for (int count : remainder_counts.values()) {
            combinations += count * (count - 1) / 2;
        }

        // Print the number of combinations
        System.out.println(combinations);
    }
}

