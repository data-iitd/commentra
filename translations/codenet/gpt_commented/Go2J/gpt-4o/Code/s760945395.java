import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input

        // Loop to iterate 5 times
        for (int i = 0; i < 5; i++) {
            int a; // Declare a variable 'a' to store user input
            a = scanner.nextInt(); // Read an integer input from the user and store it in 'a'
            
            // Check if the input value is zero
            if (a == 0) {
                // Print the current iteration index + 1 if the input is zero
                System.out.println(i + 1);
            }
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
