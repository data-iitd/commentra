
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner();
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();

		int A = Math.max(H, W);

		System.out.println((N + A - 1) / A);

	}

	static class Scanner {
		BufferedReader r;
		StringTokenizer t;

		public Scanner() {
			r = new BufferedReader(new InputStreamReader(System.in));
		}

		public int nextInt() {
			int x;
			try {
				x = Integer.parseInt(next());
			} catch (NumberFormatException e) {
				x = 0;
			}
			return x;
		}

		public String next() {
			if (t == null || !t.hasMoreTokens()) {
				try {
					t = new StringTokenizer(r.readLine());
				} catch (Exception e) {
					throw new RuntimeException(e);
				}
			}
			return t.nextToken();
		}
	}
}

