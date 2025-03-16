/*
 depth first search algorithm implementation in Java
 not lying in the stack
 */
import java.util.Scanner;

public class DFS {
	static final int N = 100; /* maximum number of vertices in the graph */
	static final int WHITE = 0; /* unvisited vertex */
	static final int GRAY = 1; /* vertex is being explored */
	static final int BLACK = 2; /* vertex has been explored */

	static int M[][]; /* adjacency matrix and number of vertices */
	static int color[]; /* arrays for depth first search */
	static int d[];
	static int f[];
	static int tt; /* time */
	static int n; /* number of vertices */

	/*
	 depth first search visit function
	 sets the color, depth and finishing time of a vertex
	 */
	static void dfs_visit(int u) {
		int v;
		color[u] = GRAY; /* mark the current vertex as being explored */
		d[u] = ++tt; /* record the discovery time */
		for (v = 0; v < n; v++) {
			if (M[u][v] == 0)
				continue; /* if there is no edge between u and v, skip */
			if (color[v] == WHITE) {
				dfs_visit(v); /* recursively call dfs_visit for the neighbor v */
			}
		}
		color[u] = BLACK; /* mark the current vertex as explored */
		f[u] = ++tt; /* record the finishing time */
	}

	/*
	 depth first search function
	 initializes the arrays and performs the DFS traversal
	 */
	static void dfs() {
		int u;
		for (int i = 0; i < n; i++) {
			color[i] = WHITE; /* initialize all vertices as unvisited */
		}
		tt = 0;

		for (u = 0; u < n; u++) {
			if (color[u] == WHITE) {
				dfs_visit(u); /* call dfs_visit for the first unvisited vertex */
			}
		}

		/* print the results */
		for (int i = 0; i < n; i++)
			System.out.println(i + 1 + " " + d[i] + " " + f[i]);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); /* read the number of vertices */

		/* initialize the adjacency matrix with zeros */
		M = new int[n][n];
		color = new int[n];
		d = new int[n];
		f = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				M[i][j] = 0;
		}

		/* read the edges and fill the adjacency matrix */
		for (int i = 0; i < n; i++) {
			int k = sc.nextInt();
			int u = sc.nextInt();
			u--;
			for (int j = 0; j < k; j++) {
				int v = sc.nextInt();
				v--;
				M[u][v] = 1;
			}
		}

		/* perform depth first search */
		dfs();

		sc.close();
	}
}

