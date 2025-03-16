import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values n and k from the standard input
        double n = scanner.nextDouble();
        double k = scanner.nextDouble();
        
        // Calculate the number of digits required in k-base representation of number n
        // This is done by finding the smallest power of k such that k^x <= n and n < k^(x+1)
        
        // Initialize a double variable x with initial value 0.0
        double x = 0.0;
        
        // Use a while loop to find the smallest power of k that satisfies the condition
        while (true) {
            // Calculate the lower and upper bounds of the current power of k
            double under = Math.pow(k, x);
            double upper = Math.pow(k, x + 1);
            
            // Check if the number n lies between under and upper bounds
            if (under <= n && n < upper) {
                // If the condition is satisfied, print the result (number of digits) and exit the function
                System.out.println((int)(x + 1));
                return;
            }
            
            // If the condition is not satisfied, increment the value of x and continue the loop
            x++;
        }
    }
}
