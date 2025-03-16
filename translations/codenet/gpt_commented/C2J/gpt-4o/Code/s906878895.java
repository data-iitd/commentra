import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Continuously read pairs of integers until EOF (End of File) is reached
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            
            // Calculate the sum of the two integers
            int x = a + b;
            
            // Initialize a counter for the number of digits in the sum
            int w = 0;
            
            // Count the number of digits in the sum (x)
            if (x == 0) {
                w = 1; // Special case for 0
            } else {
                while (x != 0) {
                    // Increment the digit counter
                    w++;
                    // Remove the last digit from x by dividing by 10
                    x /= 10;
                }
            }
            
            // Print the number of digits in the sum
            System.out.println(w);
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
