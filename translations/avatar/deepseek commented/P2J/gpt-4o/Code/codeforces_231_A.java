import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to take input
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input `n` which represents the number of lists to be provided as input.
        int n = scanner.nextInt();
        
        // Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
        int c = 0;
        
        // Loop `n` times to process each list of integers.
        for (int i = 0; i < n; i++) {
            // Take a list of integers as input, split them by spaces, convert them to integers, and store them in an array.
            int sum = 0;
            while (scanner.hasNextInt()) {
                sum += scanner.nextInt();
                if (scanner.peek() == '\n') break; // Break on new line
            }
            
            // If the sum is greater than 1, increment the counter `c` by 1.
            if (sum > 1) {
                c++;
            }
        }
        
        // After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
        System.out.println(c);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
