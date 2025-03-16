
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Create a Graph class to represent the graph data structure
    static class Graph {
        private ArrayList<ArrayList<Edge>> graph;

        // Initialize the Graph with given size
        Graph(int size) {
            this.graph = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                this.graph.add(new ArrayList<>());
            }
        }

        // Get the neighbours of a node
        private ArrayList<Edge> getNeighbours(int from) {
            return this.graph.get(from);
        }

        // Add an edge between two nodes with given weight
        private void addEdge(int from, int to, int weight) {
            this.graph.get(from).add(new Edge(from, to, weight));
            this.graph.get(to).add(new Edge(to, from, weight));
        }
    }

    // Create an Edge class to represent the edges between nodes
    private static class Edge {
        private int from;
        private int to;
        private int weight;

        // Initialize the Edge with given from, to and weight
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    // Create a PathAndDistance class to store the shortest path and its total distance
    static class PathAndDistance {
        private int distance;
        private ArrayList<Integer> path;

        // Initialize the PathAndDistance with given distance and path
        PathAndDistance(int distance, ArrayList<Integer> path) {
            this.distance = distance;
            this.path = path;
        }

        // Get the total distance of the path
        public int getDistance() {
            return distance;
        }

        // Get the shortest path
        public ArrayList<Integer> getPath() {
            return path;
        }
    }

    // A* algorithm to find the shortest path between two nodes
    public static PathAndDistance aStar(int from, int to, Graph graph, int[] heuristic) {
        PriorityQueue<PathAndDistance> queue = new PriorityQueue<>(Comparator.comparingInt(a -> (a.getDistance() + heuristic[a.getPath().get(a.getPath().size() - 1)])));
        queue.add(new PathAndDistance(0, new ArrayList<>(List.of(from))));

        // While the queue is not empty
        while (!queue.isEmpty()) {
            PathAndDistance current = queue.poll();

            // Check if the current node is the destination node
            int currentPosition = current.getPath().get(current.getPath().size() - 1);
            if (currentPosition == to) {
                return current;
            }

            // Iterate through the neighbours of the current node
            for (Edge edge : graph.getNeighbours(currentPosition)) {
                // If the neighbour is not in the current path
                if (!current.getPath().contains(edge.to)) {
                    // Create a new PathAndDistance with updated path and distance
                    ArrayList<Integer> updatedPath = new ArrayList<>(current.getPath());
                    updatedPath.add(edge.to);
                    queue.add(new PathAndDistance(current.getDistance() + edge.weight, updatedPath));
                }
            }
        }

        // If no path is found, return an empty PathAndDistance object
        return new PathAndDistance(-1, null);
    }

    // Main method to read input and call the A* algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes and edges from the input
        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();

        // Initialize the Graph with given number of nodes
        Graph graph = new Graph(nodes);

        // Read the edges and add them to the Graph
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(from, to, weight);
        }

        // Read the heuristic values for each node
        int[] heuristic = new int[nodes];
        for (int i = 0; i < nodes; i++) {
            heuristic[i] = scanner.nextInt();
        }

        // Read the start and end nodes from the input
        int start = scanner.nextInt();
        int end = scanner.nextInt();

        // Call the A* algorithm to find the shortest path and print the result
        PathAndDistance result = aStar(start, end, graph, heuristic);
        if (result.getPath() != null) {
            System.out.println("Shortest path: " + result.getPath());
            System.out.println("Total distance: " + result.getDistance());
        } else {
            System.out.println("No path found");
        }

        // Close the scanner
        scanner.close();
    }
}