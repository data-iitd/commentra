
import java.util.*;
import java.io.*;

public class s422352362{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        long[] a = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = Long.parseLong(str[i - 1]);
        }
        long[] pre = new long[n + 1];
        long[] last = new long[n + 1];
        long sumpre = 0, sumlast = 0;
        for (int i = 1; i < n; i++) {
            sumpre += a[i];
            pre[i] = sumpre;
        }
        for (int i = n; i > 1; i--) {
            sumlast += a[i];
            last[i] = sumlast;
        }
        long d = (1L << 60);
        for (int i = 1; i < n; i++) {
            d = Math.min(d, Math.abs(pre[i] - last[i + 1]));
        }
        System.out.println(d);
    }
}

