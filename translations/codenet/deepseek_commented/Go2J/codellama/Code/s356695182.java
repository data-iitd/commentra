
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int len = 5;
		int[] l = scanNums(sc, len);
		System.out.println(min(pattern1(l), pattern2(l), pattern3(l)));
	}

	public static int[] scanNums(Scanner sc, int len) {
		int[] nums = new int[len];
		for (int i = 0; i < len; i++) {
			nums[i] = sc.nextInt();
		}
		return nums;
	}

	public static int pattern1(int[] l) {
		int n = (l[0] * l[3]) + (l[1] * l[4]);
		return n;
	}

	public static int pattern2(int[] l) {
		int n = 2 * l[2] * max(l[3], l[4]);
		return n;
	}

	public static int pattern3(int[] l) {
		int n = 2 * l[2] * min(l[3], l[4]) + (doch(l));
		return n;
	}

	public static int min(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function min() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.min(res, nums[i]);
		}
		return res;
	}

	public static int max(int... nums) {
		if (nums.length == 0) {
			throw new IllegalArgumentException("function max() requires at least one argument.");
		}
		int res = nums[0];
		for (int i = 0; i < nums.length; i++) {
			res = Math.max(res, nums[i]);
		}
		return res;
	}

	public static int doch(int[] l) {
		if (l[3] > l[4]) {
			return l[0] * (l[3] - l[4]);
		} else {
			return l[1] * (l[4] - l[3]);
		}
	}
}

