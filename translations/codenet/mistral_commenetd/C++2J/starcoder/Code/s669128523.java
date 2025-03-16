/*
 depth first search algorithm implementation in Java
 not lying in the stack
 */
import java.util.*;

public class DepthFirstSearch {
	static final int N = 100; /* maximum number of vertices in the graph */
	static final int WHITE = 0; /* unvisited vertex */
	static final int GRAY = 1; /* vertex is being explored */
	static final int BLACK = 2; /* vertex has been explored */

	int M[][], n; /* adjacency matrix and number of vertices */
	int color[] = new int[N]; /* array for vertex colors */
	int d[] = new int[N]; /* array for vertex discovery times */
	int f[] = new int[N]; /* array for vertex finishing times */
	int tt; /* time stamp */

	/*
	 depth first search visit function
	 sets the color, depth and finishing time of a vertex
	 */
	void dfs_visit(int u) {
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
	void dfs() {
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
		int k, u, v;
		Scanner sc = new Scanner(System.in);
		DepthFirstSearch dfs = new DepthFirstSearch();
		dfs.n = sc.nextInt(); /* read the number of vertices */

		/* initialize the adjacency matrix with zeros */
		for (int i = 0; i < dfs.n; i++) {
			for (int j = 0; j < dfs.n; j++)
				dfs.M[i][j] = 0;
		}

		/* read the edges and fill the adjacency matrix */
		for (int i = 0; i < dfs.n; i++) {
			dfs.M[i][i] = 1;
			dfs.color[i] = WHITE;
			dfs.d[i] = 0;
			dfs.f[i] = 0;
			u = sc.nextInt();
			u--;
			k = sc.nextInt();
			for (int j = 0; j < k; j++) {
				v = sc.nextInt();
				v--;
				dfs.M[u][v] = 1;
			}
		}

		/* perform depth first search */
		dfs.dfs();

		sc.close();
	}
}

