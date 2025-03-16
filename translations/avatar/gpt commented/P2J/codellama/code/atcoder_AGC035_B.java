import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        ArrayList<Integer>[] edges = new ArrayList[N];
        int[] degs = new int[N];
        int[] parity = new int[N];
        boolean[] flag = new boolean[N];
        for (int i = 0; i < N; i++) {
            edges[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            edges[a - 1].add(b - 1);
            edges[b - 1].add(a - 1);
            degs[a - 1]++;
            degs[b - 1]++;
        }
        if (M % 2 != 0) {
            System.out.println(-1);
            return;
        }
        PriorityQueue<Integer> Q = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return degs[a] - degs[b];
            }
        });
        for (int i = 0; i < N; i++) {
            Q.add(i);
        }
        while (!Q.isEmpty()) {
            int u = Q.poll();
            if (flag[u]) {
                continue;
            }
            flag[u] = true;
            for (int i = 0; i < edges[u].size(); i++) {
                int v = edges[u].get(i);
                edges[v].remove(new Integer(u));
                if (parity[u] != 0 && i == 0) {
                    System.out.println(u + 1 + " " + v + 1);
                    parity[u] = 1 - parity[u];
                } else {
                    System.out.println(v + 1 + " " + u + 1);
                    parity[v] = 1 - parity[v];
                }
                degs[v]--;
                Q.add(v);
            }
        }
    }
}

