
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private int[] scores;
    private int height;

    // Constructor to initialize the scores array and calculate the height of the binary tree
    public Main(int[] scores) {
        this.scores = scores;
        this.height = log2(scores.length);
    }

    // Main method to run the MiniMax algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numLeafNodes = scanner.nextInt();

        // Check if the number of leaf nodes is a power of 2
        if ((numLeafNodes & (numLeafNodes - 1)) != 0) {
            System.out.println("Error: The number of leaf nodes must be a power of 2.");
            return;
        }

        // Read the scores of the leaf nodes from the user
        int[] scores = new int[numLeafNodes];
        for (int i = 0; i < numLeafNodes; i++) {
            scores[i] = scanner.nextInt();
        }

        // Create an instance of the Main class with the scores array
        Main miniMaxAlgorithm = new Main(scores);
        boolean isMaximizer = scanner.nextBoolean();
        boolean verbose = true; 

        // Run the MiniMax algorithm to find the best score
        int bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose);

        // Print the scores array and the best score for the player
        System.out.println(Arrays.toString(miniMaxAlgorithm.getScores()));
        System.out.println("The best score for " + (isMaximizer ? "Maximizer" : "Minimizer") + " is " + bestScore);
        scanner.close();
    }

    // MiniMax algorithm implementation
    public int miniMax(int depth, boolean isMaximizer, int index, boolean verbose) {
        int bestScore;
        int score1;
        int score2;

        // Base case: when depth equals the height of the tree
        if (depth == height) { 
            return scores[index];
        }

        // Recursively evaluate the scores for the left and right children
        score1 = miniMax(depth + 1, !isMaximizer, index * 2, verbose);
        score2 = miniMax(depth + 1, !isMaximizer, (index * 2) + 1, verbose);

        // Determine the best score based on whether it's the Maximizer or Minimizer's turn
        if (isMaximizer) {
            bestScore = Math.max(score1, score2);
        } else {
            bestScore = Math.min(score1, score2);
        }

        // Print the choice if verbose mode is enabled
        if (verbose) {
            System.out.printf("From %02d and %02d, %s chooses %02d%n", score1, score2, (isMaximizer ? "Maximizer" : "Minimizer"), bestScore);
        }

        return bestScore;
    }

    // Helper method to calculate the height of the binary tree
    private int log2(int n) {
        return (n == 1) ? 0 : log2(n / 2) + 1;
    }

    // Method to get the scores array
    public int[] getScores() {
        return scores;
    }
}