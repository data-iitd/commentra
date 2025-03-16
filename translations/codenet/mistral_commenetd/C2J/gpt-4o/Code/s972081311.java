import java.util.Scanner;
// Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        // Declare variables n and sum
        int n, sum;

        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input from the user

        n = scanner.nextInt();
        // Read an integer value from the user and store it in the variable n

        sum = (n * (n + 1)) / 2;
        // Calculate the sum of the first n natural numbers
        // The formula for the sum of the first n natural numbers is n*(n+1)/2

        System.out.println(sum);
        // Print the calculated sum to the standard output

        scanner.close();
        // Close the scanner to prevent resource leaks
    }
}
// Indicate successful termination of the program
