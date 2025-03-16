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
    private char[] buf;
    private int p;

    public FastScanner() {
        br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in), 1024);
        buf = new char[1024];
        p = 0;
    }

    public String next() {
        pre();
        int start = p;
        while (p < buf.length && buf[p] != ' ' && buf[p] != '\n') {
            p++;
        }
        String result = new String(buf, start, p - start);
        p++;
        return result;
    }

    public String nextLine() {
        pre();
        int start = p;
        while (p < buf.length && (buf[p] != '\n')) {
            p++;
        }
        String result = new String(buf, start, p - start);
        p++;
        return result;
    }

    public int nextInt() {
        return Integer.parseInt(next());
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

class HelperFunctions {
    public static int IntMax(int a, int b) {
        return a < b ? b : a;
    }

    public static long Int64Max(long a, long b) {
        return a < b ? b : a;
    }

    public static double Float64Max(double a, double b) {
        return a < b ? b : a;
    }

    public static int IntMin(int a, int b) {
        return a > b ? b : a;
    }

    public static long Int64Min(long a, long b) {
        return a > b ? b : a;
    }

    public static double Float64Min(double a, double b) {
        return a > b ? b : a;
    }

    public static int IntGcd(int a, int b) {
        return b == 0 ? a : IntGcd(b, a % b);
    }

    public static long Int64Gcd(long a, long b) {
        return b == 0 ? a : Int64Gcd(b, a % b);
    }

    public static int IntAbs(int a) {
        return a < 0 ? -a : a;
    }

    public static long Int64Abs(long a) {
        return a < 0 ? -a : a;
    }
}
