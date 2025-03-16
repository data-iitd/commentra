import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Reading two integers from the user
        int a = Integer.parseInt(sc.next()); // First integer input
        int b = Integer.parseInt(sc.next()); // Second integer input
        
        int sum = 0; // Initializing a variable to hold the sum of selected integers
        
        // Loop to iterate twice to calculate the sum
        for (int i = 0; i < 2; i++) {
            // Check if 'a' is greater than or equal to 'b'
            if (a >= b) {
                sum += a; // Add 'a' to the sum
                a = a - 1; // Decrement 'a' by 1
            } else {
                sum += b; // Add 'b' to the sum
                b = b - 1; // Decrement 'b' by 1
            }
        }
        
        // Output the final sum to the console
        System.out.println(sum);
    }
}
