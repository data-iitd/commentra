import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Declare the main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String str = scanner.next(); // Input the string from the user and store it in the string variable str
        
        // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
        if (str.charAt(2) == str.charAt(3) && str.charAt(4) == str.charAt(5)) {
            System.out.println("Yes"); // Output "Yes" if the conditions are met
        } else {
            System.out.println("No"); // Output "No" if the conditions are not met
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
