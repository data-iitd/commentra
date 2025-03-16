import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int _lcm = 1;
        for (int a : A) {
            _lcm = _lcm * a / gcd(_lcm, a);
        }
        int ans = _lcm * sum(A) % MOD;
        System.out.println(ans % MOD);
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static int sum(int[] A) {
        int sum = 0;
        for (int a : A) {
            sum += a;
        }
        return sum;
    }

    public static int MOD = 1000000007;
}

