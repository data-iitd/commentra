import java.util.Scanner;

public class Main {
    // 2D array to represent the path (adjacency matrix) between nodes
    private int[][] path = new int[10][10];
    // Array to store the PageRank values of each node
    private double[] pagerank = new double[10];

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Read the number of nodes from user input
        int nodes = in.nextInt();
        // Create an instance of the Main class to access its methods
        Main p = new Main();
        
        // Read the adjacency matrix from user input
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                p.path[i][j] = in.nextInt();
                // Set the diagonal to 0 since a node does not link to itself
                if (i == j) {
                    p.path[i][j] = 0; 
                }
            }
        }
        
        // Calculate the PageRank values based on the input graph
        p.calc(nodes);
        // Close the scanner to prevent resource leaks
        in.close();
    }

    public void calc(int totalNodes) {
        // Initialize the PageRank value for each node
        double initialMain = 1.0 / totalNodes;
        // Damping factor for PageRank calculation
        double dampingFactor = 0.85;
        // Temporary array to hold the previous PageRank values
        double[] tempMain = new double[10];
        
        // Set initial PageRank values for all nodes
        for (int i = 1; i <= totalNodes; i++) {
            pagerank[i] = initialMain;
        }
        
        // Perform the PageRank calculation for a fixed number of iterations
        int iterationStep = 1;
        while (iterationStep <= 2) { 
            // Store the current PageRank values in a temporary array
            for (int i = 1; i <= totalNodes; i++) {
                tempMain[i] = pagerank[i];
                pagerank[i] = 0; // Reset the pagerank for the next iteration
            }
            
            // Update the PageRank values based on the adjacency matrix
            for (int internalNode = 1; internalNode <= totalNodes; internalNode++) {
                for (int externalNode = 1; externalNode <= totalNodes; externalNode++) {
                    // Check if there is a link from externalNode to internalNode
                    if (path[externalNode][internalNode] == 1) {
                        int outgoingLinks = 0;
                        // Count the number of outgoing links from externalNode
                        for (int k = 1; k <= totalNodes; k++) {
                            if (path[externalNode][k] == 1) {
                                outgoingLinks++;
                            }
                        }
                        // Update the PageRank of the internalNode based on the contribution from externalNode
                        pagerank[internalNode] += tempMain[externalNode] / outgoingLinks;
                    }
                }
            }
            
            // Apply the damping factor to the PageRank values
            for (int i = 1; i <= totalNodes; i++) {
                pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i];
            }
            // Move to the next iteration
            iterationStep++;
        }
        
        // Print the final PageRank values for each node
        for (int i = 1; i <= totalNodes; i++) {
            System.out.printf("Page Rank of Node %d: %.6f\n", i, pagerank[i]);
        }
    }
}
