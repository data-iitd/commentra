
import java.util.Scanner;
import java.util.Arrays;

public class codeforces_351_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextDouble();
        }
        scanner.close();

        double[] arr2 = new double[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            arr2[i] = arr[i] - (int) arr[i];
            if (arr2[i]!= 0) {
                arr2[count++] = arr2[i];
            }
        }
        Arrays.sort(arr2, 0, count);

        double sum = 0;
        for (int i = 0; i < count; i++) {
            sum += arr2[i];
        }

        int o = 2 * n - count;
        double res = 2e9;
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - sum));
            }
        }

        System.out.printf("%.3f", res);
    }
}
