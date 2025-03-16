import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Declare variables to hold the input values
        int x, y, a, b;
        
        // Read four integers from the user
        x = in.nextInt(); // Upper limit for the first variable
        y = in.nextInt(); // Upper limit for the second variable
        a = in.nextInt(); // Lower limit for the first variable
        b = in.nextInt(); // Lower limit for the second variable
        
        // Initialize a counter to keep track of valid pairs
        int count = 0;
        
        // First nested loop to iterate through the range [a, x]
        for (int i = a; i <= x; i++) {
            // Second nested loop to iterate through the range [b, y]
            for (int j = b; j <= y; ++j) {
                // Skip the iteration if i is less than or equal to j
                if (i <= j) continue;
                
                // Increment the count for each valid pair (i, j)
                count++;
            }
        }
        
        // Output the total count of valid pairs
        System.out.println(count);
        
        // Second set of nested loops to print the valid pairs
        for (int i = a; i <= x; i++) {
            for (int j = b; j <= y; ++j) {
                // Skip the iteration if i is less than or equal to j
                if (i <= j) continue;
                
                // Print the valid pair (i, j)
                System.out.println(i + " " + j);
            }
        }
        
        // Close the Scanner object to free resources
        in.close();
    }
}
