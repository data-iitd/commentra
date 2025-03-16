import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int[] b = new int[n];
        int length = 0;

        for (int v : a) {
            int x = Arrays.binarySearch(b, 0, length, v);
            if (x < 0) {
                x = -(x + 1);
            }
            if (x == length) {
                b[length++] = v;
            } else {
                b[x] = v;
            }
        }

        System.out.println(length);
    }
}
// <END-OF-CODE>
