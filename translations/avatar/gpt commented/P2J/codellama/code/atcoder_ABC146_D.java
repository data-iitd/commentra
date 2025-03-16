import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Deque<Integer>[] G = new Deque[N];
        Map<String, Integer> E = new HashMap<>();
        for (int i = 0; i < N; i++) {
            G[i] = new LinkedList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            G[a].add(b);
            G[b].add(a);
            E.put(a + " " + b, 0);
        }
        int K = bfs(0, N, G, E);
        System.out.println(K);
        for (Map.Entry<String, Integer> entry : E.entrySet()) {
            System.out.println(entry.getValue());
        }
    }
    
    public static int bfs(int v, int N, Deque<Integer>[] G, Map<String, Integer> E) {
        boolean[] visited = new boolean[N];
        Deque<Integer> queue = new LinkedList<>();
        int K = -1;
        int[] node2color = new int[N];
        
        queue.add(v);
        visited[v] = true;
        
        while (!queue.isEmpty()) {
            int q = queue.remove();
            int color = 0;
            
            for (int nex : G[q]) {
                if (visited[nex]) {
                    continue;
                }
                
                visited[nex] = true;
                color++;
                
                if (color == node2color[q]) {
                    color++;
                }
                
                node2color[nex] = color;
                E.put(q + " " + nex, color);
                queue.add(nex);
            }
            
            K = Math.max(K, color);
        }
        
        return K;
    }
}

