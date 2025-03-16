
/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

package main;

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString();
//i := ReadInt();
//X := ReadIntSlice(n);
//S := ReadruneSlice();
//a := ReadFloat64();
//A := ReadFloat64Slice(n);

//str := ZeroPaddingRuneSlice(num, 32);
//str := PrintIntsLine(X...);

/*******************************************************************/

final class Const {
	// General purpose
	public static final int MOD = 1000000000 + 7;
	// MOD          = 998244353
	public static final int ALPHABET_NUM = 26;
	public static final long INF_LONG = 1L << 60;
	public static final int INF_INT = 1000000000;
	public static final long INF_LONG_ADD = 1L << 50;
	public static final int INF_INT_ADD = 1000000000;
	public static final int NIL = -1;

	// for dijkstra, prim, and so on
	public static final int WHITE = 0;
	public static final int GRAY  = 1;
	public static final int BLACK = 2;
}

public class s040219730{
	public static void main(String[] args) throws Exception {
		MyScanner sc = new MyScanner();
		PrintStream out = System.out;
		final int MOD = Const.MOD;

		int n = sc.nextInt();
		int q = sc.nextInt();
		int[] C = new int[n];
		for (int i = 0; i < n; i++) {
			C[i] = sc.nextInt();
		}

		int[] P = new int[n + 1];
		Arrays.fill(P, -1);

		int[] Answers = new int[q];
		FenwickTree ft = new FenwickTree(n + 1);

		for (int i = 0; i < q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			for (int j = l; j < r; j++) {
				if (P[C[j - 1]]!= -1) {
					ft.add(P[C[j - 1]] + 1, -1);
				}
				P[C[j - 1]] = j - 1;
				ft.add(j, 1);
			}
			Answers[i] = ft.sum(r) - ft.sum(l - 1);
		}

		for (int i = 0; i < q; i++) {
			out.println(Answers[i]);
		}
	}
}

class FenwickTree {
	private int[] data;
	private int n;
	private int minPow2;

	public FenwickTree(int n) {
		this.n = n;
		data = new int[n + 1];
		minPow2 = 1;
		while (minPow2 < n) {
			minPow2 *= 2;
		}
	}

	public int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += data[i];
			i -= i & (-i);
		}
		return s;
	}

	public void add(int i, int x) {
		while (i <= n) {
			data[i] += x;
			i += i & (-i);
		}
	}

	public int lowerBound(int w) {
		if (w <= 0) {
			return 0;
		}
		int x = 0;
		for (int k = minPow2; k > 0; k /= 2) {
			if (x + k <= n && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x + 1;
	}
}

class MyScanner {
	String[] s;
	int i;
	BufferedReader br;
	String reg = " ";

	MyScanner () {
		s = new String[0];
		i = 0;
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	public String next() throws IOException {
		if (i < s.length) return s[i++];
		String line = br.readLine();
		while (line.equals("")) {
			line = br.readLine();
		}
		s = line.split(reg, 0);
		i = 0;
		return s[i++];
	}

	public int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}

	public double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(next());
	}

	public long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(next());
	}
}