import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int a = scanner.nextInt();  // Read the first integer from the user
        int b = scanner.nextInt();  // Read the second integer from the user
        System.out.println(a * b + " " + (2 * (a + b)));  // Perform calculations and print the results
        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of Main class
// <END-OF-CODE>
