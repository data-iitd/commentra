import java.io.*;
import java.util.*;

public class EvacuationRoute {
    static int[] a = new int[100002];
    static int[] b = new int[100002];
    static byte[] buf = new byte[700002];
    static int p = 0;

    static int getint() {
        int n = 0;
        boolean neg = false;
        if (buf[p] == '-') {
            neg = true;
            p++;
        }
        while (buf[p] >= '0' && buf[p] <= '9') {
            n = (n << 3) + (n << 1) + (buf[p++] & 0xf);
        }
        return neg ? -n : n;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int w = Integer.parseInt(tokenizer.nextToken());
        reader.read(buf);
        int ans = 0, f = 0, close, i;

        for (i = 1; i <= w; i++) {
            a[i] = getint();
            if (a[i] == 0) f |= 1;
            else if (a[i] < 0) f |= 2;
            else ans += a[i];
        }
        if (ans == 0 || !(f & 1)) {
            System.out.println(0);
            return;
        }
        if ((f & 2) == 0) {
            System.out.println(ans);
            return;
        }

        for (close = 0, f = 0, i = 1; i <= w; i++) {
            if (a[i] == 0) close = Integer.MAX_VALUE;
            else if (a[i] < 0) {
                if (f < 0 || close - (i - f) > -a[i]) close = -a[i];
                f = i;
            } else {
                if (f < 0) b[i] = Integer.MAX_VALUE;
                else {
                    int k = close - (i - f);
                    if (k < 0) k = 0;
                    b[i] = k;
                }
            }
        }

        for (close = 0, f = w, i = w; i >= 1; i--) {
            if (a[i] == 0) close = Integer.MAX_VALUE;
            else if (a[i] < 0) {
                if (f < 0 || close - (f - i) > -a[i]) close = -a[i];
                f = i;
            } else {
                if (f < 0) b[i] = Integer.MAX_VALUE;
                else {
                    int k = close - (f - i);
                    if (k < 0) k = 0;
                    if (k > b[i]) b[i] = k;
                }
            }
        }

        for (ans = 0, i = 1; i <= w; i++) {
            if (a[i] > 0) {
                if (b[i] > a[i]) ans += a[i];
                else ans += b[i];
            }
        }
        System.out.println(ans);
    }
}
