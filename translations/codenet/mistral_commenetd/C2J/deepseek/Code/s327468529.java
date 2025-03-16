import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    static final long BIG = 2000000007;
    static final long VERYBIG = 20000000000000007L;
    static final int MOD = 1000000007;
    static final int FOD = 998244353;
    static final int N_MAX = 1048576;
    static final double M_PI = 3.14159265358979323846264338327950;

    static class Hwll {
        long a;
        long b;
    }

    static class Hwllc {
        long a;
        long b;
        long c;
    }

    static class Hwreal {
        double a;
        double b;
    }

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

    static String s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());

        k = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        va = Integer.parseInt(st.nextToken());
        vb = Integer.parseInt(st.nextToken());
        vc = Integer.parseInt(st.nextToken());
        vd = Integer.parseInt(st.nextToken());

        s = br.readLine();

        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < m; i++) {
            c[i] = Integer.parseInt(br.readLine());
        }

        q = Long.parseLong(br.readLine());

        solve();
    }

    public static int solve() {
        long i, j;
        long result = 1;
        long[] cnt = new long[3];
        long pcnt = 0;

        for (i = 0; i < n * 3; i++) {
            int v;
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
                    v = -1;
                    break;
            }

            if (cnt[(v + 1) % 3] > 0 && cnt[(v + 2) % 3] > 0) {
                result *= pcnt;
                pcnt--;
                result %= FOD;
                cnt[(v + 1) % 3]--;
                cnt[(v + 2) % 3]--;
            } else {
                if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
                    result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
                    result %= FOD;
                    pcnt++;
                }
                cnt[v]++;
            }
        }

        for (i = 1; i <= n; i++) {
            result = (result * i) % FOD;
        }

        System.out.println(result);
        return 0;
    }
}
