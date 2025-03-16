import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int A = sc.nextInt();
        int B = sc.nextInt();

        int mx = Math.max(A + B, A - B);
        mx = Math.max(mx, A * B);
        System.out.println(mx);
    }

    static class Scanner {
        BufferedReader r;
        StringTokenizer st;

        Scanner() {
            r = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(r.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        String nextLine() throws IOException {
            return r.readLine();
        }

        int[] nextIntArray() throws IOException {
            String[] strArr = next().split(" ");
            int[] intArr = new int[strArr.length];
            for (int i = 0; i < strArr.length; i++) {
                intArr[i] = Integer.parseInt(strArr[i]);
            }
            return intArr;
        }

        long[] nextLongArray() throws IOException {
            String[] strArr = next().split(" ");
            long[] longArr = new long[strArr.length];
            for (int i = 0; i < strArr.length; i++) {
                longArr[i] = Long.parseLong(strArr[i]);
            }
            return longArr;
        }
    }
}
