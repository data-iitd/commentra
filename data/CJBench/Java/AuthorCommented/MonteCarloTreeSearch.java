

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;
import java.util.Scanner;

/**
 * Monte Carlo Tree Search (MCTS) is a heuristic search algorithm used in
 * decition taking problems especially games.
 *
 * See more: https://en.wikipedia.org/wiki/Monte_Carlo_tree_search,
 * https://www.baeldung.com/java-monte-carlo-tree-search
 */
public class MonteCarloTreeSearch {

    public class Node {
        Node parent;
        ArrayList<Node> childNodes;
        boolean isPlayersTurn; // True if it is the player's turn.
        boolean playerWon; // True if the player won; false if the opponent won.
        int score;
        int visitCount;

        public Node(Node parent, boolean isPlayersTurn) {
            this.parent = parent;
            this.childNodes = new ArrayList<>();
            this.isPlayersTurn = isPlayersTurn;
            this.playerWon = false;
            this.score = 0;
            this.visitCount = 0;
        }
    }

    static final int WIN_SCORE = 10;
    static final int TIME_LIMIT = 500; // Time the algorithm will be running for (in milliseconds).

    /**
     * Explores a game tree using Monte Carlo Tree Search (MCTS) and returns the
     * most promising node.
     *
     * @param rootNode Root node of the game tree.
     * @return The most promising child of the root node.
     */
    public Node monteCarloTreeSearch(Node rootNode, int childCount) {
        Node winnerNode;
        double timeLimit;

        // Expand the root node with a given number of children.
        addChildNodes(rootNode, childCount);

        timeLimit = System.currentTimeMillis() + TIME_LIMIT;

        // Explore the tree until the time limit is reached.
        while (System.currentTimeMillis() < timeLimit) {
            Node promisingNode = getPromisingNode(rootNode);

            // Expand the promising node.
            if (promisingNode.childNodes.isEmpty()) {
                addChildNodes(promisingNode, childCount);
            }

            simulateRandomPlay(promisingNode);
        }

        winnerNode = getWinnerNode(rootNode);
        printScores(rootNode);

        return winnerNode;
    }

    public void addChildNodes(Node node, int childCount) {
        for (int i = 0; i < childCount; i++) {
            node.childNodes.add(new Node(node, !node.isPlayersTurn));
        }
    }

    /**
     * Uses UCT to find a promising child node to be explored.
     *
     * UCT: Upper Confidence bounds applied to Trees.
     *
     * @param rootNode Root node of the tree.
     * @return The most promising node according to UCT.
     */
    public Node getPromisingNode(Node rootNode) {
        Node promisingNode = rootNode;

        // Iterate until a node that hasn't been expanded is found.
        while (!promisingNode.childNodes.isEmpty()) {
            double uctIndex = Double.MIN_VALUE;
            int nodeIndex = 0;

            // Iterate through child nodes and pick the most promising one
            // using UCT (Upper Confidence bounds applied to Trees).
            for (int i = 0; i < promisingNode.childNodes.size(); i++) {
                Node childNode = promisingNode.childNodes.get(i);
                double uctTemp = (childNode.visitCount == 0)
                        ? Double.MAX_VALUE
                        : ((double) childNode.score / childNode.visitCount)
                        + 1.41 * Math.sqrt(Math.log(promisingNode.visitCount) / childNode.visitCount);

                if (uctTemp > uctIndex) {
                    uctIndex = uctTemp;
                    nodeIndex = i;
                }
            }

            promisingNode = promisingNode.childNodes.get(nodeIndex);
        }

        return promisingNode;
    }

    /**
     * Simulates a random play from a nodes current state and back propagates
     * the result.
     *
     * @param promisingNode Node that will be simulated.
     */
    public void simulateRandomPlay(Node promisingNode) {
        Random rand = new Random();
        Node tempNode = promisingNode;
        boolean isPlayerWinner = rand.nextBoolean(); // Random outcome for demonstration.

        while (tempNode != null) {
            tempNode.visitCount++;

            if ((tempNode.isPlayersTurn && isPlayerWinner) || (!tempNode.isPlayersTurn && !isPlayerWinner)) {
                tempNode.score += WIN_SCORE;
            }

            tempNode = tempNode.parent;
        }
    }

    public Node getWinnerNode(Node rootNode) {
        return Collections.max(rootNode.childNodes, Comparator.comparing(c -> c.score));
    }

    public void printScores(Node rootNode) {
        System.out.println("Node\tScore\tVisits");
        for (int i = 0; i < rootNode.childNodes.size(); i++) {
            System.out.printf("%d\t%d\t%d%n", i + 1, rootNode.childNodes.get(i).score, rootNode.childNodes.get(i).visitCount);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: Number of children for the root node
        int childCount = scanner.nextInt();

        // Input: Is it the player's turn at the root node
        boolean isPlayersTurn = scanner.nextBoolean();

        // Run Monte Carlo Tree Search
        MonteCarloTreeSearch mcts = new MonteCarloTreeSearch();
        Node rootNode = mcts.new Node(null, isPlayersTurn);
        Node winnerNode = mcts.monteCarloTreeSearch(rootNode, childCount);

        // Output: Optimal node index
        System.out.printf("Optimal node: %d%n", rootNode.childNodes.indexOf(winnerNode) + 1);

        scanner.close();
    }
}
