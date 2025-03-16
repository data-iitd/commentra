import java.util.Scanner; // Step 1: Import necessary classes

public class Main { // Step 2: Define the main class
    public static void main(String[] args) { // Step 3: Define the main method
        Scanner scanner = new Scanner(System.in); // Step 4: Create a Scanner object to read input
        int x = scanner.nextInt(); // Read an integer value from the user

        if (x == 1) // Step 5: Implement a simple if-else statement
            System.out.println("0"); // Print 0 if the input is 1
        else
            System.out.println("1"); // Print 1 if the input is not 1

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
