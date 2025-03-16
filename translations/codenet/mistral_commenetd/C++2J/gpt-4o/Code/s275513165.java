import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String str = scanner.next(); // Read a string input from the user

        // Check if the third and fourth characters of the string are identical
        if (str.charAt(2) == str.charAt(3)) {
            // If the condition is true, proceed to the next check
            if (str.charAt(4) == str.charAt(5)) { // Check if the fifth and sixth characters are identical
                System.out.println("Yes"); // If both conditions are true, print 'Yes'
            } else {
                System.out.println("No"); // If not, print 'No' instead
            }
        }
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
