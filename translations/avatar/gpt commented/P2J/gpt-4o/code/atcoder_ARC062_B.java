import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input and convert it into a character array
        Scanner scanner = new Scanner(System.in);
        char[] s = scanner.nextLine().toCharArray();

        // Initialize counters for 'g' and 'p' occurrences, and the score
        int numG = 0, numP = 0;
        int score = 0;

        // Iterate through each character in the input array
        for (char x : s) {
            // Check if the character is 'g'
            if (x == 'g') {
                // If there are more 'g's than 'p's, increase the score and count 'p'
                if (numG - numP > 0) {
                    score += 1;  // Increase score for 'g'
                    numP += 1;   // Increment the count of 'p's
                } else {
                    // If not, just increment the count of 'g's
                    numG += 1;   // Increment the count of 'g's
                }
            }
            // Check if the character is 'p'
            else if (x == 'p') {
                // If there are more 'g's than 'p's, just count 'p'
                if (numG - numP > 0) {
                    numP += 1;   // Increment the count of 'p's
                } else {
                    // If not, decrease the score and increment the count of 'g's
                    score -= 1;  // Decrease score for 'p'
                    numG += 1;   // Increment the count of 'g's
                }
            }
        }

        // Print the final score
        System.out.println(score);
    }
}
// <END-OF-CODE>
