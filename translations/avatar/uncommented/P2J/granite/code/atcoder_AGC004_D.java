
import java.io.*;
import java.util.*;

class atcoder_AGC004_D {
    static int dfs(ArrayList<Integer>[] links, int n, int k, int v, int p) {
        int heightFromLeaf = 0;
        int cutCount = 0;
        for (int u : links[v]) {
            if (u == 0) {
                continue;
            }
            int[] hgtCut = dfs(links, n, k, u, v);
            heightFromLeaf = Math.max(heightFromLeaf, hgtCut[0]);
            cutCount += hgtCut[1];
        }
        heightFromLeaf += 1;
        if (p!= 0 && heightFromLeaf == k) {
            heightFromLeaf = 0;
            cutCount += 1;
        }
        return new int[]{heightFromLeaf, cutCount};
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = br.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        ArrayList<Integer>[] links = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            links[i] = new ArrayList<>();
        }
        String[] aaa = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(aaa[i]) - 1;
            links[a].add(i);
        }
        int[] ans = dfs(links, n, k, 0, 0);
        if (Integer.parseInt(aaa[0])!= 1) {
            ans[1] += 1;
        }
        System.out.println(ans[1]);
    }
}

Translate the above Java code to C++ and end with comment "