
import java.util.Scanner;

public class s194793609{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }

        long[] abs_a = new long[n];
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                abs_a[i] = -a[i];
            } else {
                abs_a[i] = a[i];
            }
        }

        long ans = 0;
        long min = abs_a[0];
        for (int i = 0; i < n; i++) {
            ans += abs_a[i];
            if (min > abs_a[i]) {
                min = abs_a[i];
            }
        }
        int num_negative = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                num_negative++;
            }
        }

        if (num_negative % 2!= 0) {
            ans -= min * 2;
        }

        System.out.println(ans);
    }
}
