
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Declare instance variables
    private int[] scores;
    private int height;

    // Constructor
    public Main(int[] scores) {
        this.scores = scores;
        this.height = log2(scores.length); // Calculate height of tree based on number of scores
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize scanner for user input

        // Read number of leaf nodes and check if it's a power of 2
        int numLeafNodes = scanner.nextInt();
        if ((numLeafNodes & (numLeafNodes - 1)) != 0) { // Check if number is power of 2 using bitwise AND
            System.out.println("Error: The number of leaf nodes must be a power of 2.");
            return;
        }

        // Initialize scores array
        int[] scores = new int[numLeafNodes];
        for (int i = 0; i < numLeafNodes; i++) {
            scores[i] = scanner.nextInt(); // Read scores from user
        }

        // Initialize MiniMax algorithm
        Main miniMaxAlgorithm = new Main(scores);

        // Read whether it's maximizer or minimizer turn
        boolean isMaximizer = scanner.nextBoolean();

        // Read whether to be verbose or not
        boolean verbose = true;

        // Run MiniMax algorithm and print results
        int bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose);
        System.out.println("Scores: " + Arrays.toString(miniMaxAlgorithm.getScores()));
        System.out.println("The best score for " + (isMaximizer ? "Maximizer" : "Minimizer") + " is " + bestScore);

        scanner.close(); // Close scanner
    }

    // MiniMax algorithm
    public int miniMax(int depth, boolean isMaximizer, int index, boolean verbose) {
        int bestScore;
        int score1;
        int score2;

        // Base case: leaf node
        if (depth == height) {
            return scores[index];
        }

        // Recursive call for minimizing player
        score1 = miniMax(depth + 1, !isMaximizer, index * 2, verbose);

        // Recursive call for maximizing player
        score2 = miniMax(depth + 1, !isMaximizer, (index * 2) + 1, verbose);

        // Determine best score based on whether maximizing or minimizing
        if (isMaximizer) {
            bestScore = Math.max(score1, score2);
        } else {
            bestScore = Math.min(score1, score2);
        }

        // Print verbose output if enabled
        if (verbose) {
            System.out.printf("From %02d and %02d, %s chooses %02d%n", score1, score2, (isMaximizer ? "Maximizer" : "Minimizer"), bestScore);
        }

        return bestScore;
    }

    // Helper method to calculate log base 2 of a number
    private int log2(int n) {
        return (n == 1) ? 0 : log2(n / 2) + 1;
    }

    // Getter method for scores
    public int[] getScores() {
        return scores;
    }
}