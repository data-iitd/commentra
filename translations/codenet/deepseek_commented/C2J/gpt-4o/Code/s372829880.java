import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int x = scanner.nextInt();  // Read the first integer
        int a = scanner.nextInt();  // Read the second integer
        System.out.println((x >= a) ? 10 : 0);  // Perform a comparison and print the result
        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of Main class
// <END-OF-CODE>
