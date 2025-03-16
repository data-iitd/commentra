import java.util.Scanner; // Step 1: Import necessary classes

public class Main { // Step 2: Define the main class
    public static void main(String[] args) { // Step 3: Define the main method
        int a, b, mawari, menseki; // Step 4: Declare variables
        Scanner scanner = new Scanner(System.in); // Step 5: Create a Scanner object for input
        
        a = scanner.nextInt(); // Step 6: Read the first input value
        b = scanner.nextInt(); // Step 7: Read the second input value
        
        mawari = 2 * (a + b); // Step 8: Calculate mawari
        menseki = a * b; // Step 9: Calculate menseki
        
        System.out.println(menseki + " " + mawari); // Step 10: Print the results
        scanner.close(); // Step 11: Close the scanner
    } // Step 12: End of main method
} // Step 13: End of class
// <END-OF-CODE>
