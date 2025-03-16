
import java.util.Scanner;
import java.io.PrintWriter;
import java.util.Arrays;

public class s068639994{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int n = scanner.nextInt();
        int[] ls = new int[n];
        for (int i = 0; i < n; i++) {
            ls[i] = scanner.nextInt();
        }

        int[] lsRev = Arrays.copyOf(ls, n);
        Arrays.sort(ls);
        Arrays.sort(lsRev);
        for (int i = 0; i < n / 2; i++) {
            int tmp = lsRev[i];
            lsRev[i] = lsRev[n - i - 1];
            lsRev[n - i - 1] = tmp;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                int x = q - p;
                int y = q + p;

                int l = binarySearch(ls, x);
                int r = binarySearch(lsRev, y);

                int sum = r - l;
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                if (sum < 0) {
                    sum = 0;
                }
                ans += sum;
            }
        }

        ans /= 3;
        writer.println(ans);
        writer.flush();
    }

    private static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

