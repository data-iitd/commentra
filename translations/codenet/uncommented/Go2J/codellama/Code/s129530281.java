
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        OutputStreamWriter osw = new OutputStreamWriter(System.out);
        PrintWriter pw = new PrintWriter(osw);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Segment seg = new Segment();
        seg.init(n);
        for (int i = 0; i < n; i++) {
            seg.maximize(i, Integer.parseInt(br.readLine()));
        }
        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i];
        }

        pw.println(ans);
        pw.flush();
    }

    static class Segment {
        int n, h, i, chunk;
        int[] unit;
        int[][] bucket;

        public void init(int n) {
            this.n = n;
            unit = new int[1];
            unit[0] = 1;
            bucket = new int[1][n];

            chunk = 8;
            for (int i = 0; n > 1; i++) {
                n = (n-1)/chunk + 1;
                bucket = append(bucket, new int[n]);
                unit = append(unit, unit[i]*chunk);
            }
            h = unit.length;
        }

        public void maximize(int index, int value) {
            bucket[0][index] = value;
            for (i = 0; i < h-1; i++) {
                int s = index - index%chunk;
                int t = s + chunk;
                if (t > bucket[i].length) {
                    t = bucket[i].length;
                }
                int parent = index / chunk;
                int max = 0;
                for (int i = s; i < t; i++) {
                    if (max < bucket[i][i]) {
                        max = bucket[i][i];
                    }
                }
                bucket[i+1][parent] = max;
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
                for (int i = s; i < t; i++) {
                    if (bucket[i][i] == bucket[i+1][index]) {
                        index = i;
                        break;
                    }
                }
            }

            return index;
        }

        public int[][] append(int[][] arr, int[] newArr) {
            int[][] newArr2 = new int[arr.length+1][];
            for (int i = 0; i < arr.length; i++) {
                newArr2[i] = arr[i];
            }
            newArr2[arr.length] = newArr;
            return newArr2;
        }

        public int[] append(int[] arr, int newElem) {
            int[] newArr = new int[arr.length+1];
            for (int i = 0; i < arr.length; i++) {
                newArr[i] = arr[i];
            }
            newArr[arr.length] = newElem;
            return newArr;
        }
    }
}

