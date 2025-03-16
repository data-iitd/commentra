import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        long a = scanner.nextLong();  // Read the first long integer
        long b = scanner.nextLong();  // Read the second long integer
        long c = scanner.nextLong();  // Read the third long integer

        long d = c - a - b;  // Calculate the difference between c and the sum of a and b
        if (d > 0 && (4 * a * b) < d * d)  // Check if the difference is positive and satisfies the specific condition
            System.out.println("Yes");  // Print "Yes" if the condition is met
        else
            System.out.println("No");  // Print "No" otherwise

        scanner.close();  // Close the scanner to prevent resource leaks
    }  // End of main method
}  // End of main class
// <END-OF-CODE>
