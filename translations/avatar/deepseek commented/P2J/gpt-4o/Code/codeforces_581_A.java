import java.util.Scanner;  // Importing the Scanner class for user input

public class FactorialCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read input
        int n = scanner.nextInt();  // Taking an integer input from the user
        long factorial = 1;  // Initializing a variable to store the factorial result

        for (int i = 1; i <= n; i++) {  // Starting a loop from 1 to the input number (inclusive)
            factorial *= i;  // Multiplying the factorial by the current number
        }

        System.out.println(factorial);  // Printing the factorial result
        scanner.close();  // Closing the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
