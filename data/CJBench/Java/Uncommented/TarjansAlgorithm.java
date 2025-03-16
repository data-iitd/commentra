
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;
public class TarjansAlgorithm {
    private int time;
    private final List<List<Integer>> sccList = new ArrayList<>();
    public List<List<Integer>> stronglyConnectedComponents(int v, List<List<Integer>> graph) {
        int[] lowTime = new int[v];
        int[] insertionTime = new int[v];
        boolean[] isInStack = new boolean[v];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < v; i++) {
            insertionTime[i] = -1;
            lowTime[i] = -1;
        }
        for (int i = 0; i < v; i++) {
            if (insertionTime[i] == -1) {
                dfs(i, lowTime, insertionTime, isInStack, stack, graph);
            }
        }
        return sccList;
    }
    private void dfs(int u, int[] lowTime, int[] insertionTime, boolean[] isInStack, Stack<Integer> stack, List<List<Integer>> graph) {
        insertionTime[u] = time;
        lowTime[u] = time;
        time++;
        stack.push(u);
        isInStack[u] = true;
        for (Integer v : graph.get(u)) {
            if (insertionTime[v] == -1) {
                dfs(v, lowTime, insertionTime, isInStack, stack, graph);
                lowTime[u] = Math.min(lowTime[u], lowTime[v]);
            } else if (isInStack[v]) {
                lowTime[u] = Math.min(lowTime[u], insertionTime[v]);
            }
        }
        if (lowTime[u] == insertionTime[u]) {
            List<Integer> scc = new ArrayList<>();
            int w;
            do {
                w = stack.pop();
                scc.add(w);
                isInStack[w] = false;
            } while (w != u);
            sccList.add(scc);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(from).add(to);
        }
        scanner.close();
        TarjansAlgorithm tarjans = new TarjansAlgorithm();
        List<List<Integer>> sccs = tarjans.stronglyConnectedComponents(vertices, graph);
        for (List<Integer> scc : sccs) {
            System.out.println(scc);
        }
    }
}
