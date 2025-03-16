
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {

    // Define a custom Node class for the tree
    public static class Node {
        Node parent;
        List<Node> childNodes;
        boolean isPlayersTurn;
        boolean playerWon;
        int score;
        int visitCount;

        // Constructor for Node
        public Node(Node parent, boolean isPlayersTurn) {
            this.parent = parent;
            this.childNodes = new ArrayList<>();
            this.isPlayersTurn = isPlayersTurn;
            this.playerWon = false;
            this.score = 0;
            this.visitCount = 0;
        }
    }

    // Constants for the game
    static final int WIN_SCORE = 10;
    static final int TIME_LIMIT = 500;

    // Main method for Monte Carlo Tree Search
    public Node monteCarloTreeSearch(Node rootNode, int childCount) {
        Node winnerNode;
        long timeLimit = System.currentTimeMillis() + TIME_LIMIT;

        // Add child nodes to the root node
        addChildNodes(rootNode, childCount);

        // Search for the promising node within the time limit
        while (System.currentTimeMillis() < timeLimit) {
            Node promisingNode = getPromisingNode(rootNode);

            // If there are no child nodes for the promising node, add them
            if (promisingNode.childNodes.isEmpty()) {
                addChildNodes(promisingNode, childCount);
            }

            // Simulate random play for the promising node
            simulateRandomPlay(promisingNode);
        }

        // Find the winning node
        winnerNode = getWinnerNode(rootNode);

        // Print the scores for all nodes in the tree
        printScores(rootNode);

        return winnerNode;
    }

    // Add child nodes to the given node
    public void addChildNodes(Node node, int childCount) {
        for (int i = 0; i < childCount; i++) {
            node.childNodes.add(new Node(node, !node.isPlayersTurn));
        }
    }

    // Find the promising node based on UCT (Upper Confidence Bound)
    public Node getPromisingNode(Node rootNode) {
        Node promisingNode = rootNode;

        // Traverse the tree to find the promising node
        while (!promisingNode.childNodes.isEmpty()) {
            double maxUct = Double.MIN_VALUE;
            Node bestChildNode = null;

            // Find the child node with the highest UCT value
            for (Node childNode : promisingNode.childNodes) {
                double uctValue = (childNode.visitCount == 0)
                        ? Double.MAX_VALUE
                        : ((double) childNode.score / childNode.visitCount)
                        + 1.41 * Math.sqrt(Math.log(promisingNode.visitCount) / childNode.visitCount);

                // Update the best child node if the UCT value is higher
                if (uctValue > maxUct) {
                    maxUct = uctValue;
                    bestChildNode = childNode;
                }
            }

            // Update the promising node to the best child node
            promisingNode = bestChildNode;
        }

        return promisingNode;
    }

    // Simulate random play for the given node
    public void simulateRandomPlay(Node promisingNode) {
        Random rand = new Random();
        Node currentNode = promisingNode;

        // Simulate the game by following the tree until reaching the root node
        while (currentNode != null) {
            currentNode.visitCount++;

            // Update the score if the player wins or loses
            if ((currentNode.isPlayersTurn && rand.nextBoolean()) || (!currentNode.isPlayersTurn && !rand.nextBoolean())) {
                currentNode.score += WIN_SCORE;
            }

            currentNode = currentNode.parent;
        }
    }

    // Find the winning node with the highest score
    public Node getWinnerNode(Node rootNode) {
        return Collections.max(rootNode.childNodes, Comparator.comparing(c -> c.score));
    }

    // Print the scores and visits for all nodes in the tree
    public void printScores(Node rootNode) {
        System.out.println("Node\tScore\tVisits");

        // Traverse the tree and print the scores and visits for each node
        for (Node node : rootNode.childNodes) {
            System.out.printf("%d\t%d\t%d%n", node.index + 1, node.score, node.visitCount);
        }
    }

    // Main method for running the Monte Carlo Tree Search algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int childCount = scanner.nextInt();
        boolean isPlayersTurn = scanner.nextBoolean();

        Main mcts = new Main();
        Node rootNode = mcts.new Node(null, isPlayersTurn);

        // Perform Monte Carlo Tree Search and find the winning node
        Node winnerNode = mcts.monteCarloTreeSearch(rootNode, childCount);

        // Print the index of the winning node
        System.out.printf("Optimal node: %d%n", rootNode.childNodes.indexOf(winnerNode) + 1);

        scanner.close();
    }
}