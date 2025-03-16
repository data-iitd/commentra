
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int[] b = new int[0];
        for (int i = 0; i < n; i++) {
            int x = Arrays.binarySearch(b, a[i]);
            if (x < 0) {
                b = Arrays.copyOf(b, b.length + 1);
                b[b.length - 1] = a[i];
            } else {
                b[x] = a[i];
            }
        }

        System.out.println(b.length);
    }
}

