
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();

		int[][] patterns = duplicatePatterns(new int[] {0, 1, 2, 3}, k);

		for (int[] P : patterns) {
			int r = a, g = b, b = c;
			for (int i = 0; i < P.length; i++) {
				if (P[i] == 0) {
					continue;
				} else if (P[i] == 1) {
					r *= 2;
				} else if (P[i] == 2) {
					g *= 2;
				} else if (P[i] == 3) {
					b *= 2;
				}
			}

			if (g > r && b > g) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}

	// DuplicatePatterns returns all patterns of n^k of elems([]int).
	public static int[][] duplicatePatterns(int[] elems, int k) {
		return dupliRec(new int[] {}, elems, k);
	}

	// DFS function for DuplicatePatterns.
	public static int[][] dupliRec(int[] pattern, int[] elems, int k) {
		if (pattern.length == k) {
			return new int[][] {pattern};
		}

		int[][] res = new int[][] {};
		for (int e : elems) {
			int[] newPattern = new int[pattern.length + 1];
			System.arraycopy(pattern, 0, newPattern, 0, pattern.length);
			newPattern[pattern.length] = e;

			res = merge(res, dupliRec(newPattern, elems, k));
		}

		return res;
	}

	// Merges two int[][] arrays.
	public static int[][] merge(int[][] arr1, int[][] arr2) {
		int[][] res = new int[arr1.length + arr2.length][];
		System.arraycopy(arr1, 0, res, 0, arr1.length);
		System.arraycopy(arr2, 0, res, arr1.length, arr2.length);
		return res;
	}
}

