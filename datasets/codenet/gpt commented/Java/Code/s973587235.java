import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of integers to be processed
        int n = sc.nextInt();
        
        // Read the first integer and decrement it by 1 to initialize minN
        int minN = sc.nextInt() - 1;
        
        // Loop through the next n-1 integers
        for (int i = 0; i < n - 1; i++) {
            // Read the next integer
            int h = sc.nextInt();
            
            // Check if the current integer is equal to minN
            if (minN == h) {
                // If equal, keep minN unchanged
                minN = h;
            } 
            // Check if the current integer is one more than minN
            else if (minN == h - 1) {
                // If so, update minN to h - 1
                minN = h - 1;
            } 
            // Check if the current integer is greater than minN + 1
            else if (minN < h - 1) {
                // If so, update minN to h - 1
                minN = h - 1;
            } 
            // If the current integer is less than or equal to minN
            else if (minN > h) {
                // Print "No" and exit the program if the condition is met
                System.out.println("No");
                return;
            }
        }
        
        // If all integers are processed without issues, print "Yes"
        System.out.println("Yes");
    }
}
