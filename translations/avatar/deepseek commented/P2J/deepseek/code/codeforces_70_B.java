import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take the maximum sentence length as input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        
        // Initialize variables to keep track of the number of sentences and their cumulative length
        int ans = 1, sumL = 0;
        
        // Take a string input and split it into sentences using the regular expression [.?!]
        String[] sentences = Pattern.compile("[.?!]").split(scanner.nextLine().trim());
        
        for (String s : sentences) {
            // Strip leading and trailing whitespace and add a period to the end of the sentence
            s = s.trim() + ".";
            // Calculate the length of the sentence
            int L = s.length();
            
            // Check if the sentence length is greater than 1
            if (L > 1) {
                // Check if the sentence length is greater than the maximum allowed length
                if (L > n) {
                    // If the sentence is too long, print "Impossible" and exit
                    System.out.println("Impossible");
                    return;
                }
                
                // Check if adding the current sentence would exceed the maximum allowed length
                if (sumL + L + (sumL > 0 ? 1 : 0) > n) {
                    // If adding the sentence would exceed the maximum length, increment the sentence count
                    ans++;
                    // Reset the cumulative length to the length of the current sentence
                    sumL = L;
                } else {
                    // Otherwise, add the length of the current sentence to the cumulative length
                    sumL = sumL + L + (sumL > 0 ? 1 : 0);
                }
            }
        }
        
        // Print the total number of sentences
        System.out.println(ans);
    }
}
