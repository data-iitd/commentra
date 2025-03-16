import java.util.*;
import java.io.*;

public class Main {
    static final long BIG = 2000000007;
    static final long VERYBIG = 20000000000000007L;
    static final long MOD = 1000000007;
    static final long FOD = 998244353;
    static final int N_MAX = 1048576;

    static long n, m;
    static long h, w;
    static long k;
    static long q;
    static long va, vb, vc, vd, ve, vf;
    static long[] cnt = new long[3];
    static long pcnt;
    static long[][] x = new long[3005][3005];
    static String s = "";

    static long solve() {
        long result = 1;

        for (int i = 0; i < n * 3; i++) {
            long v;
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
                default:
                    continue;
            }

            if (cnt[(int) ((v + 1) % 3)] > 0 && cnt[(int) ((v + 2) % 3)] > 0) {
                result *= pcnt;
                pcnt--;
                result %= FOD;
                cnt[(int) ((v + 1) % 3)]--;
                cnt[(int) ((v + 2) % 3)]--;
            } else {
                if ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) > cnt[(int) v]) {
                    result *= (cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) - cnt[(int) v];
                    result %= FOD;
                    pcnt++;
                }
                cnt[(int) v]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            result = (result * i) % FOD;
        }

        System.out.println(result);
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Long.parseLong(st.nextToken());
        m = Long.parseLong(st.nextToken());

        s = br.readLine();

        solve();
    }
}

// <END-OF-CODE>
