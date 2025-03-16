
import java.util.*;

public class s846000843{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] cumsum = new int[n+1];
        for (int i = 0; i < n; i++) {
            cumsum[i+1] = cumsum[i] + a[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < n-1; i++) {
            int sum = cumsum[n] - cumsum[i];
            int target = sum - cumsum[i];
            int left = 0;
            int right = n;
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (cumsum[mid] >= target) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            ans = Math.min(ans, Math.abs(cumsum[right] - target));
        }
        System.out.println(ans);
    }
}

// END-OF-CODE