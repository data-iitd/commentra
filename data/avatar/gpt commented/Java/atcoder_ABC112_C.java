import java.util.Scanner; 
import java.util.stream.IntStream; 

public class Main { 
    // Define a constant for the maximum coordinate value
    private static final int MAX = 100; 

    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        try (Scanner scanner = new Scanner(System.in)) { 
            // Read the number of points
            int n = scanner.nextInt(); 
            // Initialize arrays to store x, y coordinates and heights
            int[] x = new int[n], y = new int[n], h = new int[n]; 
            
            // Read the x, y coordinates and heights for each point
            IntStream.range(0, n).forEach(i -> { 
                x[i] = scanner.nextInt(); 
                y[i] = scanner.nextInt(); 
                h[i] = scanner.nextInt(); 
            }); 
            
            // Iterate through all possible coordinates (i, j) within the defined range
            for (int i = 0; i <= MAX; i++) { 
                for (int j = 0; j <= MAX; j++) { 
                    // Check the height at the current coordinate (i, j)
                    int ch = check(n, x, y, h, i, j); 
                    // If the height is valid (greater than 0), print the coordinates and height
                    if (ch > 0) { 
                        System.out.println(i + " " + j + " " + ch); 
                    } 
                } 
            } 
        } 
    } 

    // Method to check the height at a given coordinate (cx, cy)
    private static int check(int n, int[] x, int[] y, int[] h, int cx, int cy) { 
        int ch = -1; 
        
        // Calculate the initial height based on the first point with a positive height
        for (int i = 0; i < n; i++) { 
            if (h[i] > 0) { 
                ch = Math.abs(x[i] - cx) + Math.abs(y[i] - cy) + h[i]; 
                break; 
            } 
        } 
        
        // Validate the height against all points
        for (int i = 0; i < n; i++) { 
            // If the calculated height does not match the expected height, return -1
            if (h[i] != Math.max(ch - Math.abs(x[i] - cx) - Math.abs(y[i] - cy), 0)) { 
                return -1; 
            } 
        } 
        
        // Return the calculated height if all checks pass
