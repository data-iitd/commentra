import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Read the number of test cases from user input
        int n = scan.nextInt();
        
        // Loop through each test case
        for (int i = 0; i < n; i++) {
            // Read two integers a and b from user input
            int a = scan.nextInt();
            int b = scan.nextInt();
            
            // Call the sub method and print the result
            System.out.println(sub(a, b));
        }
    }

    // Method to perform a specific subtraction-like operation
    public static int sub(int a, int b) {
        // Determine the minimum and maximum of the two numbers
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        
        // Initialize the result variable to store the final output
        int result = 0;
        
        // Continue the process while min is greater than 0
        while (min > 0) {
            // Add the quotient of max divided by min to the result
            result += max / min;
            
            // Update max to be the remainder of max divided by min
            max = max % min;
            
            // Update min and max for the next iteration
            int curr_min = Math.min(min, max);
            int curr_max = Math.max(min, max);
            min = curr_min;
            max = curr_max;
        }
        
        // Return the final result
        return result;
    }
}
