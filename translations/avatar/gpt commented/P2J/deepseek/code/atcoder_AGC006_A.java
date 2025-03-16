import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the integer input which represents the length of the strings
        int n = scanner.nextInt();
        
        // Read the first string and convert it to a character array
        char[] s = scanner.next().toCharArray();
        
        // Read the second string and convert it to a character array
        char[] t = scanner.next().toCharArray();
        
        // Check if both strings are identical
        if (areIdentical(s, t)) {
            // If they are the same, print the length of the strings
            System.out.println(n);
        } else {
            // Initialize a counter to keep track of the matching characters
            int cnt = 0;
            
            // Iterate over each character in the first string
            for (int i = 0; i < n; i++) {
                // For each character, check the subsequent characters in the second string
                for (int j = 0; j < n - i; j++) {
                    // If characters at the current position do not match, break the inner loop
                    if (s[i + j] != t[j]) {
                        break;
                    }
                    
                    // If we have matched all characters from this starting point
                    if (j == n - i - 1) {
                        // Update the count of matching characters
                        cnt = n - i;
                    }
                }
            }
            
            // Print the result based on the number of matching characters found
            System.out.println(2 * n - cnt);
        }
        
        scanner.close();
    }
    
    // Helper method to check if two character arrays are identical
    private static boolean areIdentical(char[] s, char[] t) {
        for (int i = 0; i < s.length; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
}
