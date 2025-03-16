
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = reader.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        Segment seg = new Segment();
        seg.init(n);

        for (int i = 0; i < n; i++) {
            seg.maximize(i, Integer.parseInt(reader.readLine()));
        }

        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i];
        }

        System.out.println(ans);
    }
}

class Segment {
    int n, h, i, chunk;
    int[] unit;
    List<List<Integer>> bucket;

    public void init(int n) {
        this.n = n;
        this.unit = new int[1];
        this.unit[0] = 1;
        this.bucket = new ArrayList<>();
        this.bucket.add(new ArrayList<>());

        int chunk = 8;
        for (int i = 0; n > 1; i++) {
            n = (n - 1) / chunk + 1;
            this.bucket.add(new ArrayList<>());
            this.unit = new int[this.unit.length + 1];
            this.unit[i + 1] = this.unit[i] * chunk;
        }
        this.h = this.unit.length;
        this.chunk = chunk;
    }

    public void maximize(int index, int value) {
        this.bucket.get(0).set(index, value);
        for (this.i = 0; this.i < this.h - 1; this.i++) {
            int s = index - index % this.chunk;
            int t = s + this.chunk;
            if (t > this.bucket.get(this.i).size()) {
                t = this.bucket.get(this.i).size();
            }
            int parent = index / this.chunk;
            int max = 0;
            for (int i = s; i < t; i++) {
                if (max < this.bucket.get(this.i).get(i)) {
                    max = this.bucket.get(this.i).get(i);
                }
            }
            this.bucket.get(this.i + 1).set(parent, max);
            index /= this.chunk;
        }
    }

    public int top() {
        int index = 0;
        for (this.i = this.h - 2; this.i >= 0; this.i--) {
            int s = index * this.chunk;
            int t = s + this.chunk;
            if (t > this.bucket.get(this.i).size()) {
                t = this.bucket.get(this.i).size();
            }
            for (int i = s; i < t; i++) {
                if (this.bucket.get(this.i).get(i) == this.bucket.get(this.i + 1).get(index)) {
                    index = i;
                    break;
                }
            }
        }

        return index;
    }
}

