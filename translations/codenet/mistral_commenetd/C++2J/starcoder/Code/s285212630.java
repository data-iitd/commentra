import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    class Node {
        int v, d;
        Node(int v, int d) {
            this.v = v;
            this.d = d;
        }
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            G[u].add(new Node(v, 1));
        }
        dfs(0, 0, 0);
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            System.out.println(L[u] + L[v] - 2 * L[U[0][u]]);
        }
    }

    void dfs(int u, int p, int d) {
        U[0][u] = p;
        R[u] = d;
        L[u] = d;
        for (Node e : G[u]) {
            if (e.v == p) continue;
            dfs(e.v, u, d + e.d);
            L[u] += L[e.v];
        }
    }
}

