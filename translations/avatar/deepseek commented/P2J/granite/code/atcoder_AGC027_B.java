
import java.util.*;

public class atcoder_AGC027_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        long[] S = new long[N + 1];
        for (int i = 0; i < N; i++) {
            S[i + 1] = S[i] + A[i];
        }
        long ans = Long.MAX_VALUE;
        for (int k = 1; k <= N; k++) {
            long E = k * X + 2 * Arrays.stream(S).skip(N - 2 * k).limit(k).sum();
            ans = Math.min(ans, E);
        }
        System.out.println(ans + N * X + 5 * S[N]);
    }
}
