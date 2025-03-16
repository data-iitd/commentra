
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class s680776563{
    public static void main(String[] args) throws IOException {
        FastScanner fsc = new FastScanner();
        int A = fsc.nextInt();
        int B = fsc.nextInt();
        int C = fsc.nextInt();
        System.out.println(B - A == C - B? "YES" : "NO");
    }
}

class FastScanner {
    private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private String[] buf = new String[0];
    private int ptr = 0;

    private boolean hasNextByte() {
        if (ptr < buf.length) {
            return true;
        }
        try {
            buf = br.readLine().split(" ");
            ptr = 0;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return buf.length > 0;
    }

    private int readByte() {
        if (hasNextByte()) {
            return buf[ptr++];
        } else {
            return -1;
        }
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() &&!isPrintableChar(buf[ptr])) {
            ptr++;
        }
        return hasNextByte();
    }

    public String next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (b!= 10) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
}

// Helper functions for finding the maximum and minimum values
class MathUtil {
    public static int max(int a, int b) {
        return Math.max(a, b);
    }

    public static long max(long a, long b) {
        return Math.max(a, b);
    }

    public static double max(double a, double b) {
        return Math.max(a, b);
    }

    public static int min(int a, int b) {
        return Math.min(a, b);
    }

    public static long min(long a, long b) {
        return Math.min(a, b);
    }

    public static double min(double a, double b) {
        return Math.min(a, b);
    }
}

// Helper function for finding the greatest common divisor of two integers
class MathUtil {
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

// Helper function for finding the absolute value of an integer
class MathUtil {
    public static int abs(int a) {
        return Math.abs(a);
    }

    public static long abs(long a) {
        return Math.abs(a);
    }
}

// End of code.