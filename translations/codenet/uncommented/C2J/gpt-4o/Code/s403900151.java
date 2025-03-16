import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, r, p, c;

        while (true) {
            n = scanner.nextInt();
            r = scanner.nextInt();
            if (n == 0 && r == 0) {
                break;
            }

            int[] a = new int[51];
            int[] b = new int[51];

            for (int i = 0; i < n; i++) {
                a[i] = i + 1;
            }

            for (int i = 0; i < r; i++) {
                p = scanner.nextInt();
                c = scanner.nextInt();

                for (int j = 0; j < c; j++) {
                    b[j] = a[n - p - c + 1 + j];
                }
                for (int j = 0; j < p - 1; j++) {
                    a[n - p - c + 1 + j] = a[n - p + j + 1];
                }
                for (int j = n - p - c + 1 + (p - 1), k = 0; k < c; j++, k++) {
                    a[j] = b[k];
                }
            }
            System.out.println(a[n - 1]);
        }
        scanner.close();
    }
}
// <END-OF-CODE>
