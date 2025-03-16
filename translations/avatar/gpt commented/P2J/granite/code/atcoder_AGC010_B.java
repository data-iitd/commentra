
import java.util.Scanner;

public class atcoder_AGC010_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        if (sum % (n * (n + 1) / 2)!= 0) {
            System.out.println("NO");
        } else {
            int k = sum / (n * (n + 1) / 2);
            int[] b = new int[n];
            b[0] = a[0];
            for (int i = 1; i < n; i++) {
                b[i] = a[i - 1];
            }
            int sum2 = 0;
            for (int i = 0; i < n; i++) {
                sum2 += (k - b[i] + b[i + 1]) % n;
            }
            if (sum2!= 0) {
                System.out.println("NO");
            } else {
                int sum3 = 0;
                for (int i = 0; i < n; i++) {
                    sum3 += (k - b[i] + b[i + 1]) / n;
                }
                if (sum3 < 0) {
                    System.out.println("NO");
                } else {
                    System.out.println("YES");
                }
            }
        }
    }
}
