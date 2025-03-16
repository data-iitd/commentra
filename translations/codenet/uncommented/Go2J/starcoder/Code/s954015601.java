// 深さ優先探索
package main;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		int N = readInt();

		int[][] ab = new int[N - 1][2];
		int[][] edges = new int[N][N];
		for (int i = 0; i < N - 1; i++) {
			int a = readInt() - 1;
			int b = readInt() - 1;
			ab[i][0] = a;
			ab[i][1] = b;
			edges[a][edges[a].length] = b;
			edges[b][edges[b].length] = a;
		}

		Map<Integer, Integer> colors = new HashMap<Integer, Integer>();
		Queue<int[]> q = new LinkedList<int[]>();
		q.add(new int[] { 0, -1, -1 });
		while (!q.isEmpty()) {
			int currentNode = q.peek()[0];
			int usedColor = q.peek()[1];
			int parentNode = q.peek()[2];
			q.poll();
			int color = 1;
			for (int childNode : edges[currentNode]) {
				if (childNode == parentNode) {
					continue;
				}
				if (color == usedColor) {
					color++;
				}
				colors.put(genid(currentNode, childNode), color);
				q.add(new int[] { childNode, color, currentNode });
				color++;
			}
		}

		int K = -1;
		for (int i = 0; i < N; i++) {
			int t = edges[i].length;
			if (t > K) {
				K = t;
			}
		}
		System.out.println(K);

		for (int i = 0; i < N - 1; i++) {
			System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
		}
	}

	public static int genid(int a, int b) {
		if (b < a) {
			a = b;
		}
		return a * 100000 + b;
	}

	public static int readInt() {
		try {
			return Integer.parseInt(readString());
		} catch (NumberFormatException e) {
			throw new RuntimeException(e);
		}
	}

	public static String readString() {
		try {
			stdinScanner.nextLine();
			return stdinScanner.nextLine();
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	private static final Scanner stdinScanner = new Scanner(System.in);
}

