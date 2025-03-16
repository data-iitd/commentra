import java.util.*;
import java.io.*;
public class Main {
	static int n, m;
	static boolean vis[] = new boolean[N];
	static int d[] = new int[N];
	static int T;
	static int cnt[] = new int[3];
	static class edge{ int to, pre, c; }
	static edge e[] = new edge[N << 1];
	static int u[] = new int[N];
	static int l = 0;
	static void ins(int a, int b, int c) {
		e[++l] = new edge();
		e[l].to = b;
		e[l].pre = u[a];
		e[l].c = c;
		u[a] = l;
	}
	static void dfs(int x, int l) {
		vis[x] = true;
		cnt[l]++;
		d[x] = l;
		for (int i = u[x]; i; i = e[i].pre) {
			T++;
			if (!vis[e[i].to]) dfs(e[i].to, (l + e[i].c) % 3);
			else if ((l + e[i].c) % 3!= d[e[i].to]) {
				System.out.println("NO");
				return;
			}
		}
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt(); m = cin.nextInt();
		for (int i = 1; i <= m; i++) {
			int a = cin.nextInt(), b = cin.nextInt();
			ins(a, b, 1);
			ins(b, a, 2);
		}
		long ans = 0;
		for (int i = 1; i <= n; i++) if (!vis[i]) {
			T = 0;
			for (int j = 0; j < 3; j++) cnt[j] = 0;
			boolean ok = true;
			dfs(i, 0);
			long s = cnt[0] + cnt[1] + cnt[2];
			if (!ok) ans += s * s;
			else {
				if (cnt[0] && cnt[1] && cnt[2]) 
					ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
				else 
					ans += T / 2;
			}
		}
		System.out.println(ans);
	}
}

