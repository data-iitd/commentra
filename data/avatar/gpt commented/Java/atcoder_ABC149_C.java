import java.util.Scanner; // Importing Scanner class for user input
import java.lang.Math; // Importing Math class for mathematical operations

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner stdIn = new Scanner(System.in);
        
        // Read an integer input from the user
        int x = Integer.parseInt(stdIn.next());
        
        // If x is even and not equal to 2, increment x to make it odd
        if (x != 2 && x % 2 == 0) 
            x++;
        
        // Infinite loop to find the next prime number
        while (true) {
            int i; // Variable to hold the divisor
            // Calculate the square root of x for optimization
            double sqrtNum = Math.sqrt(x);
            
            // Check for factors of x from 3 to the square root of x, incrementing by 2 (to check only odd numbers)
            for (i = 3; i <= sqrtNum; i += 2) {
                // If i divides x, then x is not prime
                if (x % i == 0) 
                    break; // Exit the loop if a divisor is found
            }
            
            // If no divisors were found, i will be greater than sqrtNum, indicating x is prime
            if (i > sqrtNum) 
                break; // Exit the while loop as we found a prime number
            
            // Increment x by 2 to check the next odd number
            x += 2;
        }
        
        // Output the next prime number
        System.out.println(x);
    }
}
