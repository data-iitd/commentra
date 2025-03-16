import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize scanner for input
        Scanner scanner = new Scanner(System.in);
        
        // Read input string from standard input
        String str = scanner.nextLine();
        
        // Initialize sum variable to 0
        long sum = 0;

        // Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
        for (char x : str.toCharArray()) {
            sum += (x - '0'); // Subtract '0' to convert character to its integer value
        }

        // Check if sum is divisible by 9
        if (sum % 9 == 0) {
            System.out.println("Yes"); // Output "Yes" if sum is divisible by 9
        } else {
            System.out.println("No"); // Output "No" otherwise
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
