
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] edges = new int[m][2];
		for (int i = 0; i < m; i++) {
			edges[i][0] = sc.nextInt() - 1;
			edges[i][1] = sc.nextInt() - 1;
		}

		ReRootingSolver s = new ReRootingSolver(n, edges, 1, (l, r) -> (l * r) % m, (v, p) -> v + 1);

		for (int i = 0; i < n; i++) {
			System.out.println(s.Query(i) - 1);
		}
	}
}

