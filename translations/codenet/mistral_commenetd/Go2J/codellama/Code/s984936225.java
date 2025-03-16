
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize variables
		int N, M;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		// Constants and initializations
		int Inf = 1 << 62;
		// a, b, and c are arrays of size M
		int[] a = new int[M];
		int[] b = new int[M];
		int[] c = new int[M];

		// Read input values for a, b, and c
		for (int i = 0; i < M; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = -sc.nextInt();
		}

		// Initialize the dist array with the maximum value
		int[] dist = new int[N];
		for (int i = 0; i < N; i++) {
			dist[i] = Inf;
		}
		// Set the initial distance of the source node to 0
		dist[0] = 0;

		// Dijkstra's algorithm loop
		for (int loop = 0; loop < N; loop++) {
			for (int i = 0; i < M; i++) {
				// Skip if the current node's distance is still the maximum value
				if (dist[a[i] - 1] == Inf) {
					continue;
				}
				// Update the distance if the new path is shorter
				if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
					dist[b[i] - 1] = dist[a[i] - 1] + c[i];
				}
			}
		}

		// Calculate the answer
		int ans = dist[N - 1];
		boolean[] navigate = new boolean[N];

		// Dijkstra's algorithm loop (second pass)
		for (int loop = 0; loop < N; loop++) {
			for (int i = 0; i < M; i++) {
				// Skip if the current node's distance is still the maximum value
				if (dist[a[i] - 1] == Inf) {
					continue;
				}
				// Update the distance if the new path is shorter
				if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
					dist[b[i] - 1] = dist[a[i] - 1] + c[i];
					navigate[b[i] - 1] = true;
				}
				// If the previous node is in the navigate array, set the current node's navigate array value to true
				if (navigate[a[i] - 1] == true) {
					navigate[b[i] - 1] = true;
				}
			}
		}

		// Print the result
		if (navigate[N - 1] == true) {
			System.out.println("inf");
		} else {
			System.out.println(-ans);
		}

		// End of the code
	}
}

