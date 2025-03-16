
import java.util.Arrays;
import java.util.Scanner;
public class MiniMaxAlgorithm {
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
        boolean verbose = true; 
        int bestScore = miniMaxAlgorithm.miniMax(0, isMaximizer, 0, verbose);
        System.out.println(Arrays.toString(miniMaxAlgorithm.getScores()));
        System.out.println("The best score for " + (isMaximizer ? "Maximizer" : "Minimizer") + " is " + bestScore);
        scanner.close();
    }
    public int miniMax(int depth, boolean isMaximizer, int index, boolean verbose) {
        int bestScore;
        int score1;
        int score2;
        if (depth == height) { 
            return scores[index];
        }
        score1 = miniMax(depth + 1, !isMaximizer, index * 2, verbose);
        score2 = miniMax(depth + 1, !isMaximizer, (index * 2) + 1, verbose);
        if (isMaximizer) {
            bestScore = Math.max(score1, score2);
        } else {
            bestScore = Math.min(score1, score2);
        }
        if (verbose) {
            System.out.printf("From %02d and %02d, %s chooses %02d%n", score1, score2, (isMaximizer ? "Maximizer" : "Minimizer"), bestScore);
        }
        return bestScore;
    }
    private int log2(int n) {
        return (n == 1) ? 0 : log2(n / 2) + 1;
    }
    public int[] getScores() {
        return scores;
    }
}
