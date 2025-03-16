import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];

        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
            b[i] = a[i];
        }

        Arrays.sort(b);
        int frontHalf = b[N / 2 - 1];
        int backHalf = b[N / 2];

        for (int i = 0; i < N; i++) {
            if (a[i] < backHalf) {
                System.out.println(backHalf);
            } else {
                System.out.println(frontHalf);
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
