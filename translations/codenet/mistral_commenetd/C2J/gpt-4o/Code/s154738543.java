import java.util.Scanner; // Importing the Scanner class for user input

public class CubeCalculator { // Class declaration

    public static void main(String[] args) { // Main method declaration

        int x, y; // Declaring two integer variables x and y
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input

        System.out.print("Enter a number: "); // Printing a message to ask user for input
        x = scanner.nextInt(); // Reading an integer value from the user and storing it in variable x

        y = x * x * x; // Assigning the value of x cubed to variable y

        System.out.printf("The cube of %d is %d\n", x, y); // Printing the message with the input number and its cube

        scanner.close(); // Closing the scanner to prevent resource leaks
    } // End of main method
} // End of class
// <END-OF-CODE>
