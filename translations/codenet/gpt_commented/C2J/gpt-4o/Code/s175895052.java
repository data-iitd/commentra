import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a character array to hold the input string
        Scanner scanner = new Scanner(System.in);
        String n = scanner.next();

        // Check if the first three characters are the same or if the last three characters are the same
        if ((n.charAt(0) == n.charAt(1) && n.charAt(1) == n.charAt(2)) || 
            (n.charAt(1) == n.charAt(2) && n.charAt(2) == n.charAt(3))) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
