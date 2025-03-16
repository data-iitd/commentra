import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        Segment seg = new Segment(n);
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            seg.maximize(i, Integer.parseInt(tokenizer.nextToken()));
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

class Segment {
    int n, h, chunk;
    int[] unit;
    int[][] bucket;

    public Segment(int n) {
        this.n = n;
        this.unit = new int[1];
        this.unit[0] = 1;
        this.bucket = new int[1][n];

        int chunk = 8;
        for (int i = 0; n > 1; i++) {
            n = (n - 1) / chunk + 1;
            this.bucket = Arrays.copyOf(this.bucket, this.bucket.length + 1);
            this.bucket[i + 1] = new int[n];
            this.unit = Arrays.copyOf(this.unit, this.unit.length + 1);
            this.unit[i + 1] = this.unit[i] * chunk;
        }
        this.h = this.unit.length;
        this.chunk = chunk;
    }

    public void maximize(int index, int value) {
        this.bucket[0][index] = value;

        for (int i = 0; i < this.h - 1; i++) {
            int s = index - index % this.chunk;
            int t = s + this.chunk;
            if (t > this.bucket[i].length) {
                t = this.bucket[i].length;
            }
            int parent = index / this.chunk;
            int max = 0;
            for (int j = s; j < t; j++) {
                if (max < this.bucket[i][j]) {
                    max = this.bucket[i][j];
                }
            }
            this.bucket[i + 1][parent] = max;
            index /= this.chunk;
        }
    }

    public int top() {
        int index = 0;
        for (int i = this.h - 2; i >= 0; i--) {
            int s = index * this.chunk;
            int t = s + this.chunk;
            if (t > this.bucket[i].length) {
                t = this.bucket[i].length;
            }
            for (int j = s; j < t; j++) {
                if (this.bucket[i][j] == this.bucket[i + 1][index]) {
                    index = j;
                    break;
                }
            }
        }
        return index;
    }
}
