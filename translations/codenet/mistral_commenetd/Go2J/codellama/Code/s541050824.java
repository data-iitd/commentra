// Importing required packages
import java.io.*;
import java.util.*;

// Initializing variables
class bufReader extends BufferedReader {
	StringBuilder sb = new StringBuilder();
	int index = 0;

	public bufReader(InputStream is) {
		super(is);
	}

	public String readLine() throws IOException {
		sb.setLength(0);
		int c = read();
		while (c != '\n' && c != -1) {
			sb.append((char) c);
			c = read();
		}
		return sb.toString();
	}
}

class bufWriter extends BufferedWriter {
	public bufWriter(OutputStream os) {
		super(os);
	}

	public void write(String s) throws IOException {
		super.write(s, 0, s.length());
	}
}

class Solution {
	public static void main(String[] args) throws IOException {
		// Initializing variables
		bufReader reader = new bufReader(System.in);
		bufWriter writer = new bufWriter(System.out);

		// Reading input
		String[] tokens = reader.readLine().split(" ");
		int n = Integer.parseInt(tokens[0]);
		int m = Integer.parseInt(tokens[1]);
		int[][] matrix = new int[n][m];
		for (int i = 0; i < n; i++) {
			tokens = reader.readLine().split(" ");
			for (int j = 0; j < m; j++) {
				matrix[i][j] = Integer.parseInt(tokens[j]);
			}
		}

		// Writing output
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < n - 2; i++) {
			for (int j = 0; j < m - 2; j++) {
				int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1] + matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2];
				if (sum > max) {
					max = sum;
				}
			}
		}
		writer.write(String.valueOf(max));
		writer.newLine();

		// Closing writer
		writer.close();
	}
}

