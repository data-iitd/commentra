
import java.util.*;

public class s846000843{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] cumsum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            cumsum[i + 1] = cumsum[i] + a[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < n - 1; i++) {
            ans = Math.min(ans, Math.abs(cumsum[n] - 2 * cumsum[i]));
        }
        System.out.println(ans);
    }
}

// 