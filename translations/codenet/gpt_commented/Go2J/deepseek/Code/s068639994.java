import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] ls = new int[n];
        for (int i = 0; i < n; i++) {
            ls[i] = scanner.nextInt();
        }
        int[] lsRev = Arrays.copyOf(ls, n);
        Arrays.sort(ls);
        Arrays.sort(lsRev);
        Collections.reverse(Arrays.asList(lsRev));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                int x = q - p;
                int y = q + p;

                int l = binarySearch(ls, x);
                int r = n - binarySearch(ls, y);

                int sum = r - l;
                if (i >= l && i <= r) sum--;
                if (j >= l && j <= r) sum--;
                sum = Math.max(0, sum);
                ans += sum;
            }
        }

        ans /= 3;
        System.out.println(ans);
    }

    private static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
