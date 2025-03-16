import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        long[] cum_remainders = new long[N + 1];
        cum_remainders[0] = 0;
        for (int i = 0; i < N; i++) {
            cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
        }
        Map<Long, Integer> remainder_counts = new HashMap<Long, Integer>();
        for (int i = 0; i < N + 1; i++) {
            remainder_counts.put(cum_remainders[i], remainder_counts.getOrDefault(cum_remainders[i], 0) + 1);
        }
        long combinations = 0;
        for (int count : remainder_counts.values()) {
            combinations += count * (count - 1) / 2;
        }
        System.out.println(combinations);
    }
}
