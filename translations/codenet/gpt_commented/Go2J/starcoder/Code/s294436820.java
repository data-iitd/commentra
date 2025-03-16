package main;

import java.io.*;
import java.util.*;

public class Main {
	// IO helper functions
	private static BufferedReader createReader(InputStream in) {
		return new BufferedReader(new InputStreamReader(in));
	}
	private static BufferedWriter createWriter(OutputStream out) {
		return new BufferedWriter(new OutputStreamWriter(out));
	}
	private static void close(Closeable res) {
		try {
			if (res!= null) {
				res.close();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// IO functions
	private static String readToken(BufferedReader reader) throws IOException {
		StringBuilder sb = new StringBuilder();
		while (true) {
			int c = reader.read();
			if (c == -1 ||!Character.isWhitespace(c)) {
				if (c!= -1) {
					sb.appendCodePoint(c);
				}
				break;
			}
		}
		return sb.toString();
	}
	private static String[] readTokens(BufferedReader reader) throws IOException {
		ArrayList<String> list = new ArrayList<String>();
		while (true) {
			String token = readToken(reader);
			if (token.length() == 0) {
				break;
			}
			list.add(token);
		}
		return list.toArray(new String[list.size()]);
	}
	private static String readLine(BufferedReader reader) throws IOException {
		StringBuilder sb = new StringBuilder();
		while (true) {
			String line = reader.readLine();
			if (line == null) {
				break;
			}
			sb.append(line).append("\n");
		}
		return sb.toString();
	}
	private static void writeLine(BufferedWriter writer, String line) throws IOException {
		writer.write(line);
		writer.write("\n");
	}

	// Simple math functions
	private static final int INF = 1000000007;
	private static final int INF2 = 1000000009;
	private static final int INF3 = 998244353;
	private static int min(int a, int b) {
		if (a < b) {
			return a;
		}
		return b;
	}
	private static int minll(long a, long b) {
		if (a < b) {
			return (int) a;
		}
		return (int) b;
	}
	private static int minf(float a, float b) {
		if (a < b) {
			return (int) a;
		}
		return (int) b;
	}
	private static int max(int a, int b) {
		if (a < b) {
			return b;
		}
		return a;
	}
	private static int maxll(long a, long b) {
		if (a < b) {
			return (int) b;
		}
		return (int) a;
	}
	private static int maxf(float a, float b) {
		if (a < b) {
			return (int) b;
		}
		return (int) a;
	}
	private static int abs(int a) {
		if (a < 0) {
			return -a;
		}
		return a;
	}
	private static int absll(long a) {
		if (a < 0) {
			return (int) -a;
		}
		return (int) a;
	}
	private static int absf(float a) {
		if (a < 0) {
			return (int) -a;
		}
		return (int) a;
	}
	private static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}
	private static int gcdll(long a, long b) {
		if (b == 0) {
			return (int) a;
		}
		return gcdll(b, a % b);
	}
	private static int egcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return egcd(b, a % b);
	}
	private static int egcdll(long a, long b) {
		if (b == 0) {
			return (int) a;
		}
		return egcdll(b, a % b);
	}

	// set up IO functions
	public static void main(String[] args) throws IOException {
		BufferedReader reader = createReader(System.in);
		BufferedWriter writer = createWriter(System.out);
		try {
			// Read input
			int h = Integer.parseInt(readToken(reader));
			int w = Integer.parseInt(readToken(reader));
			int a = Integer.parseInt(readToken(reader));
			int[][] m = new int[h][w];
			for (int i = 0; i < h; i++) {
				String[] row = readTokens(reader);
				for (int j = 0; j < w; j++) {
					m[i][j] = row[j].charAt(0) - '0';
				}
			}

			// Solve the problem
			int answer = solve(h, w, a, m);

			// Output the answer
			writeLine(writer, Integer.toString(answer));
		} finally {
			close(reader);
			close(writer);
		}
	}

	// Simple math functions
	private static int countBlack(int h, int w, int[][] m) {
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (m[i][j] == 1) {
					count++;
				}
			}
		}
		return count;
	}

	// solve calculates the number of ways to paint the grid to achieve the target count of black cells.
	private static int solve(int h, int w, int a, int[][] m) {
		int result = 0;
		for (int i = 0; i < 1 << h; i++) {
			for (int k = 0; k < 1 << w; k++) {
				int[][] tmp = new int[h][w];
				for (int j = 0; j < h; j++) {
					for (int l = 0; l < w; l++) {
						tmp[j][l] = m[j][l];
					}
				}
				// Paint rows based on the current combination
				for (int j = 0; j < h; j++) {
					int hPainted = (1 << j & i);
					if (hPainted > 0) {
						for (int l = 0; l < w; l++) {
							tmp[j][l] = 1;
						}
					}
				}
				// Paint columns based on the current combination
				for (int j = 0; j < w; j++) {
					int wPainted = (1 << j & k);
					if (wPainted > 0) {
						for (int l = 0; l < h; l++) {
							tmp[l][j] = 1;
						}
					}
				}
				if (countBlack(h, w, tmp) == a) {
					result++;
				}
			}
		}
		return result;
	}
}

