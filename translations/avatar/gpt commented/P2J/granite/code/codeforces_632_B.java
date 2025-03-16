
import java.util.Scanner;

public class codeforces_632_B{
    public static void main(String[] args) {
        // Read input (the first input is ignored)
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();

        // Read the second line of input, split it into integers and corresponding characters,
        // and create a tuple of pieces where each piece is a tuple of (score, character)
        int[] scores = new int[2];
        char[] characters = new char[2];
        String[] input = scanner.nextLine().split(" ");
        for (int i = 0; i < input.length; i++) {
            scores[i] = Integer.parseInt(input[i]);
            characters[i] = input[i + 1].charAt(0);
            i++;
        }
        Tuple[] pieces = new Tuple[2];
        for (int i = 0; i < 2; i++) {
            pieces[i] = new Tuple(scores[i], characters[i]);
        }

        // Call the function to calculate Bob's maximum strength and print the result
        System.out.println(Bob_sMaxStrength(pieces));
    }

    public static int Bob_sMaxStrength(Tuple[] pieces) {
        // Initialize scores for player A and player B, and their maximum scores
        int pScore = sScore = pMaxScore = sMaxScore = 0;
        for (Tuple piece : pieces) {
            if (piece.character == 'B') {
                pScore += piece.score;
            }
        }

        // Calculate maximum score for player A by iterating through pieces from the start
        for (Tuple piece : pieces) {
            if (piece.character == 'A') {
                pScore += piece.score;
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                pScore -= piece.score;
            }
        }

        // Calculate maximum score for player B by iterating through pieces from the end
        for (int i = pieces.length - 1; i >= 0; i--) {
            if (pieces[i].character == 'A') {
                sScore += pieces[i].score;
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } else {
                sScore -= pieces[i].score;
            }
        }

        // Return the maximum score between player A and player B
        if (pMaxScore > sMaxScore) {
            return pMaxScore;
        }
        return sMaxScore;
    }

    public static class Tuple {
        public int score;
        public char character;

        public Tuple(int score, char character) {
            this.score = score;
            this.character = character;
        }
    }
}

