
import java.io.*;
import java.util.*;

public class s448220316{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int[] fa = new int[n + 1];
        int[] v = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            str = br.readLine().split(" ");
            int l = Integer.parseInt(str[0]);
            int r = Integer.parseInt(str[1]);
            int vi = Integer.parseInt(str[2]);
            int li = find(l, fa, v);
            int ri = find(r, fa, v);
            if (li!= ri) {
                v[ri] = vi - v[r] + v[l];
                fa[ri] = li;
            } else {
                if (v[r] - v[l]!= vi) {
                    bw.write("No\n");
                    bw.flush();
                    return;
                }
            }
        }
        bw.write("Yes\n");
        bw.flush();
    }

    public static int find(int x, int[] fa, int[] v) {
        if (x == fa[x]) {
            return x;
        }
        int f = find(fa[x], fa, v);
        v[x] += v[fa[x]];
        fa[x] = f;
        return f;
    }
}

