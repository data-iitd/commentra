
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter wr = new PrintWriter(System.out);

		int n = sc.nextInt();

		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
		}

		int ans = 0;
		Arrays.sort(c);

		for (int i = 0; i < n; i++) {
			ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
		}

		System.out.println(ans * modpow(4, n - 1) % mod);
		wr.flush();
		wr.close();
		sc.close();
	}

	public static int modpow(int a, int n) {
		int res = 1;
		for (; n > 0; n >>= 1) {
			if (n % 2 == 1) {
				res = res * a % mod;
			}
			a = a * a % mod;
		}
		return res;
	}

	public static final int mod = 1000000007;
}

