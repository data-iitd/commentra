import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int p = scanner.nextInt();
        int[] a = new int[50];
        int b = 0, c = 0;

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            if (a[i] % 2 == 0) {
                b++;
            } else {
                c++;
            }
        }

        long bsum = (long) Math.pow(2, b);
        long csum = 0;

        if (p == 0) {
            for (int i = 0; i <= c; i++) {
                if (i % 2 == 0) {
                    csum += nCr(c, i);
                }
            }
        } else {
            for (int i = 0; i <= c; i++) {
                if (i % 2 == 1) {
                    csum += nCr(c, i);
                }
            }
        }

        long ans = bsum * csum;
        System.out.println(ans);
    }

    public static long nCr(int n, int r) {
        double res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return (long) res;
    }
}
