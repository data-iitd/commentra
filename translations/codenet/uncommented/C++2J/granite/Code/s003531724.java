
import java.util.*;
import java.io.*;

public class s003531724{
    static int n, m;
    static int[] head = new int[100005];
    static int[] ver = new int[200005];
    static int[] nxt = new int[200005];
    static int[] edge = new int[200005];
    static int cnt = 0;
    static boolean[] vis = new boolean[100005];
    static int[] d = new int[100005];
    static long[] num = new long[3];
    static boolean flag = true;
    static int T = 0;

    static void add(int u, int v, int w) {
        ver[cnt] = v;
        edge[cnt] = w;
        nxt[cnt] = head[u];
        head[u] = cnt++;
    }

    static void dfs(int u, int l) {
        vis[u] = true;
        num[l]++;
        d[u] = l;
        for (int i = head[u]; i!= -1; i = nxt[i]) {
            T++;
            int v = ver[i];
            if (!vis[v]) {
                dfs(v, (l + edge[i]) % 3);
            } else if ((l + edge[i]) % 3!= d[v]) {
                flag = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        Arrays.fill(head, -1);
        for (int i = 0; i < m; i++) {
            str = br.readLine().split(" ");
            int u = Integer.parseInt(str[0]);
            int v = Integer.parseInt(str[1]);
            add(u, v, 1);
            add(v, u, 2);
        }
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                T = 0;
                Arrays.fill(num, 0);
                flag = true;
                dfs(i, 0);
                long s = num[0] + num[1] + num[2];
                if (!flag) {
                    ans += s * s;
                } else {
                    if (num[0] > 0 && num[1] > 0 && num[2] > 0) {
                        ans += num[0] * num[1] + num[1] * num[2] + num[2] * num[0];
                    } else {
                        ans += T / 2;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}

