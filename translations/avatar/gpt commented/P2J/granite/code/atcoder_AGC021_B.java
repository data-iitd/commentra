
import java.io.*;
import java.util.*;

public class atcoder_AGC021_B{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        double[] X = new double[N];
        double[] Y = new double[N];
        for (int i = 0; i < N; i++) {
            String[] s = br.readLine().split(" ");
            X[i] = Double.parseDouble(s[0]);
            Y[i] = Double.parseDouble(s[1]);
        }
        for (int i = 0; i < N; i++) {
            List<Double> D = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                D.add(Math.atan2(Y[j] - Y[i], X[j] - X[i]));
            }
            Collections.sort(D);
            D.add(D.get(0) + 2 * Math.PI);
            double ans = 0;
            for (int j = 0; j < D.size() - 1; j++) {
                if (D.get(j + 1) - D.get(j) >= Math.PI) {
                    ans = Math.max(ans, D.get(j + 1) - D.get(j) - Math.PI);
                }
            }
            System.out.println(ans / (2 * Math.PI));
        }
    }
}
