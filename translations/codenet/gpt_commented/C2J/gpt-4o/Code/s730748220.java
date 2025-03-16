import java.util.Scanner; // Import Scanner class for user input

public class Main {
    public static void main(String[] args) {
        int n; // Declare integer variable n
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input from the user
        n = scanner.nextInt();
        
        // Calculate and print the result based on the input n
        // The expression (24 + (24 - n)) simplifies to (48 - n)
        System.out.println(24 + (24 - n));
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
