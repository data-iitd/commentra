
import java.util.Scanner;

public class s558200435{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] b = new int[n];
        int len = 0;
        for (int i = 0; i < n; i++) {
            int x = binarySearch(b, 0, len, a[i]);
            if (x == len) {
                b[len++] = a[i];
            } else {
                b[x] = a[i];
            }
        }
        System.out.println(len);
    }

    private static int binarySearch(int[] a, int l, int r, int target) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}
