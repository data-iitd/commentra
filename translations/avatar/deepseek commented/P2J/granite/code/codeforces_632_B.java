

import java.util.Scanner;

public class codeforces_632_B{
    public static void main(String[] args) {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        scanner.nextInt();
        // Process the input to get a tuple of (value, type) pairs for each piece
        int[] values = new int[100000];
        char[] types = new char[100000];
        int count = 0;
        while (scanner.hasNextInt()) {
            values[count] = scanner.nextInt();
            types[count] = scanner.next().charAt(0);
            count++;
        }
        // Call the Bob_sMaxStrength function with the processed pieces and return its result
        System.out.println(Bob_sMaxStrength(values, types, count));
    }

    public static int Bob_sMaxStrength(int[] values, char[] types, int count) {
        // Initialize scores for both ends and their maximum scores
        int pScore = sScore = pMaxScore = sMaxScore = 0;
        for (int i = 0; i < count; i++) {
            if (types[i] == 'B') {
                pScore += values[i];
            }
        }
        // Calculate the score from the front (left to right)
        for (int i = 0; i < count; i++) {
            if (types[i] == 'A') {
                pScore += values[i];
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                pScore -= values[i];
            }
        }
        // Calculate the score from the back (right to left)
        for (int i = count - 1; i >= 0; i--) {
            if (types[i] == 'A') {
                sScore += values[i];
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } else {
                sScore -= values[i];
            }
        }
        // Return the maximum score between the two ends
        if (pMaxScore > sMaxScore) {
            return pMaxScore;
        }
        return sMaxScore;
    }
}

