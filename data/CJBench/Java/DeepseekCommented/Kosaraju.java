import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    // Stack to store nodes according to their finishing times
    private final Stack<Integer> stack = new Stack<>();
    // List to store the current strongly connected component
    private List<Integer> scc = new ArrayList<>();
    // List to store all strongly connected components
    private final List<List<Integer>> sccsList = new ArrayList<>();

    // Main method to execute Kosaraju's algorithm
    public List<List<Integer>> kosaraju(int v, List<List<Integer>> list) {
        // Sort edges by lowest finish time
        sortEdgesByLowestFinishTime(v, list);
        // Create transpose of the graph
        List<List<Integer>> transposeGraph = createTransposeMatrix(v, list);
        // Find strongly connected components using the transpose graph
        findStronglyConnectedComponents(v, transposeGraph);
        // Return the list of strongly connected components
        return sccsList;
    }

    // Method to sort edges by lowest finish time using DFS
    private void sortEdgesByLowestFinishTime(int v, List<List<Integer>> list) {
        int[] vis = new int[v];
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, list);
            }
        }
    }

    // Method to create transpose of the graph
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

    // Method to find strongly connected components using DFS on transpose graph
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

    // First DFS to sort nodes by finishing times
    private void dfs(int node, int[] vis, List<List<Integer>> list) {
        vis[node] = 1;
        for (Integer neighbour : list.get(node)) {
            if (vis[neighbour] == 0) {
                dfs(neighbour, vis, list);
            }
        }
        stack.push(node);
    }

    // Second DFS to find strongly connected components
    private void dfs2(int node, int[] vis, List<List<Integer>> list) {
        vis[node] = 1;
        for (Integer neighbour : list.get(node)) {
            if (vis[neighbour] == 0) {
                dfs2(neighbour, vis, list);
            }
        }
        scc.add(node);
    }

    // Main method to read input and execute Kosaraju's algorithm
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
        Main kosaraju = new Main();
        List<List<Integer>> sccs = kosaraju.kosaraju(vertices, adjacencyList);
        System.out.println("Strongly Connected Components:");
        for (List<Integer> scc : sccs) {
            System.out.println(scc);
        }
        sc.close();
    }
}
