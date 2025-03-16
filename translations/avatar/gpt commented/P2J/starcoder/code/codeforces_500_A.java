import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of cells (n) and the target cell (t) from input
        int n = sc.nextInt();
        int t = sc.nextInt();
        
        // Read the list of jumps for each cell
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }
        
        // Initialize the current cell position
        int current_cell = 0;
        
        // Loop until the current cell exceeds the target cell
        while (current_cell <= t) {
            // Move to the next cell based on the jump value from the current cell
            current_cell += s[current_cell - 1];
            
            // Check if the current cell is exactly the target cell
            if (current_cell == t) {
                System.out.println("YES");  // Print "YES" if the target cell is reached
                return;                     // Exit the program
            } else {
                continue;  // Continue the loop if the target cell is not reached
            }
        }
        
        // If the loop ends without reaching the target cell, print "NO"
        System.out.println("NO");
    }
}
