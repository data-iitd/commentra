import java.util.Scanner;
public class FloydWarshall {
    private int[][] distanceMatrix;
    private int numberofvertices;
    public static final int INFINITY = 999;
    public FloydWarshall(int numberofvertices) {
        distanceMatrix = new int[numberofvertices + 1][numberofvertices + 1];
        this.numberofvertices = numberofvertices;
    }
    public void floydwarshall(int[][] adjacencyMatrix) {
        for (int source = 1; source <= numberofvertices; source++) {
            System.arraycopy(adjacencyMatrix[source], 1, distanceMatrix[source], 1, numberofvertices);
        }
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
