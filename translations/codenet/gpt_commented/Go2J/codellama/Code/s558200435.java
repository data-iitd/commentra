
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
        for (int v : a) {
            int x = Arrays.binarySearch(b, v);
            if (x < 0) {
                x = -x - 1;
            }
            if (x == b.length) {
                b = Arrays.copyOf(b, b.length + 1);
                b[b.length - 1] = v;
            } else {
                b[x] = v;
            }
        }
        System.out.println(b.length);
    }
}

