package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader br;
	BufferedWriter bw;

	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = nextInt();
		int[] as = nextIntArray(n);

		int[] xs = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = as[i] - i + 1;
		}
		Arrays.sort(xs);

		int b = xs[n / 2];
		int ans = 0;
		for (int x : xs) {
			ans += Math.abs(x - b);
		}
		bw.write(ans + "\n");

		bw.close();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}

	int[] nextIntArray(int n) throws IOException {
		String[] s = br.readLine().split(" ");
		int[] ret = new int[n];
		for (int i = 0; i < n; i++) {
			ret[i] = Integer.parseInt(s[i]);
		}
		return ret;
	}
}

