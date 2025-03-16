import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read the first string from the user
        String t = scanner.next(); // Read the second string from the user
        int hit = 0; // Initialize a counter for hits
        for (int i = 0; i < 3; i++) { // Compare characters in the strings
            if (s.charAt(i) == t.charAt(i)) hit++; // Increment the hit counter if characters match
        }
        System.out.println(hit); // Print the number of matching characters
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
