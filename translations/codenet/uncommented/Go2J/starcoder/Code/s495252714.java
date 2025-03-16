package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
		}
		Arrays.sort(c);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = (ans + (n - i) * c[i]) % 1000000007;
		}
		System.out.println(ans * modpow(4, n - 1) % 1000000007);
	}

	static int modpow(int a, int n) {
		int res = 1;
		while (n > 0) {
			if ((n & 1) == 1) {
				res = res * a % 1000000007;
			}
			a = a * a % 1000000007;
			n = n >> 1;
		}
		return res;
	}
}

