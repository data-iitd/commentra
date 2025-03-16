package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int k = sc.nextInt();

		long total = 0;
		for (int i = k; i <= n + 1; i++) {
			total += combi(n, i);
			total %= 1000000007;
		}
		System.out.println(total);
	}

	public static long combi(int n, int k) {
		long min = (long) k * k / 2;
		long max = (long) (2 * n - k + 1) * k / 2;
		return max - min + 1;
	}
}

