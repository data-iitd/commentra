package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		int N = nextInt();
		int K = nextInt();
		int[] As = new int[N];
		int[] Fs = new int[N];
		for (int i = 0; i < N; i++) {
			As[i] = nextInt();
		}
		for (int i = 0; i < N; i++) {
			Fs[i] = nextInt();
		}
		Arrays.sort(As);
		Arrays.sort(Fs);
		int[] scores = new int[N];
		for (int i = 0; i < N; i++) {
			scores[i] = As[i] * Fs[i];
		}
		Arrays.sort(scores);
		int ok = scores[0];
		int ng = -1;
		while (ok - ng > 1) {
			int mid = (ok + ng) / 2;
			boolean isOK = true;
			int k = K;
			for (int i = 0; isOK && i < N; i++) {
				if (As[i] * Fs[i] > mid) {
					k -= As[i] - mid / Fs[i];
				}
				if (k < 0) {
					isOK = false;
				}
			}
			if (isOK) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		System.out.println(ok);
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static String next() throws IOException {
		while (sc.hasNext()) {
			return sc.next();
		}
		return null;
	}

	static String readLine() throws IOException {
		return br.readLine();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	static String nextToken() {
		while (!st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	static int nextIntToken() {
		return Integer.parseInt(nextToken());
	}
}

