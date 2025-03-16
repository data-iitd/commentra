import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read the first string from user input
        String t = scanner.next(); // Read the second string from user input

        s += s; // Concatenate string s with itself, effectively doubling it

        // Check if string t can be found within the doubled string s
        // If found, print "Yes", otherwise print "No"
        System.out.println(s.contains(t) ? "Yes" : "No"); // Use contains method to check for substring
    }
}

// <END-OF-CODE>
