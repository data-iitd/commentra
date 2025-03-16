import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a scanner to take input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Take input from the user
        scanner.nextLine(); // To consume the first line of input
        
        // Process the input to get a tuple of (value, type) pairs for each piece
        String[] input = scanner.nextLine().split(" ");
        Piece[] pieces = new Piece[input.length];
        
        for (int i = 0; i < input.length; i++) {
            int value = Integer.parseInt(input[i]);
            char type = scanner.nextLine().charAt(0);
            pieces[i] = new Piece(value, type);
        }
        
        // Call the Bob_sMaxStrength function with the processed pieces and print its result
        System.out.println(Bob_sMaxStrength(pieces));
        
        scanner.close();
    }

    public static int Bob_sMaxStrength(Piece[] pieces) {
        // Initialize scores for both ends and their maximum scores
        int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;

        // Calculate the initial score for 'B' pieces
        for (Piece piece : pieces) {
            if (piece.type == 'B') {
                pScore += piece.value;
            }
        }
        pMaxScore = pScore;

        // Calculate the score from the front (left to right)
        for (Piece piece : pieces) {
            if (piece.type == 'A') {
                pScore += piece.value;
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                pScore -= piece.value;
            }
        }

        // Calculate the score from the back (right to left)
        for (int i = pieces.length - 1; i >= 0; i--) {
            if (pieces[i].type == 'A') {
                sScore += pieces[i].value;
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } else {
                sScore -= pieces[i].value;
            }
        }

        // Return the maximum score between the two ends
        return Math.max(pMaxScore, sMaxScore);
    }

    static class Piece {
        int value;
        char type;

        Piece(int value, char type) {
            this.value = value;
            this.type = type;
        }
    }
}

// <END-OF-CODE>
