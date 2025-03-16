import java.util.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] XY = new int[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            XY[i] = scanner.nextInt();
        }
        
        List<double[]> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            points.add(new double[]{XY[2 * i], XY[2 * i + 1]});
        }
        
        for (int i = 0; i < N; i++) {
            double x = points.get(i)[0];
            double y = points.get(i)[1];
            List<Double> D = new ArrayList<>();
            
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    double angle = atan2(points.get(j)[1] - y, points.get(j)[0] - x);
                    D.add(angle);
                }
            }
            
            Collections.sort(D);
            D.add(D.get(0) + 2 * PI);
            double ans = 0;
            
            for (int j = 0; j < D.size() - 1; j++) {
                double a = D.get(j);
                double b = D.get(j + 1);
                if (b - a >= PI) {
                    ans = (b - a) - PI;
                }
            }
            System.out.println(ans / (2 * PI));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
