/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();

		int[][] patterns = duplicatePatterns(new int[] {0, 1, 2, 3}, k);

		for (int[] P : patterns) {
			int r = a;
			int g = b;
			int b_ = c;

			for (int i = 0; i < P.length; i++) {
				if (P[i] == 0) {
					continue;
				} else if (P[i] == 1) {
					r *= 2;
				} else if (P[i] == 2) {
					g *= 2;
				} else if (P[i] == 3) {
					b_ *= 2;
				}
			}

			if (g > r && b_ > g) {
				System.out.println("Yes");
				return;
			}
		}

		System.out.println("No");
	}

	// DuplicatePatterns returns all patterns of n^k of elems([]int).
	public static int[][] duplicatePatterns(int[] elems, int k) {
		return dupliRec(new int[0], elems, k);
	}

	// DFS function for DuplicatePatterns.
	public static int[][] dupliRec(int[] pattern, int[] elems, int k) {
		if (pattern.length == k) {
			// Return the generated pattern as a slice
			return new int[][] {pattern};
		}

		int[][] res = new int[0][0];
		for (int e : elems) {
			// Create a new pattern by appending the current element to the current pattern
			int[] newPattern = new int[pattern.length + 1];
			System.arraycopy(pattern, 0, newPattern, 0, pattern.length);
			newPattern[pattern.length] = e;

			// Recursively call the function with the new pattern and the remaining elements
			int[][] subPatterns = dupliRec(newPattern, elems, k);

			// Append the sub-patterns to the result
			res = append(res, subPatterns...);
		}

		return res;
	}
}

