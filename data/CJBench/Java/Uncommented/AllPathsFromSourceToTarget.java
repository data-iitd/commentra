
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class AllPathsFromSourceToTarget {
    private final int v;
    private final List<List<Integer>> paths = new ArrayList<>();
    private ArrayList<Integer>[] adjList;
    public AllPathsFromSourceToTarget(int vertices) {
        this.v = vertices;
        initAdjList();
    }
    private void initAdjList() {
        adjList = new ArrayList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new ArrayList<>();
        }
    }
    public void addEdge(int u, int v) {
        adjList[u].add(v);
    }
    public void storeAllPaths(int s, int d) {
        boolean[] isVisited = new boolean[v];
        ArrayList<Integer> pathList = new ArrayList<>();
        pathList.add(s);
        storeAllPathsUtil(s, d, isVisited, pathList);
    }
    private void storeAllPathsUtil(Integer u, Integer d, boolean[] isVisited, List<Integer> localPathList) {
        if (u.equals(d)) {
            paths.add(new ArrayList<>(localPathList));
            return;
        }
        isVisited[u] = true;
        for (Integer i : adjList[u]) {
            if (!isVisited[i]) {
                localPathList.add(i);
                storeAllPathsUtil(i, d, isVisited, localPathList);
                localPathList.remove(i);
            }
        }
        isVisited[u] = false;
    }
    public List<List<Integer>> getPaths() {
        return paths;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        int[][] edgeList = new int[edges][2];
        for (int i = 0; i < edges; i++) {
            edgeList[i][0] = scanner.nextInt();
            edgeList[i][1] = scanner.nextInt();
        }
        int source = scanner.nextInt();
        int destination = scanner.nextInt();
        AllPathsFromSourceToTarget graph = new AllPathsFromSourceToTarget(vertices);
        for (int[] edge : edgeList) {
            graph.addEdge(edge[0], edge[1]);
        }
        graph.storeAllPaths(source, destination);
        System.out.println("All paths from source to destination: ");
        for (List<Integer> path : graph.getPaths()) {
            System.out.println(path);
        }
        scanner.close();
    }
}
