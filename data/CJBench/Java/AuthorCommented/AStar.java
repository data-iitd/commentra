
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * AStar class implements the A* pathfinding algorithm to find the shortest path in a graph.
 * The graph is represented using an adjacency list, and the algorithm uses a heuristic to estimate
 * the cost to reach the destination node.
 * Time Complexity = O(E), where E is equal to the number of edges
 */
public final class AStar {

    private AStar() {
    }

    /**
     * Represents a graph using an adjacency list.
     */
    static class Graph {
        private ArrayList<ArrayList<Edge>> graph;

        Graph(int size) {
            this.graph = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                this.graph.add(new ArrayList<>());
            }
        }

        private ArrayList<Edge> getNeighbours(int from) {
            return this.graph.get(from);
        }

        // Add a bidirectional edge to the graph
        private void addEdge(int from, int to, int weight) {
            this.graph.get(from).add(new Edge(from, to, weight));
            this.graph.get(to).add(new Edge(to, from, weight));
        }
    }

    /**
     * Represents an edge in the graph with a start node, end node, and weight.
     */
    private static class Edge {
        private int from;
        private int to;
        private int weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    /**
     * Contains information about the path and its total distance.
     */
    static class PathAndDistance {
        private int distance; // total distance from the start node
        private ArrayList<Integer> path; // list of nodes in the path

        PathAndDistance(int distance, ArrayList<Integer> path) {
            this.distance = distance;
            this.path = path;
        }

        public int getDistance() {
            return distance;
        }

        public ArrayList<Integer> getPath() {
            return path;
        }
    }

    /**
     * Implements the A* pathfinding algorithm to find the shortest path from a start node to a destination node.
     *
     * @param from     the starting node
     * @param to       the destination node
     * @param graph    the graph representation of the problem
     * @param heuristic the heuristic estimates for each node
     * @return a PathAndDistance object containing the shortest path and its distance
     */
    public static PathAndDistance aStar(int from, int to, Graph graph, int[] heuristic) {
        // PriorityQueue to explore nodes based on their distance and estimated cost to reach the destination
        PriorityQueue<PathAndDistance> queue = new PriorityQueue<>(Comparator.comparingInt(a -> (a.getDistance() + heuristic[a.getPath().get(a.getPath().size() - 1)])));

        // Start with the initial node
        queue.add(new PathAndDistance(0, new ArrayList<>(List.of(from))));

        while (!queue.isEmpty()) {
            PathAndDistance current = queue.poll(); // get the best node from the queue
            int currentPosition = current.getPath().get(current.getPath().size() - 1); // current node

            // Check if the destination has been reached
            if (currentPosition == to) {
                return current;
            }

            // Avoid cycles by checking if the next node is already in the path
            for (Edge edge : graph.getNeighbours(currentPosition)) {
                if (!current.getPath().contains(edge.to)) {
                    ArrayList<Integer> updatedPath = new ArrayList<>(current.getPath());
                    updatedPath.add(edge.to);

                    // Update the distance and heuristic for the new path
                    queue.add(new PathAndDistance(current.getDistance() + edge.weight, updatedPath));
                }
            }
        }

        return new PathAndDistance(-1, null); // No path found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int nodes = scanner.nextInt();

        int edges = scanner.nextInt();

        Graph graph = new Graph(nodes);
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(from, to, weight);
        }

        int[] heuristic = new int[nodes];
        for (int i = 0; i < nodes; i++) {
            heuristic[i] = scanner.nextInt();
        }

        int start = scanner.nextInt();
        int end = scanner.nextInt();

        PathAndDistance result = aStar(start, end, graph, heuristic);
        if (result.getPath() != null) {
            System.out.println("Shortest path: " + result.getPath());
            System.out.println("Total distance: " + result.getDistance());
        } else {
            System.out.println("No path found");
        }
    }
}
