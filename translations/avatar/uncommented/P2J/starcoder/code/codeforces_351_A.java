import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextDouble();
        }
        Arrays.sort(arr);
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        double res = 1e9;
        for (int i = 0; i <= n; i++) {
            double cur = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                cur += arr[j];
            }
            res = Math.min(res, Math.abs(cur - sum));
        }
        System.out.printf("%.3f", res);
    }
}
