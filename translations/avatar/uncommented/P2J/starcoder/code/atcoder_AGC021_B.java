import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

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
        for (int i = 0; i < N; i++) {
            double[] D = new double[N];
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                D[j] = Math.atan2(X[i] - X[j], Y[i] - Y[j]);
            }
            Arrays.sort(D);
            double ans = 0;
            for (int j = 0; j < N - 1; j++) {
                ans += Math.abs(D[j + 1] - D[j]) - Math.PI;
            }
            System.out.println(ans / (2 * Math.PI));
        }
    }
}

