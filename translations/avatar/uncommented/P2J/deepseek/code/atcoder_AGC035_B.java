import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        List<Set<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new HashSet<>());
        }
        
        int[] degs = new int[N];
        int[] parity = new int[N];
        boolean[] flag = new boolean[N];
        
        for (int i = 0; i < M; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            edges.get(a).add(b);
            edges.get(b).add(a);
            degs[a]++;
            degs[b]++;
        }
        
        if (M % 2 != 0) {
            System.out.println(-1);
            return;
        }
        
        PriorityQueue<int[]> Q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < N; i++) {
            Q.offer(new int[]{degs[i], i});
        }
        
        while (!Q.isEmpty()) {
            int[] top = Q.poll();
            int u = top[1];
            
            if (flag[u]) {
                continue;
            }
            
            flag[u] = true;
            
            for (int v : edges.get(u)) {
                edges.get(v).remove(u);
                if (parity[u] != 0) {
                    System.out.println((u + 1) + " " + (v + 1));
                    parity[u] = 1 - parity[u];
                } else {
                    System.out.println((v + 1) + " " + (u + 1));
                    parity[v] = 1 - parity[v];
                }
                degs[v]--;
                Q.offer(new int[]{degs[v], v});
            }
        }
    }
}
