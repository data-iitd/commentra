import java.util.*; // Importing the utility package for using Scanner

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Reading two integers from the user
        int a = scan.nextInt(); // The initial amount
        int b = scan.nextInt(); // The divisor
        
        // Initializing the result with the value of 'a'
        int res = a; 
        
        // Loop to perform the division and accumulate the result
        while (a >= b) {
            // Add the quotient of a divided by b to the result
            res += (a / b);
            
            // Update 'a' to be the sum of the quotient and the remainder
            a = (a / b) + (a % b);
        }
        
        // Output the final result
        System.out.println(res);
    }
}
