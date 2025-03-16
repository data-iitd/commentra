import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integer values from the standard input
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Calculate the product of "a" and "b"
        int product = a * b;

        // Check if the product is even or odd
        if (product % 2 == 0) {
            // If the product is even, print the message "Even" to the standard output
            System.out.println("Even");
        } else {
            // If the product is odd, print the message "Odd" to the standard output
            System.out.println("Odd");
        }
    }
}

