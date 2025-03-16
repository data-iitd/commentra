import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        int a, b, c, d; // Declare four integer variables a, b, c, and d

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read two integers from the user and store them in variables a and b
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Multiply the two integers and store the result in variable c
        c = a * b;

        // Multiply each integer with 2 and add them to get the value of d
        d = 2 * a + 2 * b;

        // Print the values of c and d on the console
        System.out.println(c + " " + d);

        // Close the scanner
        scanner.close();
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
