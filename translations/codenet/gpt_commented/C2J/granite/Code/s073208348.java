
import java.util.*;

public class s073208348{
    static class Edge implements Comparable<Edge> {
        int s, g, c; // start vertex, end vertex, and cost of the edge

        public Edge(int s, int g, int c) {
            this.s = s;
            this.g = g;
            this.c = c;
        }

        @Override
        public int compareTo(Edge o) {
            // Sort edges primarily by start vertex, then by end vertex
            if (this.s < o.s) return -1;
            if (this.s > o.s) return 1;
            if (this.g < o.g) return -1;
            return 1;
        }
    }

    static class Graph {
        int vcnt, ecnt; // number of vertices and edges
        Edge[] e; // array to hold edges
        int[] id; // array to hold index of edges for each vertex

        public Graph(int vcnt, int ecnt, Edge[] e) {
            this.vcnt = vcnt;
            this.ecnt = ecnt;
            this.e = e;
            this.id = new int[vcnt + 1];
        }

        public void readgraph() {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            e = new Edge[2 * n - 2];
            for (int i = 0; i < n - 1; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int c = sc.nextInt();
                e[2 * i] = new Edge(x, y, c);
                e[2 * i + 1] = new Edge(y, x, c);
            }
            Arrays.sort(e);
            int p = 0;
            for (int i = 0; i < vcnt; i++) {
                while (p < ecnt && e[p].s < i) p++;
                id[i] = p;
            }
            id[vcnt] = ecnt;
        }

        public int tyokkei() {
            int[] tyokkeitemp = new int[vcnt + 10];
            tyokkeitemp[0] = 1;
            tyokkeidfs(0, tyokkeitemp);
            int M = 0, Mi = 0;
            for (int i = 0; i < vcnt; i++) {
                if (tyokkeitemp[i] > M) {
                    M = tyokkeitemp[i];
                    Mi = i;
                }
            }
            Arrays.fill(tyokkeitemp, 0);
            tyokkeitemp[Mi] = 1;
            tyokkeidfs(Mi, tyokkeitemp);
            for (int i = 0; i < vcnt; i++) {
                M = Math.max(M, tyokkeitemp[i]);
            }
            return M - 1;
        }

        public void tyokkeidfs(int s, int[] tyokkeitemp) {
            for (int i = id[s]; i < id[s + 1]; i++) {
                if (tyokkeitemp[e[i].g] == 0) {
                    tyokkeitemp[e[i].g] = tyokkeitemp[s] + e[i].c;
                    tyokkeidfs(e[i].g, tyokkeitemp);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vcnt = sc.nextInt();
        int ecnt = sc.nextInt();
        Edge[] e = new Edge[ecnt];
        for (int i = 0; i < ecnt; i++) {
            int s = sc.nextInt();
            int g = sc.nextInt();
            int c = sc.nextInt();
            e[i] = new Edge(s, g, c);
        }
        Graph g = new Graph(vcnt, ecnt, e);
        g.readgraph();
        System.out.println(g.tyokkei());
    }
}

