import java.util.Scanner; // Import the Scanner class for input

public class ReverseString {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String str; // Declare a string to store the input
        
        str = scanner.next(); // Read a string from the user
        
        // Reverse the string and print it
        for (int i = str.length() - 1; i >= 0; i--) {
            System.out.print(str.charAt(i)); // Print each character in reverse order
        }
        System.out.println(); // Print a newline character at the end
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
