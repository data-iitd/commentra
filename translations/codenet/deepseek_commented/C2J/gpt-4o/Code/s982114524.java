import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        int i, N, x;  // Declare integer variables
        x = 0;  // Initialize the variable x to 0
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        N = scanner.nextInt();  // Read input from the user and store it in N
        for (i = 1; i <= N; i++)  // Loop through numbers from 1 to N
            x += i;  // Add each number to x
        System.out.println(x);  // Print the final value of x
        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of Main class
// <END-OF-CODE>
