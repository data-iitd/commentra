import java.util.Scanner;
import java.util.regex.Pattern;

public class SentenceCounter {
    public static void main(String[] args) {
        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Taking the number of sentences n as input
        int n = Integer.parseInt(scanner.nextLine());

        // Initializing the answer counter ans and the sum of lengths of sentences sumL
        int ans = 1, sumL = 0;

        // Taking the input string and splitting it into sentences based on punctuation marks
        String input = scanner.nextLine();
        String[] sentences = Pattern.compile("[.?!]").split(input);

        // Loop to process each sentence
        for (String s : sentences) {
            // Stripping leading and trailing whitespaces from the sentence s
            s = s.trim();
            // Adding a dot at the end of the sentence if it doesn't already have one
            s += '.';

            // Calculating the length L of the sentence s
            int L = s.length();

            // Checking if the length of the sentence is greater than the number of sentences n
            if (L > n) {
                // Printing an error message and exiting the program if the condition is true
                System.out.println("Impossible");
                return;
            }

            // Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
            if (sumL + L + (sumL > 0 ? 1 : 0) > n) {
                // Incrementing the answer counter ans if the condition is true
                ans++;
                // Updating the sum of lengths sumL with the length of the current sentence
                sumL = L;
            } else {
                // Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
                sumL = sumL + L + (sumL > 0 ? 1 : 0);
            }
        }

        // Printing the final answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
