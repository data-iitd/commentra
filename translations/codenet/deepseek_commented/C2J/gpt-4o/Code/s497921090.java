import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        long n = scanner.nextLong();  // Read the input number
        long b = (n * (n - 1)) / 2;  // Calculate the result using the given formula
        System.out.println(b);  // Print the result
        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of Main class
// <END-OF-CODE>
