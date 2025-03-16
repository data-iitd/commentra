import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Declaring the Main class
    public static void main(String[] args) { // Declaring the main method
        int a, b, s; // Declaring three integer variables a, b, and s

        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        a = scanner.nextInt(); // Reading the first integer from the user
        b = scanner.nextInt(); // Reading the second integer from the user

        s = (a * b) - (a + b) + 1; // Calculating the value of s

        // The following line prints the value of s to the console
        System.out.println(s);

        scanner.close(); // Closing the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
