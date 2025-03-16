import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double[] XY = new double[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            XY[i] = scanner.nextDouble();
        }

        for (int i = 0; i < N; i++) {
            double x = XY[2 * i];
            double y = XY[2 * i + 1];
            List<Double> angles = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    double X = XY[2 * j];
                    double Y = XY[2 * j + 1];
                    double angle = Math.atan2(X - x, Y - y);
                    angles.add(angle);
                }
            }
            Collections.sort(angles);
            angles.add(angles.get(0) + 2 * Math.PI);
            double ans = 0;
            for (int k = 0; k < angles.size() - 1; k++) {
                double a = angles.get(k);
                double b = angles.get(k + 1);
                if (b - a >= Math.PI) {
                    ans = (b - a) - Math.PI;
                    break;
                }
            }
            System.out.println(ans / (2 * Math.PI));
        }
    }
}
