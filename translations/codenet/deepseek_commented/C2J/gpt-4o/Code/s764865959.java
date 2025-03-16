import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int x; // Step 3: Declare an integer variable x.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input.
        x = scanner.nextInt(); // Step 4: Read an integer value from the user and store it in x.
        x = x * x * x; // Step 5: Calculate the cube of the value stored in x.
        System.out.println(x); // Step 6: Print the result.
        
        scanner.close(); // Close the scanner.
    } // End of main method
} // End of Main class

// Step 7: End the main function and return 0. (Implicit in Java)
