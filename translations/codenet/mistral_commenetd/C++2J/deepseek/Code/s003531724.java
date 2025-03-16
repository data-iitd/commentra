import java.util.*;

public class Main {
    static class Edge {
        int to, pre, c;
    }

    static final int N = 100010;
    static Edge[] e = new Edge[N << 1];
    static int[] u = new int[N];
    static int l = 0;
    static int n, m;
    static boolean[] vis = new boolean[N];
    static boolean ok;
    static long[] cnt = new long[3];
    static int[] d = new int[N];
    static int T;

    static void ins(int a, int b, int c) {
        e[++l] = new Edge();
        e[l].to = b;
        e[l].pre = u[a];
        e[l].c = c;
        u[a] = l;
    }

    static void dfs(int x, int l) {
        vis[x] = true;
        cnt[l % 3]++;
        d[x] = l;
        for (int i = u[x]; i != 0; i = e[i].pre) {
            T++;
            if (!vis[e[i].to]) {
                dfs(e[i].to, (l + e[i].c) % 3);
            } else if ((l + e[i].c) % 3 != d[e[i].to]) {
                ok = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                T = 0;
                Arrays.fill(cnt, 0);
                ok = true;
                dfs(i, 0);
                long s = cnt[0] + cnt[1] + cnt[2];
                if (!ok) {
                    ans += s * s;
                } else {
                    if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                        ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
                    } else {
                        ans += T / 2;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
