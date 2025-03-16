
import java.util.*;

public class s462906333{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = a[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int k = 0; k < n; k++) {
            int kans = 0;
            for (int i = 0; i < n; i++) {
                if (i - k < 0) {
                    v[i] = Math.min(v[i], a[n + i - k]);
                } else {
                    v[i] = Math.min(v[i], a[i - k]);
                }
                kans += v[i];
            }
            ans = Math.min(ans, kans + k * x);
        }
        System.out.println(ans);
    }
}

