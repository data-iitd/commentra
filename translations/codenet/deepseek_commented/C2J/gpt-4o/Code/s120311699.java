import java.util.Scanner;  // Import the Scanner class for reading input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method, the entry point of the program
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        int a = scanner.nextInt();  // Read the first integer
        int b = scanner.nextInt();  // Read the second integer
        int c = scanner.nextInt();  // Read the third integer

        if (a < b && b < c) {  // Check if a is less than b and b is less than c
            System.out.println("Yes");  // If true, print "Yes"
        } else {  // Otherwise
            System.out.println("No");  // Print "No"
        }

        scanner.close();  // Close the scanner to free resources
    }
}

// <END-OF-CODE>
