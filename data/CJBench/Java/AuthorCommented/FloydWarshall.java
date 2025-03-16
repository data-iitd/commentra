import java.util.Scanner;

/**
 * The {@code FloydWarshall} class provides an implementation of the Floyd-Warshall algorithm
 * to compute the shortest paths between all pairs of vertices in a weighted graph.
 * It handles both positive and negative edge weights but does not support negative cycles.
 * The algorithm is based on dynamic programming and runs in O(V^3) time complexity,
 * where V is the number of vertices in the graph.
 *
 * <p>
 * The distance matrix is updated iteratively to find the shortest distance between any two vertices
 * by considering each vertex as an intermediate step.
 * </p>
 *
 * Reference: <a href="https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm">Floyd-Warshall Algorithm</a>
 */
public class FloydWarshall {

    private int[][] distanceMatrix;
    private int numberofvertices;
    public static final int INFINITY = 999;

    /**
     * Constructs a Floyd-Warshall instance for a graph with the given number of vertices.
     * Initializes the distance matrix for the graph.
     *
     * @param numberofvertices The number of vertices in the graph.
     */
    public FloydWarshall(int numberofvertices) {
        distanceMatrix = new int[numberofvertices + 1][numberofvertices + 1];
        // The matrix is initialized with 0's by default
        this.numberofvertices = numberofvertices;
    }

    /**
     * Executes the Floyd-Warshall algorithm to compute the shortest path between all pairs of vertices.
     * It uses an adjacency matrix to calculate the distance matrix by considering each vertex as an intermediate point.
     *
     * @param adjacencyMatrix The weighted adjacency matrix representing the graph.
     *                        A value of 0 means no direct edge between the vertices, except for diagonal elements which are 0 (distance to self).
     */
    public void floydwarshall(int[][] adjacencyMatrix) {
        // Initialize the distance matrix with the adjacency matrix.
        for (int source = 1; source <= numberofvertices; source++) {
            System.arraycopy(adjacencyMatrix[source], 1, distanceMatrix[source], 1, numberofvertices);
        }

        for (int intermediate = 1; intermediate <= numberofvertices; intermediate++) {
            for (int source = 1; source <= numberofvertices; source++) {
                for (int destination = 1; destination <= numberofvertices; destination++) {
                    // Update distance if a shorter path through the intermediate vertex exists.
                    if (distanceMatrix[source][intermediate] + distanceMatrix[intermediate][destination] < distanceMatrix[source][destination]) {
                        distanceMatrix[source][destination] = distanceMatrix[source][intermediate] + distanceMatrix[intermediate][destination];
                    }
                }
            }
        }
    }

    /**
     * Prints the distance matrix representing the shortest paths between all pairs of vertices.
     * The rows and columns correspond to the source and destination vertices.
     */
    public void printDistanceMatrix() {
        // Print the distance matrix
        for (int source = 1; source <= numberofvertices; source++) {
            for (int destination = 1; destination <= numberofvertices; destination++) {
                if (distanceMatrix[source][destination] == INFINITY) {
                    System.out.print("INF\t");
                } else {
                    System.out.print(distanceMatrix[source][destination] + "\t");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numberofvertices = scanner.nextInt();

        int[][] adjacencyMatrix = new int[numberofvertices + 1][numberofvertices + 1];
        for (int i = 1; i <= numberofvertices; i++) {
            for (int j = 1; j <= numberofvertices; j++) {
                adjacencyMatrix[i][j] = scanner.nextInt();
            }
        }

        FloydWarshall floydWarshall = new FloydWarshall(numberofvertices);
        floydWarshall.floydwarshall(adjacencyMatrix);

        System.out.println("Shortest path matrix:");
        floydWarshall.printDistanceMatrix();

        scanner.close();
    }
}
