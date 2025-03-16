
import java.io.*;
import java.util.*;

class atcoder_AGC021_B {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        double[] x = new double[N];
        double[] y = new double[N];
        for (int i = 0; i < N; i++) {
            String[] split = br.readLine().split(" ");
            x[i] = Double.parseDouble(split[0]);
            y[i] = Double.parseDouble(split[1]);
        }
        double ans = 0;
        for (int i = 0; i < N; i++) {
            double[] d = new double[N];
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                d[j] = Math.atan2(y[j] - y[i], x[j] - x[i]);
            }
            Arrays.sort(d);
            for (int j = 0; j < N - 1; j++) {
                if (d[j + 1] - d[j] > Math.PI) {
                    ans += d[j + 1] - d[j] - Math.PI;
                }
            }
        }
        System.out.println(ans / (2 * Math.PI));
    }
}
