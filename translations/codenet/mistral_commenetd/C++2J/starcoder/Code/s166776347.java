import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Solution
        int ans1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue;
                if (A[i] > A[j]) ans1++;
                ans1 %= 1000000007;
            }
        }

        int[] count = new int[2005];
        for (int i = 0; i < N; i++) {
            count[A[i] - 1]++;
        }

        int ans2 = 0;
        int remain = N;
        for (int i = 0; i < 2005; i++) {
            remain -= count[i];
            ans2 += count[i] * remain;
            ans2 %= 1000000007;
        }

        int ans = 0;
        int tmp = K * (K - 1);
        tmp /= 2;
        tmp %= 1000000007;
        tmp *= ans2;
        tmp %= 1000000007;
        ans += ans1 * K;
        ans %= 1000000007;
        ans += tmp;
        ans %= 1000000007;

        // Output
        System.out.println(ans);
    }
}

