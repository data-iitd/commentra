import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;
import java.util.Scanner;

public class Main {
    // Node class representing each state in the game tree
    public class Node {
        Node parent; // Reference to the parent node
        ArrayList<Node> childNodes; // List of child nodes
        boolean isPlayersTurn; // Indicates if it's the player's turn
        boolean playerWon; // Indicates if the player has won
        int score; // Score for the node
        int visitCount; // Number of times the node has been visited

        // Constructor to initialize a node
        public Node(Node parent, boolean isPlayersTurn) {
            this.parent = parent;
            this.childNodes = new ArrayList<>();
            this.isPlayersTurn = isPlayersTurn;
            this.playerWon = false;
            this.score = 0;
            this.visitCount = 0;
        }
    }

    // Constants for scoring and time limits
    static final int WIN_SCORE = 10; // Score awarded for a win
    static final int TIME_LIMIT = 500; // Time limit for the Monte Carlo simulation in milliseconds

    // Main function to perform Monte Carlo Tree Search
    public Node monteCarloTreeSearch(Node rootNode, int childCount) {
        Node winnerNode; // Variable to hold the winning node
        double timeLimit; // Variable to track the time limit for the simulation

        // Generate child nodes for the root node
        addChildNodes(rootNode, childCount);
        timeLimit = System.currentTimeMillis() + TIME_LIMIT; // Set the time limit

        // Run the simulation until the time limit is reached
        while (System.currentTimeMillis() < timeLimit) {
            Node promisingNode = getPromisingNode(rootNode); // Get a promising node to explore
            // If the promising node has no child nodes, add them
            if (promisingNode.childNodes.isEmpty()) {
                addChildNodes(promisingNode, childCount);
            }
            // Simulate a random play from the promising node
            simulateRandomPlay(promisingNode);
        }

        // Determine the winning node based on scores
        winnerNode = getWinnerNode(rootNode);
        // Print the scores of all child nodes
        printScores(rootNode);
        return winnerNode; // Return the winning node
    }

    // Method to add child nodes to a given node
    public void addChildNodes(Node node, int childCount) {
        for (int i = 0; i < childCount; i++) {
            // Create a new child node with the opposite player's turn
            node.childNodes.add(new Node(node, !node.isPlayersTurn));
        }
    }

    // Method to get the most promising node based on UCT (Upper Confidence Bound for Trees)
    public Node getPromisingNode(Node rootNode) {
        Node promisingNode = rootNode; // Start with the root node
        // Traverse down the tree until a node with no children is found
        while (!promisingNode.childNodes.isEmpty()) {
            double uctIndex = Double.MIN_VALUE; // Initialize UCT index
            int nodeIndex = 0; // Index of the best child node

            // Evaluate each child node to find the one with the highest UCT value
            for (int i = 0; i < promisingNode.childNodes.size(); i++) {
                Node childNode = promisingNode.childNodes.get(i);
                double uctTemp = (childNode.visitCount == 0)
                        ? Double.MAX_VALUE // If the child has not been visited, prioritize it
                        : ((double) childNode.score / childNode.visitCount)
                        + 1.41 * Math.sqrt(Math.log(promisingNode.visitCount) / childNode.visitCount); // Calculate UCT

                // Update the best child node if the current one has a higher UCT
                if (uctTemp > uctIndex) {
                    uctIndex = uctTemp;
                    nodeIndex = i;
                }
            }
            // Move to the selected promising child node
            promisingNode = promisingNode.childNodes.get(nodeIndex);
        }
        return promisingNode; // Return the most promising node
    }

    // Method to simulate a random play from a given node
    public void simulateRandomPlay(Node promisingNode) {
        Random rand = new Random(); // Random number generator
        Node tempNode = promisingNode; // Start from the promising node
        boolean isPlayerWinner = rand.nextBoolean(); // Randomly determine the winner

        // Backpropagate the results up the tree
        while (tempNode != null) {
            tempNode.visitCount++; // Increment visit count for the node
            // Update score based on whether the player won
            if ((tempNode.isPlayersTurn && isPlayerWinner) || (!tempNode.isPlayersTurn && !isPlayerWinner)) {
                tempNode.score += WIN_SCORE; // Award score for a win
            }
            tempNode = tempNode.parent; // Move up to the parent node
        }
    }

    // Method to get the child node with the highest score
    public Node getWinnerNode(Node rootNode) {
        return Collections.max(rootNode.childNodes, Comparator.comparing(c -> c.score)); // Return the node with the maximum score
    }

    // Method to print the scores and visit counts of all child nodes
    public void printScores(Node rootNode) {
        System.out.println("Node\tScore\tVisits"); // Print header
        for (int i = 0; i < rootNode.childNodes.size(); i++) {
            // Print the index, score, and visit count for each child node
            System.out.printf("%d\t%d\t%d%n", i + 1, rootNode.childNodes.get(i).score, rootNode.childNodes.get(i).visitCount);
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int childCount = scanner.nextInt(); // Read the number of child nodes to generate
        boolean isPlayersTurn = scanner.nextBoolean(); // Read whose turn it is
        Main mcts = new Main(); // Create an instance of the Main class
        Node rootNode = mcts.new Node(null, isPlayersTurn); // Create the root node
        Node winnerNode = mcts.monteCarloTreeSearch(rootNode, childCount); // Perform Monte Carlo Tree Search
        // Print the index of the optimal node
        System.out.printf("Optimal node: %d%n", rootNode.childNodes.indexOf(winnerNode) + 1);
        scanner.close(); // Close the scanner
    }
}
