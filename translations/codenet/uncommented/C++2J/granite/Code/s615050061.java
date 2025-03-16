
import java.io.*;
import java.util.*;

public class s615050061{
    static final long B = 13131;
    static final int N = 500000 + 7;

    static int n;
    static char[] s = new char[N];
    static long[] f = new long[N];
    static int[] g = new int[N];
    static Map<Long, Long> map = new HashMap<>();
    static long cnt;

    static long pow(long a, long k) {
        if (k < 0) k += (1L << 63) - 1;
        long t = 1;
        for (; k > 0; a = a * a, k >>= 1)
            if ((k & 1) == 1) t = t * a;
        return t;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        br.read(s, 1, n);
        for (int i = 1; i <= n; ++i)
            if (s[i] == '+' || s[i] == '-')
                f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1]);
            else
                f[i] = f[i - 1], g[i] = g[i - 1] + (s[i] == '<'? -1 : 1);
        for (int i = n; i > 0; --i)
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1);
        for (int i = 1; i <= n; ++i)
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L);
        bw.write(cnt + "\n");

        bw.flush();
    }
}

