
import java.util.Scanner;

public class s389564195{
    public static void main(String[] args) {
        // Declare two integer variables: x for input and kotae for storing the result
        int x, kotae;

        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter an integer value
        System.out.print("Enter an integer value: ");
        x = scanner.nextInt();

        // Calculate the cube of the input value x and store it in kotae
        kotae = x * x * x;

        // Output the result (the cube of x) to the console
        System.out.println("The cube of " + x + " is " + kotae);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
