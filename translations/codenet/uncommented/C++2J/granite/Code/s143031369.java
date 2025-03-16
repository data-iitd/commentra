
import java.io.*;
import java.util.*;

public class s143031369{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double[] x = new double[n];
        double[] y = new double[n];
        for (int i = 0; i < n; i++) {
            String[] split = br.readLine().split(" ");
            x[i] = Double.parseDouble(split[0]);
            y[i] = Double.parseDouble(split[1]);
        }
        double[] ans = new double[n];
        if (n == 2) {
            ans[0] = 0.5;
            ans[1] = 0.5;
        } else {
            int[] ch = new int[n];
            int m = jarvis(x, y, ch);
            if (m == 2) {
                ans[ch[0]] = 0.5;
                ans[ch[1]] = 0.5;
            } else {
                double[] ang = new double[n];
                for (int i = 0; i < m; i++) {
                    ang[ch[i]] = Math.PI - Math.acos(cos(x[ch[i]], y[ch[i]], x[ch[(i - 1 + m) % m]], y[ch[(i - 1 + m) % m]], x[ch[(i + 1) % m]], y[ch[(i + 1) % m]]));
                }
                for (int i = 0; i < n; i++) {
                    ans[i] = ang[i] / (2 * Math.PI);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.printf("%.20f\n", ans[i]);
        }
    }

    static int jarvis(double[] x, double[] y, int[] ch) {
        int n = x.length;
        int d = 0, i, o, s, l, t;
        for (i = 0; i < n; i++) {
            if (y[i] < y[d] || (y[i] == y[d] && x[i] < x[d])) {
                d = i;
            }
        }
        l = s = ch[0] = d;
        d = 1;
        do {
            o = l;
            for (i = 0; i < n; i++) {
                if ((t = sig(cross(x[o], y[o], x[l], y[l], x[i], y[i]))) > 0 || (t == 0 && btw(x[o], y[o], x[l], y[l], x[i], y[i]))) {
                    l = i;
                }
            }
            ch[d++] = l;
        } while (l!= s);
        return d - 1;
    }

    static double cross(double x1, double y1, double x2, double y2, double x3, double y3) {
        return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    }

    static double dot(double x1, double y1, double x2, double y2, double x3, double y3) {
        return (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1);
    }

    static double cos(double x1, double y1, double x2, double y2, double x3, double y3) {
        return dot(x1, y1, x2, y2, x3, y3) / Math.sqrt(dot(x1, y1, x2, y2)) / Math.sqrt(dot(x2, y2, x3, y3));
    }

    static boolean btw(double x1, double y1, double x2, double y2, double x, double y) {
        return sig(cross(x1, y1, x2, y2, x, y)) == 0 && sig(dot(x1, y1, x2, y2, x, y)) <= 0;
    }

    static int sig(double d) {
        return d < -1e-8? -1 : d > 1e-8? 1 : 0;
    }
}

