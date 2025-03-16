package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	class Point {
		int x, y;
		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	void run() {
		int A = nextInt();
		int B = nextInt();
		int Q = nextInt();
		int[] s = new int[A + 2];
		s[0] = s[A + 1] = -1000000000;
		for (int i = 1; i <= A; i++) {
			s[i] = nextInt();
		}

		int[] t = new int[B + 2];
		t[0] = t[B + 1] = 1000000000;
		for (int i = 1; i <= B; i++) {
			t[i] = nextInt();
		}

		for (int i = 0; i < Q; i++) {
			int x = nextInt();
			int b = Arrays.binarySearch(s, x);
			int d = Arrays.binarySearch(t, x);
			int res = 1000000000;
			for (int S : new int[]{s[b - 1], s[b]}) {
				for (int T : new int[]{t[d - 1], t[d]}) {
					int d1 = Math.abs(S - x) + Math.abs(T - S);
					int d2 = Math.abs(T - x) + Math.abs(S - T);
					res = Math.min(res, Math.min(d1, d2));
				}
			}

			System.out.println(res);
		}
	}

	int nextInt() {
		try {
			return Integer.parseInt(nextString());
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	String nextString() {
		try {
			return sc.next();
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	Scanner sc = new Scanner(System.in);
}

// 