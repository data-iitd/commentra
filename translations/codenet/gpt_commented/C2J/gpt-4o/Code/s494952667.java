import java.util.Scanner;

public class ReverseString {
    public static void main(String[] args) {
        // Declare a character array to hold the input string (maximum length 20)
        char[] str = new char[21];
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read a string from standard input
        String input = scanner.nextLine();
        
        // Copy the input string to the character array
        input.getChars(0, Math.min(input.length(), 20), str, 0);
        
        // Calculate the length of the input string
        int len = input.length();
        
        // Loop through the string in reverse order
        for (int i = len - 1; i >= 0; i--) {
            // Output each character of the string in reverse
            System.out.print(str[i]);
        }
        
        // Print a newline character after the reversed string
        System.out.println();
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
