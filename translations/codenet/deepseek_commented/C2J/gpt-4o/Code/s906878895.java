import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        while (scanner.hasNextInt()) { // Read two integers from standard input until end of file
            int a = scanner.nextInt(); // Read the first integer
            int b = scanner.nextInt(); // Read the second integer
            int x = a + b; // Calculate the sum of the two integers
            int w = 0; // Initialize the digit count to 0
            while (x > 0) { // Loop to count the number of digits in the sum
                w++; // Increment the digit count
                x /= 10; // Divide the sum by 10 to remove the last digit
            }
            System.out.println(w); // Print the number of digits in the sum
        }
        scanner.close(); // Close the scanner
    }
} // End of class Main
// <END-OF-CODE>
