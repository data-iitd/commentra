import java.util.Scanner;

public class Main {
    private int[][] distanceMatrix; // 1. Class Initialization: Private 2D array to store distance matrix
    private int numberofvertices; // 1. Class Initialization: Integer to store the number of vertices
    public static final int INFINITY = 999; // 1. Class Initialization: Constant for infinity

    // 2. Constructor: Initializes the distance matrix and sets the number of vertices
    public Main(int numberofvertices) {
        distanceMatrix = new int[numberofvertices + 1][numberofvertices + 1];
        this.numberofvertices = numberofvertices;
    }

    // 2. Floyd-Warshall Algorithm: Computes the shortest paths between all pairs of vertices
    public void floydwarshall(int[][] adjacencyMatrix) {
        // Copy the adjacency matrix to the distance matrix
        for (int source = 1; source <= numberofvertices; source++) {
            System.arraycopy(adjacencyMatrix[source], 1, distanceMatrix[source], 1, numberofvertices);
        }
        // Compute the shortest paths
        for (int intermediate = 1; intermediate <= numberofvertices; intermediate++) {
            for (int source = 1; source <= numberofvertices; source++) {
                for (int destination = 1; destination <= numberofvertices; destination++) {
                    if (distanceMatrix[source][intermediate] + distanceMatrix[intermediate][destination] < distanceMatrix[source][destination]) {
                        distanceMatrix[source][destination] = distanceMatrix[source][intermediate] + distanceMatrix[intermediate][destination];
                    }
                }
            }
        }
    }

    // 3. Printing the Distance Matrix: Prints the computed shortest path matrix
    public void printDistanceMatrix() {
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

    // 4. Main Method: Reads the number of vertices and adjacency matrix, runs the algorithm, and prints the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberofvertices = scanner.nextInt();
        int[][] adjacencyMatrix = new int[numberofvertices + 1][numberofvertices + 1];
        // Read the adjacency matrix
        for (int i = 1; i <= numberofvertices; i++) {
            for (int j = 1; j <= numberofvertices; j++) {
                adjacencyMatrix[i][j] = scanner.nextInt();
            }
        }
        Main floydWarshall = new Main(numberofvertices);
        floydWarshall.floydwarshall(adjacencyMatrix);
        System.out.println("Shortest path matrix:");
        floydWarshall.printDistanceMatrix();
        scanner.close();
    }
}
