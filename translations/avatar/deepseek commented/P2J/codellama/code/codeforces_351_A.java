
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextDouble();
        }
        double[] arr2 = new double[n];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] - (int) arr[i] != 0) {
                arr2[j] = arr[i] - (int) arr[i];
                j++;
            }
        }
        int o = 2 * n - j;
        double arr_sum = 0;
        for (int i = 0; i < j; i++) {
            arr_sum += arr2[i];
        }
        double res = 1000000000;
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arr_sum));
            }
        }
        System.out.printf("%.3f", res);
    }
}

