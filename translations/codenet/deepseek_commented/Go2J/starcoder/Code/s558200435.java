import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] b = new int[n];
        int len = 0;
        for (int v : a) {
            int x = Arrays.binarySearch(b, 0, len, v);
            if (x < 0) {
                x = -(x + 1);
            }
            b[x] = v;
            if (x == len) {
                len++;
            }
        }
        System.out.println(len);
    }
}

