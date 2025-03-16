import java.io.*;
import java.util.*;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
        }
    }

    public static void main(String[] args) throws IOException {
        FastReader fr = new FastReader();
        FastWriter fw = new FastWriter();
        int N = fr.nextInt();
        long[] T = new long[N];
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            T[i] = fr.nextLong();
            A[i] = fr.nextLong();
        }
        long t = T[0];
        long a = A[0];
        for (int i = 1; i < N; i++) {
            long r = Math.max((t + T[i] - 1) / T[i], (a + A[i] - 1) / A[i]);
            t = T[i] * r;
            a = A[i] * r;
        }
        fw.println(t + a);
        fw.close();
    }
}
