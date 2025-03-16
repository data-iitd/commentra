import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    // Represents a graph using an adjacency list
    static class Graph {
        private ArrayList<ArrayList<Edge>> graph;
        // Initializes the graph with a given size
        Graph(int size) {
            this.graph = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                this.graph.add(new ArrayList<>());
            }
        }
        // Returns the neighbors of a given node
        private ArrayList<Edge> getNeighbours(int from) {
            return this.graph.get(from);
        }
        // Adds an edge to the graph
        private void addEdge(int from, int to, int weight) {
            this.graph.get(from).add(new Edge(from, to, weight));
            this.graph.get(to).add(new Edge(to, from, weight));
        }
    }
    // Represents an edge in the graph
    private static class Edge {
        private int from;
        private int to;
        private int weight;
        // Initializes an edge with source, destination, and weight
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }
    // Holds the path and the total distance of a path
    static class PathAndDistance {
        private int distance; 
        private ArrayList<Integer> path; 
        // Initializes the path and distance
        PathAndDistance(int distance, ArrayList<Integer> path) {
            this.distance = distance;
            this.path = path;
        }
        // Returns the total distance of the path
        public int getDistance() {
            return distance;
        }
        // Returns the path
        public ArrayList<Integer> getPath() {
            return path;
        }
    }
    // Implements the A* search algorithm to find the shortest path
    public static PathAndDistance aStar(int from, int to, Graph graph, int[] heuristic) {
        // Priority queue to explore the shortest paths
        PriorityQueue<PathAndDistance> queue = new PriorityQueue<>(Comparator.comparingInt(a -> (a.getDistance() + heuristic[a.getPath().get(a.getPath().size() - 1)])));
        queue.add(new PathAndDistance(0, new ArrayList<>(List.of(from))));
        while (!queue.isEmpty()) {
            PathAndDistance current = queue.poll(); 
            int currentPosition = current.getPath().get(current.getPath().size() - 1); 
            if (currentPosition == to) {
                return current;
            }
            for (Edge edge : graph.getNeighbours(currentPosition)) {
                if (!current.getPath().contains(edge.to)) {
                    ArrayList<Integer> updatedPath = new ArrayList<>(current.getPath());
                    updatedPath.add(edge.to);
                    queue.add(new PathAndDistance(current.getDistance() + edge.weight, updatedPath));
                }
            }
        }
        return new PathAndDistance(-1, null); 
    }
    // Reads input for the graph, heuristics, and start/end nodes, then finds the shortest path and prints the result
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
