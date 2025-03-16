import java.util.Scanner;  // Import the Scanner class for reading input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        int x;  // Declare an integer variable named x

        // Read an integer value from the standard input and store it in the variable x
        x = scanner.nextInt();

        if (x == 1) {  // Check if the value of x is equal to 1
            System.out.println("0");  // If x is 1, print 0 to the standard output
        } else {  // If x is not equal to 1
            System.out.println("1");  // Otherwise, print 1 to the standard output
        }

        scanner.close();  // Close the scanner to free resources
    }  // End of the main method
}  // End of the Main class
// <END-OF-CODE>
