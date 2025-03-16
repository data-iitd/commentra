import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int a = scanner.nextInt(); // Reading the first integer
        int b = scanner.nextInt(); // Reading the second integer
        int product = a * b; // Calculating the product

        if (product % 2 == 0) { // Checking if the product is even
            System.out.println("Even"); // Printing "Even" if the product is even
        } else {
            System.out.println("Odd"); // Printing "Odd" if the product is odd
        }

        scanner.close(); // Closing the scanner
    }
}

// <END-OF-CODE>
