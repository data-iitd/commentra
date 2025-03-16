import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the standard input
        Scanner in = new Scanner(System.in); 
        
        // Create a PrintWriter object to output results to the standard output
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read the coordinates of the two points (x1, y1) and (x2, y2)
        int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt(); 
        
        // Check if the two points are vertically aligned (same x-coordinate)
        if (x1 == x2) { 
            // Calculate the vertical distance between the two points
            int dif = Math.abs(y1 - y2); 
            // Output the coordinates of the rectangle formed by the two points
            pw.println((x1 + dif) + " " + y1 + " " + (x1 + dif) + " " + y2); 
        } 
        // Check if the two points are horizontally aligned (same y-coordinate)
        else if (y1 == y2) { 
            // Calculate the horizontal distance between the two points
            int dif = Math.abs(x1 - x2); 
            // Output the coordinates of the rectangle formed by the two points
            pw.println((x1) + " " + (y1 + dif) + " " + (x2) + " " + (y2 + dif)); 
        } 
        // Check if the two points form a square (equal distance in both x and y)
        else if (Math.abs(x1 - x2) == Math.abs(y1 - y2)) { 
            // Output the coordinates of the rectangle formed by swapping y-coordinates
            pw.println(x1 + " " + y2 + " " + x2 + " " + y1); 
        } 
        // If none of the above conditions are met, output -1 indicating no rectangle can be formed
        else { 
            pw.println(-1); 
        } 
        
        // Close the PrintWriter to flush the output
        pw.close(); 
    } 
    
    // Debugging utility method to print objects to the error output
    static void debug(Object... obj) { 
        System.err.println(Arrays.deepToString(obj)); 
    } 
}
