public class Main {
    public static void main(String[] args) {
        FastScanner fsc = new FastScanner();
        int A = fsc.nextInt();
        int B = fsc.nextInt();
        int C = fsc.nextInt();
        if (B - A == C - B) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

class FastScanner {
    private java.io.BufferedReader br;
    private java.io.StringReader sr;
    private char[] buf = new char[1024];
    private int p = 0;

    public FastScanner() {
        br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
    }

    public String next() {
        pre();
        int start = p;
        while (p < buf.length && buf[p] != ' ') {
            p++;
        }
        String result = new String(buf, start, p - start);
        p++;
        return result;
    }

    public String nextLine() {
        pre();
        int start = p;
        while (p < buf.length && buf[p] != '\n') {
            p++;
        }
        String result = new String(buf, start, p - start);
        p++;
        return result;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    private void pre() {
        if (p >= buf.length) {
            try {
                br.read(buf, 0, buf.length);
            } catch (java.io.IOException e) {
                e.printStackTrace();
            }
            p = 0;
        }
    }
}

//Max,Min
class MathUtils {
    public static int max(int a, int b) {
        return a > b ? a : b;
    }

    public static long max(long a, long b) {
        return a > b ? a : b;
    }

    public static double max(double a, double b) {
        return a > b ? a : b;
    }

    public static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static long min(long a, long b) {
        return a < b ? a : b;
    }

    public static double min(double a, double b) {
        return a < b ? a : b;
    }
}

//Gcd
class GcdUtils {
    public static int gcd(int a, int b) {
        if (b > a) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static long gcd(long a, long b) {
        if (b > a) {
            long temp = a;
            a = b;
            b = temp;
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

//Abs
class AbsUtils {
    public static int abs(int a) {
        return a < 0 ? -a : a;
    }

    public static long abs(long a) {
        return a < 0 ? -a : a;
    }
}
