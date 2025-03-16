import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Graph class to represent the graph structure
    static class Graph {
        private ArrayList<ArrayList<Edge>> graph;

        // Constructor to initialize the graph with a given size
        Graph(int size) {
            this.graph = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                this.graph.add(new ArrayList<>());
            }
        }

        // Method to get the neighbors of a given node
        private ArrayList<Edge> getNeighbours(int from) {
            return this.graph.get(from);
        }

        // Method to add an edge between two nodes with a specified weight
        private void addEdge(int from, int to, int weight) {
            this.graph.get(from).add(new Edge(from, to, weight));
            this.graph.get(to).add(new Edge(to, from, weight)); // Add edge in both directions for undirected graph
        }
    }

    // Edge class to represent an edge in the graph
    private static class Edge {
        private int from; // Starting node of the edge
        private int to;   // Ending node of the edge
        private int weight; // Weight of the edge

        // Constructor to initialize the edge
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    // Class to store the path and its total distance
    static class PathAndDistance {
        private int distance; // Total distance of the path
        private ArrayList<Integer> path; // List of nodes in the path

        // Constructor to initialize distance and path
        PathAndDistance(int distance, ArrayList<Integer> path) {
            this.distance = distance;
            this.path = path;
        }

        // Getter for distance
        public int getDistance() {
            return distance;
        }

        // Getter for path
        public ArrayList<Integer> getPath() {
            return path;
        }
    }

    // A* algorithm implementation to find the shortest path
    public static PathAndDistance aStar(int from, int to, Graph graph, int[] heuristic) {
        // Priority queue to store paths with their distances, sorted by estimated total cost
        PriorityQueue<PathAndDistance> queue = new PriorityQueue<>(Comparator.comparingInt(a -> (a.getDistance() + heuristic[a.getPath().get(a.getPath().size() - 1)])));
        
        // Initialize the queue with the starting node
        queue.add(new PathAndDistance(0, new ArrayList<>(List.of(from))));
        
        // Loop until there are no more paths to explore
        while (!queue.isEmpty()) {
            // Get the current shortest path
            PathAndDistance current = queue.poll(); 
            int currentPosition = current.getPath().get(current.getPath().size() - 1); 
            
            // Check if the destination has been reached
            if (currentPosition == to) {
                return current; // Return the found path
            }
            
            // Explore the neighbors of the current node
            for (Edge edge : graph.getNeighbours(currentPosition)) {
                // Avoid cycles by checking if the neighbor is already in the path
                if (!current.getPath().contains(edge.to)) {
                    // Create a new path including the neighbor
                    ArrayList<Integer> updatedPath = new ArrayList<>(current.getPath());
                    updatedPath.add(edge.to);
                    // Add the new path to the queue with updated distance
                    queue.add(new PathAndDistance(current.getDistance() + edge.weight, updatedPath));
                }
            }
        }
        // Return an indication that no path was found
        return new PathAndDistance(-1, null); 
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes and edges from input
        int nodes = scanner.nextInt();
        int edges = scanner.nextInt();
        
        // Initialize the graph with the specified number of nodes
        Graph graph = new Graph(nodes);
        
        // Read edges and add them to the graph
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(from, to, weight);
        }
        
        // Read heuristic values for each node
        int[] heuristic = new int[nodes];
        for (int i = 0; i < nodes; i++) {
            heuristic[i] = scanner.nextInt();
        }
        
        // Read the start and end nodes for the path search
        int start = scanner.nextInt();
        int end = scanner.nextInt();
        
        // Execute the A* algorithm to find the shortest path
        PathAndDistance result = aStar(start, end, graph, heuristic);
        
        // Output the result
        if (result.getPath() != null) {
            System.out.println("Shortest path: " + result.getPath());
            System.out.println("Total distance: " + result.getDistance());
        } else {
            System.out.println("No path found");
        }
    }
}
