
/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//String.format("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//String str = ReadString();
//int i = ReadInt();
//int[] X = ReadIntSlice(n);
//char[] S = ReadruneSlice();
//double d = ReadDouble();
//double[] A = ReadDoubleSlice(n);

//String str = ZeroPaddingRuneSlice(num, 32);
//str = PrintIntsLine(X...);

/*******************************************************************/

public class s040219730{
    final static long MOD = 1000000000L + 7;
    final static int ALPHABET_NUM = 26;
    final static int INF = Integer.MAX_VALUE / 2;
    final static long LNF = Long.MAX_VALUE / 2;
    final static int NIL = -1;

    // for dijkstra, prim, and so on
    final static int WHITE = 0;
    final static int GRAY  = 1;
    final static int BLACK = 2;

    static {
        // bufio.ScanWords <---> bufio.ScanLines
        ReadString = new ReadString(System.in, bufio.ScanWords);
        stdout = new PrintWriter(System.out);
    }

    static int n, q;
    static int[] C;
    static Query[] Q;

    static int[] P;
    static int[] Answers;

    static class Query {
        int idx, l, r;
        Query(int idx, int l, int r) {
            this.idx = idx;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) throws Exception {
        // Read input
        n = ReadInt();
        q = ReadInt();
        C = ReadIntSlice(n);

        // Initialize P array and Fenwick Tree
        P = new int[500000 + 50];
        Arrays.fill(P, NIL);

        // Process queries
        Q = new Query[q];
        for (int i = 0; i < q; i++) {
            int l = ReadInt();
            int r = ReadInt();
            Q[i] = new Query(i, l, r);
        }
        Arrays.sort(Q, (q1, q2) -> q1.r - q2.r);
        FenwickTree ft = new FenwickTree(500000 + 50);

        int k = 0;
        for (Query query : Q) {
            // Process each query
            for (; k < query.r; k++) {
                if (P[C[k]]!= NIL) {
                    ft.add(P[C[k]] + 1, -1);
                }
                P[C[k]] = k;
                ft.add(k + 1, 1);
            }

            // Calculate answer and print it
            Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
        }

        // Print answers
        for (int i = 0; i < q; i++) {
            stdout.println(Answers[i]);
        }
        stdout.flush();
    }

    // Public methods
    // ft := NewFenwickTree(200000 + 5)
    // int s = ft.sum(i); 						// Sum of [1, i](1-based)
    // ft.add(i, x); 							// Add x to i(1-based)
    // int idx = ft.lowerBound(w); 		// minimum idx such that bit.sum(idx) >= w

    static class FenwickTree {
        int[] dat;
        int n;
        int minPow2;

        FenwickTree(int n) {
            this.dat = new int[n + 1];
            this.n = n;

            minPow2 = 1;
            while ((minPow2 << 1) <= n) {
                minPow2 <<= 1;
            }
        }

        // Sum of [1, i](1-based)
        int sum(int i) {
            int s = 0;
            for (; i > 0; i -= i & (-i)) {
                s += dat[i];
            }
            return s;
        }

        // Add x to i(1-based)
        void add(int i, int x) {
            for (; i <= n; i += i & (-i)) {
                dat[i] += x;
            }
        }

        // LowerBound returns minimum i such that bit.sum(i) >= w.
        int lowerBound(int w) {
            if (w <= 0) {
                return 0;
            }

            int x = 0;
            for (int k = minPow2; k > 0; k >>= 1) {
                if (x + k <= n && dat[x + k] < w) {
                    w -= dat[x + k];
                    x += k;
                }
            }

            return x + 1;
        }
    }
}