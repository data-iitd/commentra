
import java.util.ArrayList;
import java.util.Scanner;

/**
 * A class to find and print all cycles in a directed graph using Depth First Search (DFS).
 */
class Cycle {

    private final int nodes;
    private int[][] adjacencyMatrix;
    private boolean[] visited;
    ArrayList<ArrayList<Integer>> cycles = new ArrayList<>();

    /**
     * Constructor to initialize the graph.
     *
     * @param nodes      The number of nodes in the graph.
     * @param edges      The number of edges in the graph.
     * @param edgesInput The edges of the graph, represented as an array of [start, end] pairs.
     */
    Cycle(int nodes, int edges, int[][] edgesInput) {
        this.nodes = nodes;
        adjacencyMatrix = new int[nodes][nodes];
        visited = new boolean[nodes];

        // Initialize visited array
        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
        }

        // Fill adjacency matrix with edge data
        for (int[] edge : edgesInput) {
            int start = edge[0];
            int end = edge[1];
            adjacencyMatrix[start][end] = 1;
        }
    }

    /**
     * Starts the process of finding all cycles in the graph.
     */
    public void start() {
        for (int i = 0; i < nodes; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            dfs(i, i, temp);
            for (int j = 0; j < nodes; j++) {
                adjacencyMatrix[i][j] = 0;
                adjacencyMatrix[j][i] = 0;
            }
        }
    }

    /**
     * Depth First Search (DFS) to find cycles.
     *
     * @param start The starting node of the DFS.
     * @param curr  The current node being processed.
     * @param temp  Temporary list to keep track of the current path.
     */
    private void dfs(Integer start, Integer curr, ArrayList<Integer> temp) {
        temp.add(curr);
        visited[curr] = true;
        for (int i = 0; i < nodes; i++) {
            if (adjacencyMatrix[curr][i] == 1) {
                if (i == start) {
                    cycles.add(new ArrayList<>(temp));
                } else {
                    if (!visited[i]) {
                        dfs(start, i, temp);
                    }
                }
            }
        }

        if (temp.size() > 0) {
            temp.remove(temp.size() - 1);
        }
        visited[curr] = false;
    }

    /**
     * Prints all detected cycles in the graph.
     */
    public void printAll() {
        if (cycles.isEmpty()) {
            System.out.println("No cycles found.");
            return;
        }

        for (ArrayList<Integer> cycle : cycles) {
            for (int i = 0; i < cycle.size(); i++) {
                System.out.print(cycle.get(i) + " -> ");
            }
            System.out.println(cycle.get(0));
            System.out.println();
        }
    }
}

/**
 * The main class to execute the program.
 */
public final class Cycles {
    private Cycles() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();

        int[][] edgesInput = new int[edges][2];
        for (int i = 0; i < edges; i++) {
            edgesInput[i][0] = scanner.nextInt();
            edgesInput[i][1] = scanner.nextInt();
        }

        Cycle cycleFinder = new Cycle(nodes, edges, edgesInput);
        cycleFinder.start();
        cycleFinder.printAll();
    }
}
