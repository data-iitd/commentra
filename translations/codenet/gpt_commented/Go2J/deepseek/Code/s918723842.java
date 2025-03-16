import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();

        int A = Math.max(H, W);
        System.out.println((N + A - 1) / A);
    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public int[] nextIntArray() throws IOException {
            String[] strArr = nextLine().split(" ");
            int[] intArr = new int[strArr.length];
            for (int i = 0; i < strArr.length; i++) {
                intArr[i] = Integer.parseInt(strArr[i]);
            }
            return intArr;
        }

        public long[] nextLongArray() throws IOException {
            String[] strArr = nextLine().split(" ");
            long[] longArr = new long[strArr.length];
            for (int i = 0; i < strArr.length; i++) {
                longArr[i] = Long.parseLong(strArr[i]);
            }
            return longArr;
        }

        public double[] nextDoubleArray() throws IOException {
            String[] strArr = nextLine().split(" ");
            double[] doubleArr = new double[strArr.length];
            for (int i = 0; i < strArr.length; i++) {
                doubleArr[i] = Double.parseDouble(strArr[i]);
            }
            return doubleArr;
        }
    }
}
