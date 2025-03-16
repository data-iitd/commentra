package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			char c = in.next().charAt(0);
			switch (c) {
			case 'M':
				a[i] = 1000;
				break;
			case 'A':
				a[i] = 900;
				break;
			case 'R':
				a[i] = 500;
				break;
			case 'C':
				a[i] = 400;
				break;
			case 'H':
				a[i] = 100;
				break;
			case 'D':
				a[i] = 50;
				break;
			case 'L':
				a[i] = 50;
				break;
			case 'X':
				a[i] = 10;
				break;
			case 'V':
				a[i] = 5;
				break;
			case 'I':
				a[i] = 1;
				break;
			}
		}
		dfs(a, 0, 1, 3, ans);
		System.out.println(ans);
	}

	public static void dfs(int[] a, int i, int res, int left, int ans) {
		if (left == 0) {
			ans += res;
			return;
		}
		for (int j = i; j < a.length; j++) {
			dfs(a, j + 1, res * a[j], left - 1, ans);
		}
	}
}

