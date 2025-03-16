
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of cells (n) and the target cell (t)
        int n = sc.nextInt();
        int t = sc.nextInt();
        
        // Read the list of cells that can be jumped from each cell
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }
        
        // Initialize the current cell to 0
        int current_cell = 0;
        
        // Loop until the current cell exceeds the target cell
        while (current_cell <= t) {
            // Update the current cell by adding the value of the cell it's currently on
            current_cell += s[current_cell - 1];
            
            // Check if the current cell is the target cell
            if (current_cell == t) {
                // If yes, print "YES" and exit the program
                System.out.println("YES");
                return;
            } else {
                // If not, continue to the next iteration
                continue;
            }
        }
        
        // If the loop finishes without finding the target cell, print "NO"
        System.out.println("NO");
    }
}

