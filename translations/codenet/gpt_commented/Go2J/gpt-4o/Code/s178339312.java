import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable 'x' of type int to store user input
        int x;

        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from standard input and store it in 'x'
        x = scanner.nextInt();

        // Calculate the cube of 'x' and print the result to standard output
        System.out.println(x * x * x);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
