
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s129530281{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        Segment seg = new Segment();
        seg.init(n);
        for (int i = 0; i < n; i++) {
            seg.maximize(i, Integer.parseInt(br.readLine()));
        }
        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i];
        }

        out.println(ans);
        out.flush();
    }

    // Segment...
    static class Segment {
        int n, h, i, chunk;
        int[] unit;
        int[][] bucket;

        void init(int n) {
            this.n = n;
            unit = new int[1];
            unit[0] = 1;
            bucket = new int[1][];
            bucket[0] = new int[n];

            chunk = 8;
            for (i = 0; n > 1; i++) {
                n = (n - 1) / chunk + 1;
                bucket = Arrays.copyOf(bucket, i + 2);
                bucket[i + 1] = new int[n];
                unit = Arrays.copyOf(unit, i + 2);
                unit[i + 1] = unit[i] * chunk;
            }
            h = unit.length;
        }

        void maximize(int index, int value) {
            bucket[0][index] = value;
            for (i = 0; i < h - 1; i++) {
                int s = index - index % chunk;
                int t = s + chunk;
                if (t > bucket[i].length) {
                    t = bucket[i].length;
                }
                int parent = index / chunk;
                int max = 0;
                for (int j = s; j < t; j++) {
                    if (max < bucket[i][j]) {
                        max = bucket[i][j];
                    }
                }
                bucket[i + 1][parent] = max;
                index /= chunk;
            }
        }

        int top() {
            int index = 0;
            for (i = h - 2; i >= 0; i--) {
                int s = index * chunk;
                int t = s + chunk;
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
}

// END-OF-CODE