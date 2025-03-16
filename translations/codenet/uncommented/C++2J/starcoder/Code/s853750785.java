
import java.util.*;
import java.io.*;

public class AtCoder {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N, M;
		N = sc.nextInt();
		M = sc.nextInt();
		int[] H = new int[N];
		for (int i = 0; i < N; i++) {
			H[i] = sc.nextInt();
		}
		int[][] G = new int[N][N];
		for (int i = 0; i < M; i++) {
			int u, v;
			u = sc.nextInt();
			v = sc.nextInt();
			u--;
			v--;
			G[u][v] = 1;
			G[v][u] = 1;
		}
		int ans = 0;
		for (int u = 0; u < N; u++) {
			boolean flag = true;
			for (int v = 0; v < N; v++) {
				if (H[u] <= H[v])flag = false;
			}
			if (flag)ans++;
		}
		System.out.println(ans);
	}
}

