
import java.util.Scanner;

public class Main {
    // Declare a 2D integer array 'path' to store the graph data and a 1D double array 'pagerank' to store the pagerank values
    private int[][] path = new int[10][10];
    private double[] pagerank = new double[10];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize a Scanner object to read input from the console

        int nodes = in.nextInt(); // Read the number of nodes from the console
        Main p = new Main(); // Create an instance of the Main class

        // Initialize the 'path' array with the given graph data
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                p.path[i][j] = in.nextInt();
                if (i == j) {
                    p.path[i][j] = 0; // Set the diagonal elements to zero since there is no self-loop in the graph
                }
            }
        }

        p.calc(nodes); // Call the 'calc' method to calculate the pagerank values
        in.close(); // Close the Scanner object to release the system resources
    }

    public void calc(int totalNodes) {
        // Initialize the 'pagerank' array with the initial main value
        double initialMain = 1.0 / totalNodes;
        double dampingFactor = 0.85;
        double[] tempMain = new double[10]; // Create a temporary array to store the updated pagerank values in each iteration

        // Initialize all the pagerank values with the initial main value
        for (int i = 1; i <= totalNodes; i++) {
            pagerank[i] = initialMain;
        }

        int iterationStep = 1; // Initialize the iteration counter

        // Perform the pagerank calculation for a maximum of 2 iterations
        while (iterationStep <= 2) {
            // Initialize the 'tempMain' array with the current pagerank values
            for (int i = 1; i <= totalNodes; i++) {
                tempMain[i] = pagerank[i];
            }

            // Update the pagerank values for each node based on the current pagerank values and the graph data
            for (int internalNode = 1; internalNode <= totalNodes; internalNode++) {
                for (int externalNode = 1; externalNode <= totalNodes; externalNode++) {
                    if (path[externalNode][internalNode] == 1) { // If there is a link from externalNode to internalNode
                        int outgoingLinks = 0; // Initialize the counter for the number of outgoing links from externalNode

                        // Count the number of outgoing links from externalNode
                        for (int k = 1; k <= totalNodes; k++) {
                            if (path[externalNode][k] == 1) {
                                outgoingLinks++;
                            }
                        }

                        // Update the pagerank value of internalNode based on the updated pagerank value of externalNode and the number of outgoing links
                        pagerank[internalNode] += tempMain[externalNode] / outgoingLinks;
                    }
                }
            }

            // Update the pagerank values by applying the damping factor
            for (int i = 1; i <= totalNodes; i++) {
                pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i];
            }

            iterationStep++; // Increment the iteration counter
        }

        // Print the pagerank values for all the nodes
        for (int i = 1; i <= totalNodes; i++) {
            System.out.printf("Page Rank of Node %d: %.6f\n", i, pagerank[i]);
        }
    }
}