
import java.util.Arrays;
import java.util.Scanner;

/**
 * MiniMax is an algorithm used in artificial intelligence and game theory for
 * minimizing the possible loss for the worst case scenario.
 *
 * See more (https://en.wikipedia.org/wiki/Minimax,
 * https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/).
 *
 * @author aitofi (https://github.com/aitorfi)
 */
public class MiniMaxAlgorithm {

    /**
     * Game tree represented as an int array containing scores. Each array
     * element is a leaf node.
     */
    private int[] scores;
    private int height;

    public MiniMaxAlgorithm(int[] scores) {
        this.scores = scores;
        this.height = log2(scores.length);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numLeafNodes = scanner.nextInt();
        if ((numLeafNodes & (numLeafNodes - 1)) != 0) {
            System.out.println("Error: The number of leaf nodes must be a power of 2.");
            return;
        }

        int[] scores = new int[numLeafNodes];
        for (int i = 0; i < numLeafNodes; i++) {
            scores[i] = scanner.nextInt();
        }

        MiniMaxAlgorithm miniMaxAlgorithm = new MiniMaxAlgorithm(scores);

        boolean isMaximizer = scanner.nextBoolean();

        boolean verbose = true; // Set verbose to true to show intermediate steps.
        int bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose);

        System.out.println(Arrays.toString(miniMaxAlgorithm.getScores()));
        System.out.println("The best score for " + (isMaximizer ? "Maximizer" : "Minimizer") + " is " + bestScore);

        scanner.close();
    }

    /**
     * Returns the optimal score assuming that both players play their best.
     *
     * @param depth Indicates how deep we are into the game tree.
     * @param isMaximizer True if it is maximizers turn; otherwise false.
     * @param index Index of the leaf node that is being evaluated.
     * @param verbose True to show each player's choices.
     * @return The optimal score for the player that made the first move.
     */
    public int miniMax(int depth, boolean isMaximizer, int index, boolean verbose) {
        int bestScore;
        int score1;
        int score2;

        if (depth == height) { // Leaf node reached.
            return scores[index];
        }

        score1 = miniMax(depth + 1, !isMaximizer, index * 2, verbose);
        score2 = miniMax(depth + 1, !isMaximizer, (index * 2) + 1, verbose);

        if (isMaximizer) {
            // Maximizer player wants to get the maximum possible score.
            bestScore = Math.max(score1, score2);
        } else {
            // Minimizer player wants to get the minimum possible score.
            bestScore = Math.min(score1, score2);
        }

        if (verbose) {
            System.out.printf("From %02d and %02d, %s chooses %02d%n", score1, score2, (isMaximizer ? "Maximizer" : "Minimizer"), bestScore);
        }

        return bestScore;
    }

    // A utility function to find Log n in base 2
    private int log2(int n) {
        return (n == 1) ? 0 : log2(n / 2) + 1;
    }

    public int[] getScores() {
        return scores;
    }
}
