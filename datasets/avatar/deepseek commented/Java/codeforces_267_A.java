import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Read an integer value n from the user and store it in the variable n
        int n = scan.nextInt();
        
        // Loop n times to read pairs of integers and print their greatest common divisor
        for (int i = 0; i < n; i++) {
            // Read two integers a and b from the user and store them in the variables a and b
            int a = scan.nextInt();
            int b = scan.nextInt();
            
            // Call the sub method with the values of a and b as arguments and print the result
            System.out.println(sub(a, b));
        }
    }
    
    // Define the sub method to calculate the greatest common divisor using the Euclidean algorithm
    public static int sub(int a, int b) {
        // Initialize min and max to store the smaller and larger of the two input values
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        
        // Initialize result to 0, which will be used to store the result of the Euclidean algorithm
        int result = 0;
        
        // Apply the Euclidean algorithm until min becomes 0
        while (min > 0) {
            // Add the quotient of max divided by min to result
            result += max / min;
            
            // Update max to be the remainder of max divided by min
            max = max % min;
            
            // Swap min and max if necessary to ensure min is the smaller value
            int curr_min = Math.min(min, max);
            int curr_max = Math.max(min, max);
            min = curr_min;
            max = curr_max;
        }
        
        // Return the value of result, which represents the greatest common divisor
        return result;
    }
}