import java.util.Scanner;

public class Main {
    // The main function is the starting point of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String n = scanner.next(); // Read a string of characters from the standard input

        // Check if the first three characters of the input string form an identical sequence
        if ((n.length() >= 4 && n.charAt(0) == n.charAt(1) && n.charAt(1) == n.charAt(2)) ||
            (n.length() >= 4 && n.charAt(1) == n.charAt(2) && n.charAt(2) == n.charAt(3))) {
            // If the condition is true, print "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No" to the standard output
            System.out.println("No");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
