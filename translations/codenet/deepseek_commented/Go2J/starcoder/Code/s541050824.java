package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader reader;
	BufferedWriter writer;

	void run() throws IOException {
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new BufferedWriter(new OutputStreamWriter(System.out));
		solve();
		writer.close();
	}

	void solve() throws IOException {
		int N = Integer.parseInt(reader.readLine());
		int[] T = new int[N];
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			String[] line = reader.readLine().split(" ");
			T[i] = Integer.parseInt(line[0]);
			A[i] = Integer.parseInt(line[1]);
		}
		int t = T[0], a = A[0];
		for (int i = 1; i < N; i++) {
			int r = Math.max(divUp(t, T[i]), divUp(a, A[i]));
			t = T[i] * r;
			a = A[i] * r;
		}
		out(t + a);
	}

	int divUp(int x, int y) {
		return (x + y - 1) / y;
	}

	void out(Object... o) throws IOException {
		writer.write(Arrays.deepToString(o));
		writer.write("\n");
	}
}

