import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] X = new int[N];
        int[] Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            Y[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            double[] D = new double[N];
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    D[j] = Math.atan2(X[i] - X[j], Y[i] - Y[j]);
                }
            }
            double ans = 0;
            for (int j = 0; j < N - 1; j++) {
                if (D[j + 1] - D[j] >= Math.PI) {
                    ans = D[j + 1] - D[j] - Math.PI;
                }
            }
            System.out.println(ans / (2 * Math.PI));
        }
    }
}

