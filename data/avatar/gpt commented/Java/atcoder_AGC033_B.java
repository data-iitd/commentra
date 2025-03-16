import java.util.*; 
import java.lang.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in); 
        
        // Read the height (h), width (w), number of moves (n), starting row (sr), and starting column (sc)
        int h = scanner.nextInt(); 
        int w = scanner.nextInt(); 
        int n = scanner.nextInt(); 
        int sr = scanner.nextInt(); 
        int sc = scanner.nextInt(); 
        
        // Read the strings representing the moves and the obstacles
        String s = scanner.next(); 
        String t = scanner.next(); 
        
        // Initialize a flag to indicate if the position is unsafe
        boolean end = false; 
        
        // Initialize the safe boundaries for vertical movement
        int usafe = 1; // Upper safe boundary
        int dsafe = h; // Lower safe boundary
        
        // Process the vertical moves in reverse order
        for (int i = n - 1; i >= 0; i--) { 
            // Update the safe boundaries based on the moves
            if (s.charAt(i) == 'U') { 
                usafe++; 
            } else if (s.charAt(i) == 'D') { 
                dsafe--; 
            } 
            
            // Check if the upper safe boundary exceeds the lower safe boundary
            if (usafe > dsafe) { 
                end = true; 
                break; 
            } 
            
            // Adjust the safe boundaries based on the obstacles
            if (i > 0) { 
                if (t.charAt(i - 1) == 'U') { 
                    dsafe = Math.min(dsafe + 1, h); 
                } else if (t.charAt(i - 1) == 'D') { 
                    usafe = Math.max(usafe - 1, 1); 
                } 
            } 
        } 
        
        // Initialize the safe boundaries for horizontal movement
        int lsafe = 1; // Left safe boundary
        int rsafe = w; // Right safe boundary
        
        // Process the horizontal moves in reverse order
        for (int i = n - 1; i >= 0; i--) { 
            // Update the safe boundaries based on the moves
            if (s.charAt(i) == 'L') { 
                lsafe++; 
            } else if (s.charAt(i) == 'R') { 
                rsafe--; 
            } 
            
            // Check if the left safe boundary exceeds the right safe boundary
            if (lsafe > rsafe) { 
                end = true; 
                break; 
            } 
            
            // Adjust the safe boundaries based on the obstacles
            if (i > 0) { 
                if (t.charAt(i - 1) == 'L') { 
                    rsafe = Math.min(rsafe + 1, w); 
                } else if (t.charAt(i - 1) == 'R') { 
                    lsafe = Math.max(lsafe - 1, 1); 
                } 
            } 
        } 
        
        // Check if the starting position is within the safe boundaries and not marked as unsafe
        if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end) { 
            System.out.println("YES"); // Output "YES" if the position is safe
        } else { 
            System.out.println("NO"); // Output "NO" if the position is unsafe
        } 
    } 
}
