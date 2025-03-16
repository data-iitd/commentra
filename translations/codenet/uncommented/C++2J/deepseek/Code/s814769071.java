public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long MOD = 1000000007;
        long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
        long mn = k * (k - 1) / 2;
        long res = 0;
        for (int i = (int) k; i <= n + 1; ++i) {
            res += mx - mn + 1;
            mx += n - i;
            mn += i;
            res %= MOD;
        }
        System.out.println(res);
    }
}
