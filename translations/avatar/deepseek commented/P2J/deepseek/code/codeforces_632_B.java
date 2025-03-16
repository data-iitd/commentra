import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Take input from the user
        scanner.nextLine();
        // Process the input to get a tuple of (value, type) pairs for each piece
        String[] piecesInput = scanner.nextLine().split(" ");
        int[] values = new int[piecesInput.length];
        char[] types = new char[piecesInput.length];
        for (int i = 0; i < piecesInput.length; i++) {
            values[i] = Integer.parseInt(piecesInput[i]);
            types[i] = scanner.next().charAt(0);
        }
        // Call the Bob_sMaxStrength function with the processed pieces and return its result
        System.out.println(Bob_sMaxStrength(values, types));
    }

    public static int Bob_sMaxStrength(int[] values, char[] types) {
        // Initialize scores for both ends and their maximum scores
        int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
        
        // Calculate the score from the front (left to right)
        for (int i = 0; i < values.length; i++) {
            if (types[i] == 'B') {
                pScore += values[i];
            } else {
                pScore -= values[i];
            }
            if (pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        }
        
        // Calculate the score from the back (right to left)
        for (int i = values.length - 1; i >= 0; i--) {
            if (types[i] == 'B') {
                sScore += values[i];
            } else {
                sScore -= values[i];
            }
            if (sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        }
        
        // Return the maximum score between the two ends
        return Math.max(pMaxScore, sMaxScore);
    }
}
