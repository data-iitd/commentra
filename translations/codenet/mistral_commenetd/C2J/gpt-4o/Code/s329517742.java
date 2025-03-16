import java.util.Scanner; // Importing the Scanner class for input

public class Main { // Declaring the Main class
    public static void main(String[] args) { // Declaring the main method
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int a, b; // Declaring two integer variables a and b
        a = scanner.nextInt(); // Reading the first integer from the standard input
        b = scanner.nextInt(); // Reading the second integer from the standard input

        // Logical block to check if 500 times the value of variable 'a' is greater than or equal to the value of variable 'b'
        if (500 * a >= b) {
            System.out.println("Yes"); // If the condition is true, print 'Yes' to the standard output
        } else {
            System.out.println("No"); // If the condition is false, print 'No' to the standard output
        }

        scanner.close(); // Closing the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
