import java.util.Scanner; // Step 1: Import necessary classes

public class Main { // Step 2: Define the main class
    public static void main(String[] args) { // Step 2: Define the main method
        Scanner scanner = new Scanner(System.in); // Step 3: Create a Scanner object for input
        int x; // Step 3: Declare a variable

        x = scanner.nextInt(); // Step 4: Read input from the user
        System.out.println(x * x * x); // Step 5: Perform a calculation and print the result

        scanner.close(); // Step 6: Close the scanner
    } // End of main method
} // End of class Main
// <END-OF-CODE>
