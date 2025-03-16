
/*
URL:
https://atcoder.jp/contests/abc082/tasks/arc087_b
*/

package main;

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadruneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

final class Contants {
	// General purpose
	static final int MOD = 1000000000 + 7;
	static final int ALPHABET_NUM = 26;
	static final int INF_INT64 = Long.MAX_VALUE;
	static final int INF_BIT60 = 1L << 60;
	static final int INF_INT32 = Integer.MAX_VALUE;
	static final int INF_BIT30 = 1 << 30;
	static final int NIL = -1;

	// for dijkstra, prim, and so on
	static final int WHITE = 0;
	static final int GRAY  = 1;
	static final int BLACK = 2;
}

public class s069675863{
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		String[] S = br.readLine().split("");
		int x = Integer.parseInt(br.readLine());
		int y = Integer.parseInt(br.readLine());

		List<Integer> F = new ArrayList<>();
		// if S[0] == 'T' {
		// 	F.add(0);
		// }
		int cur = 0;
		for (int i = 0; i < S.length; i++) {
			if (S[i].equals("F")) {
				cur++;
			} else {
				F.add(cur);
				cur = 0;
			}
		}
		F.add(cur);
		// System.out.println(F);

		boolean[][] dpx = new boolean[F.size() + 1][x + 1];
		boolean[][] dpy = new boolean[F.size() + 1][y + 1];
		dpx[0][0] = true;
		dpy[0][0] = true;
		for (int i = 0; i < F.size(); i++) {
			for (int j = 0; j <= x; j++) {
				if (j + F.get(i) <= x) {
					dpx[i + 1][j + F.get(i)] |= dpx[i][j];
				}
				if (j - F.get(i) >= 0) {
					dpx[i + 1][j - F.get(i)] |= dpx[i][j];
				}
			}
			for (int j = 0; j <= y; j++) {
				if (j + F.get(i) <= y) {
					dpy[i + 1][j + F.get(i)] |= dpy[i][j];
				}
				if (j - F.get(i) >= 0) {
					dpy[i + 1][j - F.get(i)] |= dpy[i][j];
				}
			}
		}

		if (dpx[F.size()][x] && dpy[F.size()][y]) {
			bw.write("Yes");
		} else {
			bw.write("No");
		}
		bw.newLine();
		bw.flush();
	}
}