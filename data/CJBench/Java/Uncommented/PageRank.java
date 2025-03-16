
import java.util.Scanner;
public class PageRank {
    private int[][] path = new int[10][10];
    private double[] pagerank = new double[10];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nodes = in.nextInt();
        PageRank p = new PageRank();
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                p.path[i][j] = in.nextInt();
                if (i == j) {
                    p.path[i][j] = 0; 
                }
            }
        }
        p.calc(nodes);
        in.close();
    }
    public void calc(int totalNodes) {
        double initialPageRank = 1.0 / totalNodes;
        double dampingFactor = 0.85;
        double[] tempPageRank = new double[10];
        for (int i = 1; i <= totalNodes; i++) {
            pagerank[i] = initialPageRank;
        }
        int iterationStep = 1;
        while (iterationStep <= 2) { 
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
                        pagerank[internalNode] += tempPageRank[externalNode] / outgoingLinks;
                    }
                }
            }
            for (int i = 1; i <= totalNodes; i++) {
                pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i];
            }
            iterationStep++;
        }
        for (int i = 1; i <= totalNodes; i++) {
            System.out.printf("Page Rank of Node %d: %.6f\n", i, pagerank[i]);
        }
    }
}
