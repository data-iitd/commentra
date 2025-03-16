import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] XY = new int[N * 2];
        for (int i = 0; i < N * 2; i++) {
            XY[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            int x = XY[i * 2];
            int y = XY[i * 2 + 1];
            double[] D = new double[N];
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                int X = XY[j * 2];
                int Y = XY[j * 2 + 1];
                D[j] = Math.atan2(X - x, Y - y);
            }
            Arrays.sort(D);
            double ans = 0;
            for (int j = 0; j < N; j++) {
                if (j == N - 1) {
                    ans += Math.PI * 2 - D[j];
                } else {
                    ans += D[j + 1] - D[j];
                }
            }
            System.out.println(ans / (Math.PI * 2));
        }
    }
}

