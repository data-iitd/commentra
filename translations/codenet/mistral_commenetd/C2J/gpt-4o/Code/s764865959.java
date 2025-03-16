import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class
    public static void main(String[] args) { // Starting the main method
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int x; // Declaring an integer variable x

        x = scanner.nextInt(); // Reading an integer value from the user and storing it in variable x

        // The following block of code calculates x raised to the power of 3
        x = x * x * x;

        // Printing the result to the console
        System.out.println(x);

        scanner.close(); // Closing the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
