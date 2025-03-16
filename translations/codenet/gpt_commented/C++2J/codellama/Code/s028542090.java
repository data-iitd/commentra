import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        long[] a = new long[k];
        for (int i = 0; i < k; i++) {
            a[i] = sc.nextLong();
        }
        long min = 3;
        long max = 2;
        if (a[k - 1] != 2) {
            System.out.println(-1);
            return;
        }
        for (int i = k - 2; i >= 0; i--) {
            if (a[i] > max) {
                System.out.println(-1);
                return;
            } else {
                max = ((max / a[i]) + 1) * a[i] - 1;
                if (min % a[i] != 0) {
                    min = ((min / a[i]) + 1) * a[i];
                }
            }
            if (max <= min) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(min + " " + max);
    }
}

