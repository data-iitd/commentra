
/*
URL:
https://atcoder.jp/contests/dp/tasks/dp_v
*/

package main;

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadruneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

final class Const {
	public static final long MOD = 1000000000L + 7;
	public static final long ALPHABET_NUM = 26L;
	public static final int INF_INT64 = Integer.MAX_VALUE;
	public static final int INF_BIT60 = 1 << 60;
	public static final int INF_INT32 = Integer.MAX_VALUE;
	public static final int INF_BIT30 = 1 << 30;
	public static final int NIL = -1;

	// for dijkstra, prim, and so on
	public static final int WHITE = 0;
	public static final int GRAY  = 1;
	public static final int BLACK = 2;
}

public class s620841407{
	public static void main(String[] args) throws Exception {
		final Scanner sc = new Scanner(System.in);
		final int n = sc.nextInt();
		final int m = sc.nextInt();
		final int[][] edges = new int[n - 1][2];
		for (int i = 0; i < n - 1; i++) {
			edges[i][0] = sc.nextInt() - 1;
			edges[i][1] = sc.nextInt() - 1;
		}
		sc.close();

		final long[] dp = new long[n];
		final long[] res = new long[n];
		final int[][] adjacents = new int[n][];
		final int[][] indexForAdjacents = new int[n][];
		for (int i = 0; i < n; i++) {
			adjacents[i] = new int[0];
			indexForAdjacents[i] = new int[0];
		}
		for (int i = 0; i < n - 1; i++) {
			final int u = edges[i][0];
			final int v = edges[i][1];
			adjacents[u] = Arrays.copyOf(adjacents[u], adjacents[u].length + 1);
			adjacents[u][adjacents[u].length - 1] = v;
			indexForAdjacents[u] = Arrays.copyOf(indexForAdjacents[u], indexForAdjacents[u].length + 1);
			indexForAdjacents[u][indexForAdjacents[u].length - 1] = adjacents[v].length;
			adjacents[v] = Arrays.copyOf(adjacents[v], adjacents[v].length + 1);
			adjacents[v][adjacents[v].length - 1] = u;
			indexForAdjacents[v] = Arrays.copyOf(indexForAdjacents[v], indexForAdjacents[v].length + 1);
			indexForAdjacents[v][indexForAdjacents[v].length - 1] = adjacents[u].length - 1;
		}

		final long[] parent = new long[n];
		final int[] order = new int[n];

		// InitOrderedTree
		int index = 0;
		final Deque<Integer> stack = new ArrayDeque<>();
		stack.push(0);
		parent[0] = -1;
		while (!stack.isEmpty()) {
			final int node = stack.pop();
			order[index] = node;
			index++;
			for (int i = 0; i < adjacents[node].length; i++) {
				final int adjacent = adjacents[node][i];
				if (adjacent == parent[node]) {
					continue;
				}
				stack.push(adjacent);
				parent[adjacent] = node;
			}
		}

		// fromLeaf
		for (int i = n - 1; i >= 1; i--) {
			final int node = order[i];
			final int parentNode = (int) parent[node];

			long accum = 0L;
			int parentIndex = -1;
			for (int j = 0; j < adjacents[node].length; j++) {
				if (adjacents[node][j] == parentNode) {
					parentIndex = j;
					continue;
				}
				accum = (accum + dp[node][j]) % m;
			}
			dp[parentNode][indexForAdjacents[node][parentIndex]] = (accum * accum) % m;
		}

		// toLeaf
		for (int i = 0; i < n; i++) {
			final int node = order[i];
			long accum = 0L;
			long[] accumsFromTail = new long[adjacents[node].length];
			accumsFromTail[adjacents[node].length - 1] = 1L;
			for (int j = adjacents[node].length - 1; j >= 1; j--) {
				accumsFromTail[j - 1] = (accumsFromTail[j] * dp[node][j]) % m;
			}
			for (int j = 0; j < adjacents[node].length; j++) {
				dp[adjacents[node][j]][indexForAdjacents[node][j]] = (dp[node][j] * accumsFromTail[j]) % m;
				accum = (accum + dp[node][j]) % m;
			}
			res[node] = accum;
		}

		// Print the answer
		for (int i = 0; i < n; i++) {
			System.out.printf("%d\n", res[i]);
		}
	}
}