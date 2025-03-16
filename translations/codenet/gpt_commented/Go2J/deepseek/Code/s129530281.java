import java.io.*;
import java.util.*;

public class Main {
    static class Scanner {
        private BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
            st = new StringTokenizer("");
        }

        public Scanner(String path) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(path));
            st = new StringTokenizer("");
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
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
    }

    static class SegmentTree {
        private int n, h;
        private int[] unit;
        private int[][] bucket;

        public void init(int n) {
            this.n = n;
            unit = new int[1];
            unit[0] = 1;
            bucket = new int[1][];
            bucket[0] = new int[n];

            int chunk = 8;
            for (int i = 0; n > 1; i++) {
                n = (n - 1) / chunk + 1;
                bucket = Arrays.copyOf(bucket, bucket.length + 1);
                bucket[bucket.length - 1] = new int[n];
                unit = Arrays.copyOf(unit, unit.length + 1);
                unit[unit.length - 1] = unit[i] * chunk;
            }
            h = unit.length;
        }

        public void maximize(int index, int value) {
            bucket[0][index] = value;
            for (int i = 0; i < h - 1; i++) {
                int s = index - index % unit[i];
                int t = s + unit[i];
                if (t > bucket[i].length) {
                    t = bucket[i].length;
                }
                int parent = index / unit[i];
                int max = 0;
                for (int j = s; j < t; j++) {
                    if (max < bucket[i][j]) {
                        max = bucket[i][j];
                    }
                }
                bucket[i + 1][parent] = max;
                index /= unit[i];
            }
        }

        public int top() {
            int index = 0;
            for (int i = h - 2; i >= 0; i--) {
                int s = index * unit[i];
                int t = s + unit[i];
                if (t > bucket[i].length) {
                    t = bucket[i].length;
                }
                for (int j = s; j < t; j++) {
                    if (bucket[i][j] == bucket[i + 1][index]) {
                        index = j;
                        break;
                    }
                }
            }
            return index;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        SegmentTree seg = new SegmentTree();
        seg.init(n);

        for (int i = 0; i < n; i++) {
            seg.maximize(i, scanner.nextInt());
        }

        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i];
        }

        writer.println(ans);
        writer.flush();
    }
}
