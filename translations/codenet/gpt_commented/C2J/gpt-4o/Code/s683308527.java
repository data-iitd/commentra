import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Variable to store the number of lines to read
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Loop to process each line of input
        while (n-- > 0) {
            // Read a line of input from stdin
            String s = scanner.nextLine();
            
            // Search for the substring "Hoshino" in the input line
            // Replace the character following "Hoshino" with 'a'
            int index;
            while ((index = s.indexOf("Hoshino")) != -1) {
                if (index + 7 < s.length()) { // Ensure there is a character to replace
                    s = s.substring(0, index + 6) + 'a' + s.substring(index + 7);
                } else {
                    s = s.substring(0, index + 6) + 'a'; // If "Hoshino" is at the end
                }
            }
            
            // Print the modified line
            System.out.println(s);
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
