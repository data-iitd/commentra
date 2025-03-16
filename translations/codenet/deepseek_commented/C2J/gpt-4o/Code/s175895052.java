import java.util.Scanner;  // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        String n = scanner.next();  // Read a string from the user input

        // Check if any two consecutive characters in the string n are the same
        if ((n.length() >= 3 && (n.charAt(0) == n.charAt(1) && n.charAt(1) == n.charAt(2))) || 
            (n.length() >= 4 && (n.charAt(1) == n.charAt(2) && n.charAt(2) == n.charAt(3)))) {
            System.out.println("Yes");  // Print "Yes" if the condition is true
        } else {
            System.out.println("No");  // Print "No" if the condition is false
        }

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
