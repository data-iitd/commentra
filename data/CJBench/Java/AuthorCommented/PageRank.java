

import java.util.Scanner;

public class PageRank {

    // Adjacency matrix to represent the link structure between webpages
    private int[][] path = new int[10][10];

    // Array to store the PageRank values for each webpage
    private double[] pagerank = new double[10];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Read number of webpages
        int nodes = in.nextInt();

        // Initialize PageRank object
        PageRank p = new PageRank();

        // Read adjacency matrix
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                p.path[i][j] = in.nextInt();
                if (i == j) {
                    p.path[i][j] = 0; // Remove self-loops
                }
            }
        }

        // Calculate PageRank
        p.calc(nodes);

        in.close();
    }

    /**
     * Calculates the PageRank values for all nodes (webpages) in the graph.
     * 
     * @param totalNodes The total number of nodes (webpages) in the graph.
     */
    public void calc(int totalNodes) {
        double initialPageRank = 1.0 / totalNodes;
        double dampingFactor = 0.85;
        double[] tempPageRank = new double[10];

        // Initialize PageRank values
        for (int i = 1; i <= totalNodes; i++) {
            pagerank[i] = initialPageRank;
        }

        int iterationStep = 1;

        // Perform iterations to compute PageRank
        while (iterationStep <= 2) { // Perform 2 iterations
            for (int i = 1; i <= totalNodes; i++) {
                tempPageRank[i] = pagerank[i];
                pagerank[i] = 0;
            }

            for (int internalNode = 1; internalNode <= totalNodes; internalNode++) {
                for (int externalNode = 1; externalNode <= totalNodes; externalNode++) {
                    if (path[externalNode][internalNode] == 1) {
                        int outgoingLinks = 0;

                        for (int k = 1; k <= totalNodes; k++) {
                            if (path[externalNode][k] == 1) {
                                outgoingLinks++;
                            }
                        }

                        // Compute contribution from externalNode to internalNode
                        pagerank[internalNode] += tempPageRank[externalNode] / outgoingLinks;
                    }
                }
            }

            // Apply damping factor
            for (int i = 1; i <= totalNodes; i++) {
                pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i];
            }

            iterationStep++;
        }

        // Print final PageRank values
        for (int i = 1; i <= totalNodes; i++) {
            System.out.printf("Page Rank of Node %d: %.6f\n", i, pagerank[i]);
        }
    }
}
