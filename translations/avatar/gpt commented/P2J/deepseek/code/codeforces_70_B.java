import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the maximum allowed length for sentences
        int n = scanner.nextInt();
        scanner.nextLine();  // Consume the newline character
        
        // Initialize the answer counter and the sum of lengths of sentences
        int ans = 1, sumL = 0;
        
        // Read the input text
        String text = scanner.nextLine();
        
        // Split the input text into sentences based on punctuation marks (., ?, !)
        String[] sentences = text.split("[.?!]");
        
        for (String s : sentences) {
            s = s.trim() + ".";  // Trim whitespace and add a period to the end of the sentence
            int L = s.length();  // Calculate the length of the current sentence
            
            // Check if the length of the sentence is greater than 1 (to avoid empty sentences)
            if (L > 1) {
                // If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
                if (L > n) {
                    System.out.println("Impossible");
                    return;
                }
                
                // Check if adding the current sentence length to the sum exceeds the maximum allowed length
                if (sumL + L + (sumL > 0 ? 1 : 0) > n) {
                    ans++;  // Increment the answer counter for a new line
                    sumL = L;  // Reset the sum of lengths to the current sentence length
                } else {
                    // Update the sum of lengths by adding the current sentence length
                    sumL += L + (sumL > 0 ? 1 : 0);  // Add 1 if there was a previous sentence (to account for space)
                }
            }
        }
        
        // Print the total number of lines needed
        System.out.println(ans);
    }
}
