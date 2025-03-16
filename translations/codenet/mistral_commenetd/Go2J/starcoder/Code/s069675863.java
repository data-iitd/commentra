
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		int x = sc.nextInt();
		int y = sc.nextInt();

		int[] evens = new int[S.length() / 2];
		int[] odds = new int[S.length() / 2];

		for (int i = 0; i < evens.length; i++) {
			evens[i] = Integer.parseInt(S.substring(2 * i, 2 * i + 2));
		}

		for (int i = 0; i < odds.length; i++) {
			odds[i] = Integer.parseInt(S.substring(2 * i + 1, 2 * i + 3));
		}

		boolean[][] dpx = new boolean[evens.length + 1][18000];
		boolean[][] dpy = new boolean[odds.length + 1][18000];

		for (int i = 0; i < evens.length; i++) {
			for (int j = 2000; j <= 18000; j++) {
				if (j + evens[i] <= 18000) {
					dpx[i + 1][j + evens[i]] = dpx[i + 1][j + evens[i]] || dpx[i][j];
				}
				if (j - evens[i] >= 2000 && i!= 0) {
					dpx[i + 1][j - evens[i]] = dpx[i + 1][j - evens[i]] || dpx[i][j];
				}
			}
		}

		for (int i = 0; i < odds.length; i++) {
			for (int j = 2000; j <= 18000; j++) {
				if (j + odds[i] <= 18000) {
					dpy[i + 1][j + odds[i]] = dpy[i + 1][j + odds[i]] || dpy[i][j];
				}
				if (j - odds[i] >= 2000) {
					dpy[i + 1][j - odds[i]] = dpy[i + 1][j - odds[i]] || dpy[i][j];
				}
			}
		}

		System.out.println(dpx[evens.length][x + 10000] && dpy[odds.length][y + 10000]? "Yes" : "No");
	}
}

