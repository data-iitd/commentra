// Set the recursion limit for the function call stack to 1 million
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    public void run() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int k = Integer.parseInt(line[1]);
            int[] aaa = new int[n];
            for (int i = 0; i < n; i++) {
                aaa[i] = Integer.parseInt(br.readLine()) - 1;
            }
            int[] links = new int[n][];
            for (int i = 0; i < n; i++) {
                links[i] = new int[0];
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (aaa[i] == aaa[j]) {
                        continue;
                    }
                    int[] tmp = links[aaa[i]];
                    int[] tmp2 = new int[tmp.length + 1];
                    System.arraycopy(tmp, 0, tmp2, 0, tmp.length);
                    tmp2[tmp.length] = aaa[j];
                    links[aaa[i]] = tmp2;
                }
            }
            int[] ans = new int[1];
            dfs(links, n, k, 0, 0, ans);
            if (aaa[0]!= 1) {
                ans[0]++;
            }
            System.out.println(ans[0]);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void dfs(int[][] links, int n, int k, int v, int p, int[] ans) {
        int heightFromLeaf = 0;
        int cutCount = 0;
        for (int u : links[v]) {
            if (u == 0) {
                continue;
            }
            int[] tmp = new int[0];
            int[] tmp2 = new int[0];
            dfs(links, n, k, u, v, tmp);
            heightFromLeaf = Math.max(heightFromLeaf, tmp[0]);
            cutCount += tmp[1];
        }
        heightFromLeaf++;
        if (p!= 0 && heightFromLeaf == k) {
            heightFromLeaf = 0;
            cutCount++;
        }
        ans[0] = Math.max(ans[0], cutCount);
    }
}

