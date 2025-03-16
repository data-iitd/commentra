import java.util.Scanner; // Step 1: Import necessary classes

public class Main { // Step 2: Define the main class
    public static void main(String[] args) { // Step 3: Define the main method
        int x, kotae; // Step 4: Declare variables

        Scanner scanner = new Scanner(System.in); // Step 5: Create a Scanner object to read input
        x = scanner.nextInt(); // Step 6: Read input from the user

        kotae = x * x * x; // Step 7: Perform the computation

        System.out.println(kotae); // Step 8: Output the result

        scanner.close(); // Step 9: Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
