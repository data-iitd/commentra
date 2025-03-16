import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Declaring the Main class
    public static void main(String[] args) { // Starting the main method
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        System.out.print("Enter a number: "); // Printing a message to ask the user to enter a number
        int n = scanner.nextInt(); // Reading an integer value from the standard input and storing it in the variable `n`

        if (n % 1000 == 0) { // Checking if the remainder of `n` when divided by 1000 is equal to 0
            System.out.println(0); // If the condition is true, we print the value 0 to the standard output
        } else {
            System.out.println((n / 1000 + 1) * 1000 - n); // If the condition is false, we calculate and print the required value
        }

        scanner.close(); // Closing the scanner to prevent resource leaks
    } // Ending the main method
} // Ending the Main class
// <END-OF-CODE>
