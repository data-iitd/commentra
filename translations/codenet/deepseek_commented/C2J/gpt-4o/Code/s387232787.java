import java.util.Scanner;

public class LetterCount {
    public static void main(String[] args) {
        // Array to store the count of each letter (a-z)
        int[] c = new int[26];
        
        // Scanner to read input strings
        Scanner scanner = new Scanner(System.in);
        
        // Read input strings until there are no more inputs
        while (scanner.hasNext()) {
            String str = scanner.next();
            
            // Traverse each character in the string
            for (char ch : str.toCharArray()) {
                // Check if the character is a lowercase letter
                if ('a' <= ch && ch <= 'z') {
                    // Increment the count for the corresponding letter
                    c[ch - 'a']++;
                } 
                // Check if the character is an uppercase letter
                else if ('A' <= ch && ch <= 'Z') {
                    // Increment the count for the corresponding letter
                    c[ch - 'A']++;
                }
            }
        }
        
        // Print the counts for each letter from 'a' to 'z'
        for (int i = 0; i < 26; i++) {
            System.out.println((char) ('a' + i) + " : " + c[i]);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
