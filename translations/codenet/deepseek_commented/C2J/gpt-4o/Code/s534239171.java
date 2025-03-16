import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int a, b, n;  // Declare integer variables
        a = scanner.nextInt();  // Read the first input value
        b = scanner.nextInt();  // Read the second input value
        n = (a + b) / 2;  // Calculate the average
        System.out.println(n);  // Print the result
        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of Main class
// <END-OF-CODE>
