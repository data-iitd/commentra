
/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//String.format("%b\n", 255); 	// binary expression

/********** I/O usage **********/

//String str = ReadString();
//int i = ReadInt();
//int[] X = ReadIntLine();
//char[] c = ReadruneLine();
//double d = ReadDouble();
//double[] D = ReadDoubleLine();

//String str = ZeroPadding(i, 32);
//str = PrintIntsLine(X...);

/*******************************************************************/

public class s557024716{
	final static long MOD = 1000000000L + 7;
	final static int ALPHABET_NUM = 26;
	final static int INF = Integer.MAX_VALUE / 2;
	final static long LNF = Long.MAX_VALUE / 2;
	final static int NIL = -1;

	public static void main (String[] args) throws Exception {
		// Read input values
		int a = ReadInt();
		int b = ReadInt();
		int c = ReadInt();
		int k = ReadInt();

		// Generate all possible patterns of length k from the given array [0, 1, 2, 3]
		List<List<Integer>> patterns = DuplicatePatterns(Arrays.asList(0, 1, 2, 3), k);

		// Check each generated pattern
		for (List<Integer> P : patterns) {
			// Apply bitwise operation to RGB values of the given input
			int r = a;
			int g = b;
			int bb = c;
			for (int i = 0; i < P.size(); i++) {
				int p = P.get(i);
				if (p == 0) {
					continue;
				} else if (p == 1) {
					r *= 2;
				} else if (p == 2) {
					g *= 2;
				} else if (p == 3) {
					bb *= 2;
				}
			}

			// Check if the result satisfies the condition g > r and b > g
			if (g > r && bb > g) {
				System.out.println("Yes");
				return;
			}
		}

		// If all patterns are checked and no satisfying pattern is found, print "No"
		System.out.println("No");
	}

	// DuplicatePatterns returns all patterns of n^k of elems([]int).
	public static List<List<Integer>> DuplicatePatterns(List<Integer> elems, int k) {
		return dupliRec(new ArrayList<Integer>(), elems, k);
	}

	// DFS function for DuplicatePatterns.
	public static List<List<Integer>> dupliRec(List<Integer> pattern, List<Integer> elems, int k) {
		if (pattern.size() == k) {
			// Return the generated pattern as a list
			return Arrays.asList(pattern);
		}

		List<List<Integer>> res = new ArrayList<>();
		for (Integer e : elems) {
			// Create a new pattern by appending the current element to the current pattern
			List<Integer> newPattern = new ArrayList<>(pattern);
			newPattern.add(e);

			// Recursively call the function with the new pattern and the remaining elements
			List<List<Integer>> subPatterns = dupliRec(newPattern, elems, k);

			// Append the sub-patterns to the result
			res.addAll(subPatterns);
		}

		return res;
	}
}

