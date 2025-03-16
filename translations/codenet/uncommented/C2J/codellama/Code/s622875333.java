
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, r, i, j, p, c;
        int[] a = new int[100];
        int[] b = new int[100];

        while (true) {
            n = sc.nextInt();
            r = sc.nextInt();
            if (n == 0 && r == 0) break;

            for (i = 0; i < n; i++) {
                a[i] = n - i;
            }

            for (i = 0; i < r; i++) {

                for (j = 0; j < n; j++) {
                    b[j] = a[j];
                }
                p = sc.nextInt();
                c = sc.nextInt();

                for (j = 0; j < c; j++) {
                    a[j] = b[p - 1 + j];
                }

                for (j = c; j < c + p - 1; j++) {
                    a[j] = b[j - c];
                }
            }
            System.out.println(a[0]);
        }
    }
}

