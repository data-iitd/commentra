import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // The Main class is the entry point of the program.
    // It reads the number of vertices and edges from the input.
    // It creates an instance of AdjacencyMatrixGraph and adds edges based on the input.
    // It then performs depth-first and breadth-first searches starting from specified vertices and prints the results.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        AdjacencyMatrixGraph graph = new AdjacencyMatrixGraph(vertices);
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }
        int dfsStartVertex = scanner.nextInt();
        int bfsStartVertex = scanner.nextInt();
        System.out.println("The graph matrix:");
        System.out.println(graph);
        System.out.println("Depth First Order:");
        System.out.println(graph.depthFirstOrder(dfsStartVertex));
        System.out.println("Breadth First Order:");
        System.out.println(graph.breadthFirstOrder(bfsStartVertex));
    }
}

class AdjacencyMatrixGraph {
    private int vertexCount;
    private int edgeCount;
    private int[][] adjMatrix;
    static final int EDGE_EXIST = 1;
    static final int EDGE_NONE = 0;

    // This class represents a graph using an adjacency matrix.
    // It provides methods to add edges, perform depth-first search, and breadth-first search.
    // It also includes a method to convert the graph to a string representation for easy visualization.
    AdjacencyMatrixGraph(int givenNumberOfVertices) {
        this.vertexCount = givenNumberOfVertices;
        this.edgeCount = 0;
        this.adjMatrix = new int[givenNumberOfVertices][givenNumberOfVertices];
    }

    // Returns the number of vertices in the graph.
    public int numberOfVertices() {
        return this.vertexCount;
    }

    // Returns the number of edges in the graph.
    public int numberOfEdges() {
        return this.edgeCount;
    }

    // Adds an edge between two vertices in the graph.
    public boolean addEdge(int from, int to) {
        if (from >= 0 && from < vertexCount && to >= 0 && to < vertexCount) {
            if (adjMatrix[from][to] == EDGE_NONE) {
                adjMatrix[from][to] = EDGE_EXIST;
                adjMatrix[to][from] = EDGE_EXIST;
                edgeCount++;
                return true;
            }
        }
        return false;
    }

    // Initiates a depth-first search from the specified start vertex.
    public List<Integer> depthFirstOrder(int startVertex) {
        if (startVertex < 0 || startVertex >= vertexCount) {
            return new ArrayList<>();
        }
        boolean[] visited = new boolean[vertexCount];
        List<Integer> orderList = new ArrayList<>();
        dfs(startVertex, visited, orderList);
        return orderList;
    }

    // Helper method for depth-first search (DFS).
    private void dfs(int currentVertex, boolean[] visited, List<Integer> orderList) {
        if (visited[currentVertex]) return;
        visited[currentVertex] = true;
        orderList.add(currentVertex);
        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[currentVertex][i] == EDGE_EXIST) {
                dfs(i, visited, orderList);
            }
        }
    }

    // Initiates a breadth-first search from the specified start vertex.
    public List<Integer> breadthFirstOrder(int startVertex) {
        if (startVertex < 0 || startVertex >= vertexCount) {
            return new ArrayList<>();
        }
        boolean[] visited = new boolean[vertexCount];
        List<Integer> orderList = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startVertex);
        while (!queue.isEmpty()) {
            int currentVertex = queue.poll();
            if (visited[currentVertex]) continue;
            visited[currentVertex] = true;
            orderList.add(currentVertex);
            for (int i = 0; i < vertexCount; i++) {
                if (adjMatrix[currentVertex][i] == EDGE_EXIST) {
                    queue.add(i);
                }
            }
        }
        return orderList;
    }

    // Provides a string representation of the adjacency matrix for easy visualization of the graph.
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("    ");
        for (int i = 0; i < vertexCount; i++) {
            sb.append(i).append(" ");
        }
        sb.append("\n");
        for (int i = 0; i < vertexCount; i++) {
            sb.append(i).append(" : ");
            for (int j = 0; j < vertexCount; j++) {
                sb.append(adjMatrix[i][j]).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}
