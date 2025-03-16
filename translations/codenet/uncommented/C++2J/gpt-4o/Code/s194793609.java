import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
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

        if (num_negative % 2 != 0) {
            ans -= min * 2;
        }

        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
