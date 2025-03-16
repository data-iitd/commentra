import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input (the first input is ignored)
        scanner.nextLine();
        
        // Read the second line of input, split it into integers and corresponding characters,
        // and create an array of pieces where each piece is an array of (score, character)
        String[] scores = scanner.nextLine().split(" ");
        String characters = scanner.nextLine();
        
        int n = scores.length;
        Piece[] pieces = new Piece[n];
        
        for (int i = 0; i < n; i++) {
            int score = Integer.parseInt(scores[i]);
            char character = characters.charAt(i);
            pieces[i] = new Piece(score, character);
        }
        
        // Call the function to calculate Bob's maximum strength and print the result
        System.out.println(BobsMaxStrength(pieces));
        
        scanner.close();
    }

    public static int BobsMaxStrength(Piece[] pieces) {
        // Initialize scores for player A and player B, and their maximum scores
        int pScore = 0, sScore = 0;
        int pMaxScore = 0, sMaxScore = 0;

        // Calculate maximum score for player A by iterating through pieces from the start
        for (Piece piece : pieces) {
            if (piece.character == 'A') {  // If the piece belongs to player A
                pScore += piece.score;  // Add the score of the piece to player A's score
                if (pScore > pMaxScore) {  // Update maximum score if current score exceeds it
                    pMaxScore = pScore;
                }
            } else {  // If the piece belongs to player B
                pScore -= piece.score;  // Subtract the score of the piece from player A's score
            }
        }

        // Calculate maximum score for player B by iterating through pieces from the end
        for (int i = pieces.length - 1; i >= 0; i--) {
            if (pieces[i].character == 'A') {  // If the piece belongs to player A
                sScore += pieces[i].score;  // Add the score of the piece to player B's score
                if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                    sMaxScore = sScore;
                }
            } else {  // If the piece belongs to player B
                sScore -= pieces[i].score;  // Subtract the score of the piece from player B's score
            }
        }

        // Return the maximum score between player A and player B
        return Math.max(pMaxScore, sMaxScore);
    }

    static class Piece {
        int score;
        char character;

        Piece(int score, char character) {
            this.score = score;
            this.character = character;
        }
    }
}

// <END-OF-CODE>
