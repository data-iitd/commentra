package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		IO io = new IO();
		int n = io.nextInt();
		double t = io.nextDouble();
		double a = io.nextDouble();
		double[] heights = io.nextDoubles(n);

		double minDiff = Math.abs(t - heights[0] * 0.006 - a);
		int minIdx = 0;
		for (int i = 1; i < n; i++) {
			double diff = Math.abs(t - heights[i] * 0.006 - a);
			if (diff < minDiff) {
				minDiff = diff;
				minIdx = i;
			}
		}
		io.println(minIdx + 1);
	}
}

class IO {
	private BufferedReader reader;
	private BufferedWriter writer;

	public IO() {
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new BufferedWriter(new OutputStreamWriter(System.out));
	}

	public void print(Object... o) {
		try {
			for (Object obj : o) {
				writer.write(obj.toString());
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public void println(Object... o) {
		try {
			for (Object obj : o) {
				writer.write(obj.toString());
			}
			writer.write("\n");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public void print(String s) {
		try {
			writer.write(s);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public void println(String s) {
		try {
			writer.write(s);
			writer.write("\n");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public void flush() {
		try {
			writer.flush();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public String next() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public String nextLine() {
		return next();
	}

	public String[] nextStrings(int n) {
		String[] strs = new String[n];
		for (int i = 0; i < n; i++) {
			strs[i] = next();
		}
		return strs;
	}

	public String[] nextStrings() {
		return nextStrings(nextInt());
	}

	public String[][] next2DStrings(int y, int x) {
		String[][] strs = new String[y][x];
		for (int i = 0; i < y; i++) {
			strs[i] = nextStrings(x);
		}
		return strs;
	}

	public String[][] next2DStrings() {
		return next2DStrings(nextInt(), nextInt());
	}

	public String[][] next2DGraph(int y) {
		return next2DStrings(y, y);
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public int[] nextInts(int n) {
		int[] ints = new int[n];
		for (int i = 0; i < n; i++) {
			ints[i] = nextInt();
		}
		return ints;
	}

	public int[][] next2DInts(int y, int x) {
		int[][] ints = new int[y][x];
		for (int i = 0; i < y; i++) {
			ints[i] = nextInts(x);
		}
		return ints;
	}

	public int[][] next2DInts() {
		return next2DInts(nextInt(), nextInt());
	}

	public int[][] next2DGraph(int y) {
		return next2DInts(y, y);
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public long[] nextLongs(int n) {
		long[] longs = new long[n];
		for (int i = 0; i < n; i++) {
			longs[i] = nextLong();
		}
		return longs;
	}

	public long[][] next2DLongs(int y, int x) {
		long[][] longs = new long[y][x];
		for (int i = 0; i < y; i++) {
			longs[i] = nextLongs(x);
		}
		return longs;
	}

	public long[][] next2DLongs() {
		return next2DLongs(nextInt(), nextInt());
	}

	public long[][] next2DGraph(int y) {
		return next2DLongs(y, y);
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public double[] nextDoubles(int n) {
		double[] doubles = new double[n];
		for (int i = 0; i < n; i++) {
			doubles[i] = nextDouble();
		}
		return doubles;
	}

	public double[][] next2DDoubles(int y, int x) {
		double[][] doubles = new double[y][x];
		for (int i = 0; i < y; i++) {
			doubles[i] = nextDoubles(x);
		}
		return doubles;
	}

	public double[][] next2DDoubles() {
		return next2DDoubles(nextInt(), nextInt());
	}

	public double[][] next2DGraph(int y) {
		return next2DDoubles(y, y);
	}

	public boolean hasNext() {
		try {
			String s = reader.readLine();
			if (s == null) {
				return false;
			}
			reader.close();
			reader = new BufferedReader(new InputStreamReader(System.in));
			reader.readLine();
			return true;
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}

