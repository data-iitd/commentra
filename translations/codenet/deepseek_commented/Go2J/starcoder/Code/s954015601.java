// 深さ優先探索
package main;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Read the number of nodes from standard input.
		int N = readInt();

		// Initialize a slice to store edges and an adjacency list for the graph.
		int[][] ab = new int[N - 1][2];
		List<Integer>[] edges = new ArrayList[N];
		for (int i = 0; i < N - 1; i++) {
			// Read edge information and populate the adjacency list.
			int a = readInt() - 1;
			int b = readInt() - 1;
			ab[i][0] = a;
			ab[i][1] = b;
			if (edges[a] == null) {
				edges[a] = new ArrayList<Integer>();
			}
			edges[a].add(b);
			if (edges[b] == null) {
				edges[b] = new ArrayList<Integer>();
			}
			edges[b].add(a);
		}

		// Initialize a map to store the color of each edge and a queue for DFS traversal.
		Map<Integer, Integer> colors = new HashMap<Integer, Integer>();
		List<int[]> q = new ArrayList<int[]>();
		q.add(new int[] { 0, -1, -1 });
		for (int[] node : q) {
			// Pop the last element from the queue for DFS traversal.
			int currentNode = node[0];
			int usedColor = node[1];
			int parentNode = node[2];
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

		// Determine the maximum degree of any node in the graph.
		int K = -1;
		for (int i = 0; i < N; i++) {
			int t = edges[i].size();
			if (t > K) {
				K = t;
			}
		}
		System.out.println(K);

		// Output the colors of the edges.
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
		Scanner s = new Scanner(System.in);
		int result = s.nextInt();
		s.close();
		return result;
	}
}

