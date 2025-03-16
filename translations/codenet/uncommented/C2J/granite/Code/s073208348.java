
import java.util.*;

class s073208348 {
    static class Edge implements Comparable<Edge> {
        int s, g, c;

        public Edge(int s, int g, int c) {
            this.s = s;
            this.g = g;
            this.c = c;
        }

        public int compareTo(Edge e) {
            if (this.s < e.s) return -1;
            if (this.s > e.s) return 1;
            if (this.g < e.g) return -1;
            if (this.g > e.g) return 1;
            return 0;
        }
    }

    static class Graph {
        int vcnt, ecnt;
        Edge[] e;
        int[] id;

        public Graph(int n) {
            vcnt = n;
            ecnt = 2 * n - 2;
            e = new Edge[ecnt];
            id = new int[vcnt + 1];
        }

        public void readGraph() {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            for (int i = 0; i < n - 1; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int c = sc.nextInt();
                e[2 * i] = new Edge(x, y, c);
                e[2 * i + 1] = new Edge(y, x, c);
            }
            sc.close();
            Arrays.sort(e);
            int p = 0;
            for (int i = 0; i < vcnt; i++) {
                while (p < ecnt && e[p].s < i) p++;
                id[i] = p;
            }
            id[vcnt] = ecnt; // 番兵
        }

        public int tyokkei() {
            int[] tyokkeitemp = new int[vcnt + 10];
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
            for (int i = 0; i < vcnt; i++) M = Math.max(M, tyokkeitemp[i]);
            return M - 1;
        }

        public void tyokkeidfs(int s) {
            for (int i = id[s]; i < id[s + 1]; i++) {
                if (tyokkeitemp[e[i].g] == 0) {
                    tyokkeitemp[e[i].g] = tyokkeitemp[s] + e[i].c;
                    tyokkeidfs(e[i].g);
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(10);
        g.readGraph();
        System.out.println(g.tyokkei());
        System.out.println("