public class Main {
    static final long B = 13131;
    static final int N = 500000 + 7;

    static int n;
    static char[] s = new char[N];
    static long[] f = new long[N];
    static int[] g = new int[N];
    static java.util.Map<Long, Long> map = new java.util.HashMap<>();
    static long cnt;

    static long pow(long a, long k) {
        if (k < 0) k += (1L << 63) - 1;
        long t = 1;
        for (; k > 0; a = a * a, k >>= 1)
            if ((k & 1) == 1) t = t * a;
        return t;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        s = (" " + scanner.next()).toCharArray();
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '+' || s[i] == '-')
                f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
            else
                f[i] = f[i - 1];
        }
        for (int i = n; i > 0; --i) {
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1);
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L);
        }
        System.out.println(cnt);
    }
}
