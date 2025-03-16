import java.util.Scanner;

public class Main {
    // Constants and macro definitions
    private static final long BIG = 2000000007;
    private static final long VERYBIG = 20000000000000007L;
    private static final long MOD = 1000000007;
    private static final long FOD = 998244353;
    private static final int N_MAX = 1048576;

    // Variable declarations
    static long n, m;
    static long h, w;
    static long k;
    static long q;
    static long va, vb, vc, vd, ve, vf;
    static long ua, ub, uc, ud, ue, uf;
    static double vra, vrb, vrc;
    static double vda, vdb, vdc;
    static char ch, dh;
    static long[] a = new long[N_MAX];
    static long[] b = new long[N_MAX];
    static long[] c = new long[N_MAX];
    static long[] d = new long[N_MAX];
    static long[] cnt = new long[3]; // Assuming cnt is needed based on the logic
    static String s;

    // Main function implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize variables
        n = 4;
        m = 0;

        // Read input values
        s = scanner.next();

        // Initialize arrays
        for (int i = 0; i < N_MAX; i++) {
            a[i] = 0;
            b[i] = 0;
            c[i] = 0;
        }

        // Read input values
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextLong();
        }

        // Read input values
        for (int i = 0; i < m; i++) {
            c[i] = scanner.nextLong();
        }

        // Read input value
        q = scanner.nextLong();

        // Call the solve function
        solve();

        // Close the scanner
        scanner.close();
    }

    // Solve function implementation
    public static void solve() {
        long result = 1;
        long pcnt = 0;

        for (int i = 0; i < n * 3; i++) {
            long v = 0;
            switch (s.charAt(i)) {
                case 'R':
                    v = 0;
                    break;
                case 'G':
                    v = 1;
                    break;
                case 'B':
                    v = 2;
                    break;
            }

            if (cnt[(int) ((v + 1) % 3)] > 0 && cnt[(int) ((v + 2) % 3)] > 0) {
                result = (result * pcnt) % FOD;
                pcnt--;
                cnt[(int) ((v + 1) % 3)]--;
                cnt[(int) ((v + 2) % 3)]--;
            } else {
                if ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) > cnt[(int) v]) {
                    result = (result * ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) - cnt[(int) v])) % FOD;
                    pcnt++;
                }
                cnt[(int) v]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            result = (result * i) % FOD;
        }

        System.out.println(result);
    }
}

// <END-OF-CODE>
