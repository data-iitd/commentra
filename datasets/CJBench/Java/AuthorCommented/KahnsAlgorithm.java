import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;

/**
 * A class representing the adjacency list of a directed graph. The adjacency list
 * maintains a mapping of vertices to their adjacent vertices.
 *
 * @param <E> the type of vertices, extending Comparable to ensure that vertices
 * can be compared
 */
class AdjacencyList<E extends Comparable<E>> {
    Map<E, ArrayList<E>> adj;

    /**
     * Constructor to initialize the adjacency list.
     */
    AdjacencyList() {
        adj = new LinkedHashMap<>();
    }

    /**
     * Adds a directed edge from one vertex to another in the adjacency list.
     * If the vertex does not exist, it will be added to the list.
     *
     * @param from the starting vertex of the directed edge
     * @param to   the destination vertex of the directed edge
     */
    void addEdge(E from, E to) {
        adj.putIfAbsent(from, new ArrayList<>());
        adj.get(from).add(to);
        adj.putIfAbsent(to, new ArrayList<>());
    }

    /**
     * Retrieves the list of adjacent vertices for a given vertex.
     *
     * @param v the vertex whose adjacent vertices are to be fetched
     * @return an ArrayList of adjacent vertices for vertex v
     */
    ArrayList<E> getAdjacents(E v) {
        return adj.get(v);
    }

    /**
     * Retrieves the set of all vertices present in the graph.
     *
     * @return a set containing all vertices in the graph
     */
    Set<E> getVertices() {
        return adj.keySet();
    }
}

/**
 * A class that performs topological sorting on a directed graph using Kahn's algorithm.
 *
 * @param <E> the type of vertices, extending Comparable to ensure that vertices
 * can be compared
 */
class TopologicalSort<E extends Comparable<E>> {
    AdjacencyList<E> graph;
    Map<E, Integer> inDegree;

    /**
     * Constructor to initialize the topological sorting class with a given graph.
     *
     * @param graph the directed graph represented as an adjacency list
     */
    TopologicalSort(AdjacencyList<E> graph) {
        this.graph = graph;
    }

    /**
     * Calculates the in-degree of all vertices in the graph. The in-degree is
     * the number of edges directed into a vertex.
     */
    void calculateInDegree() {
        inDegree = new HashMap<>();
        for (E vertex : graph.getVertices()) {
            inDegree.putIfAbsent(vertex, 0);
            for (E adjacent : graph.getAdjacents(vertex)) {
                inDegree.put(adjacent, inDegree.getOrDefault(adjacent, 0) + 1);
            }
        }
    }

    /**
     * Returns an ArrayList containing the vertices of the graph arranged in
     * topological order. Topological sorting ensures that for any directed edge
     * (u, v), vertex u appears before vertex v in the ordering.
     *
     * @return an ArrayList of vertices in topological order
     * @throws IllegalStateException if the graph contains a cycle
     */
    ArrayList<E> topSortOrder() {
        calculateInDegree();
        Queue<E> q = new LinkedList<>();

        for (var entry : inDegree.entrySet()) {
            if (entry.getValue() == 0) {
                q.add(entry.getKey());
            }
        }

        ArrayList<E> answer = new ArrayList<>();
        int processedVertices = 0;

        while (!q.isEmpty()) {
            E current = q.poll();
            answer.add(current);
            processedVertices++;

            for (E adjacent : graph.getAdjacents(current)) {
                inDegree.put(adjacent, inDegree.get(adjacent) - 1);
                if (inDegree.get(adjacent) == 0) {
                    q.add(adjacent);
                }
            }
        }

        if (processedVertices != graph.getVertices().size()) {
            throw new IllegalStateException("Graph contains a cycle, topological sort not possible");
        }

        return answer;
    }
}

/**
 * A driver class that sorts a given graph in topological order using Kahn's algorithm.
 */
public final class KahnsAlgorithm {
    private KahnsAlgorithm() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        AdjacencyList<String> graph = new AdjacencyList<>();
        for (int i = 0; i < edges; i++) {
            String from = scanner.next();
            String to = scanner.next();
            graph.addEdge(from, to);
        }

        TopologicalSort<String> topSort = new TopologicalSort<>(graph);
        try {
            ArrayList<String> sortedOrder = topSort.topSortOrder();
            System.out.println("Topological Order:");
            for (String s : sortedOrder) {
                System.out.print(s + " ");
            }
            System.out.println();
        } catch (IllegalStateException e) {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }
}
