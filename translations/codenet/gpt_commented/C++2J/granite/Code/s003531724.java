
import java.util.*;
import java.io.*;

public class s003531724{
    static int n, m;
    static int[] head = new int[100005];
    static int[] next = new int[200005];
    static int[] to = new int[200005];
    static int[] col = new int[200005];
    static int[] vis = new int[100005];
    static int[] cnt = new int[3];
    static int[] d = new int[100005];
    static int T;
    static boolean ok;
    static StringBuilder sb = new StringBuilder();

    static void add(int a, int b, int c) {
        next[++m] = head[a];
        head[a] = m;
        to[m] = b;
        col[m] = c;
    }

    static void dfs(int x, int l) {
        vis[x] = 1;
        cnt[l]++;
        d[x] = l;
        T++;
        for (int i = head[x]; i!= 0; i = next[i]) {
            if (vis[to[i]] == 0) {
                dfs(to[i], (l + col[i]) % 3);
            } else if ((l + col[i]) % 3!= d[to[i]]) {
                ok = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        for (int i = 1; i <= m; i++) {
            s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            add(a, b, 1);
            add(b, a, 2);
        }
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                T = 0;
                for (int j = 0; j < 3; j++) {
                    cnt[j] = 0;
                }
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

