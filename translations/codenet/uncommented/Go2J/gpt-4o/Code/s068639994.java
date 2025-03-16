import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = getInt(scanner);
        int[] ls = getIntArray(scanner, n);
        int[] lsRev = Arrays.copyOf(ls, n);
        Arrays.sort(ls);
        Arrays.sort(lsRev);
        reverseArray(lsRev);

        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                int x = q - p;
                int y = q + p;

                int l = binarySearch(ls, x);
                int r = n - binarySearchReverse(lsRev, y);

                long sum = r - l;
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                sum = Math.max(0, sum);
                ans += sum;
            }
        }

        ans /= 3;
        System.out.println(ans);
    }

    private static int getInt(Scanner scanner) {
        return scanner.nextInt();
    }

    private static int[] getIntArray(Scanner scanner, int n) {
        int[] is = new int[n];
        for (int i = 0; i < n; i++) {
            is[i] = getInt(scanner);
        }
        return is;
    }

    private static void reverseArray(int[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            int temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length - 1 - i] = temp;
        }
    }

    private static int binarySearch(int[] array, int key) {
        int low = 0, high = array.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (array[mid] > key) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    private static int binarySearchReverse(int[] array, int key) {
        int low = 0, high = array.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (array[mid] < key) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
// <END-OF-CODE>
