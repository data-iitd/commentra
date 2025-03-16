
import java.util.Scanner;

public class s622875333{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, r, i, j, p, c;
        int[] a = new int[100];
        int[] b = new int[100];

        while (true) {
            n = scanner.nextInt();
            r = scanner.nextInt();

            if (n == 0 && r == 0) break;

            for (i = 0; i < n; i++) {
                a[i] = n - i;
            }

            for (i = 0; i < r; i++) {
                for (j = 0; j < n; j++) {
                    b[j] = a[j];
                }

                p = scanner.nextInt();
                c = scanner.nextInt();

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
