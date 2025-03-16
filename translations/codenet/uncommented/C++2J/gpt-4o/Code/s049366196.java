import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;

    static boolean isPrime(long x) {
        if (x < 2) return false;
        for (long i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long ans = 1;

        for (int i = 2; i <= N; i++) {
            if (isPrime(i)) {
                int NN = N;
                int cnt = 0;
                while (NN > 0) {
                    cnt += NN / i;
                    NN /= i;
                }
                ans = (ans * (cnt + 1)) % MOD;
            }
        }

        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
