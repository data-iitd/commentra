import java.util.Arrays;
import java.util.Scanner;

class Edge {
    long s, g, c;

    Edge(long s, long g, long c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

class Graph {
    int vcnt, ecnt;
    Edge[] e = new Edge[200010]; // Adjust as needed
    int[] id = new int[100010]; // Adjust as needed

    public void readGraph() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        for (int i = 0; i < n - 1; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            long c = scanner.nextLong();
            e[2 * i] = new Edge(x, y, c);
            e[2 * i + 1] = new Edge(y, x, c);
        }
        vcnt = (int) n;
        ecnt = 2 * (int) n - 2;
        Arrays.sort(e, 0, ecnt, (a, b) -> {
            if (a.s != b.s) return Long.compare(a.s, b.s);
            return Long.compare(a.g, b.g);
        });

        int p = 0;
        for (int i = 0; i < vcnt; i++) {
            while (p < ecnt && e[p].s < i) p++;
            id[i] = p;
        }
        id[vcnt] = ecnt; // Sentinel
    }

    int[] tyokkeitemp;

    void tyokkeidfs(long s) {
        for (int i = id[(int) s]; i < id[(int) s + 1]; i++) {
            if (tyokkeitemp[(int) e[i].g] == 0) {
                tyokkeitemp[(int) e[i].g] = tyokkeitemp[(int) s] + (int) e[i].c;
                tyokkeidfs(e[i].g);
            }
        }
    }

    int tyokkei() {
        tyokkeitemp = new int[vcnt + 10];
        tyokkeitemp[0] = 1;
        tyokkeidfs(0);
        int M = 0, Mi = 0;
        for (int i = 0; i < vcnt; i++) {
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }
        Arrays.fill(tyokkeitemp, 0);
        tyokkeitemp[Mi] = 1;
        tyokkeidfs(Mi);
        for (int i = 0; i < vcnt; i++) {
            M = Math.max(M, tyokkeitemp[i]);
        }
        return M - 1;
    }
}

public class Main {
    public static void main(String[] args) {
        Graph g = new Graph();
        g.readGraph();
        System.out.println(g.tyokkei());
    }
}
//<END-OF-CODE>
