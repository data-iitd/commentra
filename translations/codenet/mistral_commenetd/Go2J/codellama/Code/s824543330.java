// Import the Scanner class for reading input from the command line
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize two integer variables, a and b, using Scanner
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Check if the product of a and b is even using the modulo operator (%).
        // If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
        if (a*b%2 == 0) {
            // If the condition is true, print the message "Even"
            System.out.println("Even");
        } else {
            // If the condition is false, print the message "Odd"
            System.out.println("Odd");
        }
    }
}

// End of code


Translate the above Java code to C++ and end with comment "