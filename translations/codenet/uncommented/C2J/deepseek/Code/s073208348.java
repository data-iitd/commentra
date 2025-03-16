import java.util.*;

class Edge {
    int s, g, c;
}

class Graph {
    int vcnt, ecnt;
    Edge[] e;
    int[] id;
}

public class Main {
    static Graph g;

    static int esort(Edge a, Edge b) {
        if (a.s < b.s) return -1;
        if (a.s > b.s) return 1;
        if (a.g < b.g) return -1;
        return 1;
    }

    static void readgraph() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        g = new Graph();
        g.e = new Edge[2 * n - 2];
        g.id = new int[n + 10];
        for (int i = 0; i < n - 1; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int c = scanner.nextInt();
            if (g.e[2 * i] == null) g.e[2 * i] = new Edge();
            if (g.e[2 * i + 1] == null) g.e[2 * i + 1] = new Edge();
            g.e[2 * i].s = x;
            g.e[2 * i].g = y;
            g.e[2 * i].c = c;
            g.e[2 * i + 1].s = y;
            g.e[2 * i + 1].g = x;
            g.e[2 * i + 1].c = c;
        }
        g.vcnt = n;
        g.ecnt = 2 * n - 2;
        Arrays.sort(g.e, Main::esort);
        int p = 0;
        for (int i = 0; i < g.vcnt; i++) {
            while (p < g.ecnt && g.e[p].s < i) p++;
            g.id[i] = p;
        }
        g.id[g.vcnt] = g.ecnt;
    }

    static int[] tyokkeitemp;

    static void tyokkeidfs(int s) {
        for (int i = g.id[s]; i < g.id[s + 1]; i++) {
            if (tyokkeitemp[g.e[i].g] == 0) {
                tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
                tyokkeidfs(g.e[i].g);
            }
        }
    }

    static int tyokkei() {
        tyokkeitemp = new int[g.vcnt + 10];
        Arrays.fill(tyokkeitemp, 0);
        tyokkeitemp[0] = 1;
        tyokkeidfs(0);
        int M = 0, Mi = 0;
        for (int i = 0; i < g.vcnt; i++) {
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }
        Arrays.fill(tyokkeitemp, 0);
        tyokkeitemp[Mi] = 1;
        tyokkeidfs(Mi);
        M = 0;
        for (int i = 0; i < g.vcnt; i++) {
            M = Math.max(M, tyokkeitemp[i]);
        }
        return M - 1;
    }

    public static void main(String[] args) {
        readgraph();
        System.out.println(tyokkei());
    }
}
