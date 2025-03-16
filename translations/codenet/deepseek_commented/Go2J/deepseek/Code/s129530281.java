import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
    }

    static class SegmentTree {
        int n, h;
        int[] unit;
        int[][] bucket;

        void init(int n) {
            this.n = n;
            unit = new int[1];
            unit[0] = 1;
            bucket = new int[1][n];

            int chunk = 8;
            for (int i = 0; n > 1; i++) {
                n = (n - 1) / chunk + 1;
                bucket = Arrays.copyOf(bucket, bucket.length + 1);
                bucket[i + 1] = new int[n];
                unit = Arrays.copyOf(unit, unit.length + 1);
                unit[i + 1] = unit[i] * chunk;
            }
            h = unit.length;
        }

        void maximize(int index, int value) {
            bucket[0][index] = value;
            for (int i = 0; i < h - 1; i++) {
                int s = index - index % 8;
                int t = s + 8;
                if (t > bucket[i].length) {
                    t = bucket[i].length;
                }
                int parent = index / 8;
                int max = 0;
                for (int j = s; j < t; j++) {
                    if (max < bucket[i][j]) {
                        max = bucket[i][j];
                    }
                }
                bucket[i + 1][parent] = max;
                index /= 8;
            }
        }

        int top() {
            int index = 0;
            for (int i = h - 2; i >= 0; i--) {
                int s = index * 8;
                int t = s + 8;
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

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
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
