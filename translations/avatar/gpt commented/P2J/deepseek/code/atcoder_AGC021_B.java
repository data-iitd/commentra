import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double[] X = new double[N];
        double[] Y = new double[N];
        
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextDouble();
            Y[i] = scanner.nextDouble();
        }
        
        for (int i = 0; i < N; i++) {
            List<Double> angles = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    double angle = Math.atan2(Y[j] - Y[i], X[j] - X[i]);
                    angles.add(angle);
                }
            }
            Collections.sort(angles);
            
            // Append the angle that wraps around (2*pi) to handle circularity
            angles.add(angles.get(0) + 2 * Math.PI);
            
            // Initialize the answer for the current point
            double ans = 0;
            
            // Calculate the gaps between consecutive angles
            for (int k = 0; k < angles.size() - 1; k++) {
                double a = angles.get(k);
                double b = angles.get(k + 1);
                // Check if the gap is greater than or equal to pi
                if (b - a >= Math.PI) {
                    // Update the answer with the size of the gap minus pi
                    ans = (b - a) - Math.PI;
                }
            }
            
            // Print the normalized answer (as a fraction of 2*pi)
            System.out.println(ans / (2 * Math.PI));
        }
    }
}
