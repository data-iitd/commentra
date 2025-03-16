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
            angles.add(angles.get(0) + 2 * Math.PI);
            
            double maxGap = 0;
            for (int k = 0; k < angles.size() - 1; k++) {
                double gap = angles.get(k + 1) - angles.get(k);
                if (gap >= Math.PI) {
                    maxGap = Math.max(maxGap, gap - Math.PI);
                }
            }
            System.out.println(maxGap / (2 * Math.PI));
        }
    }
}

