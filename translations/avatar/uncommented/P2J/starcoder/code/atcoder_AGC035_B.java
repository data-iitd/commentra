import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        Set<Integer>[] edges = new HashSet[N];
        for (int i = 0; i < N; i++) {
            edges[i] = new HashSet<Integer>();
        }
        int[] degs = new int[N];
        int[] parity = new int[N];
        boolean[] flag = new boolean[N];
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            edges[a - 1].add(b - 1);
            edges[b - 1].add(a - 1);
            degs[a - 1]++;
            degs[b - 1]++;
        }
        if (M % 2!= 0) {
            System.out.println(-1);
            return;
        }
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>(N, new Comparator<Pair>() {
            public int compare(Pair o1, Pair o2) {
                return o1.deg - o2.deg;
            }
        });
        for (int i = 0; i < N; i++) {
            pq.add(new Pair(degs[i], i));
        }
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int u = p.idx;
            if (flag[u]) continue;
            flag[u] = true;
            for (int v : edges[u]) {
                edges[v].remove(u);
                if (parity[u]!= 0 && edges[u].size() == 0) {
                    System.out.println(u + 1 + " " + v + 1);
                    parity[u] = 1 - parity[u];
                } else {
                    System.out.println(v + 1 + " " + u + 1);
                    parity[v] = 1 - parity[v];
                }
                degs[v]--;
                pq.add(new Pair(degs[v], v));
            }
        }
    }
}
class Pair {
    int deg;
    int idx;
    public Pair(int deg, int idx) {
        this.deg = deg;
        this.idx = idx;
    }
}
