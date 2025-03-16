import java.util.Scanner;

public class Main {
    public static void main(String[] sh) {
        // Create a Scanner object to read input from the user
        Scanner s = new Scanner(System.in);
        
        // Read four long integer inputs from the user
        long x = s.nextInt(); // First integer
        long y = s.nextInt(); // Second integer
        long a = s.nextInt(); // Lower bound of the range
        long b = s.nextInt(); // Upper bound of the range
        
        // Initialize variables for calculations
        long j = 2, i, x1 = 0, y1 = 0, c = 0; 
        boolean ans = true; // Flag to check if a valid solution exists
        
        // Determine the maximum of x and y
        c = Math.max(x, y);
        
        // Check if the maximum value exceeds the upper bound b
        if (c > b) {
            System.out.println("0"); // Output 0 if no valid multiples exist
            ans = false; // Set answer flag to false
        }
        
        // Loop to find the least common multiple (LCM) of x and y
        while (c % Math.min(x, y) != 0 && ans) {
            // Multiply by j to find the next multiple
            if (x > y) {
                c = x * j; // Calculate next multiple of x
                j++;
            } else {
                c = y * j; // Calculate next multiple of y
                j++;
            }
            
            // Check if the calculated multiple exceeds the upper bound b
            if (c > b) {
                System.out.println("0"); // Output 0 if no valid multiples exist
                ans = false; // Set answer flag to false
                break; // Exit the loop
            }
        }
        
        // If a valid multiple was found within the bounds
        if (ans) {
            long count = 0; // Initialize count of valid multiples
            // Find the first multiple of c within the range [a, b]
            for (i = a; i <= b; i++) {
                if (i % c == 0) break; // Break when a multiple is found
            }
            
            // Check if a valid multiple was found within the range
            if (i != b + 1) {
                // Calculate the number of multiples of c in the range [a, b]
                System.out.println(((b - i) / c) + 1);
            } else {
                System.out.println("0"); // Output 0 if no multiples found
            }
        }
    }
}
