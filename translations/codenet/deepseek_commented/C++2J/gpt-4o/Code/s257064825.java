import java.util.Scanner; // Import Scanner class for input

public class Main { // Define the main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String str = scanner.next(); // Read input string
        long sum = 0; // Initialize sum variable to store the sum of digits
        
        for (char x : str.toCharArray()) { // Iterate over each character in the string
            sum += (x - '0'); // Convert character to integer and add to sum
        }
        
        if (sum % 9 == 0) { // Check if sum is divisible by 9
            System.out.println("Yes"); // Print "Yes" if sum is divisible by 9
        } else { // Otherwise
            System.out.println("No"); // Print "No"
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
