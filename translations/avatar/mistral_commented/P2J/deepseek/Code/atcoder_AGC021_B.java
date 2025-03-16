import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double[] X = new double[N];
        double[] Y = new double[N];
        
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextDouble();
            Y[i] = scanner.nextDouble();
        }
        
        double ans = 0.0;
        
        for (int i = 0; i < N; i++) {
            List<Double> angles = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    double angle = Math.atan2(X[j] - X[i], Y[j] - Y[i]);
                    angles.add(angle);
                }
            }
            Collections.sort(angles);
            for (int k = 0; k < angles.size(); k++) {
                angles.add(angles.get(k) + 2 * Math.PI);
            }
            for (int k = 0; k < angles.size() - 1; k++) {
                double angle = angles.get(k + 1) - angles.get(k);
                if (angle > Math.PI) {
                    ans += (angle - Math.PI);
                }
            }
        }
        System.out.println(ans / (2 * Math.PI));
    }
}

