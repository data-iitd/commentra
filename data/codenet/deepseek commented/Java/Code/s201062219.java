import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Declare variables to store the values of c, b, and an array to store results
        String mark;
        int c = 0;
        int b = 0;
        int a[] = new int[100000];
        int x = 0;
        
        // Use a do-while loop to continuously read input values for c, mark, and b
        do {
            // Read the value of c
            c = scan.nextInt();
            // Read the value of mark
            mark = scan.next();
            // Read the value of b
            b = scan.nextInt();
            
            // Check the value of mark and perform the corresponding operation
            if (mark.equals("?")) {
                // Assign a special value to indicate the end of input
                a[x] = 2000001;
                break;
            } else if (mark.equals("+")) {
                // Perform addition and store the result in the array
                a[x] = c + b;
            } else if (mark.equals("-")) {
                // Perform subtraction and store the result in the array
                a[x] = c - b;
            } else if (mark.equals("*")) {
                // Perform multiplication and store the result in the array
                a[x] = c * b;
            } else if (mark.equals("/")) {
                // Perform division and store the result in the array
                a[x] = c / b;
            }
            
            // Increment the index for the array
            x++;
        } while (true); // Continue the loop indefinitely until the break statement is executed
        
        // Reset the index for printing results
        x = 0;
        
        // Use a do-while loop to print all the results stored in the array a
        do {
            // Check if we have reached the special value indicating the end of input
            if (a[x] == 2000001)
                break;
            // Print the result stored in the array
            System.out.println(a[x]);
            // Increment the index for the array
            x++;
        } while (true); // Continue the loop indefinitely until the break statement is executed
        
        // Close the Scanner object to free up resources
        scan.close();
    }
}
