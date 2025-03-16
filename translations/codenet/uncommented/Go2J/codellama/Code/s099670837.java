
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] a = new int[2][n];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == n - 1 && a[i][j] + ans > 0) {
					ans = a[i][j] + ans;
				}
				if (i == 0) {
					findAns(i + 1, j, a[i][j] + ans);
				}
				if (j + 1 < n) {
					findAns(i, j + 1, a[i][j] + ans);
				}
			}
		}
		System.out.println(ans);
	}

	public static void findAns(int i, int j, int sum) {
		if (i == 1 && j == n - 1 && sum + a[i][j] > ans) {
			ans = sum + a[i][j];
		}
		if (i == 0) {
			findAns(i + 1, j, sum + a[i][j]);
		}
		if (j + 1 < n) {
			findAns(i, j + 1, sum + a[i][j]);
		}
	}
}

