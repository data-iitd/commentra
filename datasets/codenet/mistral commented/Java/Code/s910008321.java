
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object to read input from the standard input stream (System.in)
        Scanner scanner = new Scanner(System.in);

        // Read the first integer value (h) from the user input
        int h = scanner.nextInt();

        // Read the second integer value (a) from the user input
        int a = scanner.nextInt();

        // Check if the value of h is divisible by a using the modulo operator (%).
        // If the condition is true, the remainder will be zero, and we can print the quotient.
        // If the condition is false, the remainder will be non-zero, and we need to print the quotient plus one.
        if (h % a == 0) {
            // If the condition is true, we print the integer value obtained by dividing h by a.
            System.out.println("The quotient is: " + (h / a));
        } else {
            // If the condition is false, we print the result of dividing h by a, plus one.
            System.out.println("The quotient is: " + ((h / a) + 1));
        }
    }
}