import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        sc.close();

        // Calculate cumulative remainders of the array A when divided by M
        // Start with a 0 to handle the case of subarrays starting from index 0
        int[] cum_remainders = new int[N + 1];
        cum_remainders[0] = 0;
        for (int i = 1; i <= N; i++) {
            cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
        }

        // Count the occurrences of each remainder using HashMap
        Map<Integer, Integer> remainder_counts = new HashMap<>();
        for (int i = 0; i <= N; i++) {
            int remainder = cum_remainders[i];
            if (remainder_counts.containsKey(remainder)) {
                remainder_counts.put(remainder, remainder_counts.get(remainder) + 1);
            } else {
                remainder_counts.put(remainder, 1);
            }
        }

        // Initialize a variable to count the number of valid combinations
        int combinations = 0;

        // Calculate the number of combinations of indices that have the same remainder
        for (int count : remainder_counts.values()) {
            combinations += count * (count - 1) / 2;  // Combinations of 2 from count
        }

        // Output the total number of combinations found
        System.out.println(combinations);
    }
}

