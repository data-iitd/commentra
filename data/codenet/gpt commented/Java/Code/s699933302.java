import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user: a, b, and c
        int a = Integer.parseInt(sc.next()); 
        int b = Integer.parseInt(sc.next()); 
        int c = Integer.parseInt(sc.next()); 
        
        // Initialize a counter to keep track of how many numbers in the range divide c
        int count = 0;
        
        // Loop through all integers from a to b (inclusive)
        for (int i = a; i <= b; i++) {
            // Check if the current integer i divides c without a remainder
            if (c % i == 0) {
                // Increment the count if i is a divisor of c
                count++;
            }
        }
        
        // Output the total count of divisors found in the range
        System.out.println(count);
    }
}
