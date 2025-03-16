
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int A = sc.nextInt();
        int B = sc.nextInt();

        int mx = Math.max(A + B, A - B);
        mx = Math.max(mx, A * B);
        System.out.println(mx);
    }

    static class Scanner {
        BufferedReader r;
        String[] buf = new String[1000];
        int p = 0;

        Scanner() {
            r = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            pre();
            int start = p;
            while (p < buf.length && buf[p] != ' ') {
                p++;
            }
            String result = buf[start] + new String(buf, start + 1, p - start - 1);
            p++;
            return result;
        }

        String nextLine() {
            pre();
            int start = p;
            p = buf.length;
            return new String(buf, start, p - start);
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int nextIntArray() {
            pre();
            int start = p;
            int[] result = new int[1000];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i++] = Integer.parseInt(new String(buf, start, p - start));
                start = p + 1;
                p++;
            }
            return result[0];
        }

        int[] nextIntArray(int n) {
            pre();
            int start = p;
            int[] result = new int[n];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i++] = Integer.parseInt(new String(buf, start, p - start));
                start = p + 1;
                p++;
            }
            return result;
        }

        int[][] nextIntArray(int n, int m) {
            pre();
            int start = p;
            int[][] result = new int[n][m];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i] = nextIntArray(m);
                i++;
            }
            return result;
        }

        int[][][] nextIntArray(int n, int m, int l) {
            pre();
            int start = p;
            int[][][] result = new int[n][m][l];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i] = nextIntArray(m, l);
                i++;
            }
            return result;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long nextLongArray() {
            pre();
            int start = p;
            long[] result = new long[1000];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i++] = Long.parseLong(new String(buf, start, p - start));
                start = p + 1;
                p++;
            }
            return result[0];
        }

        long[] nextLongArray(int n) {
            pre();
            int start = p;
            long[] result = new long[n];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i++] = Long.parseLong(new String(buf, start, p - start));
                start = p + 1;
                p++;
            }
            return result;
        }

        long[][] nextLongArray(int n, int m) {
            pre();
            int start = p;
            long[][] result = new long[n][m];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i] = nextLongArray(m);
                i++;
            }
            return result;
        }

        long[][][] nextLongArray(int n, int m, int l) {
            pre();
            int start = p;
            long[][][] result = new long[n][m][l];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i] = nextLongArray(m, l);
                i++;
            }
            return result;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray() {
            pre();
            int start = p;
            double[] result = new double[1000];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i++] = Double.parseDouble(new String(buf, start, p - start));
                start = p + 1;
                p++;
            }
            return result;
        }

        double[] nextDoubleArray(int n) {
            pre();
            int start = p;
            double[] result = new double[n];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i++] = Double.parseDouble(new String(buf, start, p - start));
                start = p + 1;
                p++;
            }
            return result;
        }

        double[][] nextDoubleArray(int n, int m) {
            pre();
            int start = p;
            double[][] result = new double[n][m];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i] = nextDoubleArray(m);
                i++;
            }
            return result;
        }

        double[][][] nextDoubleArray(int n, int m, int l) {
            pre();
            int start = p;
            double[][][] result = new double[n][m][l];
            int i = 0;
            while (p < buf.length && buf[p] != ' ') {
                result[i] = nextDoubleArray(m, l);
                i++;
            }
            return result;
        }

        String nextString() {
            pre();
            int start = p;
            while (p < buf.length && buf[p] != ' ') {
                p++;
            }
            return new String(buf, start, p - start);
        }

        String[] nextStringArray() {
            pre();
            int start = p;
            List<String> result = new ArrayList<>();
            while (p < buf.length && buf[p] != ' ') {
                result.add(nextString());
            }
            return result.toArray(new String[0]);
        }

        String[] nextStringArray(int n) {
            pre();
            int start = p;
            String[] result = new String[n];
            for (int i = 0; i < n; i++) {
                result[i] = nextString();
            }
            return result;
        }

        String[][] nextStringArray(int n, int m) {
            pre();
            int start = p;
            String[][] result = new String[n][m];
            for (int i = 0; i < n; i++) {
                result[i] = nextStringArray(m);
            }
            return result;
        }

        String[][][] nextStringArray(int n, int m, int l) {
            pre();
            int start = p;
            String[][][] result = new String[n][m][l];
            for (int i = 0; i < n; i++) {
                result[i] = nextStringArray(m, l);
            }
            return result;
        }

        void pre() {
            if (p >= buf.length) {
                readLine();
                p = 0;
            }
        }

        void readLine() {
            buf = new String(new char[1000]).toCharArray();
            try {
                int n = r.read(buf);
                while (n < buf.length) {
                    int m = r.read(buf, n, buf.length - n);
                    if (m < 0) {
                        break;
                    }
                    n += m;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}

