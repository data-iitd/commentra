import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        long[] abs_a = new long[n];
        for (int i = 0; i < n; i++) {
            abs_a[i] = Math.abs(a[i]);
        }

        long ans = 0;
        long min = abs_a[0];
        for (long e : abs_a) {
            ans += e;
            if (min > e) {
                min = e;
            }
        }
        int num_negative = 0;
        for (long e : a) {
            if (e < 0) {
                num_negative++;
            }
        }

        if (num_negative % 2) {
            ans -= min * 2;
        }

        System.out.println(ans);
    }
}
