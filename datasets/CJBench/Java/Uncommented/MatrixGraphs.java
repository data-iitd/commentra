
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
public final class MatrixGraphs {
    private MatrixGraphs() {
    }
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
    AdjacencyMatrixGraph(int givenNumberOfVertices) {
        this.vertexCount = givenNumberOfVertices;
        this.edgeCount = 0;
        this.adjMatrix = new int[givenNumberOfVertices][givenNumberOfVertices];
    }
    public int numberOfVertices() {
        return this.vertexCount;
    }
    public int numberOfEdges() {
        return this.edgeCount;
    }
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
    public List<Integer> depthFirstOrder(int startVertex) {
        if (startVertex < 0 || startVertex >= vertexCount) {
            return new ArrayList<>();
        }
        boolean[] visited = new boolean[vertexCount];
        List<Integer> orderList = new ArrayList<>();
        dfs(startVertex, visited, orderList);
        return orderList;
    }
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
