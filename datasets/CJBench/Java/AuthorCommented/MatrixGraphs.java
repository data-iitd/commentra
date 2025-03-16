
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

/**
 * Implementation of a graph in a matrix form Also known as an adjacency matrix
 * representation [Adjacency matrix -
 * Wikipedia](https://en.wikipedia.org/wiki/Adjacency_matrix)
 *
 * @author Unknown
 */
public final class MatrixGraphs {
    private MatrixGraphs() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read number of vertices and edges
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        AdjacencyMatrixGraph graph = new AdjacencyMatrixGraph(vertices);

        // Read edges
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }

        // Read starting vertices for DFS and BFS
        int dfsStartVertex = scanner.nextInt();
        int bfsStartVertex = scanner.nextInt();

        // Output the results
        System.out.println("The graph matrix:");
        System.out.println(graph);
        System.out.println("Depth First Order:");
        System.out.println(graph.depthFirstOrder(dfsStartVertex));
        System.out.println("Breadth First Order:");
        System.out.println(graph.breadthFirstOrder(bfsStartVertex));
    }
}

/**
 * AdjacencyMatrixGraph Implementation
 */
class AdjacencyMatrixGraph {

    /**
     * The number of vertices in the graph
     */
    private int vertexCount;

    /**
     * The number of edges in the graph
     */
    private int edgeCount;

    /**
     * The adjacency matrix for the graph
     */
    private int[][] adjMatrix;

    /**
     * Static variables to define whether or not an edge exists in the adjacency
     * matrix
     */
    static final int EDGE_EXIST = 1;
    static final int EDGE_NONE = 0;

    /**
     * Constructor
     */
    AdjacencyMatrixGraph(int givenNumberOfVertices) {
        this.vertexCount = givenNumberOfVertices;
        this.edgeCount = 0;
        this.adjMatrix = new int[givenNumberOfVertices][givenNumberOfVertices];
    }

    /**
     * Getter for `this.vertexCount`
     *
     * @return the number of vertices in the graph
     */
    public int numberOfVertices() {
        return this.vertexCount;
    }

    /**
     * Getter for `this.edgeCount`
     *
     * @return the number of edges
     */
    public int numberOfEdges() {
        return this.edgeCount;
    }

    /**
     * This method adds an edge to the graph between two specified vertices
     *
     * @param from the data of the vertex the edge is from
     * @param to the data of the vertex the edge is going to
     * @return returns true if the edge did not exist, return false if it
     * already did
     */
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

    /**
     * This method returns a list of the vertices in a depth first order
     * beginning with the specified vertex
     *
     * @param startVertex the vertex to begin the traversal
     * @return the list of the ordered vertices
     */
    public List<Integer> depthFirstOrder(int startVertex) {
        if (startVertex < 0 || startVertex >= vertexCount) {
            return new ArrayList<>();
        }

        boolean[] visited = new boolean[vertexCount];
        List<Integer> orderList = new ArrayList<>();
        dfs(startVertex, visited, orderList);
        return orderList;
    }

    /**
     * Helper method for public depthFirstOrder(int) that will perform a depth
     * first traversal recursively on the graph
     *
     * @param currentVertex the currently exploring vertex
     * @param visited the array of values denoting whether or not that vertex
     * has been visited
     * @param orderList the list to add vertices to as they are visited
     */
    private void dfs(int currentVertex, boolean[] visited, List<Integer> orderList) {
        if (visited[currentVertex]) return;

        // Visit the currentVertex by marking it as visited and adding it
        // to the orderList
        visited[currentVertex] = true;
        orderList.add(currentVertex);

        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[currentVertex][i] == EDGE_EXIST) {
                dfs(i, visited, orderList);
            }
        }
    }

    /**
     * This method returns a list of the vertices in a breadth first order
     * beginning with the specified vertex
     *
     * @param startVertex the vertext to begin the traversal
     * @return the list of the ordered vertices
     */
    public List<Integer> breadthFirstOrder(int startVertex) {
        // If the specified startVertex is invalid, return an empty list
        if (startVertex < 0 || startVertex >= vertexCount) {
            return new ArrayList<>();
        }

        // Create an array to keep track of the visited vertices
        boolean[] visited = new boolean[vertexCount];
        // Create a list to keep track of the ordered vertices
        List<Integer> orderList = new ArrayList<>();
        // Create a queue for our BFS algorithm and add the startVertex
        // to the queue
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startVertex);

        // Continue until the queue is empty
        while (!queue.isEmpty()) {
            // Remove the first vertex in the queue
            int currentVertex = queue.poll();
            // If we've visited this vertex, skip it
            if (visited[currentVertex]) continue;

            // We now visit this vertex by adding it to the orderList and
            // marking it as visited
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

    /**
     * this gives a list of vertices in the graph and their adjacencies
     *
     * @return returns a string describing this graph
     */
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
