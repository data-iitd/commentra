import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] XY = new int[N*2];
        for (int i = 0; i < N*2; i++) {
            XY[i] = sc.nextInt();
        }
        double[] D = new double[N];
        for (int i = 0; i < N; i++) {
            D[i] = Math.atan2(XY[2*i+0]-XY[2*i+2*N], XY[2*i+1]-XY[2*i+2*N+1]);
        }
        double ans = 0;
        for (int i = 0; i < N; i++) {
            double a = D[i];
            double b = D[(i+1)%N];
            if (b - a >= Math.PI) {
                ans += (b - a) - Math.PI;
            }
        }
        System.out.printf("%.10f", ans / (2 * Math.PI));
    }
}

