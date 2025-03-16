import java.util.Scanner; // Import the Scanner class to read input from the user

public class Main {
    public static void main(String[] sh) {
        Scanner s = new Scanner(System.in); // Create a Scanner object to read input
        long x = s.nextInt(); // Read the first integer input
        long y = s.nextInt(); // Read the second integer input
        long a = s.nextInt(); // Read the third integer input
        long b = s.nextInt(); // Read the fourth integer input
        
        long j = 2, i, x1 = 0, y1 = 0, c = 0; // Initialize variables
        boolean ans = true; // Initialize a boolean variable to track the result
        
        // Calculate the maximum of x and y and store it in c
        c = Math.max(x, y);
        
        // If c is greater than b, print "0" and set ans to false
        if (c > b) {
            System.out.println("0");
            ans = false;
        }
        
        // Continue looping until c is divisible by the minimum of x and y or ans is false
        while (c % Math.min(x, y) != 0 && ans) {
            if (x > y) {
                c = x * j; // Update c to be x multiplied by j
            } else {
                c = y * j; // Update c to be y multiplied by j
            }
            j++; // Increment j
            
            // If the updated c is greater than b, print "0" and break out of the loop
            if (c > b) {
                System.out.println("0");
                ans = false;
                break;
            }
        }
        
        // If ans is still true, calculate the number of multiples of c between a and b
        if (ans) {
            long count = 0;
            i = a;
            for (i = a; i <= b; i++) {
                if (i % c == 0) break; // Break if a multiple of c is found
            }
            if (i != b + 1) 
                System.out.println(((b - i) / c) + 1); // Print the number of multiples
            else 
                System.out.println("0");
        }
    }
}
