import java.io.*;
import java.util.*;

public class Main {
    static int[] a = new int[100002];
    static int[] b = new int[100002];
    static byte[] buf = new byte[700002];
    static int p = 0;

    static int getint() throws IOException {
        int n = 0;
        boolean isNegative = false;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        if (c == '-') {
            isNegative = true;
            c = read();
        }
        while (c >= '0') {
            n = (n << 3) + (n << 1) + (c & 0xf);
            c = read();
        }
        return isNegative ? -n : n;
    }

    static byte read() throws IOException {
        if (p == buf.length) {
            p = 0;
            System.in.read(buf);
        }
        return buf[p++];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int w = Integer.parseInt(tokenizer.nextToken());

        String line = reader.readLine();
        StringTokenizer tokenizer2 = new StringTokenizer(line);
        int ans = 0, f = 0, close = 0;

        for (int i = 1; i <= w; i++) {
            int k = getint();
            if (k == 0) {
                f |= 1;
                continue;
            }
            if (k < 0) {
                if (f < 0 || close - (i - f) > -k) close = -k;
                if (f < 0) f = -2;
            }
            ans += k;
        }

        if (ans == 0 || (f & 1) == 0) {
            System.out.println("0");
            return;
        }

        if ((f & 2) == 0) {
            System.out.println(ans);
            return;
        }

        Arrays.fill(b, Integer.MAX_VALUE);
        close = Integer.MAX_VALUE;
        f = -1;

        for (int i = w; i >= 1; i--) {
            if (a[i] == 0) {
                close = Integer.MAX_VALUE;
                f = -1;
                continue;
            }
            if (a[i] < 0) {
                if (f < 0 || close - (f - i) > -a[i]) close = -a[i];
                f = i;
            } else {
                if (f >= 0) {
                    int k = close - (f - i);
                    if (k < 0) k = 0;
                    b[i] = k;
                }
            }
        }

        close = 0;
        f = w;

        for (int i = 1; i <= w; i++) {
            if (a[i] > 0) {
                if (b[i] > a[i]) ans += a[i];
                else ans += b[i];
            }
        }

        System.out.println(ans);
    }
}
