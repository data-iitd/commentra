import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[(int) N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }

        // 解法
        long ans1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue;
                if (A[i] > A[j]) ans1++;
                ans1 %= 1000000007;
            }
        }

        long[] count = new long[2005];
        for (int i = 0; i < N; i++) {
            count[Math.toIntExact(A[i] - 1)]++;
        }
        long ans2 = 0;
        long remain = N;
        for (int i = 0; i < 2005; i++) {
            remain -= count[i];
            ans2 += count[i] * remain;
        }
        long tmp = K * (K - 1) / 2 % 1000000007;
        tmp = tmp * ans2 % 1000000007;
        long ans = (ans1 * K % 1000000007 + tmp) % 1000000007;

        // 出力
        System.out.println(ans);
    }
}
