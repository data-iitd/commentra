
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();

		// Initialize the graph edges
		int[][] e = new int[n+1][n+1];
		for (int i = 1; i < n+1; i++) {
			for (int j = 1; j < n+1; j++) {
				e[i][j] = 0;
			}
		}

		// Read the edges and populate the graph
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			e[a][b] = 1;
			e[b][a] = 1;
		}

		// Initialize visited slice and start DFS from node 1
		boolean[] visited = new boolean[n+1];
		visited[1] = true;
		int count = dfs(1, e, visited);
		System.out.println(count);
	}

	// Depth-First Search (DFS) function to count connected components in the graph
	public static int dfs(int v, int[][] e, boolean[] visited) {
		// Check if all nodes are visited
		boolean comp = true;
		for (int i = 1; i < e.length; i++) {
			if (!visited[i]) {
				comp = false;
			}
		}

		if (comp) {
			return 1;
		}

		int count = 0;
		for (int ne : e[v]) {
			if (visited[ne]) {
				continue;
			}
			visited[ne] = true;
			count += dfs(ne, e, visited);
			visited[ne] = false;
		}
		return count;
	}
}

