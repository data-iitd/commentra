import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the width (w), height (h), and number of rectangles (n) from input
        int w = scanner.nextInt(), h = scanner.nextInt(), n = scanner.nextInt();
        
        // Initialize arrays to store the x and y coordinates and the action type for each rectangle
        int[] x = new int[n];
        int[] y = new int[n];
        int[] a = new int[n];
        
        // Set initial boundaries for the rectangle
        int xmax = w, xmin = 0;
        int ymax = h, ymin = 0;
        
        // Process each rectangle's coordinates and action type
        for (int i = 0; i < n; i++) {
            // Read the x and y coordinates and the action type for the current rectangle
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
            a[i] = scanner.nextInt();
            
            // Update the boundaries based on the action type
            switch (a[i]) {
                case 1: // Action 1: Move the left boundary to the right
                    xmin = Math.max(xmin, x[i]);
                    break;
                case 2: // Action 2: Move the right boundary to the left
                    xmax = Math.min(xmax, x[i]);
                    break;
                case 3: // Action 3: Move the bottom boundary up
                    ymin = Math.max(ymin, y[i]);
                    break;
                case 4: // Action 4: Move the top boundary down
                    ymax = Math.min(ymax, y[i]);
                    break;
            }
        }
        
        // Calculate the width and height of the remaining area after processing all rectangles
        w = Math.max(xmax - xmin, 0);
        h = Math.max(ymax - ymin, 0);
        
        // Output the area of the remaining rectangle
        System.out.println(w * h);
    }
}
