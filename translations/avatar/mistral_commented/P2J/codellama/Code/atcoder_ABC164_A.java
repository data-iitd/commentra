
// Import the Scanner class for reading input from the console
import java.util.Scanner;

// Define the main function that takes no arguments and returns nothing
public static void main(String[] args) {

    // Create a Scanner object for reading input from the console
    Scanner input = new Scanner(System.in);

    // Read the input as a list of two integers, S and W, using the nextInt() method
    int S = input.nextInt();
    int W = input.nextInt();

    // Check if the condition S <= W is true or false and print the corresponding message
    if (S <= W) {
        System.out.println("unsafe");
    } else {
        System.out.println("safe");
    }

    // Close the Scanner object
    input.close();
}

// End of code
