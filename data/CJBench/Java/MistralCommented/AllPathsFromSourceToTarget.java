import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Main class for DFS path finding algorithm.
 */
public class Main {
    private final int v; // number of vertices
    private List<List<Integer>> paths; // list to store all paths from source to destination
    private ArrayList<Integer>[] adjList; // adjacency list to represent graph

    /**
     * Initialize Main class with given number of vertices.
     *
     * @param vertices number of vertices
     */
    public Main(int vertices) {
        this.v = vertices;
        initAdjList();
    }

    /**
     * Initialize adjacency list with size equal to number of vertices.
     */
    private void initAdjList() {
        adjList = new ArrayList[v];
        for (int i = 0; i < v; i++) {
            adjList[i] = new ArrayList<>();
        }
    }

    /**
     * Add edge between two vertices in adjacency list.
     *
     * @param u source vertex
     * @param v target vertex
     */
    public void addEdge(int u, int v) {
        adjList[u].add(v);
    }

    /**
     * Find all paths from source to destination using DFS algorithm.
     *
     * @param s source vertex
     * @param d destination vertex
     */
    public void storeAllPaths(int s, int d) {
        boolean[] isVisited = new boolean[v]; // boolean array to mark visited vertices
        ArrayList<Integer> pathList = new ArrayList<>(); // list to store current path
        pathList.add(s); // add source vertex to the path list
        storeAllPathsUtil(s, d, isVisited, pathList); // recursive call to find all paths
    }

    /**
     * Recursive helper method to find all paths from source to destination.
     *
     * @param u current vertex
     * @param d destination vertex
     * @param isVisited boolean array to mark visited vertices
     * @param localPathList list to store current path
     */
    private void storeAllPathsUtil(Integer u, Integer d, boolean[] isVisited, List<Integer> localPathList) {
        if (u.equals(d)) { // base case: destination reached
            paths.add(new ArrayList<>(localPathList)); // add path to the list of paths
            return;
        }

        isVisited[u] = true; // mark current vertex as visited
        for (Integer i : adjList[u]) { // iterate through neighbors of current vertex
            if (!isVisited[i]) { // if neighbor not visited yet
                localPathList.add(i); // add neighbor to the current path list
                storeAllPathsUtil(i, d, isVisited, localPathList); // recursive call to find all paths from neighbor to destination
                localPathList.remove(localPathList.size() - 1); // backtrack to previous vertex
            }
        }
        isVisited[u] = false; // mark current vertex as not visited
    }

    /**
     * Get all paths from source to destination.
     *
     * @return list of all paths
     */
    public List<List<Integer>> getPaths() {
        return paths;
    }

    /**
     * Main method to read input and run the algorithm.
     *
     * @param args command line arguments (not used in this program)
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // read input from standard input

        // read number of vertices and edges
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        // read edges and add them to the graph
        int[][] edgeList = new int[edges][2];
        for (int i = 0; i < edges; i++) {
            edgeList[i][0] = scanner.nextInt();
            edgeList[i][1] = scanner.nextInt();
            Main graph = new Main(vertices); // create new instance of Main class
            graph.addEdge(edgeList[i][0], edgeList[i][1]); // add edge to the graph
        }

        // read source and destination vertices
        int source = scanner.nextInt();
        int destination = scanner.nextInt();

        // find all paths from source to destination
        Main graph = new Main(vertices);
        for (int[] edge : edgeList) {
            graph.addEdge(edge[0], edge[1]);
        }
        graph.storeAllPaths(source, destination);

        // print all paths from source to destination
        System.out.println("All paths from source to destination: ");
        for (List<Integer> path : graph.getPaths()) {
            System.out.println(path);
        }

        scanner.close(); // close standard input
    }
}
