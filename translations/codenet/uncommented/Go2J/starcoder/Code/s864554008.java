package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] nImg = new String[n];
		String[] mImg = new String[m];
		for (int i = 0; i < n; i++) {
			nImg[i] = sc.next();
		}
		for (int i = 0; i < m; i++) {
			mImg[i] = sc.next();
		}
		if (exist(n, m, nImg, mImg)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

	public static boolean exist(int n, int m, String[] nImg, String[] mImg) {
		for (int i = 0; i <= n-m; i++) {
			for (int j = 0; j <= n-m; j++) {
				if (match(n, m, nImg, mImg, i, j)) {
					return true;
				}
			}
		}
		return false;
	}

	public static boolean match(int n, int m, String[] nImg, String[] mImg, int x, int y) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (nImg[x+i].charAt(y+j)!= mImg[i].charAt(j)) {
					return false;
				}
			}
		}
		return true;
	}
}

