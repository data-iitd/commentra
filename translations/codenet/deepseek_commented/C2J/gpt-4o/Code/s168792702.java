import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method, the entry point of the program
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        int a, b, c;  // Declare three integer variables
        a = scanner.nextInt();  // Read the first integer from the user
        b = scanner.nextInt();  // Read the second integer from the user
        c = scanner.nextInt();  // Read the third integer from the user
        
        if (a < b && b < c)  // Check if a is less than b and b is less than c
            System.out.println("Yes");  // Print "Yes" if true
        else
            System.out.println("No");  // Print "No" if the condition is not met
        
        scanner.close();  // Close the scanner to free resources
    }  // End of the main method
}  // End of the Main class
// <END-OF-CODE>
