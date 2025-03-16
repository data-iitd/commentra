import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Read the input string from the user
        String str = scanner.nextLine();
        
        // Initialize a variable to hold the sum of digits
        long sum = 0;
        
        // Iterate through each character in the string
        for (char x : str.toCharArray()) {
            // Convert character to integer and add to sum
            sum += (x - '0'); // '0' is the character representation of zero
        }
        
        // Check if the sum of digits is divisible by 9
        if (sum % 9 == 0) {
            // If divisible, print "Yes"
            System.out.println("Yes");
        } else {
            // If not divisible, print "No"
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
