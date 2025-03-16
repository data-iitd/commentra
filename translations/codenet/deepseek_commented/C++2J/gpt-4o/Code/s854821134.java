import java.util.Scanner; // Step 1: Include necessary libraries

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Step 4: Read input values
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Step 5: Check the condition and print the result
        if (a <= 8 && b <= 8) {
            System.out.println("Yay!");
        }
        
        scanner.close(); // Close the scanner
    } // Step 7: End the main function
} // <END-OF-CODE>
