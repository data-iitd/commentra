
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Program description - To find all possible paths from source to destination
 * <a href="https://en.wikipedia.org/wiki/Shortest_path_problem">Wikipedia</a>
 *
 * @author <a href="https://github.com/siddhant2002">Siddhant Swarup Mallick</a>
 */
public class AllPathsFromSourceToTarget {

    // No. of vertices in graph
    private final int v;

    // To store the paths from source to destination
    private final List<List<Integer>> paths = new ArrayList<>();

    // adjacency list
    private ArrayList<Integer>[] adjList;

    // Constructor
    public AllPathsFromSourceToTarget(int vertices) {
        this.v = vertices;
        initAdjList();
    }

    // utility method to initialise adjacency list
    private void initAdjList() {
        adjList = new ArrayList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new ArrayList<>();
        }
    }

    // add edge from u to v
    public void addEdge(int u, int v) {
        adjList[u].add(v);
    }

    public void storeAllPaths(int s, int d) {
        boolean[] isVisited = new boolean[v];
        ArrayList<Integer> pathList = new ArrayList<>();
        pathList.add(s);
        storeAllPathsUtil(s, d, isVisited, pathList);
    }

    // A recursive function to print all paths from 'u' to 'd'.
    // isVisited[] keeps track of vertices in current path.
    // localPathList<> stores actual vertices in the current path
    private void storeAllPathsUtil(Integer u, Integer d, boolean[] isVisited, List<Integer> localPathList) {
        if (u.equals(d)) {
            paths.add(new ArrayList<>(localPathList));
            return;
        }

        // Mark the current node
        isVisited[u] = true;

        // Recursion for all the vertices adjacent to current vertex
        for (Integer i : adjList[u]) {
            if (!isVisited[i]) {
                // store current node in path[]
                localPathList.add(i);
                storeAllPathsUtil(i, d, isVisited, localPathList);
                // remove current node in path[]
                localPathList.remove(i);
            }
        }

        // Mark the current node
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
