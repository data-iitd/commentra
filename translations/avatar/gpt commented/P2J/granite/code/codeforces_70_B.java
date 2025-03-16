
import java.util.Scanner;  // Import the Scanner class
import java.util.regex.Pattern;  // Import the Pattern class

public class codeforces_70_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        Pattern pattern = Pattern.compile("[.?!]");  // Create a Pattern object to match punctuation marks

        // Read an integer input which represents the maximum allowed length for sentences
        int n = scanner.nextInt();

        // Initialize the answer counter and the sum of lengths of sentences
        int ans = 1, sumL = 0;

        // Split the input text into sentences based on punctuation marks
        for (String s : pattern.split(scanner.next())) {
            s = s.trim() + '.';  // Trim whitespace and add a period to the end of the sentence
            int L = s.length();  // Calculate the length of the current sentence

            // Check if the length of the sentence is greater than 1 (to avoid empty sentences)
            if (L > 1) {
                // If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
                if (L > n) {
                    System.out.println("Impossible");
                    return;
                }

                // Check if adding the current sentence length to the sum exceeds the maximum allowed length
                if (sumL + L + (sumL > 0) > n) {
                    ans++;  // Increment the answer counter for a new line
                    sumL = L;  // Reset the sum of lengths to the current sentence length
                } else {
                    // Update the sum of lengths by adding the current sentence length
                    sumL = sumL + L + (sumL > 0);  // Add 1 if there was a previous sentence (to account for space)
                }
            }
        }

        // Print the total number of lines needed
        System.out.println(ans);
    }
}
