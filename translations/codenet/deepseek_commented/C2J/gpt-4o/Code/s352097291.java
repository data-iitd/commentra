import java.util.Scanner; // Import Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String c = scanner.next(); // Read input string into c
        StringBuilder ans = new StringBuilder(); // Use StringBuilder for efficient string manipulation

        // Process the input string
        for (int i = 0; i < c.length(); i++) {
            char currentChar = c.charAt(i); // Get the current character
            if (currentChar != 'B') {
                ans.append(currentChar); // Append character to ans if not 'B'
            } else {
                if (ans.length() > 0) {
                    ans.deleteCharAt(ans.length() - 1); // Remove last character from ans if 'B'
                }
            }
        }

        System.out.println(ans.toString()); // Output the result string ans
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
