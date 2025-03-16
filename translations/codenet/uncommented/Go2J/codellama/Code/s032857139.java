
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // 入力を読むためのクラス
    public static class FastScanner {
        private BufferedReader br;
        private StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    // 標準出力を行うためのクラス
    public static class Printer {
        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public static void print(Object object) throws IOException {
            System.out.print(object);
        }

        public static void println(Object object) throws IOException {
            System.out.println(object);
        }

        public static void printf(String format, Object... objects) throws IOException {
            System.out.printf(format, objects);
        }

        public static String readLine() throws IOException {
            return br.readLine();
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner();
        Printer printer = new Printer();

        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        Arrays.sort(A);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        if (ans == n && x > 0) {
            ans--;
        }
        printer.println(ans);
    }
}

