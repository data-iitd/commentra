import java.util.*;

public class Main {
    // Define type aliases for convenience
    static class ll {
        long value;
        ll(long value) { this.value = value; }
    }

    // Macros for loop iterations and constants
    static final int INF = (int) 1e9;
    static final int MOD1 = 1000000007;
    static final int MOD2 = 998244353;
    static final int MAX_N = 1 << 20;
    static final String YES = "Yes\n";
    static final String NO = "No\n";
    static final String PN = "\n";
    static final double PI = 3.141592653589793238;

    // Function to swap two long long integers
    static void swap(ll a, ll b) {
        long c = b.value;
        b.value = a.value;
        a.value = c;
    }

    // Function to read a long long integer
    static void cin(ll n) {
        Scanner scanner = new Scanner(System.in);
        n.value = scanner.nextLong();
    }

    // Functions to find maximum and minimum of two or three numbers
    static long max2(long a, long b) { return a >= b ? a : b; }
    static long min2(long a, long b) { return a >= b ? b : a; }
    static long min3(long a, long b, long c) { return (a <= b && a <= c) ? a : b <= c ? b : c; }
    static long max3(long a, long b, long c) { return (a >= b && a >= c) ? a : b >= c ? b : c; }

    // Functions to find minimum and maximum in an array
    static long minn(int n, long a[]) {
        long b = INF;
        for (int i = 0; i < n; i++) b = min2(b, a[i]);
        return b;
    }
    static long maxn(int n, long a[]) {
        long b = -INF;
        for (int i = 0; i < n; i++) b = max2(b, a[i]);
        return b;
    }

    // Functions for power calculations
    static long POW(long a, long b) {
        long c = 1;
        for (int i = 0; i < b; i++) c *= a;
        return c;
    }
    static double POW_d(double a, double b) {
        double c = 1;
        for (int i = 0; i < b; i++) c *= a;
        return c;
    }

    // Functions for GCD and LCM calculations
    static long gcd(long a, long b) { return b != 0 ? gcd(b, a % b) : a; }
    static long lcm(long a, long b) { return a / gcd(a, b) * b; }

    // Functions for modular arithmetic
    static long mod_MOD1(long n) {
        n = (n % MOD1 + MOD1) % MOD1;
        return n;
    }
    static long mod_p(long n, long p) {
        n = (n % p + p) % p;
        return n;
    }

    // Function to convert a string to a number
    static long change_into_num(char s[], int len, int p) {
        return p == 0 ? 0 : POW(10, p - 1) * (s[len - p] - '0') + change_into_num(s, len, p - 1);
    }

    // Function to count the number of digits in a number
    static long digits(long a, long b) {
        return a / b > 0 ? 1 + digits(a / b, b) : 1;
    }

    // Functions to check if an index is within array bounds
    static boolean is_inArr1(int x, int n) { return x < 0 || x >= n; }
    static boolean is_inArr2(int y, int x, int h, int w) { return y < 0 || y >= h || x < 0 || x >= w; }

    // Functions for lower and upper bounds in binary search
    static void lr_lower(int[] l, int[] r, long am, long val, int type) {
        if (type < 3) {
            if (am < val) {
                l[0] = (l[0] + r[0]) / 2;
            } else {
                r[0] = (l[0] + r[0]) / 2;
            }
        } else {
            if (am <= val) {
                l[0] = (l[0] + r[0]) / 2;
            } else {
                r[0] = (l[0] + r[0]) / 2;
            }
        }
    }
    static void lr_upper(int[] l, int[] r, long am, long val, int type) {
        if (type < 3) {
            if (am <= val) {
                l[0] = (l[0] + r[0]) / 2;
            } else {
                r[0] = (l[0] + r[0]) / 2;
            }
        } else {
            if (am < val) {
                l[0] = (l[0] + r[0]) / 2;
            } else {
                r[0] = (l[0] + r[0]) / 2;
            }
        }
    }

    // Comparison functions for lower and upper bounds
    static int cmp_lower(long a, long b, int type) {
        return type == 1 ? a == b ? 1 : 0 : type == 2 ? a >= b ? 1 : 0 : a > b ? 1 : 0;
    }
    static int cmp_upper(long a, long b, int type) {
        return type == 1 ? a == b ? 1 : 0 : type == 2 ? a <= b ? 1 : 0 : a < b ? 1 : 0;
    }

    // Function to find the lower bound in an array
    static long lower_bound(long[] a, int l, int r, long val, int type) {
        while (r - l > 1) {
            int m = (l + r) / 2;
            lr_lower(new int[]{l}, new int[]{r}, a[m], val, type);
        }
        return cmp_lower(a[l], val, type) ? l : cmp_lower(a[r], val, type) ? r : -1;
    }

    // Function to find the upper bound in an array
    static long upper_bound(long[] a, int l, int r, long val, int type) {
        while (r - l > 1) {
            int m = (l + r) / 2;
            lr_upper(new int[]{l}, new int[]{r}, a[m], val, type);
        }
        return cmp_upper(a[r], val, type) ? r : cmp_upper(a[l], val, type) ? l : -1;
    }

    // Function to count occurrences of a value in an array
    static long count(long[] a, int l, int r, long x) {
        int p = lower_bound(a, l, r, x, 1);
        return p == -1 ? 0 : upper_bound(a, p, r, x, 1) - p + 1;
    }

    // Global variables for factorization
    static long[][] factors = new long[2][];
    static int fac_cnt = 0, is_factor_prepared = 0;

    // Function to prepare factors for prime factorization
    static long factor_pre() {
        for (int i = 0; i < 1; i++) {
            if (is_factor_prepared++ > 0) return 0;
        }
        int tmp = (int) (1e6 / 2 + 1);
        long[] fac_tmp = new long[tmp];
        for (int i = 0; i < tmp; i++) { fac_tmp[i] = i > 0 ? 2 * i + 1 : 2; }
        for (int i = 1; i < tmp; i++) {
            if (fac_tmp[i] > 0) {
                for (int j = 3; j <= tmp / (2 * i + 1); j += 2) {
                    if (j * (2 * i + 1) < tmp) fac_tmp[(j * (2 * i + 1) - 1) / 2] = 0;
                }
            }
        }
        for (int i = 0; i < tmp; i++) {
            if (fac_tmp[i] > 0) {
                for (int j = 0; j < 2; j++) {
                    factors[j] = Arrays.copyOf(factors[j], fac_cnt + 1);
                    factors[j][j == 1 ? fac_cnt++ : fac_cnt] = j == 0 ? fac_tmp[i] : 0;
                }
            }
        }
        return 0;
    }

    // Function to factor a number and update factor counts
    static long factor(long n, long new_common_plus) {
        factor_pre();
        for (int i = 0; i < fac_cnt; i++) {
            long cnt = 0;
            for (int j = 0; j < 1; j++) {
                while ((cnt += n % factors[0][i] == 0 ? 1 : 0) > 0 && (n /= factors[0][i]) % factors[0][i] == 0) {}
            }
            factors[1][i] = new_common_plus == 1 ? cnt : new_common_plus == 2 ? Math.max(factors[1][i], cnt) : factors[1][i] + cnt;
            if (factors[0][i] > n) break;
        }
        return n;
    }

    // Function to judge if a number is prime
    static long judge_prime(long n) {
        factor_pre();
        for (int i = 0; i < fac_cnt; i++) {
            if (n < factors[0][i] * factors[0][i] || n == factors[0][i]) break;
            else if (n % factors[0][i] == 0) n /= n;
        }
        return n == 1 ? 0 : 1;
    }

    // Global variables for modular inverses and factorials
    static long[] mf_arr, inv_arr, finv_arr;
    static int is_minv_made = 0, is_mf_made = 0, num_of_inv = 2 * (int) 1e6 + 10;

    // Function to create modular inverses
    static long makeinv(long n, long mod) {
        for (int i = 0; i < 1; i++) {
            if (is_minv_made++ > 0) return 0;
        }
        inv_arr = Arrays.copyOf(inv_arr, 2);
        finv_arr = Arrays.copyOf(finv_arr, 2);
        inv_arr[1] = 1;
        finv_arr[0] = finv_arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            inv_arr = Arrays.copyOf(inv_arr, i + 1);
            finv_arr = Arrays.copyOf(finv_arr, i + 1);
            inv_arr[i] = mod - inv_arr[mod % i] * (mod / i) % mod;
            finv_arr[i] = finv_arr[i - 1] * inv_arr[i] % mod;
        }
        return 0;
    }

    // Function to create factorials
    static long make_mf(long n, long mod) {
        for (int i = 0; i < 1; i++) {
            if (is_mf_made++ > 0) return 0;
        }
        mf_arr = Arrays.copyOf(mf_arr, 2);
        long x = 1;
        mf_arr[0] = mf_arr[1] = x;
        for (int i = 2; i <= n; i++) {
            x = x * i % mod;
            mf_arr = Arrays.copyOf(mf_arr, i + 1);
            mf_arr[i] = x;
        }
        return 0;
    }

    // Function to get modular inverse based on whether it's factorial or not
    static long m_inv(long x, long mod, boolean is_fac) {
        makeinv(num_of_inv, mod);
        return is_fac ? finv_arr[x] : inv_arr[x];
    }

    // Function to get factorial modulo
    static long m_f(long x, long mod) {
        make_mf(num_of_inv, mod);
        return mf_arr[x];
    }

    // Function to calculate n choose k modulo
    static long mod_nck(long n, long k, long mod) {
        return m_f(n, mod) * m_inv(k, mod, true) % mod * m_inv(n - k, mod, true) % mod;
    }

    // Function for modular exponentiation
    static long m_p(long r, long n, long mod) {
        long t = 1, s = r;
        while (n > 0) {
            if ((n & 1) == 1) t = t * s % mod;
            s = s * s % mod;
            n >>= 1;
        }
        return r != 0 ? t : 0;
    }

    // Functions for modular multiplication
    static long m_mul2(long a, long b, long mod) { return a * b % mod; }
    static long m_mul3(long a, long b, long c, long mod) { return m_mul2(a * b % mod, c, mod); }
    static long m_mul4(long a, long b, long c, long d, long mod) { return m_mul3(a * b % mod, c, d, mod); }
    static long m_mul5(long a, long b, long c, long d, long e, long mod) { return m_mul4(a * b % mod, c, d, e, mod); }

    // Comparison functions for sorting
    static int upll(