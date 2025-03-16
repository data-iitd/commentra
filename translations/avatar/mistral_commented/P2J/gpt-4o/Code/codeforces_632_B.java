import java.util.Scanner;

public class Main {
    // This function is the entry point of the program
    public static void main(String[] args) {
        // Read input from standard input
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line (not used)

        // Parse input into an array of pairs, where each pair contains the score and the player of a piece
        String[] scores = scanner.nextLine().split(" ");
        String[] players = scanner.nextLine().split(" ");
        Piece[] pieces = new Piece[scores.length];

        for (int i = 0; i < scores.length; i++) {
            pieces[i] = new Piece(Integer.parseInt(scores[i]), players[i]);
        }

        // Call the function to find Bob's maximum strength
        int result = Bob_sMaxStrength(pieces);

        // Print the result
        System.out.println(result);
    }

    // This function calculates Bob's maximum strength based on the given pieces
    public static int Bob_sMaxStrength(Piece[] pieces) {
        // Initialize variables to store the scores for players A and B
        int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;

        // Iterate through each piece and update the scores accordingly
        for (Piece piece : pieces) {
            // If the piece belongs to player A, add its score to pScore
            if (piece.player.equals("A")) {
                pScore += piece.score;
                // Update pMaxScore if the current pScore is greater
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } 
            // If the piece belongs to player B, subtract its score from pScore
            else {
                pScore -= piece.score;
            }
        }

        // Iterate through the pieces in reverse order and update the scores for player S
        for (int i = pieces.length - 1; i >= 0; i--) {
            // If the current piece belongs to player A, add its score to sScore
            if (pieces[i].player.equals("A")) {
                sScore += pieces[i].score;
                // Update sMaxScore if the current sScore is greater
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } 
            // If the current piece belongs to player B, subtract its score from sScore
            else {
                sScore -= pieces[i].score;
            }
        }

        // Return the maximum score between Bob's and Sally's scores
        return Math.max(pMaxScore, sMaxScore);
    }

    // Helper class to represent a piece with score and player
    static class Piece {
        int score;
        String player;

        Piece(int score, String player) {
            this.score = score;
            this.player = player;
        }
    }
}

// <END-OF-CODE>
