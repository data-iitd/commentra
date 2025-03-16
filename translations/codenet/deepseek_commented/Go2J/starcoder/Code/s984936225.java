import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		int[] a = new int[M];
		int[] b = new int[M];
		int[] c = new int[M];
		for (int i = 0; i < M; i++) {
			String[] s = br.readLine().split(" ");
			a[i] = Integer.parseInt(s[0]);
			b[i] = Integer.parseInt(s[1]);
			c[i] = Integer.parseInt(s[2]);
		}
		int[] dist = new int[N];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[0] = 0;
		for (int loop = 0; loop < N; loop++) {
			for (int i = 0; i < M; i++) {
				if (dist[a[i] - 1] == Integer.MAX_VALUE) {
					continue;
				}
				if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
					dist[b[i] - 1] = dist[a[i] - 1] + c[i];
				}
			}
		}
		int ans = dist[N - 1];
		boolean[] navigate = new boolean[N];
		for (int loop = 0; loop < N; loop++) {
			for (int i = 0; i < M; i++) {
				if (dist[a[i] - 1] == Integer.MAX_VALUE) {
					continue;
				}
				if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
					dist[b[i] - 1] = dist[a[i] - 1] + c[i];
					navigate[b[i] - 1] = true;
				}
				if (navigate[a[i] - 1]) {
					navigate[b[i] - 1] = true;
				}
			}
		}
		if (navigate[N - 1]) {
			System.out.println("inf");
		} else {
			System.out.println(-ans);
		}
	}
}

