import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Reading Input
        int N = scanner.nextInt();
        int[] XY = new int[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            XY[i] = scanner.nextInt();
        }
        
        // Step 2: Processing Coordinates
        double[][] points = new double[N][2];
        for (int i = 0; i < N; i++) {
            points[i][0] = XY[2 * i];
            points[i][1] = XY[2 * i + 1];
        }
        
        // Step 3: Calculating Angles
        for (int i = 0; i < N; i++) {
            double x = points[i][0];
            double y = points[i][1];
            List<Double> D = new ArrayList<>();
            
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    double angle = Math.atan2(points[j][1] - y, points[j][0] - x);
                    D.add(angle);
                }
            }
            
            // Step 4: Handling Circular Angles
            Collections.sort(D);
            D.add(D.get(0) + 2 * Math.PI);
            
            // Step 5: Finding the Maximum Gap
            double ans = 0;
            for (int k = 0; k < D.size() - 1; k++) {
                double a = D.get(k);
                double b = D.get(k + 1);
                if (b - a >= Math.PI) {
                    ans = Math.max(ans, (b - a) - Math.PI);
                }
            }
            
            // Step 6: Calculating the Fraction
            System.out.println(ans / (2 * Math.PI));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
