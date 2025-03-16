import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int X = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        int[] S = new int[N];
        for (int i = 0; i < N; i++) {
            S[i] = A[i];
            if (i > 0) {
                S[i] += S[i - 1];
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int k = 1; k <= N; k++) {
            int E = k * X + 2 * sum(S[j] for (int j = N - 2*k - 1; j >= 0; j -= k));
            ans = Math.min(ans, E);
        }

        System.out.println(ans + N * X + 5 * S[N - 1]);
    }
}

