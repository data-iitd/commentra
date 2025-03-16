import java.util.Scanner; // Import the Scanner class for user input

public class ReverseString { // Declare a public class named ReverseString
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        System.out.print("Enter a string: "); // Prompt the user to enter a string
        String str = scanner.nextLine(); // Read a string from the user

        int len = str.length(); // Calculate the length of the string

        System.out.print("Reversed string: "); // Print a message to indicate that the reversed string will be printed

        for (int i = len - 1; i >= 0; i--) { // Use a for loop to print each character of the string in reverse order
            System.out.print(str.charAt(i)); // Print the character at index 'i' of the string
        }

        System.out.println(); // Print a newline character
        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
