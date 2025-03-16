import java.util.*;

public class AtCoder {
    static class Mint {
        long x;
        static final long mod = (long)1e9 + 7;

        Mint(long x) {
            this.x = (x % mod + mod) % mod;
        }

        Mint negate() {
            return new Mint(-x);
        }

        Mint add(Mint a) {
            if ((x += a.x) >= mod) x -= mod;
            return this;
        }

        Mint subtract(Mint a) {
            if ((x += mod - a.x) >= mod) x -= mod;
            return this;
        }

        Mint multiply(Mint a) {
            (x *= a.x) %= mod;
            return this;
        }

        Mint pow(long t) {
            if (t == 0) return new Mint(1);
            Mint a = pow(t >> 1);
            a.multiply(a);
            if ((t & 1) == 1) a.multiply(this);
            return a;
        }

        Mint inverse() {
            return pow((long)mod - 2);
        }

        Mint divide(Mint a) {
            return multiply(a.inverse());
        }

        @Override
        public String toString() {
            return String.valueOf(x);
        }
    }

    static class Combination {
        private final Mint[] fact;
        private final Mint[] ifact;
        private final long mod;

        Combination(int n, long mod) {
            this.mod = mod;
            fact = new Mint[n + 1];
            ifact = new Mint[n + 1];
            fact[0] = new Mint(1);
            for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1].multiply(new Mint(i));
            ifact[n] = fact[n].inverse();
            for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i].multiply(new Mint(i));
        }

        Mint apply(int n, int k) {
            if (k < 0 || k > n) return new Mint(0);
            return fact[n].multiply(ifact[k]).multiply(ifact[n - k]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[] H = new int[N];
        for (int i = 0; i < N; i++) {
            H[i] = scanner.nextInt();
        }
        List<Integer>[] G = new List[N];
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            G[u].add(v);
            G[v].add(u);
        }

        long ans = 0;
        for (int u = 0; u < N; u++) {
            boolean flag = true;
            for (int v : G[u]) {
                if (H[u] <= H[v]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }

        System.out.println(ans);
    }
}
