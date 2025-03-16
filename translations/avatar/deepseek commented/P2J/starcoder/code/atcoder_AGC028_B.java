
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = 1000000;
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int Nsq = 1000;
        int[] fact = new int[M];
        fact[0] = 1;
        for (int n = 1; n < M; n++) {
            fact[n] = fact[n - 1] * n % MOD;
        }
        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[i] = fact[i] * fact[n] % MOD;
            }
        }
        int[] inv = new int[N];
        inv[0] = 1;
        for (int i = 1; i < N; i++) {
            inv[i] = (inv[i - 1] + MOD - 1) % MOD;
        }
        int[] temp = new int[N];
        for (int i = 0; i < N; i++) {
            temp[i] = (inv[i] + inv[N - 1 - i] - 1) % MOD;
        }
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += (long) A[i] * temp[i] % MOD;
            ans %= MOD;
        }
        ans *= fact[N];
        ans %= MOD;
        System.out.println(ans);
    }
}

