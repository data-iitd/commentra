import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input string from the user
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize an empty string to store the result
        StringBuilder result = new StringBuilder();

        // Initialize a counter variable to iterate through the input string
        int i = 0;

        // Loop through each character in the input string
        while (i < s.length()) {
            // Check if the current character is a dot
            if (s.charAt(i) == '.') {
                // If it is a dot, append '0' to the result
                result.append('0');
            } else {
                // If it is not a dot, increment the index to check the next character
                i++;

                // Check if we are still within bounds
                if (i < s.length()) {
                    if (s.charAt(i) == '.') {
                        // If the next character is a dot, append '1' to the result
                        result.append('1');
                    } else {
                        // If the next character is not a dot, append '2' to the result
                        result.append('2');
                    }
                }
            }

            // Increment the index to move to the next character in the input string
            i++;
        }

        // Print the final result string
        System.out.println(result.toString());
    }
}
// <END-OF-CODE>
