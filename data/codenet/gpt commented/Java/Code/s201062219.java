import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Initialize variables
        String mark; // To store the operator
        int c = 0; // First operand
        int b = 0; // Second operand
        int a[] = new int[100000]; // Array to store results
        int x = 0; // Index for the results array
        
        // Loop to read input and perform calculations
        do {
            // Read the first operand
            c = scan.nextInt();
            // Read the operator
            mark = scan.next();
            // Read the second operand
            b = scan.nextInt();	
            
            // Check if the operator is "?" to terminate input
            if (mark.equals("?")) {
                a[x] = 2000001; // Use a sentinel value to indicate termination
                break; // Exit the loop
            }
            // Perform addition if the operator is "+"
            else if (mark.equals("+")) {
                a[x] = c + b;
            }
            // Perform subtraction if the operator is "-"
            else if (mark.equals("-")) {
                a[x] = c - b;
            }
            // Perform multiplication if the operator is "*"
            else if (mark.equals("*")) {
                a[x] = c * b;
            }
            // Perform division if the operator is "/"
            else if (mark.equals("/")) {
                a[x] = c / b;
            }
            // Increment the index for the results array
            x++;
        } while (true); // Continue until a termination condition is met
        
        // Reset index to print results
        x = 0;
        
        // Loop to print the results
        do {
            // Check for the sentinel value to stop printing
            if (a[x] == 2000001) break; 
            // Print the result stored in the array
            System.out.println(a[x]);
            // Increment the index for the results array
            x++;
        } while (true); // Continue until the sentinel value is encountered
        
        // Close the scanner to free resources
        scan.close();
    }
}
