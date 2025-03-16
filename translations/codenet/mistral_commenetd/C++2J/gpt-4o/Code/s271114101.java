import java.util.Scanner; // Import the Scanner class for reading input

public class Main { // Define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int a, b, c; // Declare three integer variables named a, b, and c
        a = scanner.nextInt(); // Read the first integer from the input
        b = scanner.nextInt(); // Read the second integer from the input
        c = scanner.nextInt(); // Read the third integer from the input
        
        // The following if statement checks if any of the following conditions are true:
        // (a + b) == c // If the sum of a and b is equal to c
        // (b + c) == a // If the sum of b and c is equal to a
        // (a + c) == b // If the sum of a and c is equal to b
        if ((a + b == c) || (b + c == a) || (a + c == b)) { // If any of the above conditions are true, the following code is executed.
            System.out.println("Yes"); // Output the string "Yes" to the standard output.
        } else { // If none of the above conditions are true, the following code is executed.
            System.out.println("No"); // Output the string "No" to the standard output.
        }
        
        scanner.close(); // Close the scanner to free up resources
    }
}

// <END-OF-CODE>
