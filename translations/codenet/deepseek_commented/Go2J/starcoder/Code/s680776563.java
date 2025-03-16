
package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		FastScanner fsc = new FastScanner();
		int A, B, C;
		A = fsc.nextInt();
		B = fsc.nextInt();
		C = fsc.nextInt();
		if (B - A == C - B) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}

class FastScanner {
	private BufferedReader br;
	private StringTokenizer st;

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	public String next() throws IOException {
		while (st == null ||!st.hasMoreElements()) {
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
}

