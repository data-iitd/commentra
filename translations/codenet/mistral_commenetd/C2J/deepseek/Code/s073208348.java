import java.util.*;

class Edge {
    int s, g, c;
    Edge(int s, int g, int c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

class Graph {
    int vcnt, ecnt;
    List<Edge> e;
    int[] id;

    Graph(int vcnt, int ecnt) {
        this.vcnt = vcnt;
        this.ecnt = ecnt;
        this.e = new ArrayList<>(ecnt);
        this.id = new int[vcnt + 1];
    }
}

public class TreeDiameter {
    static Graph g;
    static int[] tyokkeitemp;

    public static void readgraph() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        g = new Graph(n, 2 * n - 2);
        for (int i = 0; i < n - 1; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int c = scanner.nextInt();
            g.e.add(new Edge(x, y, c));
            g.e.add(new Edge(y, x, c));
        }
        g.e.sort(Comparator.comparingInt(o -> o.s));
        int p = 0;
        for (int i = 0; i < g.vcnt; i++) {
            while (p < g.e.size() && g.e.get(p).s < i) p++;
            g.id[i] = p;
        }
        g.id[g.vcnt] = g.e.size();
    }

    public static void tyokkeidfs(int s) {
        for (int i = g.id[s]; i < g.id[s + 1]; i++) {
            Edge edge = g.e.get(i);
            if (tyokkeitemp[edge.g] == 0) {
                tyokkeitemp[edge.g] = tyokkeitemp[s] + edge.c;
                tyokkeidfs(edge.g);
            }
        }
    }

    public static int tyokkei() {
        tyokkeitemp = new int[g.vcnt];
        tyokkeitemp[0] = 1;
        tyokkeidfs(0);
        int M = 0, Mi = 0;
        for (int i = 0; i < g.vcnt; i++) {
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }
        return M - 1;
    }

    public static void main(String[] args) {
        readgraph();
        System.out.println(tyokkei());
    }
}
