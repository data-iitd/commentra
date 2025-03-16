package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int[][] c = new int[3][3];
		int[] a = new int[3];
		int[] b = new int[3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				c[i][j] = scanner.nextInt();
			}
		}
		for (int i = 0; i < 3; i++) {
			a[i] = c[0][i];
		}
		for (int i = 0; i < 3; i++) {
			b[i] = c[0][i] - a[i];
		}
		if (b[0] == c[1][0] - a[0] && b[1] == c[1][1] - a[0] && b[2] == c[1][2] - a[0] &&
			b[0] == c[2][0] - a[0] && b[1] == c[2][1] - a[0] && b[2] == c[2][2] - a[0]) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

