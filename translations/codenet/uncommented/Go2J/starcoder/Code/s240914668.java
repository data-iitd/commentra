package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int l = i, r = i + 1;
			while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
				r++;
			}
			ans++;
			i = r;
		}
		System.out.println(ans);
	}
}

