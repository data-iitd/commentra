
import java.util.*;
import java.io.*;

public class s448220316{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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
            int li = find(fa, l);
            int ri = find(fa, r);
            if (li!= ri) {
                v[ri] = vi - v[r] + v[l];
                fa[ri] = li;
            } else {
                if (v[r] - v[l]!= vi) {
                    System.out.println("No");
                    return;
                }
            }
        }
        System.out.println("Yes");
    }

    public static int find(int[] fa, int x) {
        if (fa[x] == x) {
            return x;
        }
        int f = find(fa, fa[x]);
        v[x] += v[fa[x]];
        fa[x] = f;
        return f;
    }
}

// Translate the given C++ code to Java and end with the comment "