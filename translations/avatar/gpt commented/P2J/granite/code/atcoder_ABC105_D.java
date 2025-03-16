
import java.util.Scanner;
import java.util.HashMap;

public class atcoder_ABC105_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        scanner.close();

        int[] cum_remainders = new int[N + 1];
        cum_remainders[0] = 0;
        for (int i = 0; i < N; i++) {
            cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
        }

        HashMap<Integer, Integer> remainder_counts = new HashMap<>();
        for (int remainder : cum_remainders) {
            remainder_counts.put(remainder, remainder_counts.getOrDefault(remainder, 0) + 1);
        }

        long combinations = 0;
        for (int count : remainder_counts.values()) {
            combinations += (long) count * (count - 1) / 2;  // Combinations of 2 from count
        }

        System.out.println(combinations);
    }
}
