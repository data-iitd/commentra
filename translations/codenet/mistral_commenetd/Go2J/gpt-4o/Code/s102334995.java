// Importing the Scanner class for input operations
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Declaring two integer variables 'a' and 'b'
        int a, b;

        // Reading input values for variables 'a' and 'b' from the standard input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Multiplying the variables 'a' and 'b' and printing the result
        System.out.println(a * b);

        // Multiplying the sum of 'a' and 'b' with 2 and printing the result
        System.out.println((a + b) * 2);

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
