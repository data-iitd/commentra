import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the main class
    public static void main(String[] args) { // The entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int h = scanner.nextInt(); // Read the first integer and store it in h
        int r = scanner.nextInt(); // Read the second integer and store it in r
        
        if (r > -h) { // Check if r is greater than the negative value of h
            System.out.println("1"); // If the condition is true, print 1
        } else if (r == -h) { // Check if r is equal to the negative value of h
            System.out.println("0"); // If the condition is true, print 0
        } else { // If the previous conditions are false
            System.out.println("-1"); // Print -1
        }
        
        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
