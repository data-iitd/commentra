import java.util.Scanner;

public class Main {
    // Matrix to store the paths between nodes
    private int[][] path = new int[10][10];
    // Array to store the PageRank values for each node
    private double[] pagerank = new double[10];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // Read the number of nodes
        int nodes = in.nextInt();
        Main p = new Main();
        // Read the path matrix from the user
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                p.path[i][j] = in.nextInt();
                // Diagonal elements are set to 0 as they represent a node pointing to itself
                if (i == j) {
                    p.path[i][j] = 0; 
                }
            }
        }
        // Calculate the PageRank values
        p.calc(nodes);
        in.close();
    }

    // Method to calculate the PageRank values
    public void calc(int totalNodes) {
        // Initial PageRank for each node
        double initialMain = 1.0 / totalNodes;
        // Damping factor
        double dampingFactor = 0.85;
        // Temporary array to hold PageRank values during each iteration
        double[] tempMain = new double[10];
        // Initialize the PageRank values
        for (int i = 1; i <= totalNodes; i++) {
            pagerank[i] = initialMain;
        }
        // Number of iterations (fixed at 2 in this case)
        int iterationStep = 1;
        // Main loop to iterate and update PageRank values
        while (iterationStep <= 2) { 
            // Copy current PageRank values to tempMain array
            for (int i = 1; i <= totalNodes; i++) {
                tempMain[i] = pagerank[i];
                pagerank[i] = 0; // Reset current PageRank values
            }
            // Update PageRank values based on incoming links
            for (int internalNode = 1; internalNode <= totalNodes; internalNode++) {
                for (int externalNode = 1; externalNode <= totalNodes; externalNode++) {
                    if (path[externalNode][internalNode] == 1) {
                        int outgoingLinks = 0;
                        // Count outgoing links from the externalNode
                        for (int k = 1; k <= totalNodes; k++) {
                            if (path[externalNode][k] == 1) {
                                outgoingLinks++;
                            }
                        }
                        // Add to the PageRank of the internalNode
                        pagerank[internalNode] += tempMain[externalNode] / outgoingLinks;
                    }
                }
            }
            // Apply damping factor to the PageRank values
            for (int i = 1; i <= totalNodes; i++) {
                pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i];
            }
            // Increment the iteration step
            iterationStep++;
        }
        // Print the PageRank values for each node
        for (int i = 1; i <= totalNodes; i++) {
            System.out.printf("Page Rank of Node %d: %.6f\n", i, pagerank[i]);
        }
    }
}
