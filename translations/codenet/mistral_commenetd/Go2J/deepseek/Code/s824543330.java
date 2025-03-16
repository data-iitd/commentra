import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables, a and b
        int a, b;

        // Read two integers from the user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Check if the product of a and b is even using the modulo operator (%)
        // If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2
        if ((a * b) % 2 == 0) {
            // If the condition is true, print the message "Even"
            System.out.println("Even");
        } else {
            // If the condition is false, print the message "Odd"
            System.out.println("Odd");
        }
    }
}

