
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		int x = sc.nextInt();
		int y = sc.nextInt();

		int[] F = new int[S.length()];
		int cur = 0;
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == 'F') {
				cur++;
			} else {
				F[i] = cur;
				cur = 0;
			}
		}
		F[S.length()] = cur;

		int[] evens = new int[S.length() / 2];
		int[] odds = new int[S.length() / 2];
		for (int i = 0; i < S.length(); i++) {
			if (i % 2 == 0) {
				evens[i / 2] = F[i];
			} else {
				odds[i / 2] = F[i];
			}
		}

		boolean[][] dpx = new boolean[evens.length + 1][18001];
		boolean[][] dpy = new boolean[odds.length + 1][18001];

		dpx[0][10000] = true;
		for (int i = 0; i < evens.length; i++) {
			int val = evens[i];
			for (int j = 2000; j <= 18000; j++) {
				if (j + val <= 18000) {
					dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
				}
				if (j - val >= 2000 && i!= 0) {
					dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
				}
			}
		}
		for (int i = 0; i < odds.length; i++) {
			int val = odds[i];
			for (int j = 2000; j <= 18000; j++) {
				if (j + val <= 18000) {
					dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
				}
				if (j - val >= 2000) {
					dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
				}
			}
		}

		if (dpx[evens.length][x + 10000] && dpy[odds.length][y + 10000]) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

		sc.close();
	}
}

