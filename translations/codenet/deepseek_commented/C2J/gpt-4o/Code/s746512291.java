import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int x;  // Declare an integer variable
        x = scanner.nextInt();  // Read an integer from the user
        System.out.println(x * x * x);  // Calculate and print the cube of the input value
        scanner.close();  // Close the scanner
    }  // End of the main method
}  // End of the Main class
// <END-OF-CODE>
