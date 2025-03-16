import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Array to hold the scores
    private int[] scores;
    // Height of the tree based on the number of scores
    private int height;

    // Constructor to initialize scores and calculate the height of the tree
    public Main(int[] scores) {
        this.scores = scores;
        this.height = log2(scores.length);
    }

    public static void main(String[] args) {
        // Create a scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of leaf nodes (scores) from user input
        int numLeafNodes = scanner.nextInt();
        
        // Check if the number of leaf nodes is a power of 2
        if ((numLeafNodes & (numLeafNodes - 1)) != 0) {
            System.out.println("Error: The number of leaf nodes must be a power of 2.");
            return; // Exit if the condition is not met
        }
        
        // Initialize the scores array based on the number of leaf nodes
        int[] scores = new int[numLeafNodes];
        
        // Read the scores from user input
        for (int i = 0; i < numLeafNodes; i++) {
            scores[i] = scanner.nextInt();
        }
        
        // Create an instance of Main with the provided scores
        Main miniMaxAlgorithm = new Main(scores);
        
        // Read whether the player is a maximizer or minimizer
        boolean isMaximizer = scanner.nextBoolean();
        
        // Set verbosity for output
        boolean verbose = true; 
        
        // Calculate the best score using the miniMax algorithm
        int bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose);
        
        // Print the scores and the best score determined by the algorithm
        System.out.println(Arrays.toString(miniMaxAlgorithm.getScores()));
        System.out.println("The best score for " + (isMaximizer ? "Maximizer" : "Minimizer") + " is " + bestScore);
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Recursive method to implement the miniMax algorithm
    public int miniMax(int depth, boolean isMaximizer, int index, boolean verbose) {
        int bestScore;
        int score1;
        int score2;

        // Base case: if the current depth equals the height of the tree, return the score at the current index
        if (depth == height) { 
            return scores[index];
        }

        // Recursively calculate scores for the left and right child nodes
        score1 = miniMax(depth + 1, !isMaximizer, index * 2, verbose);
        score2 = miniMax(depth + 1, !isMaximizer, (index * 2) + 1, verbose);

        // Determine the best score based on whether the current player is a maximizer or minimizer
        if (isMaximizer) {
            bestScore = Math.max(score1, score2);
        } else {
            bestScore = Math.min(score1, score2);
        }

        // Print verbose output if enabled
        if (verbose) {
            System.out.printf("From %02d and %02d, %s chooses %02d%n", score1, score2, (isMaximizer ? "Maximizer" : "Minimizer"), bestScore);
        }
        
        // Return the best score found
        return bestScore;
    }

    // Helper method to calculate the logarithm base 2 of a number
    private int log2(int n) {
        return (n == 1) ? 0 : log2(n / 2) + 1;
    }

    // Getter method to retrieve the scores array
    public int[] getScores() {
        return scores;
    }
}
