import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        // Declaring a variable 'a' of type 'int'
        int a;

        // Creating a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Reading an integer value from the standard input
        a = scanner.nextInt();

        // Multiplying the value of 'a' with itself twice and printing the result
        System.out.println(3 * a * a);
        // This block prints the square of the number 'a' multiplied by 3

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
