

import java.util.Scanner;

public class atcoder_ARC062_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();  // Read the input string
        int numG = 0, numP = 0;  // Initialize counters for 'g' and 'p' characters
        int score = 0;  // Initialize the score variable to 0

        // Iterate over each character in the string
        for (int i = 0; i < s.length(); i++) {
            char x = s.charAt(i);
            if (x == 'g') {
                // Check if the number of 'g' characters exceeds the number of 'p' characters
                if (numG - numP > 0) {
                    score += 1;  // Increment the score and the count of 'p' characters
                    numP += 1;
                } else {
                    score = score;  // Keep the score unchanged and increment the count of 'g' characters
                    numG += 1;
                }
            } else if (x == 'p') {
                // Check if the number of 'g' characters exceeds the number of 'p' characters
                if (numG - numP > 0) {
                    score = score;  // Keep the score unchanged and increment the count of 'p' characters
                    numP += 1;
                } else {
                    score -= 1;  // Decrement the score and increment the count of 'g' characters
                    numG += 1;
                }
            }
        }

        System.out.println(score);  // Print the final score
    }
}

