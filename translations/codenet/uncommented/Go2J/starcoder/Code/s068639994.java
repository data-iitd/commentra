package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		new Main().main();
	}

	public void main() {
		int n = getInt();
		int[] ls = getIntSlice(n);
		int[] lsRev = new int[n];
		System.arraycopy(ls, 0, lsRev, 0, n);
		Arrays.sort(ls);
		Arrays.sort(lsRev);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int p = Math.min(ls[i], ls[j]);
				int q = Math.max(ls[i], ls[j]);
				int x = q - p;
				int y = q + p;

				int l = Arrays.binarySearch(ls, x);
				if (l < 0) {
					l = -l - 1;
				}
				int r = n - Arrays.binarySearch(lsRev, y);

				int sum = r - l;
				if (i >= l) {
					sum--;
				}
				if (j >= l) {
					sum--;
				}
				sum = Math.max(0, sum);
				ans += sum;
			}
		}

		ans /= 3;
		puts(ans);
	}

	public int min(int a, int b) {
		return a < b? a : b;
	}

	public int max(int a, int b) {
		return a > b? a : b;
	}

	// -----------------------------------------

	private BufferedReader reader;
	private BufferedWriter writer;

	public Main() {
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new BufferedWriter(new OutputStreamWriter(System.out));
	}

	public void close() {
		try {
			reader.close();
			writer.close();
		} catch (IOException e) {
		}
	}

	public int getInt() {
		try {
			return Integer.parseInt(reader.readLine());
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public int[] getIntSlice(int n) {
		try {
			String[] line = reader.readLine().split(" ");
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = Integer.parseInt(line[i]);
			}
			return ret;
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public String getString() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public void puts(Object... objects) {
		try {
			for (Object object : objects) {
				writer.write("" + object);
			}
			writer.write("\n");
			writer.flush();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}

