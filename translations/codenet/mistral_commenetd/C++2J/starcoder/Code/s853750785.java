
import java.util.*;
import java.io.*;
import java.math.*;

public class AtCoder {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		int[] H = new int[N];
		for (int i = 0; i < N; i++) {
			H[i] = in.nextInt();
		}
		int[][] G = new int[N][N];
		for (int i = 0; i < M; i++) {
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			G[u][v] = 1;
			G[v][u] = 1;
		}
		int ans = 0;
		for (int u = 0; u < N; u++) {
			boolean flag = true;
			for (int v = 0; v < N; v++) {
				if (H[u] <= H[v]) {
					flag = false;
				}
			}
			if (flag) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}

