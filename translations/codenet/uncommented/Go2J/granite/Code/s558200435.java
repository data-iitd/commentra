
import java.util.Scanner;
import java.util.Arrays;

public class s558200435{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int[] b = new int[n];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j == 0 || a[i] >= b[j - 1]) {
                b[j++] = a[i];
            } else {
                b[lowerBound(b, 0, j, a[i])] = a[i];
            }
        }

        System.out.println(j);
    }

    private static int lowerBound(int[] a, int fromIndex, int toIndex, int val) {
        int low = fromIndex;
        int high = toIndex - 1;

        while (low <= high) {
            int mid = (low + high) >>> 1;
            int midVal = a[mid];

            if (midVal < val) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
