package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		// IO
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// Solve
		int h = Integer.parseInt(br.readLine());
		int w = Integer.parseInt(br.readLine());
		int a = Integer.parseInt(br.readLine());
		String[] m = new String[h];
		for (int i = 0; i < h; i++) {
			m[i] = br.readLine();
		}
		int result = solve(h, w, a, m);

		// Output
		bw.write(String.valueOf(result));
		bw.newLine();

		bw.flush();
		bw.close();
	}

	public static int solve(int h, int w, int a, String[] m) {
		int result = 0;
		for (int i = 0; i < 1 << h; i++) {
			for (int k = 0; k < 1 << w; k++) {
				int[][] tmp = new int[h][w];
				for (int j = 0; j < h; j++) {
					for (int l = 0; l < w; l++) {
						tmp[j][l] = m[j].charAt(l) - '0';
					}
				}
				for (int j = 0; j < h; j++) {
					int hPainted = (1 << j & i);
					if (hPainted > 0) {
						for (int l = 0; l < w; l++) {
							tmp[j][l] = 1;
						}
					}
				}
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

	public static int countBlack(int h, int w, int[][] m) {
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
}

