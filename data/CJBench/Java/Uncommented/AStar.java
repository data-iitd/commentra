
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
public final class AStar {
    private AStar() {
    }
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
        private void addEdge(int from, int to, int weight) {
            this.graph.get(from).add(new Edge(from, to, weight));
            this.graph.get(to).add(new Edge(to, from, weight));
        }
    }
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
    static class PathAndDistance {
        private int distance; 
        private ArrayList<Integer> path; 
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
    public static PathAndDistance aStar(int from, int to, Graph graph, int[] heuristic) {
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
