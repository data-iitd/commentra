
import java.util.Scanner;

public class s194793609{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }
        long[] absA = new long[n];
        for (int i = 0; i < n; i++) {
            absA[i] = Math.abs(a[i]);
        }
        long ans = 0;
        long min = absA[0];
        for (long e : absA) {
            ans += e;
            if (min > e) {
                min = e;
            }
        }
        int numNegative = 0;
        for (long e : a) {
            if (e < 0) {
                numNegative++;
            }
        }
        if (numNegative % 2!= 0) {
            ans -= min * 2;
        }
        System.out.println(ans);
    }
}
