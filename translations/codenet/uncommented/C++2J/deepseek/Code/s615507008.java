import java.util.*;

public class Main {
    public static void solve(int N, int[] T, int M, int[] P, int[] X) {
        for (int i = 0; i < M; i++) {
            int ans = 0;
            for (int j = 0; j < N; j++) {
                if (j == P[i] - 1) ans += X[i];
                else ans += T[j];
            }
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] T = new int[N];
        for (int i = 0; i < N; i++) T[i] = scanner.nextInt();
        int M = scanner.nextInt();
        int[] P = new int[M];
        int[] X = new int[M];
        for (int i = 0; i < M; i++) {
            P[i] = scanner.nextInt();
            X[i] = scanner.nextInt();
        }
        solve(N, T, M, P, X);
    }
}
