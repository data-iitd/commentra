package main;

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] aa = new int[n];
		for (int i = 0; i < n; i++) {
			aa[i] = sc.nextInt();
		}
		int[] cumsum = CumSum(aa);
		int ans = 2020202020;
		for (int i = 1; i < cumsum.length-1; i++) {
			ans = Math.min(ans, Math.abs(cumsum[cumsum.length-1]-cumsum[i]-(cumsum[i]-cumsum[0])));
		}
		System.out.println(ans);
	}

	public static int[] CumSum(int[] nums) {
		int[] sums = new int[nums.length+1];
		sums[0] = 0;
		for (int i = 0; i < nums.length; i++) {
			sums[i+1] = sums[i] + nums[i];
		}
		return sums;
	}

}

// 