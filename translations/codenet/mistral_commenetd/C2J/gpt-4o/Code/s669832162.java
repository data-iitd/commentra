import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        // Declare four integer variables to store months and days
        int m1, d1, m2, d2;

        // Read four integers from the standard input
        m1 = scanner.nextInt();
        d1 = scanner.nextInt();
        m2 = scanner.nextInt();
        d2 = scanner.nextInt();

        // Check if the first two months are equal or not
        if (m1 != m2) {
            // If the months are not equal, print "1" to the standard output
            System.out.println("1");
        } else {
            // If the months are equal, print "0" to the standard output
            System.out.println("0");
        }

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
