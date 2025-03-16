import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method, the entry point of the program
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int a, b, c;  // Declare three integer variables
        a = scanner.nextInt();  // Read the first integer input
        b = scanner.nextInt();  // Read the second integer input
        c = scanner.nextInt();  // Read the third integer input
        
        // Check if a is less than b and b is less than c
        if (a < b && b < c) {  
            System.out.println("Yes");  // If true, print "Yes"
        } else {  // Otherwise
            System.out.println("No");  // Print "No"
        }
        
        scanner.close();  // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
