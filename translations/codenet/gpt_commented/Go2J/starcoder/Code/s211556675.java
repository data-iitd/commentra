package main;

import java.io.*;
import java.util.*;

public class Main {

	// I/O
	// Scanner to facilitate reading
	static private final Scanner SCN = new Scanner(System.in);

	// max returns the maximum value from a list of integers
	static private int max(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m < i) {
				m = i;
			}
		}
		return m;
	}

	// min returns the minimum value from a list of integers
	static private int min(int... nums) {
		int m = nums[0];
		for (int i : nums) {
			if (m > i) {
				m = i;
			}
		}
		return m;
	}

	// abs returns the absolute value of an integer
	static private int abs(int x) {
		return (x > 0)? x : -x;
	}

	// pow computes x raised to the power of y
	static private int pow(int x, int y) {
		int res = 1;
		for (int i = 0; i < y; i++) {
			res *= x;
		}
		return res;
	}

	// main function
	public static void main(String[] args) {
		int A = SCN.nextInt();
		int B = SCN.nextInt();
		int C = SCN.nextInt();
		int K = SCN.nextInt();

		int ma = max(A, B, C);
		int rest = 0;
		if (ma == A) {
			rest += B + C;
		} else if (ma == B) {
			rest += A + C;
		} else {
			rest += A + B;
		}

		for (int i = 1; i <= K; i++) {
			ma *= 2;
		}

		System.out.println(ma + rest);
	}
}

