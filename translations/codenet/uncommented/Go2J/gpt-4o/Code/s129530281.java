import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader;
        if (args.length > 0) {
            reader = new BufferedReader(new FileReader(args[0]));
        } else {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(reader.readLine().trim());
        int m = Integer.parseInt(reader.readLine().trim());
        Segment seg = new Segment();
        seg.init(n);
        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            seg.maximize(i, Integer.parseInt(st.nextToken()));
        }
        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i];
        }

        writer.write(Long.toString(ans));
        writer.newLine();
        writer.flush();
    }
}

class Segment {
    int n, h, i, chunk;
    int[] unit;
    int[][] bucket;

    public void init(int n) {
        this.n = n;
        unit = new int[1];
        unit[0] = 1;
        bucket = new int[1][n];

        int chunk = 8;
        for (int i = 0; n > 1; i++) {
            n = (n - 1) / chunk + 1;
            bucket = Arrays.copyOf(bucket, bucket.length + 1);
            bucket[bucket.length - 1] = new int[n];
            unit = Arrays.copyOf(unit, unit.length + 1);
            unit[unit.length - 1] = unit[i] * chunk;
        }
        h = unit.length;
        this.chunk = chunk;
    }

    public void maximize(int index, int value) {
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

    public int top() {
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

// <END-OF-CODE>
