import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values: the first value is N (number of points), followed by the coordinates
        int N = scanner.nextInt();
        double[] angles = new double[N];
        int[] xCoords = new int[N];
        int[] yCoords = new int[N];
        
        // Pair the coordinates into arrays
        for (int i = 0; i < N; i++) {
            xCoords[i] = scanner.nextInt();
            yCoords[i] = scanner.nextInt();
        }
        
        // Iterate over each point in the list with its index
        for (int i = 0; i < N; i++) {
            List<Double> D = new ArrayList<>();
            int x = xCoords[i];
            int y = yCoords[i];
            
            // Calculate angles from the current point (x, y) to all other points
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    double angle = Math.atan2(xCoords[j] - x, yCoords[j] - y);
                    D.add(angle);
                }
            }
            
            // Sort the angles
            Collections.sort(D);
            
            // Append the angle that wraps around (2*pi) to handle circularity
            D.add(D.get(0) + 2 * Math.PI);
            
            // Initialize the answer for the current point
            double ans = 0;
            
            // Calculate the gaps between consecutive angles
            for (int k = 0; k < D.size() - 1; k++) {
                double a = D.get(k);
                double b = D.get(k + 1);
                
                // Check if the gap is greater than or equal to pi
                if (b - a >= Math.PI) {
                    // Update the answer with the size of the gap minus pi
                    ans = (b - a) - Math.PI;
                }
            }
            
            // Print the normalized answer (as a fraction of 2*pi)
            System.out.println(ans / (2 * Math.PI));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
