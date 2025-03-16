package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Map<Character, Integer> dic = new HashMap<>();
		for (int i = 0; i < n; i++) {
			char c = sc.next().charAt(0);
			if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
				if (dic.containsKey(c)) {
					dic.put(c, dic.get(c) + 1);
				} else {
					dic.put(c, 1);
				}
			}
		}
		int[] a = new int[dic.size()];
		int i = 0;
		for (int v : dic.values()) {
			a[i++] = v;
		}
		int ans = 0;
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

