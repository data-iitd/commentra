package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

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

		wr.write(ans * modpow(4, n - 1) % mod + "\n");
		wr.close();
	}

	static int mod = 1000000007;

	static int modpow(int a, int n) {
		int res = 1;
		while (n > 0) {
			if (n % 2 == 1) {
				res = res * a % mod;
			}
			a = a * a % mod;
			n /= 2;
		}
		return res;
	}
}

