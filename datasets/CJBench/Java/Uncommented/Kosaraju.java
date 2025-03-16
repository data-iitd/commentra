
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;
public class Kosaraju {
    private final Stack<Integer> stack = new Stack<>();
    private List<Integer> scc = new ArrayList<>();
    private final List<List<Integer>> sccsList = new ArrayList<>();
    public List<List<Integer>> kosaraju(int v, List<List<Integer>> list) {
        sortEdgesByLowestFinishTime(v, list);
        List<List<Integer>> transposeGraph = createTransposeMatrix(v, list);
        findStronglyConnectedComponents(v, transposeGraph);
        return sccsList;
    }
    private void sortEdgesByLowestFinishTime(int v, List<List<Integer>> list) {
        int[] vis = new int[v];
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, list);
            }
        }
    }
    private List<List<Integer>> createTransposeMatrix(int v, List<List<Integer>> list) {
        List<List<Integer>> transposeGraph = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            transposeGraph.add(new ArrayList<>());
        }
        for (int i = 0; i < v; i++) {
            for (Integer neigh : list.get(i)) {
                transposeGraph.get(neigh).add(i);
            }
        }
        return transposeGraph;
    }
    public void findStronglyConnectedComponents(int v, List<List<Integer>> transposeGraph) {
        int[] vis = new int[v];
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (vis[node] == 0) {
                dfs2(node, vis, transposeGraph);
                sccsList.add(scc);
                scc = new ArrayList<>();
            }
        }
    }
    private void dfs(int node, int[] vis, List<List<Integer>> list) {
        vis[node] = 1;
        for (Integer neighbour : list.get(node)) {
            if (vis[neighbour] == 0) {
                dfs(neighbour, vis, list);
            }
        }
        stack.push(node);
    }
    private void dfs2(int node, int[] vis, List<List<Integer>> list) {
        vis[node] = 1;
        for (Integer neighbour : list.get(node)) {
            if (vis[neighbour] == 0) {
                dfs2(neighbour, vis, list);
            }
        }
        scc.add(node);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt();
        int edges = sc.nextInt();
        List<List<Integer>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int i = 0; i < edges; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adjacencyList.get(u).add(v);
        }
        Kosaraju kosaraju = new Kosaraju();
        List<List<Integer>> sccs = kosaraju.kosaraju(vertices, adjacencyList);
        System.out.println("Strongly Connected Components:");
        for (List<Integer> scc : sccs) {
            System.out.println(scc);
        }
        sc.close();
    }
}
