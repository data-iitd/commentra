
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

/**
 * Java program that implements Tarjan's Algorithm to find Strongly Connected Components (SCCs) in a directed graph.
 *
 * <p>
 * Tarjan's algorithm is a linear time algorithm (O(V + E)) that identifies the SCCs of a directed graph.
 * An SCC is a maximal subgraph where every vertex is reachable from every other vertex within the subgraph.
 *
 * <h3>Algorithm Overview:</h3>
 * <ul>
 * <li>DFS Search: A depth-first search (DFS) is performed on the graph to generate a DFS tree.</li>
 * <li>Identification of SCCs: SCCs correspond to subtrees within this DFS tree.</li>
 * <li>Low-Link Values: For each node, a low-link value is maintained, which indicates the earliest visited
 * vertex (the one with the minimum insertion time) that can be reached from that subtree.</li>
 * <li>Stack Usage: Nodes are stored in a stack during DFS. When an SCC is identified, nodes are popped from
 * the stack until the head of the SCC is reached.</li>
 * </ul>
 *
 * <p>
 * Example of a directed graph:
 * <pre>
 *  0 --------> 1 -------> 3 --------> 4
 *  ^          /
 *  |         /
 *  |        /
 *  |       /
 *  |      /
 *  |     /
 *  |    /
 *  |   /
 *  |  /
 *  | /
 *  V
 *  2
 * </pre>
 *
 * <p>
 * For the above graph, the SCC list is as follows:
 * <ul>
 * <li>1, 2, 0</li>
 * <li>3</li>
 * <li>4</li>
 * </ul>
 * The order of nodes in an SCC does not matter as they form cycles.
 *
 * <h3>Comparison with Kosaraju's Algorithm:</h3>
 * <p>
 * Kosaraju's algorithm also identifies SCCs but does so using two DFS traversals.
 * In contrast, Tarjan's algorithm achieves this in a single DFS traversal, leading to improved performance
 * in terms of constant factors.
 * </p>
 */
public class TarjansAlgorithm {

    // Timer for tracking low time and insertion time
    private int time;
    // List to store all strongly connected components
    private final List<List<Integer>> sccList = new ArrayList<>();

    /**
     * Finds and returns the strongly connected components (SCCs) of the directed graph.
     *
     * @param v the number of vertices in the graph
     * @param graph the adjacency list representation of the graph
     * @return a list of lists, where each inner list represents a strongly connected component
     */
    public List<List<Integer>> stronglyConnectedComponents(int v, List<List<Integer>> graph) {
        // Initialize arrays for insertion time and low-link values
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

        // Read number of vertices and edges
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        // Build adjacency list
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

        // Run Tarjan's Algorithm
        TarjansAlgorithm tarjans = new TarjansAlgorithm();
        List<List<Integer>> sccs = tarjans.stronglyConnectedComponents(vertices, graph);

        // Print the results
        for (List<Integer> scc : sccs) {
            System.out.println(scc);
        }
    }
}
