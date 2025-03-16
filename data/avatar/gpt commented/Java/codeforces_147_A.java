import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.io.PrintWriter; 

public class Main {
    
    // Method to check if a character is a lowercase Latin letter
    public static boolean isLatinLetter(char c) {
        return c >= 'a' && c <= 'z'; // Returns true if c is between 'a' and 'z'
    }

    // Method to check if a character is a punctuation mark
    public static boolean isPunctuation(char c) {
        // Check for specific punctuation characters
        if (c == '.') return true; 
        if (c == ',') return true; 
        if (c == '!') return true; 
        if (c == '?') return true; 
        return false; // Returns false if c is not a recognized punctuation
    }

    public static void main(String[] args) throws IOException {
        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        // Create a PrintWriter to output results to the console
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read a line of input from the user
        String s = br.readLine(); 
        // Initialize a StringBuilder to construct the output string
        StringBuilder sb = new StringBuilder(); 
        int n = s.length(); // Get the length of the input string
        
        // Append the first character of the input string to the StringBuilder
        sb.append(s.charAt(0)); 
        
        // Loop through the input string starting from the second character
        for (int i = 1; i < n; i++) {
            char c = s.charAt(i); // Get the current character
            
            // Check if the current character is a Latin letter
            if (isLatinLetter(c)) {
                // If the previous character is not a Latin letter, append a space
                if (!isLatinLetter(s.charAt(i - 1))) {
                    sb.append(' '); 
                }
                // Append the current Latin letter to the StringBuilder
                sb.append(c); 
            } 
            // Check if the current character is a punctuation mark
            else if (isPunctuation(c)) {
                sb.append(c); // Append the punctuation mark to the StringBuilder
            }
        }
        
        // Print the constructed output string
        pw.println(sb); 
        pw.flush(); // Ensure all output is written to the console
        pw.close(); // Close the PrintWriter
    }
}
