import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();

		ArrayList<Integer>[] e = new ArrayList[n+1];
		for (int i = 1; i <= n; i++) {
			e[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			e[a].add(b);
			e[b].add(a);
		}

		int[] visited = new int[n+1];
		visited[1] = 1;
		int count = dfs(e, visited, 1);
		System.out.println(count);
	}

	public static int dfs(ArrayList<Integer>[] e, int[] visited, int v) {
		int count = 0;
		for (int ne : e[v]) {
			if (visited[ne] == 0) {
				visited[ne] = 1;
				count += dfs(e, visited, ne);
			}
		}
		return count + 1;
	}
}

