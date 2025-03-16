import java.util.Scanner;

public class Main {
    // 2D array to hold the distance matrix
    private int[][] distanceMatrix;
    // Number of vertices in the graph
    private int numberofvertices;
    // Constant to represent infinity
    public static final int INFINITY = 999;

    // Constructor to initialize the distance matrix and number of vertices
    public Main(int numberofvertices) {
        distanceMatrix = new int[numberofvertices + 1][numberofvertices + 1];
        this.numberofvertices = numberofvertices;
    }

    // Method to perform the Floyd-Warshall algorithm
    public void floydwarshall(int[][] adjacencyMatrix) {
        // Initialize the distance matrix with the adjacency matrix values
        for (int source = 1; source <= numberofvertices; source++) {
            System.arraycopy(adjacencyMatrix[source], 1, distanceMatrix[source], 1, numberofvertices);
        }

        // Update the distance matrix with the shortest paths
        for (int intermediate = 1; intermediate <= numberofvertices; intermediate++) {
            for (int source = 1; source <= numberofvertices; source++) {
                for (int destination = 1; destination <= numberofvertices; destination++) {
                    // Check if a shorter path exists through the intermediate vertex
                    if (distanceMatrix[source][intermediate] + distanceMatrix[intermediate][destination] < distanceMatrix[source][destination]) {
                        distanceMatrix[source][destination] = distanceMatrix[source][intermediate] + distanceMatrix[intermediate][destination];
                    }
                }
            }
        }
    }

    // Method to print the distance matrix
    public void printDistanceMatrix() {
        for (int source = 1; source <= numberofvertices; source++) {
            for (int destination = 1; destination <= numberofvertices; destination++) {
                // Print "INF" for unreachable paths
                if (distanceMatrix[source][destination] == INFINITY) {
                    System.out.print("INF\t");
                } else {
                    // Print the distance for reachable paths
                    System.out.print(distanceMatrix[source][destination] + "\t");
                }
            }
            // Move to the next line after printing each row
            System.out.println();
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner object for input
        Scanner scanner = new Scanner(System.in);
        // Read the number of vertices from user input
        int numberofvertices = scanner.nextInt();
        // Initialize the adjacency matrix
        int[][] adjacencyMatrix = new int[numberofvertices + 1][numberofvertices + 1];

        // Read the adjacency matrix values from user input
        for (int i = 1; i <= numberofvertices; i++) {
            for (int j = 1; j <= numberofvertices; j++) {
                adjacencyMatrix[i][j] = scanner.nextInt();
            }
        }

        // Create an instance of Main and execute the Floyd-Warshall algorithm
        Main floydWarshall = new Main(numberofvertices);
        floydWarshall.floydwarshall(adjacencyMatrix);

        // Print the resulting shortest path matrix
        System.out.println("Shortest path matrix:");
        floydWarshall.printDistanceMatrix();

        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
