
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int[] aa = new int[n];
		for (int i = 0; i < n; i++) {
			aa[i] = Integer.parseInt(st.nextToken());
		}
		int[] cumsum = cumsum(aa);
		int ans = 2020202020;
		for (int i = 1; i < cumsum.length - 1; i++) {
			int diff1 = Math.abs(cumsum[cumsum.length - 1] - cumsum[i]);
			int diff2 = cumsum[i] - cumsum[0];
			ans = Math.min(ans, diff1, diff2);
		}
		System.out.println(ans);
	}

	public static int[] cumsum(int[] a) {
		int[] cumsum = new int[a.length + 1];
		cumsum[0] = 0;
		for (int i = 0; i < a.length; i++) {
			cumsum[i + 1] = cumsum[i] + a[i];
		}
		return cumsum;
	}

	public static int min(int... nums) {
		int min = Integer.MAX_VALUE;
		for (int num : nums) {
			min = Math.min(min, num);
		}
		return min;
	}
}

