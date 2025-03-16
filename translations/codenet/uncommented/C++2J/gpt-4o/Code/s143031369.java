import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final double PI = Math.acos(-1.0);
    static final int MAX_POINTS = 110;
    static Point[] P = new Point[MAX_POINTS];
    static int[] ch = new int[MAX_POINTS];
    static double[] ang = new double[MAX_POINTS];
    static double[] ans = new double[MAX_POINTS];

    static int sig(double d) {
        return Math.abs(d) < 1e-8 ? 0 : d < 0 ? -1 : 1;
    }

    static class Point {
        double x, y;

        Point() {}

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        void set(double x, double y) {
            this.x = x;
            this.y = y;
        }

        double mod() {
            return Math.sqrt(x * x + y * y);
        }

        double modPow() {
            return x * x + y * y;
        }

        void output() {
            System.out.printf("x = %f, y = %f\n", x, y);
        }

        public int compareTo(Point p) {
            return sig(x - p.x) != 0 ? (x < p.x ? -1 : 1) : sig(y - p.y);
        }
    }

    static double dot(Point o, Point a, Point b) {
        return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    static double cross(Point o, Point a, Point b) {
        return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
    }

    static int btw(Point x, Point a, Point b) {
        return sig(dot(x, a, b));
    }

    static double dis(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    static double cos(Point o, Point a, Point b) {
        return dot(o, a, b) / dis(o, a) / dis(o, b);
    }

    static int jarvis(Point[] p, int n, int[] ch) {
        int d, i, o, s, l, t;
        d = 0;
        for (i = 0; i < n; i++) {
            if (p[i].compareTo(p[d]) < 0) {
                d = i;
            }
        }
        l = s = ch[0] = d;
        d = 1;
        do {
            o = l;
            for (i = 0; i < n; i++) {
                t = sig(cross(p[o], p[l], p[i]));
                if (t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0)) {
                    l = i;
                }
            }
            ch[d++] = l;
        } while (l != s);
        return d - 1;
    }

    public static void main(String[] args) {
        Arrays.fill(ang, 0);
        Arrays.fill(ans, 0);
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int xx = scanner.nextInt();
            int yy = scanner.nextInt();
            P[i] = new Point(xx, yy);
        }
        if (n == 2) {
            System.out.println("0.5");
            System.out.println("0.5");
        } else {
            int m = jarvis(P, n, ch);
            double sum = 0;
            if (m == 2) {
                ans[ch[0]] = 0.5;
                ans[ch[1]] = 0.5;
            } else {
                for (int i = 0; i < m; i++) {
                    ang[ch[i]] = PI - Math.acos(cos(P[ch[i]], P[ch[(i - 1 + m) % m]], P[ch[(i + 1) % m]]));
                }
                for (int i = 0; i < n; i++) {
                    ans[i] = ang[i] / 2.0 / PI;
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.printf("%.20f\n", ans[i]);
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
