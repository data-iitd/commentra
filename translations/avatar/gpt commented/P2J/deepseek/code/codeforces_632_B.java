import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first input (ignored)
        scanner.nextLine();
        
        // Read the second line of input, split into integers and corresponding characters,
        // and create a tuple of pieces where each piece is a tuple of (score, character)
        String[] input = scanner.nextLine().split(" ");
        int[] scores = new int[input.length];
        char[] characters = new char[input.length];
        
        for (int i = 0; i < input.length; i++) {
            scores[i] = Integer.parseInt(input[i]);
        }
        
        String charactersInput = scanner.nextLine();
        for (int i = 0; i < charactersInput.length(); i++) {
            characters[i] = charactersInput.charAt(i);
        }
        
        // Create a tuple of pieces where each piece is a tuple of (score, character)
        Tuple[] pieces = new Tuple[scores.length];
        for (int i = 0; i < scores.length; i++) {
            pieces[i] = new Tuple(scores[i], characters[i]);
        }
        
        // Call the function to calculate Bob's maximum strength and return the result
        int result = Bob_sMaxStrength(pieces);
        System.out.println(result);
    }
    
    public static int Bob_sMaxStrength(Tuple[] pieces) {
        // Initialize scores for player A and player B, and their maximum scores
        int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
        
        // Calculate maximum score for player A by iterating through pieces from the start
        for (Tuple piece : pieces) {
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
            Tuple piece = pieces[i];
            if (piece.character == 'A') {  // If the piece belongs to player A
                sScore += piece.score;  // Add the score of the piece to player B's score
                if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                    sMaxScore = sScore;
                }
            } else {  // If the piece belongs to player B
                sScore -= piece.score;  // Subtract the score of the piece from player B's score
            }
        }
        
        // Return the maximum score between player A and player B
        return Math.max(pMaxScore, sMaxScore);
    }
    
    static class Tuple {
        int score;
        char character;
        
        Tuple(int score, char character) {
            this.score = score;
            this.character = character;
        }
    }
}
